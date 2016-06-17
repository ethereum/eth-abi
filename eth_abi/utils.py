import sys

from rlp.utils import (
    int_to_big_endian,
)

from eth_abi.constants import (
    TT256,
)


if sys.version_info.major == 2:
    def is_numeric(v):
        return isinstance(v, (int, long))  # NOQA

    def is_string(v):
        return isinstance(v, basestring)  # NOQA

    def is_text(v):
        return is_string(v)

    def to_string(value):
        return str(value)

    def to_string_for_regexp(value):
        return str(value)
else:
    def is_numeric(v):
        return isinstance(v, int)

    def is_string(v):
        return isinstance(v, bytes)

    def is_text(v):
        return isinstance(v, (bytes, str))

    def to_string(value):
        if isinstance(value, bytes):
            return value
        if isinstance(value, str):
            return bytes(value, 'utf-8')
        if isinstance(value, int):
            return bytes(str(value), 'utf-8')

    def to_string_for_regexp(value):
        return str(to_string(value), 'utf-8')


def strip_0x_prefix(value):
    """
    Remove the `0x` prefix from a hex value.
    """
    if to_string(value).startswith(b'0x'):
        return value[2:]
    return value


def zpad(value, length):
    """
    Pad the left side of the provided string will null bytes up to `length`

        zpad("abc", 5") => "\x00\x00abc"
    """
    return b'\x00' * max(0, length - len(value)) + to_string(value)


def ceil32(x):
    return x if x % 32 == 0 else x + 32 - (x % 32)


def encode_int(v):
    '''encodes an integer into serialization'''
    if not is_numeric(v) or v < 0 or v >= TT256:
        raise Exception("Integer invalid or out of range: %r" % v)
    return int_to_big_endian(v)


HEX_CHARS = b'1234567890abcdef'


def is_hex_encoded_value(v):
    if not strip_0x_prefix(to_string(v)).lower().strip(HEX_CHARS) == b'':
        return False
    if len(strip_0x_prefix(v)) % 64 and len(strip_0x_prefix(v)) % 40:
        return False
    return True
