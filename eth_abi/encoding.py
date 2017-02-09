from eth_utils import (
    is_boolean,
    is_integer,
    is_address,
    is_bytes,
    to_canonical_address,
)

from eth_abi.exceptions import (
    EncodingTypeError,
    ValueOutOfBounds,
)

from eth_abi.utils.numeric import (
    int_to_big_endian,
    compute_signed_bounds,
    compute_unsigned_bounds,
    ceil32,
)
from eth_abi.utils.padding import (
    zpad,
    zpad_right,
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


class BooleanEncoder(FixedSizeEncoder):
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


class NumberEncoder(FixedSizeEncoder):
    is_big_endian = True
    bounds_fn = None

    @classmethod
    def validate_value(cls, value):
        if not is_integer(value):
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


class UIntEncoder(NumberEncoder):
    encode_fn = staticmethod(int_to_big_endian)
    bounds_fn = staticmethod(compute_unsigned_bounds)


encode_uint_256 = UIntEncoder.as_encoder(value_bit_size=256, data_byte_size=32)


class IntEncoder(NumberEncoder):
    bounds_fn = staticmethod(compute_signed_bounds)

    @classmethod
    def encode_fn(cls, value):
        return int_to_big_endian(value % 2**cls.value_bit_size)


class AddressEncoder(FixedSizeEncoder):
    encode_fn = to_canonical_address
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


class BytesEncoder(FixedSizeEncoder):
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
        padded_value = zpad_right(value, ceil32(len(value)))
        encoded_value = encoded_size + padded_value

        return encoded_value
