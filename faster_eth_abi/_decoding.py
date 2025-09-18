from typing import (
    TYPE_CHECKING,
    Any,
    Optional,
    Tuple,
)

from faster_eth_abi.io import (
    ContextFramesBytesIO,
)

if TYPE_CHECKING:
    from .decoding import (
        HeadTailDecoder,
        TupleDecoder,
        UnsignedIntegerDecoder,
    )


_UINT256_DECODER: Optional["UnsignedIntegerDecoder"] = None


def __set_uint256_decoder() -> "UnsignedIntegerDecoder":
    # this helper breaks a circular dependency on the non-compiled decoding module
    from . import (
        decoding,
    )

    global _UINT256_DECODER
    _UINT256_DECODER = decoding.decode_uint_256

    return _UINT256_DECODER


def decode_uint_256(stream: ContextFramesBytesIO) -> int:
    decoder = _UINT256_DECODER
    if decoder is None:
        decoder = __set_uint256_decoder()
    decoded: int = decoder(stream)
    return decoded


# HeadTailDecoder
def decode_head_tail(self: "HeadTailDecoder", stream: ContextFramesBytesIO) -> Any:
    # Decode the offset and move the stream cursor forward 32 bytes
    start_pos = decode_uint_256(stream)
    # Jump ahead to the start of the value
    stream.push_frame(start_pos)

    # assertion check for mypy
    if self.tail_decoder is None:
        raise AssertionError("`tail_decoder` is None")
    # Decode the value
    value = self.tail_decoder(stream)
    # Return the cursor
    stream.pop_frame()

    return value


# TupleDecoder
def decode_tuple(self: "TupleDecoder", stream: ContextFramesBytesIO) -> Tuple[Any, ...]:
    self.validate_pointers(stream)
    return tuple(decoder(stream) for decoder in self.decoders)
