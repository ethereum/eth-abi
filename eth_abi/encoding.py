import abc
import codecs
import decimal
from itertools import (
    accumulate,
)
from typing import (
    Any,
)

from eth_utils import (
    int_to_big_endian,
    is_address,
    is_boolean,
    is_bytes,
    is_integer,
    is_list_like,
    is_number,
    is_text,
    to_canonical_address,
)

from eth_abi.base import (
    BaseCoder,
    parse_tuple_type_str,
    parse_type_str,
)
from eth_abi.exceptions import (
    EncodingTypeError,
    IllegalValue,
    ValueOutOfBounds,
)
from eth_abi.utils.numeric import (
    TEN,
    abi_decimal_context,
    ceil32,
    compute_signed_fixed_bounds,
    compute_signed_integer_bounds,
    compute_unsigned_fixed_bounds,
    compute_unsigned_integer_bounds,
)
from eth_abi.utils.padding import (
    fpad,
    zpad,
    zpad_right,
)


class BaseEncoder(BaseCoder, metaclass=abc.ABCMeta):
    """
    Base class for all encoder classes.  Subclass this if you want to define a
    custom encoder class.  Subclasses must also implement
    :any:`BaseCoder.from_type_str`.
    """
    @abc.abstractmethod
    def encode(self, value: Any) -> bytes:  # pragma: no cover
        """
        Encodes the given value as a sequence of bytes.  Should raise
        :any:`exceptions.EncodingError` if ``value`` cannot be encoded.
        """
        pass

    @abc.abstractmethod
    def validate_value(self, value: Any) -> None:  # pragma: no cover
        """
        Checks whether or not the given value can be encoded by this encoder.
        If the given value cannot be encoded, must raise
        :any:`exceptions.EncodingError`.
        """
        pass

    def __call__(self, value: Any) -> bytes:
        return self.encode(value)


class TupleEncoder(BaseEncoder):
    encoders = None

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.is_dynamic = any(getattr(e, 'is_dynamic', False) for e in self.encoders)

    def validate(self):
        super().validate()

        if self.encoders is None:
            raise ValueError("`encoders` may not be none")

    def validate_value(self, value):
        if not is_list_like(value):
            raise EncodingTypeError(
                "Cannot encode value of type {0} using tuple encoder.  Must be "
                "a list-like object such as an array or tuple".format(
                    type(value),
                )
            )

        if len(value) != len(self.encoders):
            raise ValueOutOfBounds(
                "Expected value with length {0}.  Provided value has {1} "
                "elements".format(len(self.encoders), len(value))
            )

        for item, encoder in zip(value, self.encoders):
            try:
                encoder.validate_value(item)
            except AttributeError:
                encoder(item)

    def encode(self, values):
        self.validate_value(values)

        raw_head_chunks = []
        tail_chunks = []
        for value, encoder in zip(values, self.encoders):
            if getattr(encoder, 'is_dynamic', False):
                raw_head_chunks.append(None)
                tail_chunks.append(encoder(value))
            else:
                raw_head_chunks.append(encoder(value))
                tail_chunks.append(b'')

        head_length = sum(
            32 if item is None else len(item)
            for item in raw_head_chunks
        )
        tail_offsets = (0,) + tuple(accumulate(map(len, tail_chunks[:-1])))
        head_chunks = tuple(
            encode_uint_256(head_length + offset) if chunk is None else chunk
            for chunk, offset in zip(raw_head_chunks, tail_offsets)
        )

        encoded_value = b''.join(head_chunks + tuple(tail_chunks))

        return encoded_value

    @parse_tuple_type_str
    def from_type_str(cls, abi_type, registry):
        encoders = tuple(registry.get_encoder(str(c)) for c in abi_type.components)

        return cls(encoders=encoders)


