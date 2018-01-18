"""
Vendored from `pyethereum.abi`
"""
import warnings

from io import BytesIO

from eth_utils import (
    is_text,
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

from eth_abi.utils.parsing import (  # noqa: F401
    process_type,
    collapse_type,
)


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
    if v == b'':
        return False
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

    if is_text(data):
        warnings.warn(DeprecationWarning(
            "Automatic conversion of encoded data to bytes has been deprecated. "
            "Please adjust your code to ensure that the data argument for "
            "`decode_single` is a byte string"
        ))
        data = force_bytes(data)

    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    decoder = get_single_decoder(base, sub, arrlist)
    stream = BytesIO(data)
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

    if is_text(data):
        warnings.warn(DeprecationWarning(
            "Automatic conversion of encoded data to bytes has been deprecated. "
            "Please adjust your code to ensure that the data argument for "
            "`decode_abi` is a byte string"
        ))
        data = force_bytes(data)

    processed_types = tuple(process_type(_type) for _type in types)
    decoder = get_multi_decoder(processed_types)
    stream = BytesIO(data)
    return decoder(stream)
