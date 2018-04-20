import decimal

from eth_utils import (
    big_endian_to_int,
    to_tuple,
    to_normalized_address,
)

from eth_abi.base import (
    BaseCoder,
    parse_type_str,
)

from eth_abi.exceptions import (
    InsufficientDataBytes,
    NonEmptyPaddingBytes,
)
from eth_abi.utils.numeric import (
    TEN,
    abi_decimal_context,
    ceil32,
    quantize_value,
)


class BaseDecoder(BaseCoder):
    def decode(self, stream):  # pragma: no cover
        """
        Decodes the given stream of bytes into a Python value.
        """
        raise NotImplementedError('Must implement `decode`')

    def __call__(self, stream):
        return self.decode(stream)


class HeadTailDecoder(BaseDecoder):
    tail_decoder = None

    def validate(self):
        super().validate()
        if self.tail_decoder is None:
            raise ValueError("No `tail_decoder` set")

    def decode(self, stream):
        start_pos = decode_uint_256(stream)
        anchor_pos = stream.tell()
        stream.seek(start_pos)
        value = self.tail_decoder(stream)
        stream.seek(anchor_pos)
        return value


class MultiDecoder(BaseDecoder):
    decoders = None

    def validate(self):
        super().validate()
        if self.decoders is None:
            raise ValueError("No `decoders` set")

    @to_tuple
    def decode(self, stream):
        for decoder in self.decoders:
            if isinstance(decoder, (DynamicArrayDecoder, StringDecoder)):
                yield HeadTailDecoder(tail_decoder=decoder)(stream)
            else:
                yield decoder(stream)


class SingleDecoder(BaseDecoder):
    decoder_fn = None

    def validate(self):
        super().validate()
        if self.decoder_fn is None:
            raise ValueError("No `decoder_fn` set")

    def validate_padding_bytes(self, value, padding_bytes):
        raise NotImplementedError("Must be implemented by subclasses")

    def decode(self, stream):
        raw_data = self.read_data_from_stream(stream)
        data, padding_bytes = self.split_data_and_padding(raw_data)
        value = self.decoder_fn(data)
        self.validate_padding_bytes(value, padding_bytes)

        return value

    def read_data_from_stream(self, stream):
        raise NotImplementedError("Must be implemented by subclasses")

    def split_data_and_padding(self, raw_data):
        return raw_data, b''


class BaseArrayDecoder(BaseDecoder):
    item_decoder = None

    def validate(self):
        super().validate()
        if self.item_decoder is None:
            raise ValueError("No `item_decoder` set")

    @parse_type_str(with_arrlist=True)
    def from_type_str(cls, abi_type, registry):
        item_decoder = registry.get_decoder(str(abi_type.item_type))

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


class SizedArrayDecoder(BaseArrayDecoder):
    array_size = None

    @to_tuple
    def decode(self, stream):
        for _ in range(self.array_size):
            yield self.item_decoder(stream)


class DynamicArrayDecoder(BaseArrayDecoder):
    @to_tuple
    def decode(self, stream):
        array_size = decode_uint_256(stream)
        for _ in range(array_size):
            yield self.item_decoder(stream)


class FixedByteSizeDecoder(SingleDecoder):
    decoder_fn = None
    value_bit_size = None
    data_byte_size = None
    is_big_endian = None

    def validate(self):
        super().validate()

        if self.value_bit_size is None:
            raise ValueError("`value_bit_size` may not be None")
        if self.data_byte_size is None:
            raise ValueError("`data_byte_size` may not be None")
        if self.decoder_fn is None:
            raise ValueError("`decoder_fn` may not be None")
        if self.is_big_endian is None:
            raise ValueError("`is_big_endian` may not be None")

        if self.value_bit_size % 8 != 0:
            raise ValueError(
                "Invalid value bit size: {0}.  Must be a multiple of 8".format(
                    self.value_bit_size,
                )
            )

        if self.value_bit_size > self.data_byte_size * 8:
            raise ValueError("Value byte size exceeds data size")

    def read_data_from_stream(self, stream):
        data = stream.read(self.data_byte_size)

        if len(data) != self.data_byte_size:
            raise InsufficientDataBytes(
                "Tried to read {0} bytes.  Only got {1} bytes".format(
                    self.data_byte_size,
                    len(data),
                )
            )

        return data

    def split_data_and_padding(self, raw_data):
        value_byte_size = self._get_value_byte_size()
        padding_size = self.data_byte_size - value_byte_size

        if self.is_big_endian:
            padding_bytes = raw_data[:padding_size]
            data = raw_data[padding_size:]
        else:
            data = raw_data[:value_byte_size]
            padding_bytes = raw_data[value_byte_size:]

        return data, padding_bytes

    def validate_padding_bytes(self, value, padding_bytes):
        value_byte_size = self._get_value_byte_size()
        padding_size = self.data_byte_size - value_byte_size

        if padding_bytes != b'\x00' * padding_size:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(repr(padding_bytes))
            )

    def _get_value_byte_size(self):
        value_byte_size = self.value_bit_size // 8
        return value_byte_size


class Fixed32ByteSizeDecoder(FixedByteSizeDecoder):
    data_byte_size = 32


class BooleanDecoder(Fixed32ByteSizeDecoder):
    value_bit_size = 8
    is_big_endian = True

    @staticmethod
    def decoder_fn(data):
        if data == b'\x00':
            return False
        elif data == b'\x01':
            return True
        else:
            raise NonEmptyPaddingBytes(
                "Boolean must be either 0x0 or 0x1.  Got: {0}".format(repr(data))
            )

    @parse_type_str('bool')
    def from_type_str(cls, abi_type, registry):
        return cls()


