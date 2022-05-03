import pytest

from eth_abi.packed import (
    encode_packed,
    encode_single_packed,
)
from tests.common.unit import (
    CORRECT_SINGLE_ENCODINGS,
)


@pytest.mark.parametrize(
    'typ,python_value,_,packed_encoding',
    CORRECT_SINGLE_ENCODINGS,
)
def test_encode_single(typ, python_value, _, packed_encoding):
    assert encode_packed([typ], [python_value]) == packed_encoding

    with pytest.warns(
        DeprecationWarning,
        match=r"abi.encode_single\(\) and abi.encode_single_packed\(\) are deprecated and will be "
              r"removed in version 4.0.0 in favor of abi.encode\(\) and abi.encode_packed\(\), "
              r"respectively",
    ):
        assert encode_single_packed(typ, python_value) == packed_encoding
