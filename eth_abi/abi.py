"""
Vendored from `pyethereum.abi`
"""
import re
import ast

from eth_abi.utils import (
    ceil32,
    zpad,
    is_string,
    is_numeric,
    big_endian_to_int,
    int_to_big_endian,
    strip_0x_prefix,
)
from eth_abi.encoding import (
    encode_int,
    encode_hex,
)
from eth_abi.exceptions import (
    EncodingError,
    DecodingError,
    ValueOutOfBounds,
)


# Decodes a single base datum
def decode_single(typ, data):
    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    try:
        data = strip_0x_prefix(data).decode('hex')
    except TypeError:
        pass

    if arrlist:
        raise EncodingError("Must use `encode_abi` for array types")

    if base == 'address':
        return '0x' + encode_hex(data[12:])
    elif base == 'string' or base == 'bytes' or base == 'hash':
        return data[:int(sub)] if len(sub) else data
    elif base == 'uint':
        return big_endian_to_int(data)
    elif base == 'int':
        o = big_endian_to_int(data)
        return (o - 2**int(sub)) if o >= 2**(int(sub) - 1) else o
    elif base == 'ureal':
        high, low = [int(x) for x in sub.split('x')]
        return big_endian_to_int(data) * 1.0 / 2**low
    elif base == 'real':
        high, low = [int(x) for x in sub.split('x')]
        return (big_endian_to_int(data) * 1.0 / 2**low) % 2**high
    elif base == 'bool':
        return bool(int(data.encode('hex'), 16))


# Encodes a base datum
def encode_single(typ, arg):
    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    if arrlist:
        raise DecodingError("Must use `decode_abi` for array types")

    # Unsigned integers: uint<sz>
    if base == 'uint':
        sub = int(sub)
        i = encode_int(arg)

        if not 0 <= i < 2**sub:
            raise ValueOutOfBounds(repr(arg))
        return zpad(int_to_big_endian(arg), 32)
    # bool: int<sz>
    elif base == 'bool':
        if not isinstance(arg, bool):
            raise EncodingError("Cannot encode non-boolean")
        return zpad(int_to_big_endian(int(arg)), 32)
    # Signed integers: int<sz>
    elif base == 'int':
        sub = int(sub)
        i = encode_int(arg)
        if not -2**(sub - 1) <= i < 2**sub:
            raise ValueOutOfBounds(repr(arg))
        return zpad(int_to_big_endian(i % 2**sub), 32)
    # Unsigned reals: ureal<high>x<low>
    elif base == 'ureal':
        high, low = [int(x) for x in sub.split('x')]
        if not 0 <= arg < 2**high:
            raise ValueOutOfBounds(repr(arg))
        return zpad(int_to_big_endian(arg * 2**low), 32)
    # Signed reals: real<high>x<low>
    elif base == 'real':
        high, low = [int(x) for x in sub.split('x')]
        if not -2**(high - 1) <= arg < 2**(high - 1):
            raise ValueOutOfBounds(repr(arg))
        return zpad(int_to_big_endian((arg % 2**high) * 2**low), 32)
    # Strings
    elif base == 'string' or base == 'bytes':
        if not is_string(arg):
            raise EncodingError("Expecting string: %r" % arg)
        # Fixed length: string<sz>
        if len(sub):
            assert int(sub) <= 32
            assert len(arg) <= int(sub)
            return arg + b'\x00' * (32 - len(arg))
        # Variable length: string
        else:
            return zpad(int_to_big_endian(len(arg)), 32) + \
                arg + \
                b'\x00' * (ceil32(len(arg)) - len(arg))
    # Hashes: hash<sz>
    elif base == 'hash':
        if not (int(sub) and int(sub) <= 32):
            raise EncodingError("too long: %r" % arg)
        if is_numeric(arg):
            return zpad(int_to_big_endian(arg), 32)
        elif len(arg) == len(sub):
            return zpad(arg, 32)
        elif len(arg) == len(sub) * 2:
            return zpad(arg.decode('hex'), 32)
        else:
            raise EncodingError("Could not parse hash: %r" % arg)
    # Addresses: address (== hash160)
    elif base == 'address':
        assert sub == ''
        if is_numeric(arg):
            return zpad(int_to_big_endian(arg), 32)
        elif len(arg) == 20:
            return zpad(arg, 32)
        elif len(arg) == 40:
            return zpad(arg.decode('hex'), 32)
        elif len(arg) == 42 and arg[:2] == '0x':
            return zpad(arg[2:].decode('hex'), 32)
        else:
            raise EncodingError("Could not parse address: %r" % arg)
    raise EncodingError("Unhandled type: %r %r" % (base, sub))


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


