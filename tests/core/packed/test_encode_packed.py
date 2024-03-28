import pytest

from eth_abi.grammar import (
    parse,
)
from eth_abi.packed import (
    encode_packed,
)
from tests.core.common.unit import (
    CORRECT_ENCODINGS,
    CORRECT_TUPLE_ENCODINGS,
)


@pytest.mark.parametrize(
    "single_abi_type,python_value,_,packed_encoding",
    CORRECT_TUPLE_ENCODINGS,
)
def test_encode_packed(single_abi_type, python_value, _, packed_encoding):
    abi_type = parse(single_abi_type)
    if abi_type.arrlist is not None:
        pytest.skip("ABI coding functions do not support array types")

    types = [t.to_type_str() for t in abi_type.components]

    actual = encode_packed(types, python_value)
    assert actual == packed_encoding


@pytest.mark.parametrize(
    "single_abi_type,python_value,_,packed_encoding",
    CORRECT_ENCODINGS,
)
def test_encode_packed_single_types(single_abi_type, python_value, _, packed_encoding):
    actual = encode_packed([single_abi_type], [python_value])
    assert actual == packed_encoding
