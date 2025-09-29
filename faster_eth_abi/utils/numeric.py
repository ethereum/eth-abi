import decimal
from typing import (
    Callable,
    Dict,
    Final,
    Tuple,
)

ABI_DECIMAL_PREC: Final = 999

abi_decimal_context: Final = decimal.Context(prec=ABI_DECIMAL_PREC)
decimal_localcontext: Final = decimal.localcontext

ZERO: Final = decimal.Decimal(0)
TEN: Final = decimal.Decimal(10)

Decimal: Final = decimal.Decimal


def ceil32(x: int) -> int:
    remainder = x % 32
    return x if remainder == 0 else x + 32 - (x % 32)


_unsigned_integer_bounds_cache: Final[Dict[int, Tuple[int, int]]] = {}


def compute_unsigned_integer_bounds(num_bits: int) -> Tuple[int, int]:
    bounds = _unsigned_integer_bounds_cache.get(num_bits)
    if bounds is None:
        bounds = 0, 2**num_bits - 1
        _unsigned_integer_bounds_cache[num_bits] = bounds
    return bounds


_signed_integer_bounds_cache: Final[Dict[int, Tuple[int, int]]] = {}


def compute_signed_integer_bounds(num_bits: int) -> Tuple[int, int]:
    bounds = _signed_integer_bounds_cache.get(num_bits)
    if bounds is None:
        overflow_at = 2 ** (num_bits - 1)
        min_value = -overflow_at
        max_value = overflow_at - 1
        bounds = min_value, max_value
        _signed_integer_bounds_cache[num_bits] = bounds
    return bounds


_unsigned_fixed_bounds_cache: Final[Dict[Tuple[int, int], decimal.Decimal]] = {}


def compute_unsigned_fixed_bounds(
    num_bits: int,
    frac_places: int,
) -> Tuple[decimal.Decimal, decimal.Decimal]:
    upper = _unsigned_fixed_bounds_cache.get((num_bits, frac_places))
    if upper is None:
        int_upper = 2 ** (num_bits - 1) - 1
    
        with decimal_localcontext(abi_decimal_context):
            upper = Decimal(int_upper) * TEN**-frac_places

        _unsigned_fixed_bounds_cache[(num_bits, frac_places)] = upper
        
    return ZERO, upper


_signed_fixed_bounds_cache: Final[Dict[Tuple[int, int], Tuple[decimal.Decimal, decimal.Decimal]]] = {}


def compute_signed_fixed_bounds(
    num_bits: int,
    frac_places: int,
) -> Tuple[decimal.Decimal, decimal.Decimal]:
    bounds = _signed_fixed_bounds_cache.get((num_bits, frac_places))
    if bounds is None:
        int_lower, int_upper = compute_signed_integer_bounds(num_bits)
    
        with decimal_localcontext(abi_decimal_context):
            exp = TEN**-frac_places
            lower = Decimal(int_lower) * exp
            upper = Decimal(int_upper) * exp

        bounds = lower, upper
        _signed_fixed_bounds_cache[(num_bits, frac_places)] = bounds

    return bounds


def scale_places(places: int) -> Callable[[decimal.Decimal], decimal.Decimal]:
    """
    Returns a function that shifts the decimal point of decimal values to the
    right by ``places`` places.
    """
    if not isinstance(places, int):
        raise ValueError(
            f"Argument `places` must be int.  Got value {places} "
            f"of type {type(places)}.",
        )

    with decimal_localcontext(abi_decimal_context):
        scaling_factor = TEN**-places

    def f(x: decimal.Decimal) -> decimal.Decimal:
        with decimal_localcontext(abi_decimal_context):
            return x * scaling_factor

    places_repr = f"Eneg{places}" if places > 0 else f"Epos{-places}"
    func_name = f"scale_by_{places_repr}"

    f.__name__ = func_name
    f.__qualname__ = func_name

    return f
