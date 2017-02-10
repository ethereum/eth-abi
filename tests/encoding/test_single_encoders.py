from __future__ import absolute_import

import pytest

from hypothesis import (
    given,
    settings,
    example,
    strategies as st,
)

from eth_utils import (
    is_boolean,
    is_integer,
    is_address,
    is_bytes,
    to_normalized_address,
    to_canonical_address,
    to_checksum_address,
)

from eth_abi.exceptions import (
    EncodingTypeError,
    ValueOutOfBounds,
)
from eth_abi.encoding import (
    BooleanEncoder,
    UIntEncoder,
    IntEncoder,
    AddressEncoder,
    BytesEncoder,
    StringEncoder,
    encode_uint_256,
)

from eth_abi.utils.numeric import (
    int_to_big_endian,
    compute_unsigned_integer_bounds,
    compute_signed_integer_bounds,
    ceil32,
)
from eth_abi.utils.padding import (
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
        with pytest.raises(EncodingTypeError):
            encoder(bool_value)
        return

    expected_value = zpad(b'\x01' if bool_value else b'\x00', data_byte_size)
    encoded_value = encoder(bool_value)

    assert encoded_value == expected_value


@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_unsigned_integer(integer_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            UIntEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UIntEncoder.as_encoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )
    lower_bound, upper_bound = compute_unsigned_integer_bounds(value_bit_size)

    if not is_integer(integer_value):
        with pytest.raises(EncodingTypeError):
            encoder(integer_value)
        return
    elif integer_value < lower_bound or integer_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(integer_value)
        return

    expected_value = zpad(int_to_big_endian(integer_value), data_byte_size)
    encoded_value = encoder(integer_value)

    assert encoded_value == expected_value


@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_signed_integer(integer_value, value_bit_size, data_byte_size):
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            UIntEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = IntEncoder.as_encoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )

    lower_bound, upper_bound = compute_signed_integer_bounds(value_bit_size)

    if not is_integer(integer_value):
        with pytest.raises(EncodingTypeError):
            encoder(integer_value)
        return
    elif integer_value < lower_bound or integer_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(integer_value)
        return

    expected_value = zpad(int_to_big_endian(integer_value % 2**value_bit_size), data_byte_size)
    encoded_value = encoder(integer_value)

    assert encoded_value == expected_value


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
        with pytest.raises(EncodingTypeError):
            encoder(address_value)
        return

    expected_value = zpad(to_canonical_address(address_value), data_byte_size)
    encoded_value = encoder(address_value)

    assert encoded_value == expected_value


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
        with pytest.raises(EncodingTypeError):
            encoder(bytes_value)
        return
    elif len(bytes_value) * 8 > value_bit_size:
        with pytest.raises(ValueOutOfBounds):
            encoder(bytes_value)
        return

    expected_value = zpad_right(bytes_value, data_byte_size)
    encoded_value = encoder(bytes_value)

    assert encoded_value == expected_value


@given(
    string_value=st.one_of(
        st.none(),
        st.binary(min_size=0, max_size=256),
    ),
)
def test_encode_string(string_value):
    encoder = StringEncoder.as_encoder()

    if not is_bytes(string_value):
        with pytest.raises(EncodingTypeError):
            encoder(string_value)
        return

    expected_value = (
        encode_uint_256(len(string_value)) +
        zpad_right(string_value, ceil32(len(string_value)))
    )
    encoded_value = encoder(string_value)

    assert encoded_value == expected_value


@given(
    integer_value=st.one_of(st.integers(), st.none()),
    value_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_encode_unsigned_real(integer_value, value_bit_size, data_byte_size):
    assert False, "TODO"
    if value_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            UIntEncoder.as_encoder(
                value_bit_size=value_bit_size,
                data_byte_size=data_byte_size,
            )
        return

    encoder = UIntEncoder.as_encoder(
        value_bit_size=value_bit_size,
        data_byte_size=data_byte_size,
    )
    lower_bound, upper_bound = compute_unsigned_integer_bounds(value_bit_size)

    if not is_integer(integer_value):
        with pytest.raises(EncodingTypeError):
            encoder(integer_value)
        return
    elif integer_value < lower_bound or integer_value > upper_bound:
        with pytest.raises(ValueOutOfBounds):
            encoder(integer_value)
        return

    expected_value = zpad(int_to_big_endian(integer_value), data_byte_size)
    encoded_value = encoder(integer_value)

    assert encoded_value == expected_value
