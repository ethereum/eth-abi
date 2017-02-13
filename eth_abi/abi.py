"""
Vendored from `pyethereum.abi`
"""
import re
import ast
import warnings

from io import BytesIO

from eth_utils import (
    is_text,
    force_text,
    force_bytes,
    remove_0x_prefix,
    decode_hex,
)

from eth_abi.decoding import (
    get_single_decoder,
    get_multi_decoder,
)
from eth_abi.encoding import (
    get_single_encoder,
    get_multi_encoder,
)


def process_type(typ):
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


def encode_single(typ, arg):
    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    if is_text(arg):
        arg = force_bytes(arg)

    encoder = get_single_encoder(base, sub, arrlist)
    return encoder(arg)


def encode_abi(types, args):
    processed_types = [process_type(typ) for typ in types]
    encoder = get_multi_encoder(processed_types)
    return encoder(args)


HEX_CHARS = b'1234567890abcdef'


def is_hex_encoded_value(v):
    if not remove_0x_prefix(force_bytes(v)).lower().strip(HEX_CHARS) == b'':
        return False
    if len(remove_0x_prefix(v)) % 64 and len(remove_0x_prefix(v)) % 40:
        return False
    return True


# Decodes a single base datum
def decode_single(typ, data):
    if is_hex_encoded_value(data):
        warnings.warn(DeprecationWarning(
            "Automatic inference of hex encoded data has been deprecated. "
            "Please adjust your code to ensure that the data argument for "
            "`decode_single` is a byte string"
        ))
        data = decode_hex(remove_0x_prefix(data))

    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    decoder = get_single_decoder(base, sub, arrlist)
    stream = BytesIO(force_bytes(data))
    return decoder(stream)


# Decodes multiple arguments using the head/tail mechanism
def decode_abi(types, data):
    if is_hex_encoded_value(data):
        warnings.warn(DeprecationWarning(
            "Automatic inference of hex encoded data has been deprecated. "
            "Please adjust your code to ensure that the data argument for "
            "`decode_single` is a byte string"
        ))
        data = decode_hex(remove_0x_prefix(data))

    processed_types = tuple(process_type(_type) for _type in types)
    decoder = get_multi_decoder(processed_types)
    stream = BytesIO(force_bytes(data))
    return decoder(stream)
