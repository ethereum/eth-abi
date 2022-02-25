from hypothesis import (
    given,
    settings,
)
import pytest

from eth_abi.packed import (
    is_encodable_packed,
)
from tests.common.strategies import (
    single_strs_values,
    tuple_strs_values,
)
from tests.common.unit import (
    CORRECT_SINGLE_ENCODINGS,
    NOT_ENCODABLE,
)


@pytest.mark.parametrize(
    'type_str,python_value,_1,_2,_3',
    CORRECT_SINGLE_ENCODINGS,
)
def test_is_encodable_returns_true(type_str, python_value, _1, _2, _3):
    assert is_encodable_packed(type_str, python_value)


@pytest.mark.parametrize(
    'type_str,python_value',
    NOT_ENCODABLE,
)
def test_is_encodable_returns_false(type_str, python_value):
    assert not is_encodable_packed(type_str, python_value)


@settings(deadline=None)
@given(single_strs_values)
def test_is_encodable_returns_true_for_random_valid_values(type_and_value):
    _type, value = type_and_value
    assert is_encodable_packed(_type, value)


@settings(deadline=None)
@given(tuple_strs_values)
def test_is_encodable_returns_true_for_random_valid_tuple_values(type_and_value):
    _type, value = type_and_value
    assert is_encodable_packed(_type, value)
