import decimal
from typing import (
    Tuple,
)

abi_decimal_context = decimal.Context(prec=999)

ZERO = decimal.Decimal(0)
TEN = decimal.Decimal(10)


def ceil32(x: int) -> int:
    return x if x % 32 == 0 else x + 32 - (x % 32)


def compute_unsigned_integer_bounds(num_bits: int) -> Tuple[int, int]:
    return (
        0,
        2 ** num_bits - 1,
    )


def compute_signed_integer_bounds(num_bits: int) -> Tuple[int, int]:
    return (
        -1 * 2 ** (num_bits - 1),
        2 ** (num_bits - 1) - 1,
    )


def compute_unsigned_fixed_bounds(
    num_bits: int,
    frac_places: int,
) -> Tuple[decimal.Decimal, decimal.Decimal]:
    int_upper = compute_unsigned_integer_bounds(num_bits)[1]

    with decimal.localcontext(abi_decimal_context):
        upper = decimal.Decimal(int_upper) * TEN ** -frac_places

    return ZERO, upper


def compute_signed_fixed_bounds(
    num_bits: int,
    frac_places: int,
) -> Tuple[decimal.Decimal, decimal.Decimal]:
    int_lower, int_upper = compute_signed_integer_bounds(num_bits)

    with decimal.localcontext(abi_decimal_context):
        exp = TEN ** -frac_places
        lower = decimal.Decimal(int_lower) * exp
        upper = decimal.Decimal(int_upper) * exp

    return lower, upper
