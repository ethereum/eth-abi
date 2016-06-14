from hypothesis import given
import hypothesis.strategies as st

from eth_abi import (
    encode_abi,
    decode_abi,
    encode_single,
    decode_single,
)

from .abi_type_strategies import (
    uint_strats,
)


@given(st.one_of(uint_strats))
def test_always_positive_multi(type_and_value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    _type, value = type_and_value

    assert value >= 0

    encoded_value = encode_abi([_type], [value])
    decoded_value = decode_abi([_type], encoded_value)

    assert decoded_value >= 0


@given(st.one_of(uint_strats))
def test_always_positive_single(type_and_value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    _type, value = type_and_value

    assert value >= 0

    encoded_value = encode_single(_type, value)
    decoded_value = decode_single(_type, encoded_value)

    assert decoded_value >= 0
