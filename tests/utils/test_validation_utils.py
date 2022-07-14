import pytest

from eth_abi.utils.validation import (
    validate_bytes_param,
    validate_list_like_param,
)


@pytest.mark.parametrize(
    "bytes_value",
    (
        b"",
        b"\x00",
        b"david attenborough",
        b"\xff" * 32,
        bytearray(b"\x01\x02\x03\x04\xff"),
    ),
)
def test_validate_bytes_param(bytes_value):
    validate_bytes_param(bytes_value, "test_param")


@pytest.mark.parametrize(
    "non_bytes_value",
    (
        "",
        123,
        [b"david attenborough"],
        {b"david attenborough"},
        (b"david attenborough",),
    ),
)
def test_validate_bytes_param_raises_for_non_bytes_types(non_bytes_value):
    param_name = "test_param"
    with pytest.raises(
        TypeError,
        match=f"The `{param_name}` value must be of bytes type. "
        f"Got {type(non_bytes_value)}",
    ):
        validate_bytes_param(non_bytes_value, param_name)


@pytest.mark.parametrize(
    "list_like_value", ([1, 2], (1, 2), ["1", 2], ("1", 2), [], tuple())
)
def test_validate_list_like_param(list_like_value):
    validate_list_like_param(list_like_value, "test_param")


@pytest.mark.parametrize(
    "non_list_like_value",
    (
        "",
        123,
        b"",
        b"\xff",
        b"david attenborough",
        bytearray(b"\x01\xff"),
        {"key": "val"},
        {1, 2},
    ),
)
def test_validate_list_like_param_taises_for_non_list_like_types(non_list_like_value):
    param_name = "test_param"
    with pytest.raises(
        TypeError,
        match=f"The `{param_name}` value type must be one of list or tuple. "
        f"Got {type(non_list_like_value)}",
    ):
        validate_list_like_param(non_list_like_value, param_name)
