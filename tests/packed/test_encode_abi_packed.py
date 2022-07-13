import pytest

from eth_abi.grammar import (
    parse,
)
from eth_abi.packed import (
    encode_abi_packed,
    encode_packed,
)
from tests.common.unit import (
    CORRECT_TUPLE_ENCODINGS,
)


@pytest.mark.parametrize(
    "type_str,python_value,_,packed_encoding",
    CORRECT_TUPLE_ENCODINGS,
)
def test_encode_abi_packed(type_str, python_value, _, packed_encoding):
    abi_type = parse(type_str)
    if abi_type.arrlist is not None:
        pytest.skip("ABI coding functions do not support array types")

    types = [t.to_type_str() for t in abi_type.components]

    assert encode_packed(types, python_value) == packed_encoding

    with pytest.warns(
        DeprecationWarning,
        match=r"abi.encode_abi\(\) and abi.encode_abi_packed\(\) are deprecated and will be "
        r"removed in version 4.0.0 in favor of abi.encode\(\) and abi.encode_packed\(\), "
        r"respectively",
    ):
        assert encode_abi_packed(types, python_value) == packed_encoding
