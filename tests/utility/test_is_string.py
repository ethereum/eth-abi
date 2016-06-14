import pytest

from eth_abi.utils import is_string


@pytest.mark.parametrize(
    'value,expected',
    (
        # Byte Strings
        (b'abc', True),
        (b'', True),
        # Ints
        (0, False),
        # Ints
        (2 ** 256, False),
        # Bools
        (True, False),
    )
)
def test_is_string(value, expected):
    actual = is_string(value)
    assert actual == expected
