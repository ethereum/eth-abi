import re
import ast

from eth_utils import (
    force_text,
)


def process_type(typ):
    if typ == 'function':
        return process_strict_type('bytes24')
    elif typ in ('int', 'uint'):
        return process_strict_type(typ + '256')
    else:
        return process_strict_type(typ)


def process_strict_type(typ):
    # Crazy reg expression to separate out base type component (eg. uint),
    # size (eg. 256, 128x128, none), array component (eg. [], [45], none)
    regexp = '([a-z]*)([0-9]*x?[0-9]*)((\[[0-9]*\])*)'
    base, sub, arr, _ = re.match(regexp, force_text(typ)).groups()
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
