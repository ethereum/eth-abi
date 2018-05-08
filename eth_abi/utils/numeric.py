import math
import decimal


abi_decimal_context = decimal.Context(prec=999)

ZERO = decimal.Decimal(0)
TEN = decimal.Decimal(10)


def ceil32(x):
    return x if x % 32 == 0 else x + 32 - (x % 32)


def compute_unsigned_integer_bounds(num_bits):
    return (
        0,
        2 ** num_bits - 1,
    )


def compute_signed_integer_bounds(num_bits):
    return (
        -1 * 2 ** (num_bits - 1),
        2 ** (num_bits - 1) - 1,
    )


def compute_unsigned_fixed_bounds(num_bits, frac_places):
    int_upper = compute_unsigned_integer_bounds(num_bits)[1]

    with decimal.localcontext(abi_decimal_context):
        upper = decimal.Decimal(int_upper) * TEN ** -frac_places

    return ZERO, upper


def compute_signed_fixed_bounds(num_bits, frac_places):
    int_lower, int_upper = compute_signed_integer_bounds(num_bits)

    with decimal.localcontext(abi_decimal_context):
        exp = TEN ** -frac_places
        lower = decimal.Decimal(int_lower) * exp
        upper = decimal.Decimal(int_upper) * exp

    return lower, upper


def compute_unsigned_real_bounds(num_high_bits, num_low_bits):
    integer_lower_bound, integer_upper_bount = compute_unsigned_integer_bounds(
        num_high_bits,
    )
    return (
        integer_lower_bound * 1.0 / 2 ** num_low_bits,
        integer_upper_bount * 1.0 / 2 ** num_low_bits,
    )


def compute_signed_real_bounds(num_high_bits, num_low_bits):
    integer_lower_bound, integer_upper_bount = compute_signed_integer_bounds(
        num_high_bits,
    )
    return (
        integer_lower_bound * 1.0 / 2 ** num_low_bits,
        integer_upper_bount * 1.0 / 2 ** num_low_bits,
    )


def quantize_value(value, decimal_bit_size):
    num_decimals = int(math.ceil(math.log10(2 ** decimal_bit_size)))
    with decimal.localcontext(abi_decimal_context):
        if num_decimals == 0:
            quantize_value = decimal.Decimal('1')
        else:
            quantize_value = decimal.Decimal('1.{0}'.format(''.zfill(num_decimals)))
        decimal_value = decimal.Decimal(value)
        return decimal_value.quantize(quantize_value)
