import abc
import decimal
from typing import (
    Any,
    Callable,
    Final,
    Optional,
    Tuple,
    Union,
)

from faster_eth_utils import (
    big_endian_to_int,
    to_normalized_address,
)

from faster_eth_abi._decoding import (
    decode_dynamic_array,
    decode_head_tail,
    decode_sized_array,
    decode_tuple,
    get_value_byte_size,
    read_fixed_byte_size_data_from_stream,
)
from faster_eth_abi.base import (
    BaseCoder,
)
from faster_eth_abi.exceptions import (
    InsufficientDataBytes,
    InvalidPointer,
    NonEmptyPaddingBytes,
)
from faster_eth_abi.from_type_str import (
    parse_tuple_type_str,
    parse_type_str,
)
from faster_eth_abi.io import (
    ContextFramesBytesIO,
)
from faster_eth_abi.utils.numeric import (
    TEN,
    abi_decimal_context,
    ceil32,
)

DynamicDecoder = Union[
    "HeadTailDecoder", "SizedArrayDecoder", "DynamicArrayDecoder", "ByteStringDecoder"
]


class BaseDecoder(BaseCoder, metaclass=abc.ABCMeta):
    """
    Base class for all decoder classes.  Subclass this if you want to define a
    custom decoder class.  Subclasses must also implement
    :any:`BaseCoder.from_type_str`.
    """

    strict = True

    @abc.abstractmethod
    def decode(self, stream: ContextFramesBytesIO) -> Any:  # pragma: no cover
        """
        Decodes the given stream of bytes into a python value.  Should raise
        :any:`exceptions.DecodingError` if a python value cannot be decoded
        from the given byte stream.
        """

    def __call__(self, stream: ContextFramesBytesIO) -> Any:
        return self.decode(stream)


class HeadTailDecoder(BaseDecoder):
    """
    Decoder for a dynamic element of a dynamic container (a dynamic array, or a sized
    array or tuple that contains dynamic elements). A dynamic element consists of a
    pointer, aka offset, which is located in the head section of the encoded container,
    and the actual value, which is located in the tail section of the encoding.
    """

    is_dynamic = True

    tail_decoder: Optional[DynamicDecoder] = None

    def validate(self) -> None:
        super().validate()

        if self.tail_decoder is None:
            raise ValueError("No `tail_decoder` set")

    def decode(self, stream: ContextFramesBytesIO) -> Any:
        return decode_head_tail(self, stream)

    __call__ = decode


class TupleDecoder(BaseDecoder):
    decoders: Tuple[BaseDecoder, ...] = ()

    def __init__(self, decoders: Tuple[BaseDecoder, ...], **kwargs: Any) -> None:
        super().__init__(**kwargs)

        self.decoders = decoders = tuple(
            HeadTailDecoder(tail_decoder=d) if getattr(d, "is_dynamic", False) else d
            for d in decoders
        )

        self.is_dynamic = any(getattr(d, "is_dynamic", False) for d in decoders)
        self.len_of_head = sum(
            getattr(decoder, "array_size", 1) for decoder in decoders
        )

    def validate(self) -> None:
        super().validate()

        if self.decoders is None:
            raise ValueError("No `decoders` set")

    def validate_pointers(self, stream: ContextFramesBytesIO) -> None:
        """
        Verify that all pointers point to a valid location in the stream.
        """
        current_location = stream.tell()
        end_of_offsets = current_location + 32 * self.len_of_head
        total_stream_length = len(stream.getbuffer())
        for decoder in self.decoders:
            if isinstance(decoder, HeadTailDecoder):
                # the next 32 bytes are a pointer
                offset = decode_uint_256(stream)
                indicated_idx = current_location + offset
                if (
                    indicated_idx < end_of_offsets
                    or indicated_idx >= total_stream_length
                ):
                    # the pointer is indicating its data is located either within the
                    # offsets section of the stream or beyond the end of the stream,
                    # both of which are invalid
                    raise InvalidPointer(
                        "Invalid pointer in tuple at location "
                        f"{stream.tell() - 32} in payload"
                    )
            else:
                # the next 32 bytes are not a pointer, so progress the stream per
                # the decoder
                decoder(stream)
        # return the stream to its original location for actual decoding
        stream.seek(current_location)

    def decode(self, stream: ContextFramesBytesIO) -> Tuple[Any, ...]:
        return decode_tuple(self, stream)

    __call__ = decode

    @parse_tuple_type_str
    def from_type_str(cls, abi_type, registry):
        decoders = tuple(
            registry.get_decoder(c.to_type_str()) for c in abi_type.components
        )

        return cls(decoders=decoders)


