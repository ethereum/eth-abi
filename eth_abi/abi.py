from typing import (
    Any,
    Iterable,
    Tuple,
)

from eth_utils import (
    is_bytes,
)

from eth_abi.decoding import (
    ContextFramesBytesIO,
    TupleDecoder,
)
from eth_abi.encoding import (
    TupleEncoder,
)
from eth_abi.exceptions import (
    EncodingError,
)
from eth_abi.registry import (
    registry,
)
from eth_abi.utils.parsing import (  # noqa: F401
    collapse_type,
    process_type,
)
from eth_typing.abi import (
    Decodable,
    TypeStr,
)


def encode_single(typ: TypeStr, arg: Any) -> bytes:
    if isinstance(typ, str):
        type_str = typ
    else:
        type_str = collapse_type(*typ)

    encoder = registry.get_encoder(type_str)

    return encoder(arg)


def encode_abi(types: Iterable[TypeStr], args: Iterable[Any]) -> bytes:
    encoders = [
        registry.get_encoder(type_str)
        for type_str in types
    ]

    encoder = TupleEncoder(encoders=encoders)

    return encoder(args)


def is_encodable(typ: TypeStr, arg: Any) -> bool:
    """
    Determines if the given python value ``arg`` can be encoded as a value of
    abi type ``typ``.
    """
    if isinstance(typ, str):
        type_str = typ
    else:
        type_str = collapse_type(*typ)

    encoder = registry.get_encoder(type_str)

    try:
        encoder.validate_value(arg)
    except EncodingError:
        return False
    except AttributeError:
        try:
            encoder(arg)
        except EncodingError:
            return False

    return True


# Decodes a single base datum
def decode_single(typ: TypeStr, data: Decodable) -> Any:
    if not is_bytes(data):
        raise TypeError("The `data` value must be of bytes type.  Got {0}".format(type(data)))

    if isinstance(typ, str):
        type_str = typ
    else:
        type_str = collapse_type(*typ)

    decoder = registry.get_decoder(type_str)
    stream = ContextFramesBytesIO(data)

    return decoder(stream)


# Decodes multiple arguments using the head/tail mechanism
def decode_abi(types: Iterable[TypeStr], data: Decodable) -> Tuple[Any, ...]:
    if not is_bytes(data):
        raise TypeError("The `data` value must be of bytes type.  Got {0}".format(type(data)))

    decoders = [
        registry.get_decoder(type_str)
        for type_str in types
    ]

    decoder = TupleDecoder(decoders=decoders)
    stream = ContextFramesBytesIO(data)

    return decoder(stream)
