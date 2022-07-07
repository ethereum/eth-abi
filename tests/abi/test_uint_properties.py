from hypothesis import (
    given,
)

from eth_abi import (
    decode,
    encode,
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

    encoded_value = encode([_type], [value])
    (decoded_value,) = decode([_type], encoded_value)

    assert decoded_value >= 0
