import pytest

from hypothesis import (
    example,
    given,
    strategies as st,
)

from eth_abi.exceptions import (
    ABITypeError,
    ParseError,
)

from eth_abi.grammar import (
    BasicType,
    TYPE_ALIASES,
    TupleType,
    normalize,
    parse,
)

from .common.strategies import (
    malformed_type_strs,
    type_strs,
)


@pytest.mark.parametrize(
    'type_str, expected_type',
    (
        ('uint', BasicType('uint')),
        ('uint256', BasicType('uint', 256)),
        ('uint256[]', BasicType('uint', 256, ((),))),
        ('uint256[][1][23][]', BasicType('uint', 256, ((), (1,), (23,), ()))),
        ('uint[]', BasicType('uint', None, ((),))),
        ('int[2]', BasicType('int', None, ((2,),))),
        ('fixed128x19', BasicType('fixed', (128, 19))),
        ('ufixed128x19[][]', BasicType('ufixed', (128, 19), ((), ()))),
        (
            '(int,ufixed128x19[][])',
            TupleType((
                BasicType('int'),
                BasicType('ufixed', (128, 19), ((), ())),
            )),
        ),
        (
            '(int,(address,function))',
            TupleType((
                BasicType('int'),
                TupleType((
                    BasicType('address'),
                    BasicType('function'),
                )),
            )),
        ),
        (
            '((address,(fixed,bool)),(uint256[][1][],fixed128x19))',
            TupleType((
                TupleType((
                    BasicType('address'),
                    TupleType((
                        BasicType('fixed'),
                        BasicType('bool'),
                    )),
                )),
                TupleType((
                    BasicType('uint', 256, ((), (1,), ())),
                    BasicType('fixed', (128, 19)),
                )),
            )),
        ),
        ('()', TupleType(tuple())),
        (
            '(int,(),())',
            TupleType((BasicType('int'), TupleType(tuple()), TupleType(tuple()))),
        ),
    )
)
def test_parsing_with_parsimonious_grammar_and_node_visitor_works(type_str, expected_type):
    assert parse(type_str) == expected_type


@given(malformed_type_strs, st.none())
@example('int0', 4)
@example('fixed128x0', 9)
@example('ufixed128x0', 10)
@example('int!', 4)
@example('(int, bool)', 6)
@example('(int,bool,)', 11)
@example('(int,(address,uint256[][])', 27)
def test_parsing_invalid_type_str_causes_parse_error(type_str, error_col):
    if error_col is not None:
        pattern = r'Parse error at .* \(column {}\)'.format(error_col)
    else:
        pattern = r'Parse error at .*'

    with pytest.raises(ParseError, match=pattern):
        parse(type_str)


def test_parse_raises_type_error_for_wrong_data_type():
    with pytest.raises(TypeError):
        parse(b'uint256')


@given(type_strs)
def test_end_to_end_parsing_and_collapsing(type_str):
    assert str(parse(type_str)) == type_str


@pytest.mark.parametrize(
    'type_str, pattern',
    (
        ('string1x1', 'string type cannot have suffix'),
        ('string33', 'string type cannot have suffix'),
        ('bytes1x1', 'no suffix or a numerical'),
        ('bytes33', 'maximum 32 bytes'),
        ('int', 'must have numerical suffix'),
        ('int7', 'size out of bounds'),
        ('int257', 'size out of bounds'),
        ('int9', 'must be multiple of 8'),
        ('uint', 'must have numerical suffix'),
        ('uint7', 'size out of bounds'),
        ('uint257', 'size out of bounds'),
        ('uint9', 'must be multiple of 8'),
        ('fixed', 'must have suffix of form'),
        ('fixed8', 'must have suffix of form'),
        ('fixed7x19', 'fixed size out of bounds'),
        ('fixed257x19', 'fixed size out of bounds'),
        ('fixed17x19', 'must be multiple of 8'),
        ('fixed128x81', 'exponent size out of bounds'),
        ('ufixed', 'must have suffix of form'),
        ('ufixed8', 'must have suffix of form'),
        ('ufixed7x19', 'fixed size out of bounds'),
        ('ufixed257x19', 'fixed size out of bounds'),
        ('ufixed17x19', 'must be multiple of 8'),
        ('ufixed128x81', 'exponent size out of bounds'),
        ('real', 'must have suffix of form'),
        ('real8', 'must have suffix of form'),
        ('real6x1', 'real size out of bounds'),
        ('real256x1', 'real size out of bounds'),
        ('real17x8', 'must be multiples of 8'),
        ('real16x9', 'must be multiples of 8'),
        ('ureal', 'must have suffix of form'),
        ('ureal8', 'must have suffix of form'),
        ('ureal6x1', 'real size out of bounds'),
        ('ureal256x1', 'real size out of bounds'),
        ('ureal17x8', 'must be multiples of 8'),
        ('ureal16x9', 'must be multiples of 8'),
        ('hash', 'must have numerical suffix'),
        ('hash128x128', 'must have numerical suffix'),
        ('address128', 'cannot have suffix'),
        ('address128x128', 'cannot have suffix'),
        (
            '(int256,(address,(ufixed7x19,fixed)))',
            "For 'ufixed7x19' type at column 19 "
            r"in '\(int256,\(address,\(ufixed7x19,fixed\)\)\)': "
            "fixed size out of bounds",
        ),
        (
            '(int256,(address,(ufixed128x19,fixed)))',
            "For 'fixed' type at column 32 "
            r"in '\(int256,\(address,\(ufixed128x19,fixed\)\)\)': "
            "fixed type must have suffix of form",
        ),
    )
)
def test_invalid_abi_types(type_str, pattern):
    with pytest.raises(ABITypeError, match=pattern):
        parse(type_str).validate()


@pytest.mark.parametrize(
    'type_str',
    (
        'string',
        'bytes24',
        'int256',
        'uint128',
        'fixed128x19',
        'ufixed256x19',
        'real128x128',
        'ureal128x64',
        'hash256',
        'address',
        '(int256,(address,(ufixed128x19,fixed128x19)))',
    )
)
def test_valid_abi_types(type_str):
    parse(type_str).validate()


@pytest.mark.parametrize(
    'type_str, normalized',
    tuple(TYPE_ALIASES.items()) + (
        ('(int,uint,fixed,ufixed)', '(int256,uint256,fixed128x18,ufixed128x18)'),
        ('(function,function,function)', '(bytes24,bytes24,bytes24)'),
    ),
)
def test_normalize(type_str, normalized):
    assert normalize(type_str) == normalized


def test_basic_type_item_type_throws_errors():
    bt = parse('int256')

    pattern = "Cannot determine item type for non-array type 'int256'"
    with pytest.raises(ValueError, match=pattern):
        bt.item_type
