from hypothesis import (
    given,
    settings,
)

from eth_abi import (
    decode,
    encode,
)
from tests.common.strategies import (
    multi_strs_values,
    single_strs_values,
    tuple_strs_values,
)


@settings(deadline=None)
@given(multi_strs_values)
def test_multi_abi_reversibility(types_and_values):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    types, values = types_and_values
    encoded_values = encode(values, types)
    decoded_values = decode(encoded_values, types)
    assert values == decoded_values


@settings(deadline=None)
@given(single_strs_values)
def test_single_abi_type_reversibility(type_and_value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    _type, value = type_and_value
    encoded_value = encode([value], [_type])
    (decoded_value,) = decode(encoded_value, [_type])
    assert value == decoded_value


@settings(deadline=None)
@given(tuple_strs_values)
def test_single_abi_type_tuple_reversibility(type_and_value):
    """
    Tests round trip encoding and decoding for tuple types.
    """
    _type, value = type_and_value
    encoded_value = encode([value], [_type])
    (decoded_value,) = decode(encoded_value, [_type])
    assert value == decoded_value
