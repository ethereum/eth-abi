import struct
import binascii


def strip_0x_prefix(value):
    """
    Remove the `0x` prefix from a hex value.
    """
    if value.startswith('0x'):
        return value[2:]
    return value


def zpad(value, length):
    """
    Pad the left side of the provided string will null bytes up to `length`

        zpad("abc", 5") => "\x00\x00abc"
    """
    return b'\x00' * max(0, length - len(value)) + value


def ceil32(x):
    return x if x % 32 == 0 else x + 32 - (x % 32)


def is_numeric(v):
    return isinstance(v, (int, long))


def is_string(v):
    return isinstance(v, basestring)


def int_to_big_endian(lnum):
    if lnum == 0:
        return b'\0'
    s = hex(lnum)[2:]
    s = s.rstrip('L')
    if len(s) & 1:
        s = '0' + s
    s = binascii.unhexlify(s)
    return s


def big_endian_to_int(value):
    if len(value) == 1:
        return ord(value)
    elif len(value) <= 8:
        return struct.unpack('>Q', value.rjust(8, '\x00'))[0]
    else:
        return int(value.encode('hex'), 16)