class SingleDecoder(BaseDecoder):
    decoder_fn = None

    def validate(self) -> None:
        super().validate()

        if self.decoder_fn is None:
            raise ValueError("No `decoder_fn` set")

    def validate_padding_bytes(self, value, padding_bytes):
        raise NotImplementedError("Must be implemented by subclasses")

    def decode(self, stream):
        raw_data = self.read_data_from_stream(stream)
        data, padding_bytes = self.split_data_and_padding(raw_data)
        decoder_fn = self.decoder_fn
        if decoder_fn is None:
            raise AssertionError("`decoder_fn` is None")
        value = decoder_fn(data)
        self.validate_padding_bytes(value, padding_bytes)

        return value

    __call__ = decode

    def read_data_from_stream(self, stream: ContextFramesBytesIO) -> bytes:
        raise NotImplementedError("Must be implemented by subclasses")

    def split_data_and_padding(self, raw_data: bytes) -> Tuple[bytes, bytes]:
        return raw_data, b""


class BaseArrayDecoder(BaseDecoder):
    item_decoder: BaseDecoder = None

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)

        # Use a head-tail decoder to decode dynamic elements
        item_decoder = self.item_decoder
        if item_decoder.is_dynamic:
            self.item_decoder = HeadTailDecoder(tail_decoder=item_decoder)

    def validate(self) -> None:
        super().validate()

        if self.item_decoder is None:
            raise ValueError("No `item_decoder` set")

    @parse_type_str(with_arrlist=True)
    def from_type_str(cls, abi_type, registry):
        item_decoder = registry.get_decoder(abi_type.item_type.to_type_str())

        array_spec = abi_type.arrlist[-1]
        if len(array_spec) == 1:
            # If array dimension is fixed
            return SizedArrayDecoder(
                array_size=array_spec[0],
                item_decoder=item_decoder,
            )
        else:
            # If array dimension is dynamic
            return DynamicArrayDecoder(item_decoder=item_decoder)

    def validate_pointers(self, stream: ContextFramesBytesIO, array_size: int) -> None:
        """
        Verify that all pointers point to a valid location in the stream.
        """
        if isinstance(self.item_decoder, HeadTailDecoder):
            current_location = stream.tell()
            end_of_offsets = current_location + 32 * array_size
            total_stream_length = len(stream.getbuffer())
            for _ in range(array_size):
                offset = decode_uint_256(stream)
                indicated_idx = current_location + offset
                if (
                    indicated_idx < end_of_offsets
                    or indicated_idx >= total_stream_length
                ):
                    # the pointer is indicating its data is located either within the
                    # offsets section of the stream or beyond the end of the stream,
                    # both of which are invalid
                    raise InvalidPointer(
                        "Invalid pointer in array at location "
                        f"{stream.tell() - 32} in payload"
                    )
            stream.seek(current_location)


class SizedArrayDecoder(BaseArrayDecoder):
    array_size: int = None

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.is_dynamic = self.item_decoder.is_dynamic

    def decode(self, stream):
        return decode_sized_array(self, stream)

    __call__ = decode


