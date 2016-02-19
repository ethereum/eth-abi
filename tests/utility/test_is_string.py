import pytest

from eth_abi.utils import is_string


@pytest.mark.parametrize(
    'value,expected',
    (
        # Strings
        ('abc', True),
        ('', True),
        # Ints
        (0, False),
        # Longs
        (0L, False),
        # Bools
        (True, False),
    )
)
def test_is_string(value, expected):
    actual = is_string(value)
    assert actual == expected
