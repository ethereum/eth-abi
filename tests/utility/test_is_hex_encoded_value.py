import pytest
from hypothesis import given
import hypothesis.strategies as st

from eth_abi.utils import is_hex_encoded_value


@pytest.mark.parametrize(
    'value,expected',
    (
        # True
        (b'', True),
        (b'0x', True),
        (b'65100b148bc68f0197eaa9e4d2db289d2409a6e58bb3fca22301f5826fd1e7e4', True),
        (b'0x65100b148bc68f0197eaa9e4d2db289d2409a6e58bb3fca22301f5826fd1e7e4', True),
        (b'abcdef1234567890abcdef1234567890abcdef12', True),
        (b'0xabcdef1234567890abcdef1234567890abcdef12', True),
        # False
        (b'abcdef1234567890abcdef1234567890abcdef12a', False),
        (b'0xcdef1234567890abcdef1234567890abcdef12', False),
        (b'0x0xabcdef1234567890abcdef1234567890abcdef12', False),
        (b'abcdefg', False),
        (b'0xabcdefg', False),
    )
)
def test_is_hex_encoded_value(value, expected):
    actual = is_hex_encoded_value(value)
    assert actual is expected
