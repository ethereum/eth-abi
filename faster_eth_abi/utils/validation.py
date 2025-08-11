from typing import (
    Any,
)


def validate_bytes_param(param: Any, param_name: str) -> None:
    if not isinstance(param, (bytes, bytearray)):
        raise TypeError(
            f"The `{param_name}` value must be of bytes type. Got {type(param)}"
        )


def validate_list_like_param(param: Any, param_name: str) -> None:
    if not isinstance(param, (list, tuple)):
        raise TypeError(
            f"The `{param_name}` value type must be one of list or tuple. "
            f"Got {type(param)}"
        )
