import pytest

from rlp.utils import (
    decode_hex,
)

from eth_abi.abi import decode_single


@pytest.mark.parametrize(
    'input,expected',
    (
        ('0000000000000000000000000000000000000000000000000000000000000015', 21),
        ('0000000000000000000000000000000000000000000000000000000000000001', 1),
        ('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff', -1),
        ('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c', -100),
    )
)
def test_0x_prefix_optional(input, expected):
    output = decode_single('int256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        ('0x0000000000000000000000000000000000000000000000000000000000000015', 21),
        ('0x0000000000000000000000000000000000000000000000000000000000000001', 1),
        ('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff', -1),
        ('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c', -100),
    )
)
def test_decode_int256(input, expected):
    output = decode_single('int256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        ('0000000000000000000000000000000000000000000000000000000000000015', 21),
        ('0000000000000000000000000000000000000000000000000000000000000001', 1),
        ('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff', -1),
        ('ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c', -100),
    )
)
def test_decode_accepts_bytes(input, expected):
    output = decode_single('int256', decode_hex(input))
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        ('0x0000000000000000000000000000000000000000000000000000000000000015', 21),
        ('0x0000000000000000000000000000000000000000000000000000000000000001', 1),
        ('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff', 2 ** 256 - 1),
        ('0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff9c', 2 ** 256 -100),
    )
)
def test_decode_uint256(input, expected):
    output = decode_single('uint256', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        ('0x0000000000000000000000000000000000000000000000000000000000000001', True),
        ('0x0000000000000000000000000000000000000000000000000000000000000000', False),
    )
)
def test_decode_bool(input, expected):
    output = decode_single('bool', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        ('0x0000000000000000000000000000000220000000000000000000000000000000', 2.125),
        ('0x0000000000000000000000000000000880000000000000000000000000000000', 8.5),
        ('0xfffffffffffffffffffffffffffffffee0000000000000000000000000000000', -1.125),
        ('0x0000000000000000000000000000000120000000000000000000000000000000', 1.125),
    )
)
def test_decode_fixed(input, expected):
    output = decode_single('fixed128x128', input)
    assert output == expected


@pytest.mark.parametrize(
    'input,expected',
    (
        (
            '0x7465737400000000000000000000000000000000000000000000000000000000',
            b'test\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        (
            '0x6162636465666768696a6b6c6d6e6f707172737475767778797a000000000000',
            b'abcdefghijklmnopqrstuvwxyz\x00\x00\x00\x00\x00\x00',
        ),
        (
            '0x3031323334353637383921402324255e262a2829000000000000000000000000',
            b'0123456789!@#$%^&*()\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        (
            '0x6162630000000000616263000000000000000000000000000000000000000000',
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
            '0x0000000000000000000000000000000000000000000000000000000000000000',
            b'0000000000000000000000000000000000000000',
        ),
        (
            '0x000000000000000000000000c305c901078781c232a2a521c2af7980f8385ee9',
            b'c305c901078781c232a2a521c2af7980f8385ee9',
        ),
        (
            '0x0000000000000000000000000005c901078781c232a2a521c2af7980f8385ee9',
            b'0005c901078781c232a2a521c2af7980f8385ee9',
        ),
        (
            '0x000000000000000000000000c305c901078781c232a2a521c2af7980f8385000',
            b'c305c901078781c232a2a521c2af7980f8385000',
        ),
        (
            '0x0000000000000000000000000005c901078781c232a2a521c2af7980f8385000',
            b'0005c901078781c232a2a521c2af7980f8385000',
        ),
    )
)
def test_decode_address(input, expected):
    output = decode_single('address', input)
    assert output == expected
