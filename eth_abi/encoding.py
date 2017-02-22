import itertools

from eth_utils import (
    is_boolean,
    is_integer,
    is_number,
    is_address,
    is_bytes,
    is_list_like,
    is_null,
    to_canonical_address,
)

from eth_abi.exceptions import (
    EncodingTypeError,
    ValueOutOfBounds,
)

from eth_abi.utils.numeric import (
    int_to_big_endian,
    compute_signed_integer_bounds,
    compute_unsigned_integer_bounds,
    compute_signed_real_bounds,
    compute_unsigned_real_bounds,
    ceil32,
)
from eth_abi.utils.padding import (
    fpad,
    zpad,
    zpad_right,
)


def get_multi_encoder(processed_types):
    """
    """
    encoders = tuple(
        get_single_encoder(base, sub, arrlist) for base, sub, arrlist in processed_types
    )
    return MultiEncoder.as_encoder(encoders=encoders)


def get_single_encoder(base, sub, arrlist):
    if arrlist:
        item_encoder = get_single_encoder(base, sub, arrlist[:-1])
        if arrlist[-1]:
            return SizedArrayEncoder.as_encoder(
                array_size=arrlist[-1][0],
                item_encoder=item_encoder,
            )
        else:
            return DynamicArrayEncoder.as_encoder(item_encoder=item_encoder)
    elif base == 'address':
        return encode_address
    elif base == 'bool':
        return encode_bool
    elif base == 'bytes':
        if sub:
            return BytesEncoder.as_encoder(value_bit_size=int(sub) * 8)
        else:
            return encode_bytes
    elif base == 'int':
        return SignedIntegerEncoder.as_encoder(value_bit_size=int(sub))
    elif base == 'string':
        return encode_string
    elif base == 'uint':
        return UnsignedIntegerEncoder.as_encoder(value_bit_size=int(sub))
    elif base == 'ureal':
        high_bit_size, low_bit_size = [int(v) for v in sub.split('x')]
        return UnsignedRealEncoder.as_encoder(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )
    elif base == 'real':
        high_bit_size, low_bit_size = [int(v) for v in sub.split('x')]
        return SignedRealEncoder.as_encoder(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )
    else:
        raise ValueError(
            "Unsupported type: {0} - must be one of "
            "address/bool/bytesXX/bytes/string/uintXXX/intXXX"
        )


class BaseEncoder(object):
    @classmethod
    def as_encoder(cls, name=None, **kwargs):
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

    def __call__(self, value):
        return self.encode(value)


class MultiEncoder(BaseEncoder):
    encoders = None

    @classmethod
    def validate(cls):
        super(MultiEncoder, cls).validate()
        if cls.encoders is None:
            raise ValueError("`encoders` may not be none")

    @classmethod
    def encode(cls, values):
        if len(values) != len(cls.encoders):
            raise ValueOutOfBounds(
                "Recieved {0} values to encode.  Expected {1}".format(
                    len(values),
                    len(cls.encoders),
                )
            )
        raw_head_chunks = []
        tail_chunks = []

        for value, encoder in zip(values, cls.encoders):
            if isinstance(encoder, (DynamicArrayEncoder, StringEncoder)):
                raw_head_chunks.append(None)
                tail_chunks.append(encoder(value))
            else:
                raw_head_chunks.append(encoder(value))
                tail_chunks.append(b'')

        head_length = sum((
            32 if is_null(item) else len(item)
            for item in raw_head_chunks
        ))
        tail_offsets = tuple((
            sum((len(chunk) for chunk in tail_chunks[:i]))
            for i in range(len(tail_chunks))
        ))
        head_chunks = tuple((
            (
                encode_uint_256(head_length + tail_offsets[idx])
                if is_null(head_chunk)
                else head_chunk
            ) for idx, head_chunk
            in enumerate(raw_head_chunks)
        ))
        encoded_value = b''.join(tuple(itertools.chain(head_chunks, tail_chunks)))
        return encoded_value


