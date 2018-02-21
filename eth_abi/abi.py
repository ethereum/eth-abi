"""
Vendored from `pyethereum.abi`
"""
from io import BytesIO

from eth_utils import (
    is_bytes,
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

    encoder = get_single_encoder(base, sub, arrlist)
    return encoder(arg)


def encode_abi(types, args):
    processed_types = [process_type(typ) for typ in types]
    encoder = get_multi_encoder(processed_types)
    return encoder(args)


# Decodes a single base datum
def decode_single(typ, data):
    if not is_bytes(data):
        raise TypeError("The `data` value must be of bytes type.  Got {0}".format(type(data)))
    try:
        base, sub, arrlist = typ
    except ValueError:
        base, sub, arrlist = process_type(typ)

    decoder = get_single_decoder(base, sub, arrlist)
    stream = BytesIO(data)
    return decoder(stream)


# Decodes multiple arguments using the head/tail mechanism
def decode_abi(types, data):
    if not is_bytes(data):
        raise TypeError("The `data` value must be of bytes type.  Got {0}".format(type(data)))

    processed_types = tuple(process_type(_type) for _type in types)
    decoder = get_multi_decoder(processed_types)
    stream = BytesIO(data)
    return decoder(stream)
