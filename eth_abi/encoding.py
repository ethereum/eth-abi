import codecs
import decimal
import itertools

from eth_utils import (
    int_to_big_endian,
    is_boolean,
    is_integer,
    is_number,
    is_address,
    is_bytes,
    is_text,
    is_list_like,
    is_null,
    to_canonical_address,
)

from eth_abi.base import (
    BaseCoder,
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
    compute_signed_integer_bounds,
    compute_unsigned_integer_bounds,
    compute_signed_fixed_bounds,
    compute_unsigned_fixed_bounds,
    compute_signed_real_bounds,
    compute_unsigned_real_bounds,
    ceil32,
)
from eth_abi.utils.padding import (
    fpad,
    zpad,
    zpad_right,
)


class BaseEncoder(BaseCoder):
    @classmethod
    def as_encoder(cls, name=None, **kwargs):
        for key in kwargs:
            if not hasattr(cls, key):
                raise AttributeError(
                    "Property `{key}` not found on {cls_name} class. "
                    "`{cls_name}.as_encoder` only accepts keyword arguments which are "
                    "present on the {cls_name} class.".format(
                        key=key,
                        cls_name=cls.__name__,
                    )
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
        super().validate()
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
            if isinstance(encoder, (DynamicArrayEncoder, ByteStringEncoder, TextStringEncoder)):
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
        super().validate()

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
        return cls.as_encoder()


encode_bool = BooleanEncoder.as_encoder()


class NumberEncoder(Fixed32ByteSizeEncoder):
    is_big_endian = True
    bounds_fn = None
    illegal_value_fn = None
    type_check_fn = None

    @classmethod
    def validate(cls):
        super().validate()
        if cls.bounds_fn is None:
            raise ValueError("`bounds_fn` cannot be null")
        if cls.type_check_fn is None:
            raise ValueError("`type_check_fn` cannot be null")

    @classmethod
    def validate_value(cls, value):
        if not cls.type_check_fn(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {1}".format(
                    type(value),
                    cls.__name__,
                )
            )

        illegal_value = (
            cls.illegal_value_fn is not None
            and cls.illegal_value_fn(value)
        )
        if illegal_value:
            raise IllegalValue(
                'Value {} cannot be encoded by {}'.format(repr(value), cls.__name__)
            )

        lower_bound, upper_bound = cls.bounds_fn(cls.value_bit_size)
        if value < lower_bound or value > upper_bound:
            raise ValueOutOfBounds(
                "Value {0} cannot be encoded in {1} bits.  Must be bounded "
                "between [{2}, {3}]".format(
                    repr(value),
                    cls.value_bit_size,
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
        return cls.as_encoder(value_bit_size=abi_type.sub)


encode_uint_256 = UnsignedIntegerEncoder.as_encoder(value_bit_size=256, data_byte_size=32)


class SignedIntegerEncoder(NumberEncoder):
    bounds_fn = staticmethod(compute_signed_integer_bounds)
    type_check_fn = staticmethod(is_integer)

    @classmethod
    def encode_fn(cls, value):
        return int_to_big_endian(value % (2 ** cls.value_bit_size))

    @classmethod
    def encode(cls, value):
        cls.validate_value(value)
        base_encoded_value = cls.encode_fn(value)

        if value >= 0:
            padded_encoded_value = zpad(base_encoded_value, cls.data_byte_size)
        else:
            padded_encoded_value = fpad(base_encoded_value, cls.data_byte_size)
        return padded_encoded_value

    @parse_type_str('int')
    def from_type_str(cls, abi_type, registry):
        return cls.as_encoder(value_bit_size=abi_type.sub)


class BaseFixedEncoder(NumberEncoder):
    frac_places = None
    type_check_fn = staticmethod(is_number)

    @classmethod
    def illegal_value_fn(cls, value):
        if isinstance(value, decimal.Decimal):
            return value.is_nan() or value.is_infinite()

        return False

    @classmethod
    def validate_value(cls, value):
        super().validate_value(value)

        with decimal.localcontext(abi_decimal_context):
            residue = value % (TEN ** -cls.frac_places)

        if residue > 0:
            raise ValueError(
                '{} cannot encode value {}: '
                'residue {} outside allowed fractional precision of {}'.format(
                    cls.__name__,
                    repr(value),
                    repr(residue),
                    cls.frac_places,
                )
            )

    @classmethod
    def validate(cls):
        super().validate()

        if cls.frac_places is None:
            raise ValueError("must specify `frac_places`")

        if cls.frac_places <= 0 or cls.frac_places > 80:
            raise ValueError("`frac_places` must be in range (0, 80]")


class UnsignedFixedEncoder(BaseFixedEncoder):
    @classmethod
    def bounds_fn(cls, value_bit_size):
        return compute_unsigned_fixed_bounds(cls.value_bit_size, cls.frac_places)

    @classmethod
    def encode_fn(cls, value):
        with decimal.localcontext(abi_decimal_context):
            scaled_value = value * TEN ** cls.frac_places
            integer_value = int(scaled_value)

        return int_to_big_endian(integer_value)

    @parse_type_str('ufixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls.as_encoder(
            value_bit_size=value_bit_size,
            frac_places=frac_places,
        )


class SignedFixedEncoder(BaseFixedEncoder):
    @classmethod
    def bounds_fn(cls, value_bit_size):
        return compute_signed_fixed_bounds(cls.value_bit_size, cls.frac_places)

    @classmethod
    def encode_fn(cls, value):
        with decimal.localcontext(abi_decimal_context):
            scaled_value = value * TEN ** cls.frac_places
            integer_value = int(scaled_value)

        unsigned_integer_value = integer_value % (2 ** cls.value_bit_size)

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

    @parse_type_str('fixed')
    def from_type_str(cls, abi_type, registry):
        value_bit_size, frac_places = abi_type.sub

        return cls.as_encoder(
            value_bit_size=value_bit_size,
            frac_places=frac_places,
        )


class BaseRealEncoder(NumberEncoder):
    low_bit_size = None
    high_bit_size = None
    type_check_fn = staticmethod(is_number)

    @classmethod
    def validate(cls):
        super().validate()
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

    @parse_type_str('ureal')
    def from_type_str(cls, abi_type, registry):
        high_bit_size, low_bit_size = abi_type.sub

        return cls.as_encoder(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )


class SignedRealEncoder(BaseRealEncoder):
    @classmethod
    def bounds_fn(cls, value_bit_size):
        return compute_signed_real_bounds(cls.high_bit_size, cls.low_bit_size)

    @classmethod
    def encode_fn(cls, value):
        scaled_value = value * 2 ** cls.low_bit_size
        integer_value = int(scaled_value)
        unsigned_integer_value = integer_value % (2 ** (cls.high_bit_size + cls.low_bit_size))
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

    @parse_type_str('real')
    def from_type_str(cls, abi_type, registry):
        high_bit_size, low_bit_size = abi_type.sub

        return cls.as_encoder(
            value_bit_size=high_bit_size + low_bit_size,
            high_bit_size=high_bit_size,
            low_bit_size=low_bit_size,
        )


class AddressEncoder(Fixed32ByteSizeEncoder):
    value_bit_size = 20 * 8
    encode_fn = staticmethod(to_canonical_address)
    is_big_endian = True

    @classmethod
    def validate_value(cls, value):
        if not is_address(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {1}".format(
                    type(value),
                    cls.__name__,
                )
            )

    @classmethod
    def validate(cls):
        super().validate()
        if cls.value_bit_size != 20 * 8:
            raise ValueError('Addresses must be 160 bits in length')

    @parse_type_str('address')
    def from_type_str(cls, abi_type, registry):
        return cls.as_encoder()


encode_address = AddressEncoder.as_encoder()


class BytesEncoder(Fixed32ByteSizeEncoder):
    is_big_endian = False

    @classmethod
    def validate_value(cls, value):
        if not is_bytes(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by {1}".format(
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

    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls.as_encoder(value_bit_size=abi_type.sub * 8)


class ByteStringEncoder(BaseEncoder):
    @classmethod
    def encode(cls, value):
        if not is_bytes(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by ByteStringEncoder".format(
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

    @parse_type_str('bytes')
    def from_type_str(cls, abi_type, registry):
        return cls.as_encoder()


encode_bytes = ByteStringEncoder.as_encoder()


class TextStringEncoder(ByteStringEncoder):
    @classmethod
    def encode(cls, value):
        if not is_text(value):
            raise EncodingTypeError(
                "Value of type {0} cannot be encoded by TextStringEncoder".format(
                    type(value),
                )
            )
        value_as_bytes = codecs.encode(value, 'utf8')
        return super().encode(value_as_bytes)

    @parse_type_str('string')
    def from_type_str(cls, abi_type, registry):
        return cls.as_encoder()


encode_string = TextStringEncoder.as_encoder()


class BaseArrayEncoder(BaseEncoder):
    item_encoder = None

    @classmethod
    def validate(cls):
        super().validate()
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

    @parse_type_str(with_arrlist=True)
    def from_type_str(cls, abi_type, registry):
        item_encoder = registry.get_encoder(str(abi_type.item_type))

        array_spec = abi_type.arrlist[-1]
        if len(array_spec) == 1:
            # If array dimension is fixed
            return SizedArrayEncoder.as_encoder(
                array_size=array_spec[0],
                item_encoder=item_encoder,
            )
        else:
            # If array dimension is dynamic
            return DynamicArrayEncoder.as_encoder(item_encoder=item_encoder)


class SizedArrayEncoder(BaseArrayEncoder):
    array_size = None

    @classmethod
    def validate(cls):
        super().validate()
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
