from __future__ import unicode_literals

import decimal

from eth_utils import (
    force_text,
    to_tuple,
    to_normalized_address,
)

from eth_abi.exceptions import (
    InsufficientDataBytes,
    NonEmptyPaddingBytes,
)
from eth_abi.utils.numeric import (
    big_endian_to_int,
    quantize_value,
    ceil32,
)


decimal.DefaultContext.prec = 999


def get_multi_decoder(processed_types):
    """
    """
    decoders = tuple(
        get_single_decoder(base, sub, arrlist) for base, sub, arrlist in processed_types
    )
    return MultiDecoder.as_decoder(decoders=decoders)


def get_single_decoder(base, sub, arrlist):
    if arrlist:
        item_decoder = get_single_decoder(base, sub, arrlist[:-1])
        if arrlist[-1]:
            return SizedArrayDecoder.as_decoder(
                array_size=arrlist[-1][0],
                item_decoder=item_decoder,
            )
        else:
            return DynamicArrayDecoder.as_decoder(item_decoder=item_decoder)
    elif base == 'address':
        return decode_address
    elif base == 'bool':
        return decode_bool
    elif base == 'bytes':
        if sub:
            return BytesDecoder.as_decoder(value_bit_size=int(sub) * 8)
        else:
            return decode_bytes
    elif base == 'int':
        return SignedIntegerDecoder.as_decoder(value_bit_size=int(sub))
    elif base == 'string':
        return decode_string
    elif base == 'uint':
        return UnsignedIntegerDecoder.as_decoder(value_bit_size=int(sub))
    elif base == 'ureal':
        high_bit_size, low_bit_size = [int(v) for v in sub.split('x')]
        return UnsignedRealDecoder.as_decoder(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )
    elif base == 'real':
        high_bit_size, low_bit_size = [int(v) for v in sub.split('x')]
        return SignedRealDecoder.as_decoder(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )
    else:
        raise ValueError(
            "Unsupported type: {0} - must be one of "
            "address/bool/bytesXX/bytes/string/uintXXX/intXXX"
        )


class BaseDecoder(object):
    @classmethod
    def as_decoder(cls, name=None, **kwargs):
        for key in kwargs:
            if not hasattr(cls, key):
                raise AttributeError(
                    "Property {0} not found on Decoder class. "
                    "`Decoder.factory` only accepts keyword arguments which are "
                    "present on the Decoder class".format(key)
                )
        if name is None:
            name = cls.__name__
        sub_cls = type(name, (cls,), kwargs)
        sub_cls.validate()
        instance = sub_cls()
        return instance

    @classmethod
    def validate(cls):
        pass

    def __call__(self, stream):
        return self.decode(stream)


class HeadTailDecoder(BaseDecoder):
    tail_decoder = None

    @classmethod
    def validate(cls):
        super(HeadTailDecoder, cls).validate()
        if cls.tail_decoder is None:
            raise ValueError("No `tail_decoder` set")

    @classmethod
    def decode(cls, stream):
        start_pos = decode_uint_256(stream)
        anchor_pos = stream.tell()
        stream.seek(start_pos)
        value = cls.tail_decoder(stream)
        stream.seek(anchor_pos)
        return value


class MultiDecoder(BaseDecoder):
    decoders = None

    @classmethod
    def validate(cls):
        super(MultiDecoder, cls).validate()
        if cls.decoders is None:
            raise ValueError("No `decoders` set")

    @classmethod
    @to_tuple
    def decode(cls, stream):
        for decoder in cls.decoders:
            if isinstance(decoder, (DynamicArrayDecoder, StringDecoder)):
                yield HeadTailDecoder.as_decoder(tail_decoder=decoder)(stream)
            else:
                yield decoder(stream)