class FixedSizeEncoder(BaseEncoder):
    value_bit_size = None
    data_byte_size = None
    encode_fn = None
    type_check_fn = None
    is_big_endian = None

    @classmethod
    def validate(cls):
        super(FixedSizeEncoder, cls).validate()
        if cls.value_bit_size is None:
            raise ValueError("`value_bit_size` may not be none")
        if cls.data_byte_size is None:
            raise ValueError("`data_byte_size` may not be none")
        if cls.encode_fn is None:
            raise ValueError("`encode_fn` may not be none")
        if cls.is_big_endian is None:
            raise ValueError("`is_big_endian` may not be none")

        if cls.value_bit_size % 8 != 0:
            raise ValueError(
                "Invalid value bit size: {0}.  Must be a multiple of 8".format(
                    cls.value_bit_size,
                )
            )

        if cls.value_bit_size > cls.data_byte_size * 8:
            raise ValueError("Value byte size exceeds data size")

    @classmethod
    def validate_value(cls, value):
        raise NotImplementedError("Must be implemented by subclasses")

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)
        base_encoded_value = cls.encode_fn(value)

        if cls.is_big_endian:
            padded_encoded_value = zpad(base_encoded_value, cls.data_byte_size)
        else:
            padded_encoded_value = zpad_right(base_encoded_value, cls.data_byte_size)
        return padded_encoded_value


class Fixed32ByteSizeEncoder(FixedSizeEncoder):
    data_byte_size = 32


class BooleanEncoder(Fixed32ByteSizeEncoder):
    value_bit_size = 8
    is_big_endian = True

    @classmethod
    def validate_value(cls, value):
        if not is_boolean(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {0}".format(
                    type(value),
                    cls.__name__,
                )
            )

    @classmethod
    def encode_fn(cls, value):
        if value is True:
            return b'\x01'
        elif value is False:
            return b'\x00'
        else:
            raise ValueError("Invariant")


encode_bool = BooleanEncoder.as_encoder()


class NumberEncoder(Fixed32ByteSizeEncoder):
    is_big_endian = True
    bounds_fn = None
    type_check_fn = None

    @classmethod
    def validate(cls):
        super(NumberEncoder, cls).validate()
        if cls.bounds_fn is None:
            raise ValueError("`bounds_fn` cannot be null")
        if cls.type_check_fn is None:
            raise ValueError("`type_check_fn` cannot be null")

    @classmethod
    def validate_value(cls, value):
        if not cls.type_check_fn(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {0}".format(
                    type(value),
                    cls.__name__,
                )
            )

        lower_bound, upper_bound = cls.bounds_fn(cls.value_bit_size)

        if value < lower_bound or value > upper_bound:
            raise ValueOutOfBounds(
                "Value '{0}' cannot be encoded in {1} bits.  Must be bounded "
                "between [{2}, {3}]".format(
                    value,
                    cls.value_bit_size,
                    lower_bound,
                    upper_bound,
                )
            )


class UnsignedIntegerEncoder(NumberEncoder):
    encode_fn = staticmethod(int_to_big_endian)
    bounds_fn = staticmethod(compute_unsigned_integer_bounds)
    type_check_fn = staticmethod(is_integer)


encode_uint_256 = UnsignedIntegerEncoder.as_encoder(value_bit_size=256, data_byte_size=32)


class SignedIntegerEncoder(NumberEncoder):
    bounds_fn = staticmethod(compute_signed_integer_bounds)
    type_check_fn = staticmethod(is_integer)

    @classmethod
    def encode_fn(cls, value):
        return int_to_big_endian(value % 2**cls.value_bit_size)

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)
        base_encoded_value = cls.encode_fn(value)

        if value >= 0:
            padded_encoded_value = zpad(base_encoded_value, cls.data_byte_size)
        else:
            padded_encoded_value = fpad(base_encoded_value, cls.data_byte_size)
        return padded_encoded_value


class BaseRealEncoder(NumberEncoder):
    low_bit_size = None
    high_bit_size = None
    type_check_fn = staticmethod(is_number)

    @classmethod
    def validate(cls):
        super(BaseRealEncoder, cls).validate()
        if cls.high_bit_size is None:
            raise ValueError("`high_bit_size` cannot be null")
        if cls.low_bit_size is None:
            raise ValueError("`low_bit_size` cannot be null")
        if cls.low_bit_size + cls.high_bit_size != cls.value_bit_size:
            raise ValueError("high and low bitsizes must sum to the value_bit_size")