class FixedSizeEncoder(BaseEncoder):
    value_bit_size = None
    data_byte_size = None
    encode_fn = None
    type_check_fn = None
    is_big_endian = None

    def validate(self):
        super().validate()

        if self.value_bit_size is None:
            raise ValueError("`value_bit_size` may not be none")
        if self.data_byte_size is None:
            raise ValueError("`data_byte_size` may not be none")
        if self.encode_fn is None:
            raise ValueError("`encode_fn` may not be none")
        if self.is_big_endian is None:
            raise ValueError("`is_big_endian` may not be none")

        if self.value_bit_size % 8 != 0:
            raise ValueError(
                "Invalid value bit size: {0}.  Must be a multiple of 8".format(
                    self.value_bit_size,
                )
            )

        if self.value_bit_size > self.data_byte_size * 8:
            raise ValueError("Value byte size exceeds data size")

    def validate_value(self, value):
        raise NotImplementedError("Must be implemented by subclasses")

    def encode(self, value):
        self.validate_value(value)
        base_encoded_value = self.encode_fn(value)

        if self.is_big_endian:
            padded_encoded_value = zpad(base_encoded_value, self.data_byte_size)
        else:
            padded_encoded_value = zpad_right(base_encoded_value, self.data_byte_size)

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
                "Value of type {0} cannot be encoded by {1}".format(
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

    @parse_type_str('bool')
    def from_type_str(cls, abi_type, registry):
        return cls()


class PackedBooleanEncoder(BooleanEncoder):
    data_byte_size = 1


class NumberEncoder(Fixed32ByteSizeEncoder):
    is_big_endian = True
    bounds_fn = None
    illegal_value_fn = None
    type_check_fn = None

    def validate(self):
        super().validate()

        if self.bounds_fn is None:
            raise ValueError("`bounds_fn` cannot be null")
        if self.type_check_fn is None:
            raise ValueError("`type_check_fn` cannot be null")

    def validate_value(self, value):
        cls = type(self)
        if not self.type_check_fn(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {1}".format(
                    type(value),
                    cls.__name__,
                )
            )

        illegal_value = (
            self.illegal_value_fn is not None and
            self.illegal_value_fn(value)
        )
        if illegal_value:
            raise IllegalValue(
                'Value {} cannot be encoded by {}'.format(repr(value), cls.__name__)
            )

        lower_bound, upper_bound = self.bounds_fn(self.value_bit_size)
        if value < lower_bound or value > upper_bound:
            raise ValueOutOfBounds(
                "Value {0} cannot be encoded in {1} bits.  Must be bounded "
                "between [{2}, {3}]".format(
                    repr(value),
                    self.value_bit_size,
                    lower_bound,
                    upper_bound,
                )
            )


class UnsignedIntegerEncoder(NumberEncoder):
    encode_fn = staticmethod(int_to_big_endian)
    bounds_fn = staticmethod(compute_unsigned_integer_bounds)
    type_check_fn = staticmethod(is_integer)

    @parse_type_str('uint')
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub)


encode_uint_256 = UnsignedIntegerEncoder(value_bit_size=256, data_byte_size=32)


class PackedUnsignedIntegerEncoder(UnsignedIntegerEncoder):
    @parse_type_str('uint')
    def from_type_str(cls, abi_type, registry):
        return cls(
            value_bit_size=abi_type.sub,
            data_byte_size=abi_type.sub // 8,
        )


class SignedIntegerEncoder(NumberEncoder):
    bounds_fn = staticmethod(compute_signed_integer_bounds)
    type_check_fn = staticmethod(is_integer)

    def encode_fn(self, value):
        return int_to_big_endian(value % (2 ** self.value_bit_size))

    def encode(self, value):
        self.validate_value(value)
        base_encoded_value = self.encode_fn(value)

        if value >= 0:
            padded_encoded_value = zpad(base_encoded_value, self.data_byte_size)
        else:
            padded_encoded_value = fpad(base_encoded_value, self.data_byte_size)

        return padded_encoded_value

    @parse_type_str('int')
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub)


class PackedSignedIntegerEncoder(SignedIntegerEncoder):
    @parse_type_str('int')
    def from_type_str(cls, abi_type, registry):
        return cls(
            value_bit_size=abi_type.sub,
            data_byte_size=abi_type.sub // 8,
        )


class BaseFixedEncoder(NumberEncoder):
    frac_places = None

    @staticmethod
    def type_check_fn(value):
        return is_number(value) and not isinstance(value, float)

    @staticmethod
    def illegal_value_fn(value):
        if isinstance(value, decimal.Decimal):
            return value.is_nan() or value.is_infinite()

        return False

    def validate_value(self, value):
        super().validate_value(value)

        with decimal.localcontext(abi_decimal_context):
            residue = value % (TEN ** -self.frac_places)

        if residue > 0:
            raise IllegalValue(
                '{} cannot encode value {}: '
                'residue {} outside allowed fractional precision of {}'.format(
                    type(self).__name__,
                    repr(value),
                    repr(residue),
                    self.frac_places,
                )
            )

    def validate(self):
        super().validate()

        if self.frac_places is None:
            raise ValueError("must specify `frac_places`")

        if self.frac_places <= 0 or self.frac_places > 80:
            raise ValueError("`frac_places` must be in range (0, 80]")