def process_type(typ):
    # Crazy reg expression to separate out base type component (eg. uint),
    # size (eg. 256, 128x128, none), array component (eg. [], [45], none)
    regexp = '([a-z]*)([0-9]*x?[0-9]*)((\[[0-9]*\])*)'
    base, sub, arr, _ = re.match(regexp, typ).groups()
    arrlist = re.findall('\[[0-9]*\]', arr)
    assert len(''.join(arrlist)) == len(arr), \
        "Unknown characters found in array declaration"
    # Check validity of string type
    if base == 'string' or base == 'bytes':
        assert re.match('^[0-9]*$', sub), \
            "String type must have no suffix or numerical suffix"
    # Check validity of integer type
    elif base == 'uint' or base == 'int':
        assert re.match('^[0-9]+$', sub), \
            "Integer type must have numerical suffix"
        assert 8 <= int(sub) <= 256, \
            "Integer size out of bounds"
        assert int(sub) % 8 == 0, \
            "Integer size must be multiple of 8"
    # Check validity of string type
    if base == 'string' or base == 'bytes':
        assert re.match('^[0-9]*$', sub), \
            "String type must have no suffix or numerical suffix"
        assert not sub or int(sub) <= 32, \
            "Maximum 32 bytes for fixed-length str or bytes"
    # Check validity of real type
    elif base == 'ureal' or base == 'real':
        assert re.match('^[0-9]+x[0-9]+$', sub), \
            "Real type must have suffix of form <high>x<low>, eg. 128x128"
        high, low = [int(x) for x in sub.split('x')]
        assert 8 <= (high + low) <= 256, \
            "Real size out of bounds (max 32 bytes)"
        assert high % 8 == 0 and low % 8 == 0, \
            "Real high/low sizes must be multiples of 8"
    # Check validity of hash type
    elif base == 'hash':
        assert re.match('^[0-9]+$', sub), \
            "Hash type must have numerical suffix"
    # Check validity of address type
    elif base == 'address':
        assert sub == '', "Address cannot have suffix"
    return base, sub, [ast.literal_eval(x) for x in arrlist]


# Decodes multiple arguments using the head/tail mechanism
def decode_abi(types, data):
    try:
        data = strip_0x_prefix(data).decode('hex')
    except TypeError:
        data = data

    # Process types
    proctypes = [process_type(typ) for typ in types]
    # Get sizes of everything
    sizes = [get_size(typ) for typ in proctypes]
    # Initialize array of outputs
    outs = [None] * len(types)
    # Initialize array of start positions
    start_positions = [None] * len(types) + [len(data)]
    # If a type is static, grab the data directly, otherwise record
    # its start position
    pos = 0
    for i, typ in enumerate(types):
        if sizes[i] is None:
            start_positions[i] = big_endian_to_int(data[pos:pos + 32])
            j = i - 1
            while j >= 0 and start_positions[j] is None:
                start_positions[j] = start_positions[i]
                j -= 1
            pos += 32
        else:
            outs[i] = data[pos:pos + sizes[i]]
            pos += sizes[i]
    # We add a start position equal to the length of the entire data
    # for convenience.
    j = len(types) - 1
    while j >= 0 and start_positions[j] is None:
        start_positions[j] = start_positions[len(types)]
        j -= 1
    assert pos <= len(data), "Not enough data for head"
    # Grab the data for tail arguments using the start positions
    # calculated above
    for i, typ in enumerate(types):
        if sizes[i] is None:
            offset = start_positions[i]
            next_offset = start_positions[i + 1]
            outs[i] = data[offset:next_offset]
    # Recursively decode them all
    return [dec(proctypes[i], outs[i]) for i in range(len(outs))]


# Decode a single value (static or dynamic)
def dec(typ, arg):
    base, sub, arrlist = typ
    sz = get_size(typ)
    # Dynamic-sized strings are encoded as <len(str)> + <str>
    if base in ('string', 'bytes') and not sub:
        L = big_endian_to_int(arg[:32])
        assert len(arg[32:]) == ceil32(L), "Wrong data size for string/bytes object"
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
            assert len(arg) >= 32 + 32 * L, "Not enough data for head"
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


lentyp = 'uint', 256, []


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


# Encodes a single value (static or dynamic)
def enc(typ, arg):
    base, sub, arrlist = typ
    sz = get_size(typ)
    # Encode dynamic-sized strings as <len(str)> + <str>
    if base in ('string', 'bytes') and not sub:
        assert isinstance(arg, (str, bytes, unicode)), \
            "Expecting a string"
        return enc(lentyp, len(arg)) + \
            arg + \
            b'\x00' * (ceil32(len(arg)) - len(arg))
    # Encode dynamic-sized lists via the head/tail mechanism described in
    # https://github.com/ethereum/wiki/wiki/Proposal-for-new-ABI-value-encoding
    elif sz is None:
        assert isinstance(arg, list), \
            "Expecting a list argument"
        subtyp = base, sub, arrlist[:-1]
        subsize = get_size(subtyp)
        myhead, mytail = b'', b''
        if arrlist[-1] == []:
            myhead += enc(lentyp, len(arg))
        else:
            assert len(arg) == arrlist[-1][0], \
                "Wrong array size: found %d, expecting %d" % \
                (len(arg), arrlist[-1][0])
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
            return encode_single(typ, arg)
        else:
            subtyp = base, sub, arrlist[:-1]
            o = b''
            for x in arg:
                o += enc(subtyp, x)
            return o
