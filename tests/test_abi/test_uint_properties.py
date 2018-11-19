from hypothesis import (
    given,
)

from eth_abi.abi import (
    encoder as default_encoder,
)
from tests.common.strategies import (
    uint_strs,
    uint_values,
)


@given(uint_strs, uint_values)
def test_always_positive_multi(_type, value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    assert value >= 0

    encoded_value = default_encoder.encode_abi([_type], [value])
    decoded_value = default_encoder.decode_abi([_type], encoded_value)

    assert decoded_value[0] >= 0


@given(uint_strs, uint_values)
def test_always_positive_single(_type, value):
    """
    Tests round trip encoding and decoding for basic types and lists of basic
    types.
    """
    assert value >= 0

    encoded_value = default_encoder.encode_single(_type, value)
    decoded_value = default_encoder.decode_single(_type, encoded_value)

    assert decoded_value >= 0