class UnsignedRealEncoder(BaseRealEncoder):
    @classmethod
    def bounds_fn(cls, value_bit_size):
        return compute_unsigned_real_bounds(cls.high_bit_size, cls.low_bit_size)

    @classmethod
    def encode_fn(cls, value):
        scaled_value = value * 2 ** cls.low_bit_size
        integer_value = int(scaled_value)
        return int_to_big_endian(integer_value)


class SignedRealEncoder(BaseRealEncoder):
    @classmethod
    def bounds_fn(cls, value_bit_size):
        return compute_signed_real_bounds(cls.high_bit_size, cls.low_bit_size)

    @classmethod
    def encode_fn(cls, value):
        scaled_value = value * 2 ** cls.low_bit_size
        integer_value = int(scaled_value)
        unsigned_integer_value = integer_value % 2 ** (cls.high_bit_size + cls.low_bit_size)
        return int_to_big_endian(unsigned_integer_value)

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)
        base_encoded_value = cls.encode_fn(value)

        if value >= 0:
            padded_encoded_value = zpad(base_encoded_value, cls.data_byte_size)
        else:
            padded_encoded_value = fpad(base_encoded_value, cls.data_byte_size)
        return padded_encoded_value


class AddressEncoder(Fixed32ByteSizeEncoder):
    value_bit_size = 20 * 8
    encode_fn = staticmethod(to_canonical_address)
    is_big_endian = True

    @classmethod
    def validate_value(cls, value):
        if not is_address(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {0}".format(
                    type(value),
                    cls.__name__,
                )
            )

    @classmethod
    def validate(cls):
        super(AddressEncoder, cls).validate()
        if cls.value_bit_size != 20 * 8:
            raise ValueError('Addresses must be 160 bits in length')


encode_address = AddressEncoder.as_encoder()


class BytesEncoder(Fixed32ByteSizeEncoder):
    is_big_endian = False

    @classmethod
    def validate_value(cls, value):
        if not is_bytes(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {0}".format(
                    type(value),
                    cls.__name__,
                )
            )
        if len(value) > cls.value_bit_size // 8:
            raise ValueOutOfBounds(
                "String {0} exceeds total byte size for bytes{1} encoding".format(
                    value,
                    cls.value_bit_size // 8,
                )
            )

    @classmethod
    def encode_fn(cls, value):
        return value


class StringEncoder(BaseEncoder):
    @classmethod
    def encode(cls, value):
        if not is_bytes(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded as a string".format(
                    type(value),
                )
            )

        encoded_size = encode_uint_256(len(value))
        if not value:
            padded_value = b'\x00' * 32
        else:
            padded_value = zpad_right(value, ceil32(len(value)))
        encoded_value = encoded_size + padded_value

        return encoded_value


encode_string = encode_bytes = StringEncoder.as_encoder()


class BaseArrayEncoder(BaseEncoder):
    item_encoder = None

    @classmethod
    def validate(cls):
        super(BaseArrayEncoder, cls).validate()
        if cls.item_encoder is None:
            raise ValueError("`item_encoder` may not be none")

    @classmethod
    def encode_elements(cls, value):
        if not is_list_like(value):
            raise EncodingTypeError(
                "Cannot encode value of type {0} using array encoder.  Must be "
                "a list-like object such as an array or tuple".format(
                    type(value),
                )
            )
        encoded_elements = b''.join((
            cls.item_encoder(item)
            for item in value
        ))
        return encoded_elements


class SizedArrayEncoder(BaseArrayEncoder):
    array_size = None

    @classmethod
    def validate(cls):
        super(SizedArrayEncoder, cls).validate()
        if cls.array_size is None:
            raise ValueError("`array_size` may not be none")

    @classmethod
    def encode(cls, value):
        if len(value) != cls.array_size:
            raise ValueOutOfBounds(
                "Expected value with length {0}.  Provided value has {1} "
                "elements".format(cls.array_size, len(value))
            )
        encoded_elements = cls.encode_elements(value)
        return encoded_elements


class DynamicArrayEncoder(BaseArrayEncoder):
    @classmethod
    def encode(cls, value):
        encoded_size = encode_uint_256(len(value))
        encoded_elements = cls.encode_elements(value)
        encoded_value = encoded_size + encoded_elements
        return encoded_value
