import codecs
import decimal
import re

import pytest

from hypothesis import (
    given,
    settings,
    example,
    strategies as st,
)

from eth_utils import (
    int_to_big_endian,
    is_boolean,
    is_integer,
    is_number,
    is_address,
    is_bytes,
    is_text,
    to_normalized_address,
    to_canonical_address,
    to_checksum_address,
    decode_hex,
)

from eth_abi.exceptions import (
    EncodingTypeError,
    IllegalValue,
    ValueOutOfBounds,
)
from eth_abi.encoding import (
    BooleanEncoder,
    UnsignedIntegerEncoder,
    SignedIntegerEncoder,
    AddressEncoder,
    BytesEncoder,
    ByteStringEncoder,
    TextStringEncoder,
    encode_uint_256,
    UnsignedFixedEncoder,
    SignedFixedEncoder,
    UnsignedRealEncoder,
    SignedRealEncoder,
    TupleEncoder,
)

from eth_abi.utils.numeric import (
    TEN,
    abi_decimal_context,
    compute_unsigned_integer_bounds,
    compute_signed_integer_bounds,
    compute_unsigned_fixed_bounds,
    compute_signed_fixed_bounds,
    compute_unsigned_real_bounds,
    compute_signed_real_bounds,
    ceil32,
)
from eth_abi.utils.padding import (
    fpad,
    zpad,
    zpad_right,
)


