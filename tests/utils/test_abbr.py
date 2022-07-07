import pytest

from eth_abi.utils.string import (
    abbr,
)


@pytest.mark.parametrize(
    "value,expected,limit",
    (
        (1234567891234567891, "1234567891234567891", None),
        (12345678912345678912, "12345678912345678912", None),
        (
            "asdf" * 30,
            "'asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd...",
            None,
        ),
        (
            list(range(100)),
            "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 2...",  # noqa: E501
            None,
        ),
        (1234567891234567891, "...", 3),
        (1234567891234567891, "1...", 4),
    ),
)
def test_abbr(value, expected, limit):
    if limit is not None:
        actual = abbr(value, limit)
    else:
        actual = abbr(value)
    assert actual == expected


def test_abbr_throws_value_errors():
    with pytest.raises(ValueError):
        abbr("asdf", limit=2)
