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

from .abi_type_strategies import (
    multi_abi_strats,
    single_abi_strats,
)


@settings(max_examples=1000)
@given(multi_abi_strats)
def test_multi_abi_reversability(types_and_values):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    types, value = types_and_values
    encoded_value = encode_abi(types, value)
    decoded_value = decode_abi(types, encoded_value)
    assert value == decoded_value



@settings(max_examples=1000)
@given(single_abi_strats)
def test_single_abi_reversability(type_and_value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    _type, value = type_and_value
    encoded_value = encode_single(_type, value)
    decoded_value = decode_single(_type, encoded_value)
    assert value == decoded_value