class DynamicArrayDecoder(BaseArrayDecoder):
    # Dynamic arrays are always dynamic, regardless of their elements
    is_dynamic = True

    def decode(self, stream: ContextFramesBytesIO) -> Tuple[Any, ...]:
        return decode_dynamic_array(self, stream)

    __call__ = decode


class FixedByteSizeDecoder(SingleDecoder):
    decoder_fn: Callable[[bytes], Any] = None
    value_bit_size: int = None
    data_byte_size: int = None
    is_big_endian: bool = None

    def validate(self) -> None:
        super().validate()

        value_bit_size = self.value_bit_size
        if value_bit_size is None:
            raise ValueError("`value_bit_size` may not be None")
        data_byte_size = self.data_byte_size
        if data_byte_size is None:
            raise ValueError("`data_byte_size` may not be None")
        if self.decoder_fn is None:
            raise ValueError("`decoder_fn` may not be None")
        if self.is_big_endian is None:
            raise ValueError("`is_big_endian` may not be None")

        if value_bit_size % 8 != 0:
            raise ValueError(
                f"Invalid value bit size: {value_bit_size}. Must be a multiple of 8"
            )

        if value_bit_size > data_byte_size * 8:
            raise ValueError("Value byte size exceeds data size")

    def read_data_from_stream(self, stream: ContextFramesBytesIO) -> bytes:
        return read_fixed_byte_size_data_from_stream(self, stream)

    def split_data_and_padding(self, raw_data: bytes) -> Tuple[bytes, bytes]:
        value_byte_size = get_value_byte_size(self)
        padding_size = self.data_byte_size - value_byte_size

        if self.is_big_endian:
            padding_bytes = raw_data[:padding_size]
            data = raw_data[padding_size:]
        else:
            data = raw_data[:value_byte_size]
            padding_bytes = raw_data[value_byte_size:]

        return data, padding_bytes

    def validate_padding_bytes(self, value: Any, padding_bytes: bytes) -> None:
        value_byte_size = get_value_byte_size(self)
        padding_size = self.data_byte_size - value_byte_size

        if padding_bytes != b"\x00" * padding_size:
            raise NonEmptyPaddingBytes(
                f"Padding bytes were not empty: {padding_bytes!r}"
            )

    def _get_value_byte_size(self) -> int:
        # This is unused, but it is kept in to preserve the eth-abi api
        return get_value_byte_size(self)


class Fixed32ByteSizeDecoder(FixedByteSizeDecoder):
    data_byte_size = 32


class BooleanDecoder(Fixed32ByteSizeDecoder):
    value_bit_size = 8
    is_big_endian = True

    @staticmethod
    def decoder_fn(data: bytes) -> bool:
        if data == b"\x00":
            return False
        elif data == b"\x01":
            return True
        else:
            raise NonEmptyPaddingBytes(
                f"Boolean must be either 0x0 or 0x1.  Got: {data!r}"
            )

    @parse_type_str("bool")
    def from_type_str(cls, abi_type, registry):
        return cls()


class AddressDecoder(Fixed32ByteSizeDecoder):
    value_bit_size = 20 * 8
    is_big_endian = True
    decoder_fn = staticmethod(to_normalized_address)

    @parse_type_str("address")
    def from_type_str(cls, abi_type, registry):
        return cls()


#
# Unsigned Integer Decoders
#
class UnsignedIntegerDecoder(Fixed32ByteSizeDecoder):
    decoder_fn = staticmethod(big_endian_to_int)
    is_big_endian = True

    @parse_type_str("uint")
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub)


decode_uint_256 = UnsignedIntegerDecoder(value_bit_size=256)


#
# Signed Integer Decoders
#
class SignedIntegerDecoder(Fixed32ByteSizeDecoder):
    is_big_endian = True

    def decoder_fn(self, data):
        value = big_endian_to_int(data)
        value_bit_size = self.value_bit_size
        if value >= 2 ** (value_bit_size - 1):
            return value - 2**value_bit_size
        else:
            return value

    def validate_padding_bytes(self, value: Any, padding_bytes: bytes) -> None:
        value_byte_size = get_value_byte_size(self)
        padding_size = self.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b"\x00" * padding_size
        else:
            expected_padding_bytes = b"\xff" * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                f"Padding bytes were not empty: {padding_bytes!r}"
            )

    @parse_type_str("int")
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub)


