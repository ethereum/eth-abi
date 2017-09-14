
import pytest

from eth_abi.utils.parsing import (
    process_type,
)


@pytest.mark.parametrize(
    'typestr, expected_parse',
    (
        ('uint256', ('uint', '256', [])),
        ('uint', ('uint', '256', [])),
        ('function', ('bytes', '24', [])),
    )
)
def test_process_type(typestr, expected_parse):
    assert process_type(typestr) == expected_parse
