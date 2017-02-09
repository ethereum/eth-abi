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
)

from eth_abi.exceptions import (
    EncodingTypeError,
    ValueOutOfBounds,
)
from eth_abi.encoding import (
    BooleanEncoder,
    UIntEncoder,
)

from eth_abi.utils.numeric import (
    int_to_big_endian,
)
from eth_abi.utils.padding import (
    zpad,
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


    if not is_integer(integer_value):
        with pytest.raises(EncodingTypeError):
            encoder(integer_value)
        return
    elif integer_value < 0 or integer_value > 2 ** value_bit_size - 1:
        with pytest.raises(ValueOutOfBounds):
            encoder(integer_value)
        return

    expected_value = zpad(int_to_big_endian(integer_value), data_byte_size)
    encoded_value = encoder(integer_value)

    assert encoded_value == expected_value
