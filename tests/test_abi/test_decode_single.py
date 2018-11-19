import pytest

from eth_abi.abi import (
    encoder as default_encoder,
)

from ..common.unit import (
    CORRECT_SINGLE_ENCODINGS,
)


@pytest.mark.parametrize(
    'typ,expected,abi_encoding,_',
    CORRECT_SINGLE_ENCODINGS,
)
def test_decode_single(typ, expected, abi_encoding, _):
    actual = default_encoder.decode_single(typ, abi_encoding)
    assert actual == expected


def test_decode_single_wrong_data_type_raises():
    with pytest.raises(TypeError):
        default_encoder.decode_single('uint32', '')
