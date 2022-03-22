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

    encoded_value = encode([value], [_type])
    (decoded_value,) = decode(encoded_value, [_type])

    assert decoded_value >= 0
