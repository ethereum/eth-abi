from typing import (
    TYPE_CHECKING,
    Any,
    Tuple,
)

from faster_eth_utils import (
    big_endian_to_int,
)

from faster_eth_abi.exceptions import (
    InsufficientDataBytes,
)
from faster_eth_abi.io import (
    BytesIO,
    ContextFramesBytesIO,
)

if TYPE_CHECKING:
    from .decoding import (
        DynamicArrayDecoder,
        FixedByteSizeDecoder,
        HeadTailDecoder,
        SizedArrayDecoder,
        TupleDecoder,
    )


# Helpers
def decode_uint_256(stream: ContextFramesBytesIO) -> int:
    """
    This function is a faster version of decode_uint_256 in decoding.py.

    It recreates the logic from the UnsignedIntegerDecoder, but we can
    skip a lot because we know the value of many vars.
    """
    # read data from stream
    if len(data := stream.read(32)) == 32:
        return big_endian_to_int(data)  # type: ignore [no-any-return]
    raise InsufficientDataBytes(f"Tried to read 32 bytes, only got {len(data)} bytes.")


def get_value_byte_size(decoder: "FixedByteSizeDecoder") -> int:
    return decoder.value_bit_size // 8


# HeadTailDecoder
def decode_head_tail(self: "HeadTailDecoder", stream: ContextFramesBytesIO) -> Any:
    # Decode the offset and move the stream cursor forward 32 bytes
    start_pos = decode_uint_256(stream)
    # Jump ahead to the start of the value
    stream.push_frame(start_pos)

    # assertion check for mypy
    tail_decoder = self.tail_decoder
    if tail_decoder is None:
        raise AssertionError("`tail_decoder` is None")
    # Decode the value
    value = tail_decoder(stream)
    # Return the cursor
    stream.pop_frame()

    return value


# TupleDecoder
def decode_tuple(self: "TupleDecoder", stream: ContextFramesBytesIO) -> Tuple[Any, ...]:
    self.validate_pointers(stream)
    return tuple(decoder(stream) for decoder in self.decoders)


# SizedArrayDecoder
def decode_sized_array(
    self: "SizedArrayDecoder", stream: ContextFramesBytesIO
) -> Tuple[Any, ...]:
    item_decoder = self.item_decoder
    if item_decoder is None:
        raise AssertionError("`item_decoder` is None")

    array_size = self.array_size
    self.validate_pointers(stream, array_size)
    return tuple(item_decoder(stream) for _ in range(array_size))


# DynamicArrayDecoder
def decode_dynamic_array(
    self: "DynamicArrayDecoder", stream: ContextFramesBytesIO
) -> Tuple[Any, ...]:
    array_size = decode_uint_256(stream)
    stream.push_frame(32)
    if self.item_decoder is None:
        raise AssertionError("`item_decoder` is None")

    self.validate_pointers(stream, array_size)
    item_decoder = self.item_decoder
    try:
        return tuple(item_decoder(stream) for _ in range(array_size))
    finally:
        stream.pop_frame()


# FixedByteSizeDecoder
def read_fixed_byte_size_data_from_stream(
    self: "FixedByteSizeDecoder",
    # NOTE: use BytesIO here so mypyc doesn't type-check
    # `stream` once we compile ContextFramesBytesIO.
    stream: BytesIO,
) -> bytes:
    data_byte_size = self.data_byte_size
    if len(data := stream.read(data_byte_size)) == data_byte_size:
        return data
    raise InsufficientDataBytes(
        f"Tried to read {data_byte_size} bytes, only got {len(data)} bytes."
    )
