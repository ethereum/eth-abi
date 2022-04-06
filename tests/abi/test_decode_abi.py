import pytest

from eth_abi.abi import (
    decode,
    decode_abi,
)
from eth_abi.exceptions import (
    DecodingError,
)
from eth_abi.grammar import (
    parse,
)

from ..common.unit import (
    CORRECT_TUPLE_ENCODINGS,
)


@pytest.mark.parametrize(
    'type_str,expected,abi_encoding,_',
    CORRECT_TUPLE_ENCODINGS,
)
def test_decode_abi(type_str, expected, abi_encoding, _):
    abi_type = parse(type_str)
    if abi_type.arrlist is not None:
        pytest.skip('ABI coding functions do not support array types')

    types = [t.to_type_str() for t in abi_type.components]

    assert decode(types, abi_encoding) == expected

    with pytest.warns(
        DeprecationWarning,
        match=r"abi.decode_abi\(\) is deprecated and will be removed in version 4.0.0 in favor of "
              r"abi.decode\(\)"
    ):
        assert decode_abi(types, abi_encoding) == expected


def test_decode_abi_empty_data_raises():
    with pytest.raises(DecodingError):
        with pytest.warns(
            DeprecationWarning,
            match=r"abi.decode_abi\(\) is deprecated and will be removed in version 4.0.0 in favor "
                  r"of abi.decode\(\)"
        ):
            decode_abi(['uint32', 'uint32'], b'')

    with pytest.raises(DecodingError):
        decode(['uint32', 'uint32'], b'')


def test_decode_abi_wrong_data_type_raises():
    with pytest.raises(TypeError):
        with pytest.warns(
            DeprecationWarning,
            match=r"abi.decode_abi\(\) is deprecated and will be removed in version 4.0.0 in favor "
                  r"of abi.decode\(\)"
        ):
            decode_abi(['uint32', 'uint32'], '')

    with pytest.raises(DecodingError):
        decode(['uint32', 'uint32'], b'')
