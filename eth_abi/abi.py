"""
Vendored from `pyethereum.abi`
"""
import re
import ast
import warnings

from io import BytesIO

from eth_utils import (
    is_text,
    is_bytes,
    is_integer,
    force_text,
    force_bytes,
    remove_0x_prefix,
    decode_hex,
    coerce_args_to_bytes,
)

from eth_abi.constants import (
    TT255,
    TT256,
    TT256M1,
)

from eth_abi.decoding import (
    get_decoder_for_type,
    get_decoder,
)
from eth_abi.exceptions import (
    EncodingError,
    DecodingError,
    ValueOutOfBounds,
)

from eth_abi.utils.numeric import (
    ceil32,
    big_endian_to_int,
    encode_int,
)
from eth_abi.utils.padding import (
    zpad32,
)


# Decode an unsigned/signed integer
@coerce_args_to_bytes
def decint(n, signed=False):
    if is_integer(n):
        min, max = (-TT255, TT255 - 1) if signed else (0, TT256M1)
        if n > max or n < min:
            raise EncodingError("Number out of range: %r" % n)
        return n
    elif is_bytes(n):
        if len(n) == 40:
            n = decode_hex(n)
        if len(n) > 32:
            raise EncodingError("String too long: %r" % n)

        i = big_endian_to_int(n)
        return (i - TT256) if signed and i >= TT255 else i
    elif n is True:
        return 1
    elif n is False or n is None:
        return 0
    else:
        raise EncodingError("Cannot encode integer: %r" % n)


# Encodes a base datum
def encode_single(typ, arg):
    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    if is_text(arg):
        arg = force_bytes(arg)

    # Unsigned integers: uint<sz>
    if base == 'uint':
        sub = int(sub)
        i = decint(arg, False)

        if not 0 <= i < 2**sub:
            raise ValueOutOfBounds(repr(arg))
        return zpad32(encode_int(i))
    # bool: int<sz>
    elif base == 'bool':
        if not isinstance(arg, bool):
            raise EncodingError("Value must be a boolean")
        return zpad32(encode_int(int(arg)))
    # Signed integers: int<sz>
    elif base == 'int':
        sub = int(sub)
        i = decint(arg, True)
        if not -2**(sub - 1) <= i < 2**(sub - 1):
            raise ValueOutOfBounds(repr(arg))
        return zpad32(encode_int(i % 2**sub))
    # Unsigned reals: ureal<high>x<low>
    elif base == 'ureal':
        high, low = [int(x) for x in sub.split('x')]
        if not 0 <= arg < 2**high:
            raise ValueOutOfBounds(repr(arg))
        return zpad32(encode_int(int(arg * 2**low)))
    # Signed reals: real<high>x<low>
    elif base == 'real':
        high, low = [int(x) for x in sub.split('x')]
        if not -2**(high - 1) <= arg < 2**(high - 1):
            raise ValueOutOfBounds(repr(arg))
        i = int(arg * 2**low)
        return zpad32(encode_int(i % 2**(high + low)))
    # Strings
    elif base == 'string' or base == 'bytes':
        if not is_bytes(arg):
            raise EncodingError("Expecting string: %r" % arg)
        # Fixed length: string<sz>
        if len(sub):
            if int(sub) > 32:
                raise EncodingError("Fixed length strings must be 32 bytes or less")
            if len(arg) > int(sub):
                raise EncodingError(
                    "Value cannot exceed {0} bytes in length".format(sub)
                )
            return arg + b'\x00' * (32 - len(arg))
        # Variable length: string
        else:
            return zpad32(encode_int(len(arg))) + \
                arg + \
                b'\x00' * (ceil32(len(arg)) - len(arg))
    # Hashes: hash<sz>
    elif base == 'hash':
        if not (int(sub) and int(sub) <= 32):
            raise EncodingError("too long: %r" % arg)
        if is_integer(arg):
            return zpad32(encode_int(arg))
        elif len(arg) == int(sub):
            return zpad32(arg)
        elif len(arg) == int(sub) * 2:
            return zpad32(decode_hex(arg))
        else:
            raise EncodingError("Could not parse hash: %r" % arg)
    # Addresses: address (== hash160)
    elif base == 'address':
        if sub != '':
            raise EncodingError("Address type cannot specify a byte size")
        if is_integer(arg):
            return zpad32(encode_int(arg))
        elif len(arg) == 20:
            return zpad32(arg)
        elif len(arg) == 40:
            return zpad32(decode_hex(arg))
        elif len(arg) == 42 and arg[:2] == b'0x':
            return zpad32(decode_hex(arg[2:]))
        else:
            raise EncodingError("Could not parse address: %r" % arg)
    raise EncodingError("Unhandled type: %r %r" % (base, sub))


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


