import pytest

from eth_utils import (
    decode_hex,
)

from eth_abi.abi import decode_abi
from eth_abi.exceptions import (
    DecodingError,
)


@pytest.mark.parametrize(
    'input,expected',
    (
        (
            decode_hex('0x00000000000000000000000000000000000000000000000000000000000000060000000000000000000000000000000000000000000000000000000000000001'),
            (6, 1),
        ),
        (
            decode_hex('0x00000000000000000000000000000000000000000000000000000000ffffffff00000000000000000000000000000000000000000000000000000000ffffffff'),
            (2**32-1, 2**32-1),
        ),
    )
)
def test_decode_two_uint32(input, expected):
    output = decode_abi(['uint32', 'uint32'], input)
    assert output == expected


def test_empty_data_raises():
    with pytest.raises(DecodingError):
        decode_abi(['uint32', 'uint32'], b'')


def test_decode_various():
    data = decode_hex(
        '0x00000000000000000000000082a978b3f5962a5b0957d9ee9eef472ee55b42f10000000000000'
        '0000000000000000000000000000000000000000000000000017374757069642070696e6b20616e69'
        '6d616c000000000000000000000000000000000000000000000000000000000000000000000000000'
        '00000000000000000'
    )

    expected = (
        '0x82a978b3f5962a5b0957d9ee9eef472ee55b42f1',
        1,
        b'stupid pink animal\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        0,
    )
    output = decode_abi(['address', 'uint32', 'bytes32', 'int32'], data)
    assert output == expected


@pytest.mark.parametrize(
    'types,data,expected',
    (
        (
            ('uint256', 'bytes'),
            decode_hex(
                '0x'
                '0000000000000000000000000000000000000000000000000000000000000000'
                '0000000000000000000000000000000000000000000000000000000000000040'
                '0000000000000000000000000000000000000000000000000000000000000000'
                '0000000000000000000000000000000000000000000000000000000000000000'
            ),
            (0, b''),
        ),
    ),
)
def test_decode_uint256_and_bytes(types, data, expected):
    actual = decode_abi(types, data)
    assert actual == expected
