import pytest

from eth_abi.abi import (
    decode,
)
from eth_abi.exceptions import (
    InsufficientDataBytes,
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

    actual = decode(types, abi_encoding)
    assert actual == expected


@pytest.mark.parametrize(
    'type_str,expected,abi_encoding,_',
    CORRECT_STATIC_ENCODINGS,
)
def test_abi_decode_for_single_static_types(type_str, expected, abi_encoding, _):
    (actual,) = decode([type_str], abi_encoding)
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

    (actual,) = decode([type_str], abi_encoding)

    assert actual == expected


@pytest.mark.parametrize('data', (b'', bytearray()))
def test_decode_abi_empty_data_raises(data):
    with pytest.raises(InsufficientDataBytes):
        decode(['uint'], data)


@pytest.mark.parametrize('data', ('', 123, 0x123, [b'\x01'], (b'\x01',), {b'\x01'}))
def test_decode_abi_wrong_data_param_type_raises(data):
    with pytest.raises(
        TypeError,
        match=f"The `data` value must be of bytes type. Got {type(data)}"
    ):
        decode(['uint32', 'uint32'], data)


@pytest.mark.parametrize(
    'types',
    ('', 123, b'', b'\xff', b'david attenborough', bytearray(b'\x01\xff'), {'key': 'val'}, {1, 2})
)
def test_decode_abi_wrong_types_param_type_raises(types):
    with pytest.raises(
        TypeError,
        match=f"The `types` value type must be one of list or tuple. Got {type(types)}"
    ):
        decode(types, b'\x00' * 32)
