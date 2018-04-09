"""
Vendored from `pyethereum.abi`
"""
from io import BytesIO

from eth_utils import (
    is_bytes,
)

from eth_abi.decoding import MultiDecoder
from eth_abi.encoding import MultiEncoder

from eth_abi.registry import registry

from eth_abi.utils.parsing import (  # noqa: F401
    process_type,
    collapse_type,
)


def encode_single(typ, arg):
    try:
        base, sub, arrlist = typ
    except ValueError:
        type_str = typ
    else:
        type_str = collapse_type(base, sub, arrlist)

    encoder = registry.get_encoder(type_str)

    return encoder(arg)


def encode_abi(types, args):
    encoders = [
        registry.get_encoder(type_str)
        for type_str in types
    ]

    encoder = MultiEncoder.as_encoder(encoders=encoders)

    return encoder(args)


# Decodes a single base datum
def decode_single(typ, data):
    if not is_bytes(data):
        raise TypeError("The `data` value must be of bytes type.  Got {0}".format(type(data)))

    try:
        base, sub, arrlist = typ
    except ValueError:
        type_str = typ
    else:
        type_str = collapse_type(base, sub, arrlist)

    decoder = registry.get_decoder(type_str)
    stream = BytesIO(data)

    return decoder(stream)


# Decodes multiple arguments using the head/tail mechanism
def decode_abi(types, data):
    if not is_bytes(data):
        raise TypeError("The `data` value must be of bytes type.  Got {0}".format(type(data)))

    decoders = [
        registry.get_decoder(type_str)
        for type_str in types
    ]

    decoder = MultiDecoder.as_decoder(decoders=decoders)
    stream = BytesIO(data)

    return decoder(stream)
