import pytest

from eth_abi import (
    encode_abi_packed,
)
from eth_abi.grammar import (
    parse,
)

from ..common.unit import (
    CORRECT_TUPLE_ENCODINGS,
)


@pytest.mark.parametrize(
    'type_str,python_value,_,packed_encoding',
    CORRECT_TUPLE_ENCODINGS,
)
def test_encode_abi(type_str, python_value, _, packed_encoding):
    abi_type = parse(type_str)
    types = [str(t) for t in abi_type.components]

    actual = encode_abi_packed(types, python_value)
    assert actual == packed_encoding
