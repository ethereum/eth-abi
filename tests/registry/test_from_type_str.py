import re

import pytest

from eth_abi import encoding


def test_parse_type_str_gives_correct_encoder():
    uint_encoder = encoding.UnsignedIntegerEncoder.from_type_str('uint', None)
    uint128_encoder = encoding.UnsignedIntegerEncoder.from_type_str('uint128', None)
    function_encoder = encoding.BytesEncoder.from_type_str('function', None)

    # Correct kind of encoder was created
    assert isinstance(uint_encoder, encoding.UnsignedIntegerEncoder)
    assert isinstance(uint128_encoder, encoding.UnsignedIntegerEncoder)
    assert isinstance(function_encoder, encoding.BytesEncoder)

    # Type string was normalized
    assert type(uint_encoder).value_bit_size == 256
    assert type(function_encoder).value_bit_size == 192


@pytest.mark.parametrize(
    'bad_type_str, pattern',
    (
        (
            '(uint,bytes1)',
            'Cannot create UnsignedIntegerEncoder for non-basic '
            "type '(uint,bytes1)' (normalized to '(uint256,bytes1)')",
        ),
        (
            'bytes1',
            "Cannot create UnsignedIntegerEncoder for type 'bytes1': "
            "expected type with base 'uint'",
        ),
        (
            'uint[]',
            "Cannot create UnsignedIntegerEncoder for type 'uint[]' "
            "(normalized to 'uint256[]'): "
            'expected type with no array dimension list',
        ),
        (
            'uint101',
            'integer size must be multiple of 8',
        ),
    )
)
def test_parse_type_str_fails_correctly(bad_type_str, pattern):
    with pytest.raises(ValueError, match=re.escape(pattern)):
        encoding.UnsignedIntegerEncoder.from_type_str(bad_type_str, None)