class SingleDecoder(BaseDecoder):
    decoder_fn = None

    @classmethod
    def validate(cls):
        super(SingleDecoder, cls).validate()
        if cls.decoder_fn is None:
            raise ValueError("No `decoder_fn` set")

    @classmethod
    def validate_padding_bytes(cls, value, padding_bytes):
        raise NotImplementedError("Must be implemented by subclasses")
        value_byte_size = cls._get_value_byte_size()
        padding_size = cls.data_byte_size - value_byte_size

        if padding_bytes != b'\x00' * padding_size:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(force_text(padding_bytes))
            )

    @classmethod
    def decode(cls, stream):
        raw_data = cls.read_data_from_stream(stream)
        data, padding_bytes = cls.split_data_and_padding(raw_data)
        value = cls.decoder_fn(data)
        cls.validate_padding_bytes(value, padding_bytes)

        return value

    @classmethod
    def read_data_from_stream(cls, stream):
        raise NotImplementedError("Must be implemented by subclasses")

    @classmethod
    def split_data_and_padding(cls, raw_data):
        return raw_data, b''


class BaseArrayDecoder(BaseDecoder):
    item_decoder = None

    @classmethod
    def validate(cls):
        super(BaseArrayDecoder, cls).validate()
        if cls.item_decoder is None:
            raise ValueError("No `item_decoder` set")


class SizedArrayDecoder(BaseArrayDecoder):
    array_size = None

    @classmethod
    @to_tuple
    def decode(cls, stream):
        for _ in range(cls.array_size):
            yield cls.item_decoder(stream)


class DynamicArrayDecoder(BaseArrayDecoder):
    @classmethod
    @to_tuple
    def decode(cls, stream):
        array_size = decode_uint_256(stream)
        for _ in range(array_size):
            yield cls.item_decoder(stream)


class FixedByteSizeDecoder(SingleDecoder):
    decoder_fn = None
    value_bit_size = None
    data_byte_size = None
    is_big_endian = None

    @classmethod
    def validate(cls):
        super(FixedByteSizeDecoder, cls).validate()

        if cls.value_bit_size is None:
            raise ValueError("`value_bit_size` may not be None")
        if cls.data_byte_size is None:
            raise ValueError("`data_byte_size` may not be None")
        if cls.decoder_fn is None:
            raise ValueError("`decoder_fn` may not be None")
        if cls.is_big_endian is None:
            raise ValueError("`is_big_endian` may not be None")

        if cls.value_bit_size % 8 != 0:
            raise ValueError(
                "Invalid value bit size: {0}.  Must be a multiple of 8".format(
                    cls.value_bit_size,
                )
            )

        if cls.value_bit_size > cls.data_byte_size * 8:
            raise ValueError("Value byte size exceeds data size")

    @classmethod
    def read_data_from_stream(cls, stream):
        data = stream.read(cls.data_byte_size)

        if len(data) != cls.data_byte_size:
            raise InsufficientDataBytes(
                "Tried to read {0} bytes.  Only got {1} bytes".format(
                    cls.data_byte_size,
                    len(data),
                )
            )

        return data

    @classmethod
    def split_data_and_padding(cls, raw_data):
        value_byte_size = cls._get_value_byte_size()
        padding_size = cls.data_byte_size - value_byte_size

        if cls.is_big_endian:
            padding_bytes = raw_data[:padding_size]
            data = raw_data[padding_size:]
        else:
            data = raw_data[:value_byte_size]
            padding_bytes = raw_data[value_byte_size:]

        return data, padding_bytes

    @classmethod
    def validate_padding_bytes(cls, value, padding_bytes):
        value_byte_size = cls._get_value_byte_size()
        padding_size = cls.data_byte_size - value_byte_size

        if padding_bytes != b'\x00' * padding_size:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(force_text(padding_bytes))
            )

    @classmethod
    def _get_value_byte_size(cls):
        value_byte_size = cls.value_bit_size // 8
        return value_byte_size


class Fixed32ByteSizeDecoder(FixedByteSizeDecoder):
    data_byte_size = 32


class BooleanDecoder(Fixed32ByteSizeDecoder):
    value_bit_size = 8
    is_big_endian = True

    @classmethod
    def decoder_fn(cls, data):
        if data == b'\x00':
            return False
        elif data == b'\x01':
            return True
        else:
            raise NonEmptyPaddingBytes(
                "Boolean must be either 0x0 or 0x1.  Got: {0}".format(force_text(data))
            )


