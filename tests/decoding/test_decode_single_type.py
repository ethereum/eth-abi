import pytest

from eth_utils import (
    decode_hex,
)

from eth_abi.abi import decode_single


@pytest.mark.parametrize(
    'input,expected',
    (
        (decode_hex('0000000000000000000000000000000000000000000000000000000000000015'), 21),
        (decode_hex('0000000000000000000000000000000000000000000000000000000000000001'), 1),
        (decode_hex('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'), -1),
        (decode_hex('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c'), -100),
    )
)
def test_0x_prefix_optional(input, expected):
    output = decode_single('int256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (decode_hex('0000000000000000000000000000000000000000000000000000000000000015'), 21),
        (decode_hex('0000000000000000000000000000000000000000000000000000000000000001'), 1),
        (decode_hex('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'), -1),
        (decode_hex('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c'), -100),
    )
)
def test_int8_decoding(input, expected):
    output = decode_single('int8', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (decode_hex('0x0000000000000000000000000000000000000000000000000000000000000015'), 21),
        (decode_hex('0x0000000000000000000000000000000000000000000000000000000000000001'), 1),
        (decode_hex('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'), -1),
        (decode_hex('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c'), -100),
    )
)
def test_decode_int256(input, expected):
    output = decode_single('int256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (decode_hex('0000000000000000000000000000000000000000000000000000000000000015'), 21),
        (decode_hex('0000000000000000000000000000000000000000000000000000000000000001'), 1),
        (decode_hex('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'), -1),
        (decode_hex('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c'), -100),
    )
)
def test_decode_accepts_bytes(input, expected):
    output = decode_single('int256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (decode_hex('0x0000000000000000000000000000000000000000000000000000000000000015'), 21),
        (decode_hex('0x0000000000000000000000000000000000000000000000000000000000000001'), 1),
        (
            decode_hex('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'),
            2 ** 256 - 1,
        ),
        (
            decode_hex('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c'),
            2 ** 256 -100,
        ),
    )
)
def test_decode_uint256(input, expected):
    output = decode_single('uint256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (decode_hex('0x0000000000000000000000000000000000000000000000000000000000000001'), True),
        (decode_hex('0x0000000000000000000000000000000000000000000000000000000000000000'), False),
    )
)
def test_decode_bool(input, expected):
    output = decode_single('bool', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (
            decode_hex('0x7465737400000000000000000000000000000000000000000000000000000000'),
            b'test\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        (
            decode_hex('0x6162636465666768696a6b6c6d6e6f707172737475767778797a000000000000'),
            b'abcdefghijklmnopqrstuvwxyz\x00\x00\x00\x00\x00\x00',
        ),
        (
            decode_hex('0x3031323334353637383921402324255e262a2829000000000000000000000000'),
            b'0123456789!@#$%^&*()\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        (
            decode_hex('0x6162630000000000616263000000000000000000000000000000000000000000'),
            b'abc\x00\x00\x00\x00\x00abc\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
    )
)
def test_decode_bytes32(input, expected):
    output = decode_single('bytes32', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (
            decode_hex('0x0000000000000000000000000000000000000000000000000000000000000000'),
            '0x0000000000000000000000000000000000000000',
        ),
        (
            decode_hex('0x000000000000000000000000c305c901078781c232a2a521c2af7980f8385ee9'),
            '0xc305c901078781c232a2a521c2af7980f8385ee9',
        ),
        (
            decode_hex('0x0000000000000000000000000005c901078781c232a2a521c2af7980f8385ee9'),
            '0x0005c901078781c232a2a521c2af7980f8385ee9',
        ),
        (
            decode_hex('0x000000000000000000000000c305c901078781c232a2a521c2af7980f8385000'),
            '0xc305c901078781c232a2a521c2af7980f8385000',
        ),
        (
            decode_hex('0x0000000000000000000000000005c901078781c232a2a521c2af7980f8385000'),
            '0x0005c901078781c232a2a521c2af7980f8385000',
        ),
    )
)
def test_decode_address(input, expected):
    output = decode_single('address', input)
    assert output == expected