@given(
    bool_value=st.one_of(st.booleans(), st.none()),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_boolean(bool_value, data_byte_size):
    encoder = BooleanEncoder(
        data_byte_size=data_byte_size,
    )


    if not is_boolean(bool_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(bool_value)
        assert 'BooleanEncoder' in str(exception_info.value)
        return

    expected_value = zpad(b'\x01' if bool_value else b'\x00', data_byte_size)
    encoded_value = encoder(bool_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@example(integer_value=-1, value_bit_size=8, data_byte_size=1)
@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_unsigned_integer(integer_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError) as exception_info:
            UnsignedIntegerEncoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UnsignedIntegerEncoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )
    lower_bound, upper_bound = compute_unsigned_integer_bounds(value_bit_size)

    if not is_integer(integer_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(integer_value)
        assert 'UnsignedInteger' in str(exception_info.value)
        return
    elif integer_value < lower_bound or integer_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(integer_value)
        return

    if integer_value >= 0:
        expected_value = zpad(int_to_big_endian(integer_value), data_byte_size)
    else:
        expected_value = fpad(int_to_big_endian(integer_value), data_byte_size)

    encoded_value = encoder(integer_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_signed_integer(integer_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            SignedIntegerEncoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = SignedIntegerEncoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )

    lower_bound, upper_bound = compute_signed_integer_bounds(value_bit_size)

    if not is_integer(integer_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(integer_value)
        assert 'SignedInteger' in str(exception_info.value)
        return
    elif integer_value < lower_bound or integer_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(integer_value)
        return

    if integer_value >= 0:
        expected_value = zpad(
            int_to_big_endian(integer_value % 2**value_bit_size),
            data_byte_size
        )
    else:
        expected_value = fpad(
            int_to_big_endian(integer_value % 2**value_bit_size),
            data_byte_size
        )

    encoded_value = encoder(integer_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    address_value=st.one_of(
        st.none(),
        st.binary(min_size=20, max_size=20),
        st.binary(min_size=20, max_size=20).map(to_normalized_address),
        st.binary(min_size=20, max_size=20).map(to_checksum_address),
    ),
    value_bit_size=st.integers(min_value=19, max_value=21).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=18, max_value=32),
)
def test_encode_address(address_value, value_bit_size, data_byte_size):
    if value_bit_size != 20 * 8:
        with pytest.raises(ValueError):
            AddressEncoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            AddressEncoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = AddressEncoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )

    if not is_address(address_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(address_value)
        assert 'AddressEncoder' in str(exception_info.value)
        return

    expected_value = zpad(to_canonical_address(address_value), data_byte_size)
    encoded_value = encoder(address_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    bytes_value=st.one_of(
        st.none(),
        st.binary(min_size=0, max_size=40),
    ),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=18, max_value=32),
)
def test_encode_bytes_xx(bytes_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            AddressEncoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = BytesEncoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )

    if not is_bytes(bytes_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(bytes_value)
        assert 'BytesEncoder' in str(exception_info.value)
        return
    elif len(bytes_value) * 8 > value_bit_size:
        with pytest.raises(ValueOutOfBounds):
            encoder(bytes_value)
        return

    expected_value = zpad_right(bytes_value, data_byte_size)
    encoded_value = encoder(bytes_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    string_value=st.one_of(
        st.none(),
        st.text(min_size=0, max_size=256),
        st.binary(min_size=0, max_size=256),
    ),
)
def test_encode_byte_string(string_value):
    encoder = ByteStringEncoder()

    if not is_bytes(string_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(string_value)
        assert 'ByteStringEncoder' in str(exception_info.value)
        return

    expected_value = (
        encode_uint_256(len(string_value)) +
        (
            zpad_right(string_value, ceil32(len(string_value)))
            if string_value
            else b'\x00' * 32
        )
    )
    encoded_value = encoder(string_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    string_value=st.one_of(
        st.none(),
        st.text(min_size=0, max_size=256),
        st.binary(min_size=0, max_size=256),
    ),
)
def test_encode_text_string(string_value):
    encoder = TextStringEncoder()

    if not is_text(string_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(string_value)
        assert 'TextStringEncoder' in str(exception_info.value)
        return

    string_value_as_bytes = codecs.encode(string_value, 'utf8')

    expected_value = (
        encode_uint_256(len(string_value_as_bytes)) +
        (
            zpad_right(
                string_value_as_bytes,
                ceil32(len(string_value_as_bytes)),
            )
            if string_value
            else b'\x00' * 32
        )
    )
    encoded_value = encoder(string_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    base_integer_value=st.one_of(st.integers(), st.none()),
    high_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    low_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
@example(
    base_integer_value=384,
    value_bit_size=232,
    high_bit_size=64,
    low_bit_size=168,
    data_byte_size=29,
)
def test_encode_unsigned_real(base_integer_value,
                              value_bit_size,
                              high_bit_size,
                              low_bit_size,
                              data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            UnsignedRealEncoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif high_bit_size + low_bit_size != value_bit_size:
        with pytest.raises(ValueError):
            UnsignedRealEncoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UnsignedRealEncoder(
        value_bit_size=value_bit_size,
        high_bit_size=high_bit_size,
        low_bit_size=low_bit_size,
        data_byte_size=data_byte_size,
    )

    if not is_number(base_integer_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(base_integer_value)
        assert 'UnsignedReal' in str(exception_info.value)
        return

    with decimal.localcontext(abi_decimal_context):
        real_value = decimal.Decimal(base_integer_value) / 2 ** low_bit_size

    lower_bound, upper_bound = compute_unsigned_real_bounds(
        high_bit_size,
        low_bit_size,
    )

    if real_value < lower_bound or real_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(base_integer_value)
        return

    expected_value = zpad(int_to_big_endian(base_integer_value), data_byte_size)
    encoded_value = encoder(real_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    base_integer_value=st.one_of(st.integers(), st.none()),
    high_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    low_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_signed_real(base_integer_value,
                              value_bit_size,
                              high_bit_size,
                              low_bit_size,
                              data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            SignedRealEncoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif high_bit_size + low_bit_size != value_bit_size:
        with pytest.raises(ValueError):
            SignedRealEncoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = SignedRealEncoder(
        value_bit_size=value_bit_size,
        high_bit_size=high_bit_size,
        low_bit_size=low_bit_size,
        data_byte_size=data_byte_size,
    )

    if not is_number(base_integer_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(base_integer_value)
        assert 'SignedReal' in str(exception_info.value)
        return

    unsigned_integer_value = base_integer_value % 2**(high_bit_size + low_bit_size)

    with decimal.localcontext(abi_decimal_context):
        real_value = decimal.Decimal(unsigned_integer_value) / 2 ** low_bit_size

    lower_bound, upper_bound = compute_signed_real_bounds(
        high_bit_size,
        low_bit_size,
    )

    if real_value < lower_bound or real_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(real_value)
        return

    expected_value = zpad(int_to_big_endian(unsigned_integer_value), data_byte_size)
    encoded_value = encoder(real_value)

    assert encoded_value == expected_value


@settings(max_examples=250)
@given(
    value=st.one_of(st.integers(), st.decimals(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    frac_places=st.integers(min_value=1, max_value=80),
    data_byte_size=st.integers(min_value=0, max_value=32),
)
@example(value=decimal.Decimal('5.33'), value_bit_size=8, frac_places=1, data_byte_size=1)
def test_encode_unsigned_fixed(value,
                               value_bit_size,
                               frac_places,
                               data_byte_size):
    if value_bit_size > data_byte_size * 8:
        pattern = r'Value byte size exceeds data size'
        with pytest.raises(ValueError, match=pattern):
            UnsignedFixedEncoder(
                value_bit_size=value_bit_size,
                frac_places=frac_places,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UnsignedFixedEncoder(
        value_bit_size=value_bit_size,
        frac_places=frac_places,
        data_byte_size=data_byte_size,
    )

    if not is_number(value):
        pattern = r'Value of type .*NoneType.* cannot be encoded by UnsignedFixedEncoder'
        with pytest.raises(EncodingTypeError, match=pattern):
            encoder(value)
        return

    if UnsignedFixedEncoder.illegal_value_fn(value):
        pattern = r'Value .*(NaN|Infinity|-Infinity).* cannot be encoded by UnsignedFixedEncoder'
        with pytest.raises(IllegalValue, match=pattern):
            encoder(value)
        return

    lower, upper = compute_unsigned_fixed_bounds(value_bit_size, frac_places)
    if value < lower or value > upper:
        pattern = r'Value .* cannot be encoded in .* bits'
        with pytest.raises(ValueOutOfBounds, match=pattern):
            encoder(value)
        return

    with decimal.localcontext(abi_decimal_context):
        residue = value % (TEN ** -frac_places)
    if residue > 0:
        pattern = re.escape(
            'UnsignedFixedEncoder cannot encode value {}: '
            'residue {} outside allowed fractional precision of {}'.format(
                repr(value),
                repr(residue),
                frac_places,
            )
        )
        with pytest.raises(IllegalValue, match=pattern):
            encoder(value)
        return

    # Ensure no exception
    encoder(value)


@settings(max_examples=250)
@given(
    value=st.one_of(st.integers(), st.decimals(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    frac_places=st.integers(min_value=1, max_value=80),
    data_byte_size=st.integers(min_value=0, max_value=32),
)
def test_encode_signed_fixed(value,
                             value_bit_size,
                             frac_places,
                             data_byte_size):
    if value_bit_size > data_byte_size * 8:
        pattern = r'Value byte size exceeds data size'
        with pytest.raises(ValueError, match=pattern):
            SignedFixedEncoder(
                value_bit_size=value_bit_size,
                frac_places=frac_places,
                data_byte_size=data_byte_size,
            )
        return

    encoder = SignedFixedEncoder(
        value_bit_size=value_bit_size,
        frac_places=frac_places,
        data_byte_size=data_byte_size,
    )

    if not is_number(value):
        pattern = r'Value of type .*NoneType.* cannot be encoded by SignedFixedEncoder'
        with pytest.raises(EncodingTypeError, match=pattern):
            encoder(value)
        return

    if SignedFixedEncoder.illegal_value_fn(value):
        pattern = r'Value .*(NaN|Infinity|-Infinity).* cannot be encoded by SignedFixedEncoder'
        with pytest.raises(IllegalValue, match=pattern):
            encoder(value)
        return

    lower, upper = compute_signed_fixed_bounds(value_bit_size, frac_places)
    if value < lower or value > upper:
        pattern = r'Value .* cannot be encoded in .* bits'
        with pytest.raises(ValueOutOfBounds, match=pattern):
            encoder(value)
        return

    with decimal.localcontext(abi_decimal_context):
        residue = value % (TEN ** -frac_places)
    if residue > 0:
        pattern = re.escape(
            'SignedFixedEncoder cannot encode value {}: '
            'residue {} outside allowed fractional precision of {}'.format(
                repr(value),
                repr(residue),
                frac_places,
            )
        )
        with pytest.raises(IllegalValue, match=pattern):
            encoder(value)
        return

    # Ensure no exception
    encoder(value)


# TODO: make this generic
def test_tuple_encoder():
    encoder = TupleEncoder(encoders=(
        UnsignedIntegerEncoder(value_bit_size=256),
        ByteStringEncoder(),
    ))
    expected = decode_hex('0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    actual = encoder((0, b''))
    assert actual == expected
