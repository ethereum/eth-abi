import pytest

from eth_abi.exceptions import (
    ParseError,
)
from eth_abi.utils.parsing import (
    process_type,
)


@pytest.mark.parametrize(
    'typestr, expected_parse',
    (
        ('uint256', ('uint', '256', [])),
        ('uint', ('uint', '256', [])),
        ('uint256[]', ('uint', '256', [[]])),
        ('uint[]', ('uint', '256', [[]])),
        ('int[2]', ('int', '256', [[2]])),
        ('function', ('bytes', '24', [])),
        ('fixed', ('fixed', '128x18', [])),
        ('ufixed', ('ufixed', '128x18', [])),
    )
)
def test_process_type(typestr, expected_parse):
    assert process_type(typestr) == expected_parse


def test_process_type_requires_string_type():
    with pytest.raises(TypeError):
        process_type(b'uint256')


def test_process_type_requires_basic_type():
    with pytest.raises(ValueError):
        process_type('(int,int)')


@pytest.mark.parametrize(
    'typestr',
    (
        'fixed264x1',
        'fixed9x1',
        'fixed256x81',
        'ufixed264x1',
        'ufixed9x1',
        'ufixed256x81',
    )
)
def test_process_validation_errors(typestr):
    with pytest.raises(ValueError):
        process_type(typestr)


@pytest.mark.parametrize(
    'typestr',
    (
        'fixed0x1',
        'fixed256x0',
        'ufixed0x1',
        'ufixed256x0',
    )
)
def test_process_parsing_errors(typestr):
    with pytest.raises(ParseError):
        process_type(typestr)
