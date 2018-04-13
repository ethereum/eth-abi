import decimal

import pytest

from eth_abi.abi import encode_single

from eth_abi.utils.padding import (
    fpad32,
    zpad32,
)


@pytest.mark.parametrize(
    "_type,value,expected",
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
        # address without 0x prefix
        (
            'address',
            'd3cda913deb6f67967b99d67acdfa1712c293601',
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xd3\xcd\xa9\x13\xde\xb6\xf6yg\xb9\x9dg\xac\xdf\xa1q,)6\x01',
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
def test_encode_single_fixed_length(_type, value, expected):
    actual = encode_single(_type, value)
    assert actual == expected


@pytest.mark.parametrize(
    "_type,value,expected",
    (
        # string
        (
            'string',
            '',
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        (
            'string',
            'a',
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        # bytes
        (
            'bytes',
            b'',
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
        (
            'bytes',
            b'a',
            b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00',
        ),
    ),
)
def test_encode_single_dynamic_length(_type, value, expected):
    actual = encode_single(_type, value)
    assert actual == expected
