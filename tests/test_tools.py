from hypothesis import (
    example,
    given,
    settings,
    strategies as st,
)
import pytest

from eth_abi.exceptions import (
    NoEntriesFound,
    ParseError,
)
from eth_abi.tools import (
    get_abi_strategy,
)

from .common.strategies import (
    malformed_type_strs,
    type_strs,
)


@given(type_strs)
@settings(deadline=None)
def test_get_abi_strategy_returns_strategy_for_valid_type_strs(type_str):
    assert isinstance(get_abi_strategy(type_str), st.SearchStrategy)


@given(malformed_type_strs)
@example("address20")
def test_get_abi_strategy_returns_no_strategy_for_invalid_type_strs(malformed_type_str):
    try:
        get_abi_strategy(malformed_type_str)
    except (ParseError, NoEntriesFound, ValueError):
        pass
    else:
        assert False, "Expected ParseError or NoEntriesFound"


@pytest.mark.parametrize(
    "type_str,strategy_repr",
    (
        ("uint8", "integers(min_value=0, max_value=255)"),
        ("uint16", "integers(min_value=0, max_value=65535)"),
        (
            "uint",
            "integers(min_value=0, max_value=115792089237316195423570985008687907853269984665640564039457584007913129639935)",  # noqa: E501
        ),
        (
            "uint256",
            "integers(min_value=0, max_value=115792089237316195423570985008687907853269984665640564039457584007913129639935)",  # noqa: E501
        ),
        ("int8", "integers(min_value=-128, max_value=127)"),
        ("int16", "integers(min_value=-32768, max_value=32767)"),
        (
            "int",
            "integers(min_value=-57896044618658097711785492504343953926634992332820282019728792003956564819968, max_value=57896044618658097711785492504343953926634992332820282019728792003956564819967)",  # noqa: E501
        ),
        (
            "int256",
            "integers(min_value=-57896044618658097711785492504343953926634992332820282019728792003956564819968, max_value=57896044618658097711785492504343953926634992332820282019728792003956564819967)",  # noqa: E501
        ),
        ("address", "binary(min_size=20, max_size=20).map(to_checksum_address)"),
        ("bool", "booleans()"),
        (
            "ufixed8x10",
            "decimals(min_value=0, max_value=255, places=0).map(scale_by_Eneg10)",
        ),
        (
            "ufixed16x11",
            "decimals(min_value=0, max_value=65535, places=0).map(scale_by_Eneg11)",
        ),
        (
            "ufixed",
            "decimals(min_value=0, max_value=340282366920938463463374607431768211455, places=0).map(scale_by_Eneg18)",  # noqa: E501
        ),
        (
            "ufixed128x18",
            "decimals(min_value=0, max_value=340282366920938463463374607431768211455, places=0).map(scale_by_Eneg18)",  # noqa: E501
        ),
        (
            "fixed8x8",
            "decimals(min_value=-128, max_value=127, places=0).map(scale_by_Eneg8)",
        ),
        (
            "fixed16x7",
            "decimals(min_value=-32768, max_value=32767, places=0).map(scale_by_Eneg7)",
        ),
        (
            "fixed",
            "decimals(min_value=-170141183460469231731687303715884105728, max_value=170141183460469231731687303715884105727, places=0).map(scale_by_Eneg18)",  # noqa: E501
        ),
        (
            "fixed128x18",
            "decimals(min_value=-170141183460469231731687303715884105728, max_value=170141183460469231731687303715884105727, places=0).map(scale_by_Eneg18)",  # noqa: E501
        ),
        ("bytes2", "binary(min_size=2, max_size=2)"),
        ("bytes", "binary(max_size=4096)"),
        ("function", "binary(min_size=24, max_size=24)"),
        ("string", "text()"),
        ("bool[]", "lists(elements=booleans())"),
        ("bool[3]", "lists(elements=booleans(), min_size=3, max_size=3)"),
        (
            "bool[3][]",
            "lists(elements=lists(elements=booleans(), min_size=3, max_size=3))",
        ),
        ("(bool,int8)", "tuples(booleans(), integers(min_value=-128, max_value=127))"),
        (
            "(bool,(uint8,int8))",
            "tuples(booleans(), tuples(integers(min_value=0, max_value=255), integers(min_value=-128, max_value=127)))",  # noqa: E501
        ),
        ("(bool,bool)[]", "lists(elements=tuples(booleans(), booleans()))"),
    ),
)
def test_get_abi_strategy_returns_certain_strategies_for_known_type_strings(
    type_str, strategy_repr
):
    assert repr(get_abi_strategy(type_str)) == strategy_repr