class UnsignedFixedEncoder(BaseFixedEncoder):
    def bounds_fn(self, value_bit_size):
        return compute_unsigned_fixed_bounds(self.value_bit_size, self.frac_places)

    def encode_fn(self, value):
        with decimal.localcontext(abi_decimal_context):
            scaled_value = value * TEN ** self.frac_places
            integer_value = int(scaled_value)

        return int_to_big_endian(integer_value)

    @parse_type_str('ufixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(
            value_bit_size=value_bit_size,
            frac_places=frac_places,
        )


class PackedUnsignedFixedEncoder(UnsignedFixedEncoder):
    @parse_type_str('ufixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(
            value_bit_size=value_bit_size,
            data_byte_size=value_bit_size // 8,
            frac_places=frac_places,
        )


class SignedFixedEncoder(BaseFixedEncoder):
    def bounds_fn(self, value_bit_size):
        return compute_signed_fixed_bounds(self.value_bit_size, self.frac_places)

    def encode_fn(self, value):
        with decimal.localcontext(abi_decimal_context):
            scaled_value = value * TEN ** self.frac_places
            integer_value = int(scaled_value)

        unsigned_integer_value = integer_value % (2 ** self.value_bit_size)

        return int_to_big_endian(unsigned_integer_value)

    def encode(self, value):
        self.validate_value(value)
        base_encoded_value = self.encode_fn(value)

        if value >= 0:
            padded_encoded_value = zpad(base_encoded_value, self.data_byte_size)
        else:
            padded_encoded_value = fpad(base_encoded_value, self.data_byte_size)

        return padded_encoded_value

    @parse_type_str('fixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(
            value_bit_size=value_bit_size,
            frac_places=frac_places,
        )


class PackedSignedFixedEncoder(SignedFixedEncoder):
    @parse_type_str('fixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls(
            value_bit_size=value_bit_size,
            data_byte_size=value_bit_size // 8,
            frac_places=frac_places,
        )


class AddressEncoder(Fixed32ByteSizeEncoder):
    value_bit_size = 20 * 8
    encode_fn = staticmethod(to_canonical_address)
    is_big_endian = True

    @classmethod
    def validate_value(cls, value):
        if not is_address(value):
            raise EncodingTypeError(
                "Cannot encode value {0} of type {1} using {2}".format(
                    repr(value),
                    type(value),
                    cls.__name__,
                )
            )

    def validate(self):
        super().validate()

        if self.value_bit_size != 20 * 8:
            raise ValueError('Addresses must be 160 bits in length')

    @parse_type_str('address')
    def from_type_str(cls, abi_type, registry):
        return cls()


class PackedAddressEncoder(AddressEncoder):
    data_byte_size = 20


class BytesEncoder(Fixed32ByteSizeEncoder):
    is_big_endian = False

    def validate_value(self, value):
        if not is_bytes(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {1}".format(
                    type(value),
                    type(self).__name__,
                )
            )
        if len(value) > self.value_bit_size // 8:
            raise ValueOutOfBounds(
                "String {0} exceeds total byte size for bytes{1} encoding".format(
                    value,
                    self.value_bit_size // 8,
                )
            )

    @staticmethod
    def encode_fn(value):
        return value

    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls(value_bit_size=abi_type.sub * 8)


class PackedBytesEncoder(BytesEncoder):
    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls(
            value_bit_size=abi_type.sub * 8,
            data_byte_size=abi_type.sub,
        )


class ByteStringEncoder(BaseEncoder):
    is_dynamic = True

    @classmethod
    def validate_value(cls, value):
        if not is_bytes(value):
            raise EncodingTypeError(
                "Value of type {} cannot be encoded by {}".format(
                    type(value),
                    cls.__name__,
                )
            )

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)

        if not value:
            padded_value = b'\x00' * 32
        else:
            padded_value = zpad_right(value, ceil32(len(value)))

        encoded_size = encode_uint_256(len(value))
        encoded_value = encoded_size + padded_value

        return encoded_value

    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls()


