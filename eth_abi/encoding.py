from eth_abi import utils
from eth_abi.exceptions import (
    EncodingError,
)


def encode_int(n):
    """
    Encode a value as a 256-bit integer
    """
    if utils.is_numeric(n) and n < 2**256 and n > -2**255:
        return n
    elif utils.is_numeric(n):
        raise EncodingError("Number out of range: %r" % n)
    elif utils.is_string(n) and len(n) == 40:
        return utils.big_endian_to_int(n.decode('hex'))
    elif utils.is_string(n) and len(n) <= 32:
        return utils.big_endian_to_int(n)
    elif utils.is_string(n) and len(n) > 32:
        raise EncodingError("String too long: %r" % n)
    elif n is True:
        return 1
    elif n is False or n is None:
        return 0
    else:
        raise EncodingError("Cannot encode integer: %r" % n)


def encode_hex(v):
    return v.encode('hex')
