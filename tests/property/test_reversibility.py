from hypothesis import (
    given,
    settings,
)

from eth_abi import (
    encode_abi,
    decode_abi,
    encode_single,
    decode_single,
)

from ..common.strategies import (
    multi_strs_values,
    single_strs_values,
)


@settings(max_examples=1000)
@given(multi_strs_values)
def test_multi_abi_reversability(types_and_values):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    types, values = types_and_values
    encoded_values = encode_abi(types, values)
    decoded_values = decode_abi(types, encoded_values)
    assert values == decoded_values


@settings(max_examples=1000)
@given(single_strs_values)
def test_single_abi_reversability(type_and_value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    _type, value = type_and_value
    encoded_value = encode_single(_type, value)
    decoded_value = decode_single(_type, encoded_value)
    assert value == decoded_value