decode_bool = BooleanDecoder.as_decoder()


class AddressDecoder(Fixed32ByteSizeDecoder):
    value_bit_size = 20 * 8
    is_big_endian = True
    decoder_fn = staticmethod(to_normalized_address)


decode_address = AddressDecoder.as_decoder()


#
# Unsigned Integer Decoders
#
class UnsignedIntegerDecoder(Fixed32ByteSizeDecoder):
    decoder_fn = staticmethod(big_endian_to_int)
    is_big_endian = True


decode_uint_256 = UnsignedIntegerDecoder.as_decoder(value_bit_size=256)


#
# Signed Integer Decoders
#
class SignedIntegerDecoder(Fixed32ByteSizeDecoder):
    is_big_endian = True

    @classmethod
    def decoder_fn(cls, data):
        value = big_endian_to_int(data)
        if value >= 2 ** (cls.value_bit_size - 1):
            return value - 2 ** cls.value_bit_size
        else:
            return value

    @classmethod
    def validate_padding_bytes(cls, value, padding_bytes):
        value_byte_size = cls._get_value_byte_size()
        padding_size = cls.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b'\x00' * padding_size
        else:
            expected_padding_bytes = b'\xff' * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(force_text(padding_bytes))
            )


#
# Bytes1..32
#
class BytesDecoder(Fixed32ByteSizeDecoder):
    is_big_endian = False

    @classmethod
    def decoder_fn(cls, data):
        return data


class BaseRealDecoder(Fixed32ByteSizeDecoder):
    high_bit_size = None
    low_bit_size = None
    data_byte_size = None
    is_big_endian = True

    @classmethod
    def validate(cls):
        super(BaseRealDecoder, cls).validate()

        if cls.high_bit_size is None:
            raise ValueError("`high_bit_size` cannot be null")
        if cls.low_bit_size is None:
            raise ValueError("`low_bit_size` cannot be null")
        if cls.low_bit_size + cls.high_bit_size != cls.value_bit_size:
            raise ValueError("high and low bitsizes must sum to the value_bit_size")


class UnsignedRealDecoder(BaseRealDecoder):
    @classmethod
    def decoder_fn(cls, data):
        value = big_endian_to_int(data)
        decimal_value = decimal.Decimal(value)
        raw_real_value = decimal_value / 2 ** cls.low_bit_size
        real_value = quantize_value(raw_real_value, cls.low_bit_size)
        return real_value


class SignedRealDecoder(BaseRealDecoder):
    @classmethod
    def decoder_fn(cls, data):
        value = big_endian_to_int(data)
        if value >= 2 ** (cls.high_bit_size + cls.low_bit_size - 1):
            signed_value = value - 2 ** (cls.high_bit_size + cls.low_bit_size)
        else:
            signed_value = value
        signed_decimal_value = decimal.Decimal(signed_value)
        raw_real_value = signed_decimal_value / 2 ** cls.low_bit_size
        real_value = quantize_value(raw_real_value, cls.low_bit_size)
        return real_value

    @classmethod
    def validate_padding_bytes(cls, value, padding_bytes):
        value_byte_size = cls._get_value_byte_size()
        padding_size = cls.data_byte_size - value_byte_size

        if value >= 0:
            expected_padding_bytes = b'\x00' * padding_size
        else:
            expected_padding_bytes = b'\xff' * padding_size

        if padding_bytes != expected_padding_bytes:
            raise NonEmptyPaddingBytes(
                "Padding bytes were not empty: {0}".format(force_text(padding_bytes))
            )


#
# String and Bytes
#
class StringDecoder(SingleDecoder):
    @classmethod
    def decoder_fn(cls, data):
        return data

    @classmethod
    def read_data_from_stream(cls, stream):
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
                "Padding bytes were not empty: {0}".format(force_text(padding_bytes))
            )

        return data[:data_length]

    @classmethod
    def validate_padding_bytes(cls, value, padding_bytes):
        pass


decode_string = decode_bytes = StringDecoder.as_decoder()
