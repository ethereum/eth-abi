import pytest

from io import BytesIO

from hypothesis import (
    given,
    settings,
    example,
    strategies as st,
)

from eth_utils import (
    decode_hex,
    to_normalized_address,
)

from eth_abi.constants import (
    TT256M1,
)
from eth_abi.exceptions import (
    InsufficientDataBytes,
    NonEmptyPaddingBytes,
)
from eth_abi.decoding import (
    UIntDecoder,
    IntDecoder,
    StringDecoder,
    BytesDecoder,
    MultiDecoder,
    BooleanDecoder,
    AddressDecoder,
    ArrayDecoder,
)

from eth_abi.utils.padding import (
    zpad32,
)
from eth_abi.utils.numeric import (
    big_endian_to_int,
    int_to_big_endian,
    ceil32,
)


def is_non_empty_non_null_byte_string(value):
    return value and big_endian_to_int(value) != 0


@settings(max_examples=1000)
@given(
    integer_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    stream_bytes=st.binary(min_size=0, max_size=32, average_size=32),
    data_byte_size=st.integers(min_value=0, max_value=32),
)
def test_decode_unsigned_int(integer_bit_size, stream_bytes, data_byte_size):
    if integer_bit_size % 8 != 0:
        with pytest.raises(ValueError):
            UIntDecoder.factory(
                value_bit_size=integer_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif integer_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            UIntDecoder.factory(
                value_bit_size=integer_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    else:
        decoder = UIntDecoder.factory(
            value_bit_size=integer_bit_size,
            data_byte_size=data_byte_size,
        )


    stream = BytesIO(stream_bytes)
    actual_value = big_endian_to_int(stream_bytes[:data_byte_size])

    if len(stream_bytes) < data_byte_size:
        with pytest.raises(InsufficientDataBytes):
            decoder.decode(stream)
        return
    elif actual_value > 2 ** integer_bit_size - 1:
        with pytest.raises(NonEmptyPaddingBytes):
            decoder.decode(stream)
        return
    else:
        decoded_value = decoder.decode(stream)

    assert decoded_value == actual_value


@settings(max_examples=1000)
@given(
    integer_bit_size=st.integers(min_value=1, max_value=32).map(lambda v: v * 8),
    stream_bytes=st.binary(min_size=0, max_size=32, average_size=32),
    data_byte_size=st.integers(min_value=0, max_value=32),
)
def test_decode_signed_int(integer_bit_size, stream_bytes, data_byte_size):
    if integer_bit_size % 8 != 0:
        with pytest.raises(ValueError):
            IntDecoder.factory(
                value_bit_size=integer_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    elif integer_bit_size > data_byte_size * 8:
        with pytest.raises(ValueError):
            IntDecoder.factory(
                value_bit_size=integer_bit_size,
                data_byte_size=data_byte_size,
            )
        return
    else:
        decoder = IntDecoder.factory(
            value_bit_size=integer_bit_size,
            data_byte_size=data_byte_size,
        )


    stream = BytesIO(stream_bytes)

    raw_value = big_endian_to_int(stream_bytes[:data_byte_size])
    if raw_value >= 2 ** (integer_bit_size - 1):
        actual_value = raw_value - 2 ** integer_bit_size
    else:
        actual_value = raw_value

    if len(stream_bytes) < data_byte_size:
        with pytest.raises(InsufficientDataBytes):
            decoder.decode(stream)
        return
    elif raw_value > 2 ** integer_bit_size - 1:
        with pytest.raises(NonEmptyPaddingBytes):
            decoder.decode(stream)
        return
    else:
        decoded_value = decoder.decode(stream)

    assert decoded_value == actual_value


@settings(max_examples=1000)
@given(
    string_bytes=st.binary(min_size=0, max_size=256),
    pad_size=st.integers(min_value=0, max_value=32),
)
def test_decode_bytes_and_string(string_bytes, pad_size):
    size_bytes = zpad32(int_to_big_endian(len(string_bytes)))
    padded_string_bytes = string_bytes + b'\x00' * pad_size
    stream_bytes = size_bytes + padded_string_bytes
    stream = BytesIO(stream_bytes)

    if len(padded_string_bytes) < ceil32(len(string_bytes)):
        with pytest.raises(InsufficientDataBytes):
            StringDecoder.decode(stream)
        return

    decoded_value = StringDecoder.decode(stream)
    assert decoded_value == string_bytes


@settings(max_examples=1000)
@given(
    stream_bytes=st.binary(min_size=1, max_size=32, average_size=32),
    data_byte_size=st.integers(min_value=1, max_value=32),
)
def test_decode_boolean(stream_bytes, data_byte_size):
    stream = BytesIO(stream_bytes)

    decoder = BooleanDecoder.factory(data_byte_size=data_byte_size)

    if len(stream_bytes) < data_byte_size:
        with pytest.raises(InsufficientDataBytes):
            decoder.decode(stream)
        return

    padding_bytes = stream_bytes[:data_byte_size][:-1]
    if is_non_empty_non_null_byte_string(padding_bytes):
        with pytest.raises(NonEmptyPaddingBytes):
            decoder.decode(stream)
        return

    byte_value = stream_bytes[data_byte_size - 1]

    if byte_value == 0:
        actual_value = False
    elif byte_value == 1:
        actual_value = True
    else:
        with pytest.raises(NonEmptyPaddingBytes):
            decoder.decode(stream)
        return

    decoded_value = decoder.decode(stream)
    assert decoded_value is actual_value


@settings(max_examples=1000)
@given(
    value_byte_size=st.integers(min_value=1, max_value=32),
    stream_bytes=st.binary(min_size=0, max_size=32, average_size=32),
    data_byte_size=st.integers(min_value=0, max_value=32),
)
def test_decode_bytes_xx(value_byte_size, stream_bytes, data_byte_size):
    if value_byte_size > data_byte_size:
        with pytest.raises(ValueError):
            BytesDecoder.factory(
                value_bit_size=value_byte_size * 8,
                data_byte_size=data_byte_size,
            )
        return
    else:
        decoder = BytesDecoder.factory(
            value_bit_size=value_byte_size * 8,
            data_byte_size=data_byte_size,
        )

    stream = BytesIO(stream_bytes)
    actual_value = stream_bytes[:value_byte_size]
    padding_bytes = stream_bytes[value_byte_size:data_byte_size]

    if len(stream_bytes) < data_byte_size:
        with pytest.raises(InsufficientDataBytes):
            decoder.decode(stream)
        return
    elif is_non_empty_non_null_byte_string(padding_bytes):
        with pytest.raises(NonEmptyPaddingBytes):
            decoder.decode(stream)
        return
    else:
        decoded_value = decoder.decode(stream)

    assert decoded_value == actual_value


@settings(max_examples=1000)
@given(
    address_bytes=st.binary(min_size=0, max_size=32, average_size=20),
    padding_size=st.integers(min_value=10, max_value=14),
    data_byte_size=st.integers(min_value=0, max_value=32),
)
def test_decode_address(address_bytes, padding_size, data_byte_size):
    stream_bytes = b'\x00' * padding_size + address_bytes
    if data_byte_size < 20:
        with pytest.raises(ValueError):
            AddressDecoder.factory(
                data_byte_size=data_byte_size,
            )
        return
    else:
        decoder = AddressDecoder.factory(
            data_byte_size=data_byte_size,
        )

    stream = BytesIO(stream_bytes)
    padding_bytes = stream_bytes[:data_byte_size][:-20]

    if len(stream_bytes) < data_byte_size:
        with pytest.raises(InsufficientDataBytes):
            decoder.decode(stream)
        return
    elif is_non_empty_non_null_byte_string(padding_bytes):
        with pytest.raises(NonEmptyPaddingBytes):
            decoder.decode(stream)
        return
    else:
        decoded_value = decoder.decode(stream)

    actual_value = to_normalized_address(stream_bytes[:data_byte_size][-20:])

    assert decoded_value == actual_value


@settings(max_examples=1000)
@given(
    array_size=st.integers(min_value=0, max_value=32),
    array_values=st.lists(st.integers(min_value=0, max_value=TT256M1), min_size=0, max_size=64, average_size=32).map(tuple),
)
def test_decode_array_of_unsigned_integers(array_size, array_values):
    size_bytes = zpad32(int_to_big_endian(array_size))
    values_bytes = b''.join((
        zpad32(int_to_big_endian(v)) for v in array_values
    ))
    stream_bytes = size_bytes + values_bytes

    decoder = ArrayDecoder.factory(sub_decoder=UIntDecoder.factory(value_bit_size=256).decode)
    stream = BytesIO(stream_bytes)

    if len(array_values) < array_size:
        with pytest.raises(InsufficientDataBytes):
            decoder.decode(stream)
        return

    actual_values = decoder.decode(stream)
    assert actual_values == array_values[:array_size]


# TODO: make this generic
def test_multi_decoder():
    decoder = MultiDecoder.factory(decoders=(
        UIntDecoder.factory(value_bit_size=256).decode,
        StringDecoder.decode,
    ))
    stream = BytesIO(decode_hex('0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'))
    uint_v, bytes_v = decoder.decode(stream)
    assert uint_v == 0
    assert bytes_v == 64 * b'\x00'