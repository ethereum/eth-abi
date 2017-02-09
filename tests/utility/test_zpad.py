import pytest

from eth_abi.utils.padding import zpad


@pytest.mark.parametrize(
    'value,length,expected',
    (
        ('', 5, "\x00\x00\x00\x00\x00"),
        ('abc', 5, "\x00\x00abc"),
        ('abcde', 5, "abcde"),
        ('abcdef', 5, "abcdef"),
    )
)
def test_zpadding(value, length, expected):
    actual = zpad(value, length)
    assert actual == expected
