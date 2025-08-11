from itertools import (
    accumulate,
)
from typing import (
    TYPE_CHECKING,
    Any,
    Callable,
    List,
    Optional,
    Sequence,
    TypeVar,
)

if TYPE_CHECKING:
    from faster_eth_abi.encoding import (
        BaseEncoder,
    )


T = TypeVar("T")


def encode_tuple(
    values: Sequence[Any],
    encoders: Sequence["BaseEncoder"],
) -> bytes:
    raw_head_chunks: List[Optional[bytes]] = []
    tail_chunks: List[bytes] = []
    for value, encoder in zip(values, encoders):
        if getattr(encoder, "is_dynamic", False):
            raw_head_chunks.append(None)
            tail_chunks.append(encoder(value))
        else:
            raw_head_chunks.append(encoder(value))
            tail_chunks.append(b"")

    head_length = sum(32 if item is None else len(item) for item in raw_head_chunks)
    tail_offsets = (0, *accumulate(len(item) for item in tail_chunks[:-1]))
    head_chunks = tuple(
        encode_uint_256(head_length + offset) if chunk is None else chunk
        for chunk, offset in zip(raw_head_chunks, tail_offsets)
    )

    return b"".join(head_chunks) + b"".join(tail_chunks)


def encode_fixed(
    value: Any,
    encode_fn: Callable[[Any], bytes],
    is_big_endian: bool,
    data_byte_size: int,
) -> bytes:
    base_encoded_value = encode_fn(value)
    if is_big_endian:
        return base_encoded_value.rjust(data_byte_size, b"\x00")
    else:
        return base_encoded_value.ljust(data_byte_size, b"\x00")


def encode_signed(
    value: T,
    encode_fn: Callable[[T], bytes],
    data_byte_size: int,
) -> bytes:
    base_encoded_value = encode_fn(value)
    if value >= 0:
        return base_encoded_value.rjust(data_byte_size, b"\x00")
    else:
        return base_encoded_value.rjust(data_byte_size, b"\xff")


def encode_elements(item_encoder: "BaseEncoder", value: Sequence[Any]) -> bytes:
    tail_chunks = tuple(item_encoder(i) for i in value)

    items_are_dynamic = getattr(item_encoder, "is_dynamic", False)
    if not items_are_dynamic or len(value) == 0:
        return b"".join(tail_chunks)

    head_length = 32 * len(value)
    tail_offsets = (0, *accumulate(len(item) for item in tail_chunks[:-1]))
    head_chunks = tuple(
        encode_uint_256(head_length + offset) for offset in tail_offsets
    )
    return b"".join(head_chunks) + b"".join(tail_chunks)


def encode_elements_dynamic(item_encoder: "BaseEncoder", value: Sequence[Any]) -> bytes:
    encoded_size = encode_uint_256(len(value))
    encoded_elements = encode_elements(item_encoder, value)
    return encoded_size + encoded_elements


def encode_uint_256(i: int) -> bytes:
    # An optimized version of the `encode_uint_256` in `encoding.py` which does not perform any validation.
    # We should not have any issues here unless you're encoding really really massive iterables.
    big_endian = int_to_big_endian(i)
    return big_endian.rjust(32, b"\x00")


def int_to_big_endian(value: int) -> bytes:
    # vendored from eth-utils so it can compile nicely into faster-eth-abi's binary
    return value.to_bytes((value.bit_length() + 7) // 8 or 1, "big")
