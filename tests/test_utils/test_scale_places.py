import decimal
import itertools
from typing import (
    Iterable,
    Iterator,
    TypeVar,
)

from hypothesis import (
    given,
    strategies as st,
)

from eth_abi.utils.numeric import (
    ABI_DECIMAL_PREC,
    scale_places,
)


T = TypeVar('T')


def take(n: int, it: Iterable[T]) -> Iterator[T]:
    """
    Returns an iterator that takes ``n`` items from the iterable ``it``.
    """
    yield from (i for _, i in zip(range(n), it))


def get_test_value(prec: int, frac_places: int) -> decimal.Decimal:
    """
    Returns a test decimal value with ``prec`` total significant figures and
    ``frac_places`` fractional places.
    """
    digits = itertools.cycle(map(str, range(1, 10)))
    decimal_repr = ''.join(take(prec, digits))

    if frac_places <= 0:
        # Add zeroes to right side of repr
        return decimal.Decimal(decimal_repr + '0' * -frac_places)
    elif frac_places > prec:
        # Add zeroes to left side of repr
        extra_frac_places = frac_places - prec
        return decimal.Decimal('.' + '0' * extra_frac_places + decimal_repr)
    else:
        # Split repr according to frac places
        whole_places = prec - frac_places
        return decimal.Decimal(decimal_repr[:whole_places] + '.' + decimal_repr[-frac_places:])


@given(st.integers(min_value=1, max_value=ABI_DECIMAL_PREC))
def test_scale_places_pos(size):
    scaled_by_string = get_test_value(size, size)

    dec_value = get_test_value(size, 0)
    scaled_by_math = scale_places(size)(dec_value)

    assert scaled_by_string == scaled_by_math


@given(st.integers(min_value=1, max_value=ABI_DECIMAL_PREC))
def test_scale_places_neg(size):
    scaled_by_string = get_test_value(size, -size)

    dec_value = get_test_value(size, 0)
    scaled_by_math = scale_places(-size)(dec_value)

    assert scaled_by_string == scaled_by_math
