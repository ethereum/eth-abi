from decimal import Decimal

from hypothesis import (
    given,
    settings,
)
import pytest

from eth_utils import decode_hex

from eth_abi import is_encodable

from tests.common.strategies import (
    single_strs_values,
    tuple_strs_values,
)
from tests.common.unit import CORRECT_SINGLE_ENCODINGS


@pytest.mark.parametrize(
    'type_str,python_value,_',
    CORRECT_SINGLE_ENCODINGS,
)
def test_is_encodable_returns_true(type_str, python_value, _):
    assert is_encodable(type_str, python_value)


@pytest.mark.parametrize(
    'type_str,python_value',
    (
        # Wrong value type
        ('((bytes,bool),(bytes,bool))', ((b'david attenborough', 0), (b'boaty mcboatface', True))),
        ('(uint32)', ('6',)),
        ('int[]', 6),
        ('bool[2]', (True, 2)),
        ('bool', 1),
        ('uint', True),
        ('int', True),
        ('bytes', 129),
        ('fixed8x1', 0.1),  # only Decimal and int are allowed

        # List size mismatch
        ('int[3]', (6, 2)),

        # Bytes string is wrong size
        ('bytes5', b'asdfgt'),

        # Addresses aren't 20 bytes long
        ('address', '0x8deebe59332ebc3f81935e311f0fb8556cf573'),
        ('address', decode_hex('0x8deebe59332ebc3f81935e311f0fb8556cf573')),

        # Values out of bounds
        ('uint8', 256),
        ('uint8', -1),
        ('int8', 128),
        ('int8', -129),
        ('string', -129),
        ('fixed8x1', Decimal('128e-1')),
        ('fixed8x1', Decimal('-129e-1')),
        ('ufixed8x1', Decimal('256e-1')),
        ('ufixed8x1', Decimal('-1e-1')),
        ('fixed8x1', Decimal('1e-2')),

    )
)
def test_is_encodable_returns_false(type_str, python_value):
    assert not is_encodable(type_str, python_value)


@settings(deadline=None)
@given(single_strs_values)
def test_is_encodable_returns_true_for_random_valid_values(type_and_value):
    _type, value = type_and_value
    assert is_encodable(_type, value)


@settings(deadline=None)
@given(tuple_strs_values)
def test_is_encodable_returns_true_for_random_valid_tuple_values(type_and_value):
    _type, value = type_and_value
    assert is_encodable(_type, value)
