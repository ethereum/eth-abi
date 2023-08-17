from typing import (
    Any,
    Iterable,
)

from eth_typing import (
    TypeStr,
)
from eth_utils import (
    is_bytes,
)


def validate_bytes_param(param: Any, param_name: str) -> None:
    if not is_bytes(param):
        raise TypeError(
            f"The `{param_name}` value must be of bytes type. Got {type(param)}"
        )


def validate_list_like_param(param: Any, param_name: str) -> None:
    if not isinstance(param, (list, tuple)):
        raise TypeError(
            f"The `{param_name}` value type must be one of list or tuple. "
            f"Got {type(param)}"
        )


def validate_against_zero_sized_tuples(types: Iterable[TypeStr]) -> None:
    if any("()" in type_str for type_str in types):
        raise ValueError('Zero-sized tuple types "()" are not supported.')


def validate_codec_types(types: Iterable[TypeStr]) -> None:
    """
    Validate that the provided types are valid for encoding or decoding.
    """
    validate_list_like_param(types, "types")
    validate_against_zero_sized_tuples(types)