#
# Bytes1..32
#
class BytesDecoder(Fixed32ByteSizeDecoder):
    is_big_endian = False

    @staticmethod
    def decoder_fn(data):
        return data

    @parse_type_str("bytes")
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub * 8)


class BaseFixedDecoder(Fixed32ByteSizeDecoder):
    frac_places: int = None
    is_big_endian = True

    def validate(self) -> None:
        super().validate()

        frac_places = self.frac_places
        if frac_places is None:
            raise ValueError("must specify `frac_places`")

        if frac_places <= 0 or frac_places > 80:
            raise ValueError("`frac_places` must be in range (0, 80]")


class UnsignedFixedDecoder(BaseFixedDecoder):
    def decoder_fn(self, data):
        value = big_endian_to_int(data)

        with decimal.localcontext(abi_decimal_context):
            decimal_value = decimal.Decimal(value) / TEN**self.frac_places

        return decimal_value

    @parse_type_str("ufixed")
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(value_bit_size=value_bit_size, frac_places=frac_places)


class SignedFixedDecoder(BaseFixedDecoder):
    def decoder_fn(self, data):
        value = big_endian_to_int(data)
        value_bit_size = self.value_bit_size
        if value >= 2 ** (value_bit_size - 1):
            signed_value = value - 2**value_bit_size
        else:
            signed_value = value

        with decimal.localcontext(abi_decimal_context):
            decimal_value = decimal.Decimal(signed_value) / TEN**self.frac_places

        return decimal_value

    def validate_padding_bytes(self, value: Any, padding_bytes: bytes) -> None:
        value_byte_size = get_value_byte_size(self)
        padding_size = self.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b"\x00" * padding_size
        else:
            expected_padding_bytes = b"\xff" * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                f"Padding bytes were not empty: {padding_bytes!r}"
            )

    @parse_type_str("fixed")
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(value_bit_size=value_bit_size, frac_places=frac_places)


#
# String and Bytes
#
class ByteStringDecoder(SingleDecoder):
    is_dynamic = True

    @staticmethod
    def decoder_fn(data):
        return data

    def read_data_from_stream(self, stream: ContextFramesBytesIO) -> bytes:
        data_length = decode_uint_256(stream)
        padded_length = ceil32(data_length)

        data = stream.read(padded_length)

        if self.strict:
            if len(data) < padded_length:
                raise InsufficientDataBytes(
                    f"Tried to read {padded_length} bytes, only got {len(data)} bytes"
                )

            padding_bytes = data[data_length:]
            if padding_bytes != b"\x00" * (padded_length - data_length):
                raise NonEmptyPaddingBytes(
                    f"Padding bytes were not empty: {padding_bytes!r}"
                )

        return data[:data_length]

    def validate_padding_bytes(self, value: Any, padding_bytes: bytes) -> None:
        pass

    @parse_type_str("bytes")
    def from_type_str(cls, abi_type, registry):
        return cls()


class StringDecoder(ByteStringDecoder):
    def __init__(self, handle_string_errors: str = "strict") -> None:
        self.bytes_errors: Final = handle_string_errors
        super().__init__()

    @parse_type_str("string")
    def from_type_str(cls, abi_type, registry):
        return cls()

    def decode(self, stream: ContextFramesBytesIO) -> str:
        raw_data = self.read_data_from_stream(stream)
        data, padding_bytes = self.split_data_and_padding(raw_data)
        return self.decoder_fn(data, self.bytes_errors)

    __call__ = decode

    @staticmethod
    def decoder_fn(data: bytes, handle_string_errors: str = "strict") -> str:
        return data.decode("utf-8", errors=handle_string_errors)
