import pytest

from eth_abi.abi import (
    decode,
)
from eth_abi.exceptions import (
    DecodingError,
)
from eth_abi.grammar import (
    parse,
)

from ..common.unit import (
    CORRECT_DYNAMIC_ENCODINGS,
    CORRECT_STATIC_ENCODINGS,
    CORRECT_TUPLE_ENCODINGS,
    words,
)


@pytest.mark.parametrize(
    'type_str,expected,abi_encoding,_',
    CORRECT_TUPLE_ENCODINGS,
)
def test_decode_abi_for_multiple_types_as_list(type_str, expected, abi_encoding, _):
    abi_type = parse(type_str)
    if abi_type.arrlist is not None:
        pytest.skip('ABI coding functions do not support array types')

    types = [t.to_type_str() for t in abi_type.components]

    actual = decode(abi_encoding, types)
    assert actual == expected


@pytest.mark.parametrize(
    'type_str,expected,abi_encoding,_',
    CORRECT_STATIC_ENCODINGS,
)
def test_abi_decode_for_single_static_types(type_str, expected, abi_encoding, _):
    (actual,) = decode(abi_encoding, [type_str])
    assert actual == expected


@pytest.mark.parametrize(
    'type_str,expected,abi_encoding,_',
    CORRECT_DYNAMIC_ENCODINGS,
)
def test_abi_decode_for_single_dynamic_types(type_str, expected, abi_encoding, _):
    # Tests set up list values but encoders return sequences as tuples.
    # i.e. [b'\xde\xad\xbe\xef'] vs encoder return type (b'\xde\xad\xbe\xef',)
    expected = tuple(expected) if isinstance(expected, list) else expected

    abi_encoding = (
        # 32 bytes offset for dynamic types
        b''.join([words('20'), abi_encoding])
    )

    (actual,) = decode(abi_encoding, [type_str])

    assert actual == expected


def test_decode_abi_empty_data_raises():
    with pytest.raises(DecodingError):
        decode(b'', ['uint32', 'uint32'])


def test_decode_abi_wrong_data_type_raises():
    with pytest.raises(TypeError):
        decode('', ['uint32', 'uint32'])
