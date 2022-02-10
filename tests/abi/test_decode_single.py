import pytest

from eth_abi.abi import (
    decode_single,
)

from ..common.unit import (
    CORRECT_SINGLE_ENCODINGS,
)


@pytest.mark.parametrize(
    'typ,expected,_1,abi_encoding,_2',
    CORRECT_SINGLE_ENCODINGS,
)
def test_decode_single(typ, expected, _1, abi_encoding, _2):
    actual = decode_single(typ, abi_encoding)
    assert actual == expected


def test_decode_single_wrong_data_type_raises():
    with pytest.raises(TypeError):
        decode_single('uint32', '')
