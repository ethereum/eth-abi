import decimal

import pytest

from eth_utils import (
    decode_hex,
)

from eth_abi.abi import decode_single

from eth_abi.utils.padding import (
    fpad32,
    zpad32,
)


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


@pytest.mark.parametrize(
    "_type,expected,value",
    (
        # expanded type
        (
            ('uint', '256', []),
            2 ** 256 - 1,
            b'\xff' * 32,
        ),
        # unexpanded type
        (
            'uint256',
            2 ** 256 - 1,
            b'\xff' * 32,
        ),
        # address 0x prefixed
        (
            'address',
            '0xd3cda913deb6f67967b99d67acdfa1712c293601',
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xd3\xcd\xa9\x13\xde\xb6\xf6yg\xb9\x9dg\xac\xdf\xa1q,)6\x01',
        ),
        # unsigned integer
        (
            'uint256',
            12345,
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009',
        ),
        # signed integer positive
        (
            'int256',
            12345,
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009',
        ),
        # signed integer negative
        (
            'int256',
            -12345,
            b'\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xcf\xc7',
        ),
        # signed integer negative
        (
            'int8',
            -1,
            b'\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff',
        ),
        # boolean true
        (
            'bool',
            True,
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01',
        ),
        # boolean false
        (
            'bool',
            False,
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        # fixed values
        ('fixed8x1', decimal.Decimal('127e-1'), zpad32(b'\x7f')),
        ('fixed8x1', decimal.Decimal('1e-1'), zpad32(b'\x01')),
        ('fixed8x1', decimal.Decimal('0'), zpad32(b'\x00')),
        ('fixed8x1', decimal.Decimal('-1e-1'), fpad32(b'\xff')),
        ('fixed8x1', decimal.Decimal('-128e-1'), fpad32(b'\x80')),

        ('fixed128x19', decimal.Decimal('127e-19'), zpad32(b'\x7f')),
        ('fixed128x19', decimal.Decimal('1e-19'), zpad32(b'\x01')),
        ('fixed128x19', decimal.Decimal('0'), zpad32(b'\x00')),
        ('fixed128x19', decimal.Decimal('-1e-19'), fpad32(b'\xff')),
        ('fixed128x19', decimal.Decimal('-128e-19'), fpad32(b'\x80')),

        ('fixed256x80', decimal.Decimal('127e-80'), zpad32(b'\x7f')),
        ('fixed256x80', decimal.Decimal('1e-80'), zpad32(b'\x01')),
        ('fixed256x80', decimal.Decimal('0'), zpad32(b'\x00')),
        ('fixed256x80', decimal.Decimal('-1e-80'), fpad32(b'\xff')),
        ('fixed256x80', decimal.Decimal('-128e-80'), fpad32(b'\x80')),

        ('ufixed8x1', decimal.Decimal('255e-1'), zpad32(b'\xff')),
        ('ufixed8x1', decimal.Decimal('254e-1'), zpad32(b'\xfe')),
        ('ufixed8x1', decimal.Decimal('1e-1'), zpad32(b'\x01')),
        ('ufixed8x1', decimal.Decimal('0'), zpad32(b'\x00')),

        ('ufixed128x19', decimal.Decimal('255e-19'), zpad32(b'\xff')),
        ('ufixed128x19', decimal.Decimal('254e-19'), zpad32(b'\xfe')),
        ('ufixed128x19', decimal.Decimal('1e-19'), zpad32(b'\x01')),
        ('ufixed128x19', decimal.Decimal('0'), zpad32(b'\x00')),

        ('ufixed256x80', decimal.Decimal('255e-80'), zpad32(b'\xff')),
        ('ufixed256x80', decimal.Decimal('254e-80'), zpad32(b'\xfe')),
        ('ufixed256x80', decimal.Decimal('1e-80'), zpad32(b'\x01')),
        ('ufixed256x80', decimal.Decimal('0'), zpad32(b'\x00')),
    )
)
def test_decode_single_fixed_length(_type, expected, value):
    actual = decode_single(_type, value)
    assert actual == expected