class PackedByteStringEncoder(ByteStringEncoder):
    is_dynamic = False

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)
        return value


class TextStringEncoder(BaseEncoder):
    is_dynamic = True

    @classmethod
    def validate_value(cls, value):
        if not is_text(value):
            raise EncodingTypeError(
                "Value of type {} cannot be encoded by {}".format(
                    type(value),
                    cls.__name__,
                )
            )

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)

        value_as_bytes = codecs.encode(value, 'utf8')

        if not value_as_bytes:
            padded_value = b'\x00' * 32
        else:
            padded_value = zpad_right(value_as_bytes, ceil32(len(value_as_bytes)))

        encoded_size = encode_uint_256(len(value_as_bytes))
        encoded_value = encoded_size + padded_value

        return encoded_value

    @parse_type_str('string')
    def from_type_str(cls, abi_type, registry):
        return cls()


class PackedTextStringEncoder(TextStringEncoder):
    is_dynamic = False

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)
        return codecs.encode(value, 'utf8')


class BaseArrayEncoder(BaseEncoder):
    item_encoder = None

    def validate(self):
        super().validate()

        if self.item_encoder is None:
            raise ValueError("`item_encoder` may not be none")

    def validate_value(self, value):
        if not is_list_like(value):
            raise EncodingTypeError(
                "Cannot encode value of type {0} using array encoder.  Must be "
                "a list-like object such as an array or tuple".format(
                    type(value),
                )
            )

        for item in value:
            self.item_encoder.validate_value(item)

    def encode_elements(self, value):
        self.validate_value(value)

        item_encoder = self.item_encoder
        tail_chunks = tuple(item_encoder(i) for i in value)

        items_are_dynamic = getattr(item_encoder, 'is_dynamic', False)
        if not items_are_dynamic:
            return b''.join(tail_chunks)

        head_length = 32 * len(value)
        tail_offsets = (0,) + tuple(accumulate(map(len, tail_chunks[:-1])))
        head_chunks = tuple(
            encode_uint_256(head_length + offset)
            for offset in tail_offsets
        )
        return b''.join(head_chunks + tail_chunks)

    @parse_type_str(with_arrlist=True)
    def from_type_str(cls, abi_type, registry):
        item_encoder = registry.get_encoder(str(abi_type.item_type))

        array_spec = abi_type.arrlist[-1]
        if len(array_spec) == 1:
            # If array dimension is fixed
            return SizedArrayEncoder(
                array_size=array_spec[0],
                item_encoder=item_encoder,
            )
        else:
            # If array dimension is dynamic
            return DynamicArrayEncoder(item_encoder=item_encoder)


class PackedArrayEncoder(BaseArrayEncoder):
    array_size = None

    def validate_value(self, value):
        super().validate_value(value)

        if self.array_size is not None and len(value) != self.array_size:
            raise ValueOutOfBounds(
                "Expected value with length {0}.  Provided value has {1} "
                "elements".format(self.array_size, len(value))
            )

    def encode(self, value):
        encoded_elements = self.encode_elements(value)

        return encoded_elements

    @parse_type_str(with_arrlist=True)
    def from_type_str(cls, abi_type, registry):
        item_encoder = registry.get_encoder(str(abi_type.item_type))

        array_spec = abi_type.arrlist[-1]
        if len(array_spec) == 1:
            return cls(
                array_size=array_spec[0],
                item_encoder=item_encoder,
            )
        else:
            return cls(item_encoder=item_encoder)


class SizedArrayEncoder(BaseArrayEncoder):
    array_size = None

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.is_dynamic = self.item_encoder.is_dynamic

    def validate(self):
        super().validate()

        if self.array_size is None:
            raise ValueError("`array_size` may not be none")

    def validate_value(self, value):
        super().validate_value(value)

        if len(value) != self.array_size:
            raise ValueOutOfBounds(
                "Expected value with length {0}.  Provided value has {1} "
                "elements".format(self.array_size, len(value))
            )

    def encode(self, value):
        encoded_elements = self.encode_elements(value)

        return encoded_elements


class DynamicArrayEncoder(BaseArrayEncoder):
    is_dynamic = True

    def encode(self, value):
        encoded_size = encode_uint_256(len(value))
        encoded_elements = self.encode_elements(value)
        encoded_value = encoded_size + encoded_elements

        return encoded_value
