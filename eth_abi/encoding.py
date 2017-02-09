from eth_utils import (
    is_boolean,
    is_integer,
)

from eth_abi.exceptions import (
    EncodingTypeError,
    ValueOutOfBounds,
)

from eth_abi.utils.numeric import (
    int_to_big_endian,
)
from eth_abi.utils.padding import (
    zpad,
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
            raise NotImplementedError("Not yet implemented")
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


class UIntEncoder(FixedSizeEncoder):
    is_big_endian = True
    encode_fn = staticmethod(int_to_big_endian)

    @classmethod
    def validate_value(cls, value):
        if not is_integer(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {0}".format(
                    type(value),
                    cls.__name__,
                )
            )

        upper_bound = 2 ** cls.value_bit_size - 1

        if value < 0 or value > upper_bound:
            raise ValueOutOfBounds(
                "Value '{0}' cannot be encoded in {1} bits.  Must be bounded "
                "between [0, {2}]".format(
                    value,
                    cls.value_bit_size,
                    upper_bound,
                )
            )