decode_bool = BooleanDecoder()


class AddressDecoder(Fixed32ByteSizeDecoder):
    value_bit_size = 20 * 8
    is_big_endian = True
    decoder_fn = staticmethod(to_normalized_address)

    @parse_type_str('address')
    def from_type_str(cls, abi_type, registry):
        return cls()


decode_address = AddressDecoder()


#
# Unsigned Integer Decoders
#
class UnsignedIntegerDecoder(Fixed32ByteSizeDecoder):
    decoder_fn = staticmethod(big_endian_to_int)
    is_big_endian = True

    @parse_type_str('uint')
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
        if value >= 2 ** (self.value_bit_size - 1):
            return value - 2 ** self.value_bit_size
        else:
            return value

    def validate_padding_bytes(self, value, padding_bytes):
        value_byte_size = self._get_value_byte_size()
        padding_size = self.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b'\x00' * padding_size
        else:
            expected_padding_bytes = b'\xff' * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(repr(padding_bytes))
            )

    @parse_type_str('int')
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

    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub * 8)


class BaseFixedDecoder(Fixed32ByteSizeDecoder):
    frac_places = None
    is_big_endian = True

    def validate(self):
        super().validate()

        if self.frac_places is None:
            raise ValueError("must specify `frac_places`")

        if self.frac_places <= 0 or self.frac_places > 80:
            raise ValueError("`frac_places` must be in range (0, 80]")


class UnsignedFixedDecoder(BaseFixedDecoder):
    def decoder_fn(self, data):
        value = big_endian_to_int(data)

        with decimal.localcontext(abi_decimal_context):
            decimal_value = decimal.Decimal(value) / TEN ** self.frac_places

        return decimal_value

    @parse_type_str('ufixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(value_bit_size=value_bit_size, frac_places=frac_places)


class SignedFixedDecoder(BaseFixedDecoder):
    def decoder_fn(self, data):
        value = big_endian_to_int(data)
        if value >= 2 ** (self.value_bit_size - 1):
            signed_value = value - 2 ** self.value_bit_size
        else:
            signed_value = value

        with decimal.localcontext(abi_decimal_context):
            decimal_value = decimal.Decimal(signed_value) / TEN ** self.frac_places

        return decimal_value

    def validate_padding_bytes(self, value, padding_bytes):
        value_byte_size = self._get_value_byte_size()
        padding_size = self.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b'\x00' * padding_size
        else:
            expected_padding_bytes = b'\xff' * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(repr(padding_bytes))
            )

    @parse_type_str('fixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(value_bit_size=value_bit_size, frac_places=frac_places)


class BaseRealDecoder(Fixed32ByteSizeDecoder):
    high_bit_size = None
    low_bit_size = None
    is_big_endian = True

    def validate(self):
        super().validate()

        if self.high_bit_size is None:
            raise ValueError("`high_bit_size` cannot be null")
        if self.low_bit_size is None:
            raise ValueError("`low_bit_size` cannot be null")
        if self.low_bit_size + self.high_bit_size != self.value_bit_size:
            raise ValueError("high and low bitsizes must sum to the value_bit_size")


class UnsignedRealDecoder(BaseRealDecoder):
    def decoder_fn(self, data):
        value = big_endian_to_int(data)
        with decimal.localcontext(abi_decimal_context):
            decimal_value = decimal.Decimal(value)
            raw_real_value = decimal_value / 2 ** self.low_bit_size
            real_value = quantize_value(raw_real_value, self.low_bit_size)
        return real_value

    @parse_type_str('ureal')
    def from_type_str(cls, abi_type, registry):
        high_bit_size, low_bit_size = abi_type.sub

        return cls(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )


class SignedRealDecoder(BaseRealDecoder):
    def decoder_fn(self, data):
        value = big_endian_to_int(data)
        if value >= 2 ** (self.high_bit_size + self.low_bit_size - 1):
            signed_value = value - 2 ** (self.high_bit_size + self.low_bit_size)
        else:
            signed_value = value
        with decimal.localcontext(abi_decimal_context):
            signed_decimal_value = decimal.Decimal(signed_value)
            raw_real_value = signed_decimal_value / 2 ** self.low_bit_size
            real_value = quantize_value(raw_real_value, self.low_bit_size)
        return real_value

    def validate_padding_bytes(self, value, padding_bytes):
        value_byte_size = self._get_value_byte_size()
        padding_size = self.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b'\x00' * padding_size
        else:
            expected_padding_bytes = b'\xff' * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(repr(padding_bytes))
            )

    @parse_type_str('real')
    def from_type_str(cls, abi_type, registry):
        high_bit_size, low_bit_size = abi_type.sub

        return cls(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )


#
# String and Bytes
#
class StringDecoder(SingleDecoder):
    @staticmethod
    def decoder_fn(data):
        return data

    @staticmethod
    def read_data_from_stream(stream):
        data_length = decode_uint_256(stream)
        padded_length = ceil32(data_length)

        data = stream.read(padded_length)

        if len(data) < padded_length:
            raise InsufficientDataBytes(
                "Tried to read {0} bytes.  Only got {1} bytes".format(
                    padded_length,
                    len(data),
                )
            )

        padding_bytes = data[data_length:]

        if padding_bytes != b'\x00' * (padded_length - data_length):
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(repr(padding_bytes))
            )

        return data[:data_length]

    def validate_padding_bytes(self, value, padding_bytes):
        pass

    @parse_type_str('string')
    def from_type_str(cls, abi_type, registry):
        return cls()


decode_string = StringDecoder()


class ByteStringDecoder(StringDecoder):
    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls()


decode_bytes = ByteStringDecoder()
