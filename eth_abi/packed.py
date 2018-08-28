from typing import (
    Any,
    Iterable,
)
import warnings

from eth_typing.abi import (
    TypeStr,
)

from eth_abi.encoding import (
    TupleEncoder,
)
from eth_abi.registry import (
    registry_packed,
)

warnings.warn(
    "Packed mode encoding is an experimental feature.  Please report any "
    "problems at https://github.com/ethereum/eth-abi/issues."
)


def encode_single_packed(typ: TypeStr, arg: Any) -> bytes:
    """
    Encodes the python value ``arg`` as a binary value of the ABI type ``typ``
    in non-standard packed mode.

    :param typ: The string representation of the ABI type that will be used for
        encoding e.g. ``'uint256'``, ``'bytes[]'``, ``'(int,int)'``, etc.
    :param arg: The python value to be encoded.

    :returns: The non-standard packed mode binary representation of the python
        value ``arg`` as a value of the ABI type ``typ``.
    """
    encoder = registry_packed.get_encoder(typ)

    return encoder(arg)


def encode_abi_packed(types: Iterable[TypeStr], args: Iterable[Any]) -> bytes:
    """
    Encodes the python values in ``args`` as a sequence of binary values of the
    ABI types in ``types`` via the head-tail mechanism.  Binary values are
    encoded in non-standard packed mode.

    :param types: An iterable of string representations of the ABI types that
        will be used for encoding e.g.  ``('uint256', 'bytes[]', '(int,int)')``
    :param args: An iterable of python values to be encoded.

    :returns: The head-tail encoded non-standard packed mode binary
    representation of the python values in ``args`` as values of the ABI types
    in ``types``.
    """
    encoders = [
        registry_packed.get_encoder(type_str)
        for type_str in types
    ]

    encoder = TupleEncoder(encoders=encoders)

    return encoder(args)
