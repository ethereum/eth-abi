import pytest

from eth_abi.utils import zpad


@pytest.mark.parametrize(
    'value,length,expected',
    (
        ('', 5, b"\x00\x00\x00\x00\x00"),
        ('abc', 5, b"\x00\x00abc"),
        ('abcde', 5, b"abcde"),
        ('abcdef', 5, b"abcdef"),
    )
)
def test_zpadding(value, length, expected):
    actual = zpad(value, length)
    assert actual == expected
