import pytest

from eth_abi.utils import is_numeric


@pytest.mark.parametrize(
    'value,expected',
    (
        # Ints
        (0, True),
        (-1, True),
        (1, True),
        # Longs
        (0L, True),
        (-1L, True),
        (1L, True),
        # Bools
        (True, True),
        (False, True),
        # Strings
        ('abc', False),
        ('1', False),
        ('0', False),
        ('', False),
    )
)
def test_is_numeric(value, expected):
    actual = is_numeric(value)
    assert actual == expected
