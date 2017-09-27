import ast
import re
import string

from eth_utils import (
    coerce_args_to_text,
)

DEFAULT_LENGTHS = (
    ('int', '256'),
    ('uint', '256'),
    ('fixed', '128x19'),
    ('ufixed', '128x19'),
)


@coerce_args_to_text
def process_type(raw_type):
    typ = normalize_type(raw_type)
    return process_strict_type(typ)


def collapse_type(base, sub, arrlist):
    return str(base + sub + ''.join(map(repr, arrlist)))


def normalize_type(raw_type):
    if raw_type == 'function':
        return 'bytes24'
    elif is_missing_length(raw_type):
        return type_with_default_length(raw_type)
    else:
        return raw_type


def process_strict_type(typ):
    # Crazy reg expression to separate out base type component (eg. uint),
    # size (eg. 256, 128x128, none), array component (eg. [], [45], none)
    regexp = '([a-z]*)([0-9]*x?[0-9]*)((\[[0-9]*\])*)'
    base, sub, arr, _ = re.match(regexp, typ).groups()
    arrlist = re.findall('\[[0-9]*\]', arr)
    if len(''.join(arrlist)) != len(arr):
        raise ValueError("Unknown characters found in array declaration")
    # Check validity of string type
    if base == 'string' or base == 'bytes':
        if not re.match('^[0-9]*$', sub):
            raise ValueError("String type must have no suffix or numerical suffix")
        if sub and int(sub) > 32:
            raise ValueError("Maximum 32 bytes for fixed-length str or bytes")
    # Check validity of integer type
    elif base == 'uint' or base == 'int':
        if not re.match('^[0-9]+$', sub):
            raise ValueError("Integer type must have numerical suffix")
        if 8 > int(sub) or int(sub) > 256:
            raise ValueError("Integer size out of bounds")
        if int(sub) % 8 != 0:
            raise ValueError("Integer size must be multiple of 8")
    # Check validity of fixed type
    elif base == 'ufixed' or base == 'fixed':
        if not re.match('^[0-9]+x[0-9]+$', sub):
            raise ValueError("Fixed type must have suffix of form <high>x<low>, eg. 128x128")
        bits, minus_e = [int(x) for x in sub.split('x')]
        if bits % 8 != 0:
            raise ValueError("Fixed size must be multiple of 8")
        if bits < 8 or bits > 256:
            raise ValueError("Fixed size out of bounds (max 256 bits)")
        if minus_e < 1 or minus_e > 80:
            raise ValueError("Fixed size exponent is out of bounds, %s must be in 1-80" % minus_e)
    # Check validity of real type
    elif base == 'ureal' or base == 'real':
        if not re.match('^[0-9]+x[0-9]+$', sub):
            raise ValueError("Real type must have suffix of form <high>x<low>, eg. 128x128")
        high, low = [int(x) for x in sub.split('x')]
        if 8 > (high + low) or (high + low) > 256:
            raise ValueError("Real size out of bounds (max 32 bytes)")
        if high % 8 != 0 or low % 8 != 0:
            raise ValueError("Real high/low sizes must be multiples of 8")
    # Check validity of hash type
    elif base == 'hash':
        if not re.match('^[0-9]+$', sub):
            raise ValueError("Hash type must have numerical suffix")
    # Check validity of address type
    elif base == 'address':
        if sub != '':
            raise ValueError("Address cannot have suffix")
    return base, sub, [ast.literal_eval(x) for x in arrlist]


def is_missing_length(raw_type):
    default_base, default_length = find_matching_default(raw_type)
    if default_base:
        raw_rest = raw_type[len(default_base):]
        return not raw_rest or raw_rest[0] not in string.digits
    else:
        return False


def type_with_default_length(raw_type):
    default_base, default_length = find_matching_default(raw_type)
    if default_base:
        return default_base + default_length + raw_type[len(default_base):]
    else:
        raise ValueError("Type %s has no default length" % raw_type)


def find_matching_default(raw_type):
    for test_base, default_length in DEFAULT_LENGTHS:
        if raw_type.startswith(test_base):
            return (test_base, default_length)
    return (None, None)
