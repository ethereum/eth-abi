from __future__ import absolute_import

import pytest

import decimal

from hypothesis import (
    given,
    settings,
    example,
    strategies as st,
)

from eth_utils import (
    is_boolean,
    is_integer,
    is_number,
    is_address,
    is_bytes,
    to_normalized_address,
    to_canonical_address,
    to_checksum_address,
    decode_hex,
)

from eth_abi.exceptions import (
    EncodingTypeError,
    ValueOutOfBounds,
)
from eth_abi.encoding import (
    BooleanEncoder,
    UnsignedIntegerEncoder,
    SignedIntegerEncoder,
    AddressEncoder,
    BytesEncoder,
    StringEncoder,
    encode_uint_256,
    UnsignedRealEncoder,
    SignedRealEncoder,
    MultiEncoder,
)

from eth_abi.utils.numeric import (
    abi_decimal_context,
    int_to_big_endian,
    compute_unsigned_integer_bounds,
    compute_signed_integer_bounds,
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
    encoder = BooleanEncoder.as_encoder(
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


@settings(max_examples=1000)
@example(integer_value=-1, value_bit_size=8, data_byte_size=1)
@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_unsigned_integer(integer_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError) as exception_info:
            UnsignedIntegerEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UnsignedIntegerEncoder.as_encoder(
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


@settings(max_examples=1000)
@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_signed_integer(integer_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            SignedIntegerEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = SignedIntegerEncoder.as_encoder(
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


@settings(max_examples=1000)
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
            AddressEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            AddressEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = AddressEncoder.as_encoder(
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


@settings(max_examples=1000)
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
            AddressEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = BytesEncoder.as_encoder(
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


@settings(max_examples=1000)
@given(
    string_value=st.one_of(
        st.none(),
        st.binary(min_size=0, max_size=256),
    ),
)
def test_encode_string(string_value):
    encoder = StringEncoder.as_encoder()

    if not is_bytes(string_value):
        with pytest.raises(EncodingTypeError) as exception_info:
            encoder(string_value)
        assert 'StringEncoder' in str(exception_info.value)
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


@settings(max_examples=1000)
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
            UnsignedRealEncoder.as_encoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif high_bit_size + low_bit_size != value_bit_size:
        with pytest.raises(ValueError):
            UnsignedRealEncoder.as_encoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UnsignedRealEncoder.as_encoder(
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


@settings(max_examples=1000)
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
            SignedRealEncoder.as_encoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif high_bit_size + low_bit_size != value_bit_size:
        with pytest.raises(ValueError):
            SignedRealEncoder.as_encoder(
                value_bit_size=value_bit_size,
                high_bit_size=high_bit_size,
                low_bit_size=low_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = SignedRealEncoder.as_encoder(
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


# TODO: make this generic
def test_multi_encoder():
    encoder = MultiEncoder.as_encoder(encoders=(
        UnsignedIntegerEncoder.as_encoder(value_bit_size=256),
        StringEncoder.as_encoder(),
    ))
    expected = decode_hex('0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    actual = encoder((0, b''))
    assert actual == expected