# Returns the static size of a type, or None if dynamic
def get_size(typ):
    base, sub, arrlist = typ
    if not len(arrlist):
        if base in ('string', 'bytes') and not sub:
            return None
        return 32
    if arrlist[-1] == []:
        return None
    o = get_size((base, sub, arrlist[:-1]))
    if o is None:
        return None
    return arrlist[-1][0] * o


lentyp = 'uint', 256, []


# Encodes a single value (static or dynamic)
def enc(typ, arg):
    base, sub, arrlist = typ
    sz = get_size(typ)
    # Encode dynamic-sized strings as <len(str)> + <str>
    if base in ('string', 'bytes') and not sub:
        if not is_text(arg):
            raise EncodingError("Expecting a text type")
        return enc(lentyp, len(arg)) + \
            force_bytes(arg) + \
            b'\x00' * (ceil32(len(arg)) - len(arg))
    # Encode dynamic-sized lists via the head/tail mechanism described in
    # https://github.com/ethereum/wiki/wiki/Proposal-for-new-ABI-value-encoding
    elif sz is None:
        if not isinstance(arg, list):
            raise EncodingError("Expecting a list argument")
        subtyp = base, sub, arrlist[:-1]
        subsize = get_size(subtyp)
        myhead, mytail = b'', b''
        if arrlist[-1] == []:
            myhead += enc(lentyp, len(arg))
        else:
            if len(arg) != arrlist[-1][0]:
                raise EncodingError(
                    "Wrong array size: found {0:d}, expecting {1:d}".format(
                        len(arg),
                        arrlist[-1][0],
                    )
                )
        for i in range(len(arg)):
            if subsize is None:
                myhead += enc(lentyp, 32 * len(arg) + len(mytail))
                mytail += enc(subtyp, arg[i])
            else:
                myhead += enc(subtyp, arg[i])
        return myhead + mytail
    # Encode static-sized lists via sequential packing
    else:
        if arrlist == []:
            return force_bytes(encode_single(typ, arg))
        else:
            subtyp = base, sub, arrlist[:-1]
            o = b''
            for x in arg:
                o += enc(subtyp, x)
            return o


# Encodes multiple arguments using the head/tail mechanism
def encode_abi(types, args):
    headsize = 0
    proctypes = [process_type(typ) for typ in types]
    sizes = [get_size(typ) for typ in proctypes]
    for i, arg in enumerate(args):
        if sizes[i] is None:
            headsize += 32
        else:
            headsize += sizes[i]
    myhead, mytail = b'', b''
    for i, arg in enumerate(args):
        if sizes[i] is None:
            myhead += enc(lentyp, headsize + len(mytail))
            mytail += enc(proctypes[i], args[i])
        else:
            myhead += enc(proctypes[i], args[i])
    return myhead + mytail


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

    decoder = get_decoder_for_type(base, sub, arrlist)
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
    decoder = get_decoder(processed_types)
    stream = BytesIO(force_bytes(data))
    return decoder(stream)


# Decode a single value (static or dynamic)
def dec(typ, arg):
    base, sub, arrlist = typ
    sz = get_size(typ)

    # Dynamic-sized strings are encoded as <len(str)> + <str>
    if base in ('string', 'bytes') and not sub:
        L = big_endian_to_int(arg[:32])
        if len(arg[32:]) != ceil32(L):
            raise ValueError("Wrong data size for string/bytes object")
        return arg[32:][:L]
    # Dynamic-sized arrays
    elif sz is None:
        L = big_endian_to_int(arg[:32])
        subtyp = base, sub, arrlist[:-1]
        subsize = get_size(subtyp)
        # If children are dynamic, use the head/tail mechanism. Fortunately,
        # here the code is simpler since we do not have to worry about
        # mixed dynamic and static children, as we do in the top-level multi-arg
        # case
        if subsize is None:
            if len(arg) < 32 + 32 * L:
                raise DecodingError("Not enough data for head")
            start_positions = [big_endian_to_int(arg[32 + 32 * i: 64 + 32 * i])
                               for i in range(L)] + [len(arg)]
            outs = [arg[start_positions[i]: start_positions[i + 1]]
                    for i in range(L)]
            return [dec(subtyp, out) for out in outs]
        # If children are static, then grab the data slice for each one and
        # sequentially decode them manually
        else:
            return [dec(subtyp, arg[32 + subsize * i: 32 + subsize * (i + 1)])
                    for i in range(L)]
    # Static-sized arrays: decode piece-by-piece
    elif len(arrlist):
        L = arrlist[-1][0]
        subtyp = base, sub, arrlist[:-1]
        subsize = get_size(subtyp)
        return [dec(subtyp, arg[subsize * i:subsize * (i + 1)])
                for i in range(L)]
    else:
        return decode_single(typ, arg)
