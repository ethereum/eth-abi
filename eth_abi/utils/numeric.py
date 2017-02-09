import sys
import math

from eth_utils import (
    encode_hex,
    is_number,
)

from eth_abi.constants import (
    TT256,
)


if sys.version_info.major == 2:
    import struct

    def int_to_big_endian(value):
        cs = []
        while value > 0:
            cs.append(chr(value % 256))
            value /= 256
        s = ''.join(reversed(cs))
        return s

    def big_endian_to_int(value):
        if len(value) == 1:
            return ord(value)
        elif len(value) <= 8:
            return struct.unpack('>Q', value.rjust(8, '\x00'))[0]
        else:
            return int(encode_hex(value), 16)
else:
    def int_to_big_endian(value):
        byte_length = math.ceil(value.bit_length() / 8)
        return (value).to_bytes(byte_length, byteorder='big')

    def big_endian_to_int(value):
        return int.from_bytes(value, byteorder='big')


def ceil32(x):
    return x if x % 32 == 0 else x + 32 - (x % 32)


def encode_int(value):
    '''encodes an integer into serialization'''
    if not is_number(value) or value < 0 or value >= TT256:
        raise Exception("Integer invalid or out of range: %r" % value)
    return int_to_big_endian(value)


def compute_unsigned_bounds(num_bits):
    return (
        0,
        2 ** num_bits - 1,
    )


def compute_signed_bounds(num_bits):
    return (
        -1 * 2 ** (num_bits - 1),
        2 ** (num_bits - 1) - 1,
    )
