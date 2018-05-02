import pytest

from eth_abi.abi import decode_single

from ..common import CORRECT_SINGLE_ENCODINGS


@pytest.mark.parametrize('typ,expected,byte_str', CORRECT_SINGLE_ENCODINGS)
def test_decode_single(typ, expected, byte_str):
    actual = decode_single(typ, byte_str)
    assert actual == expected
