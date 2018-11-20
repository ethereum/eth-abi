from typing import (
    Any,
    Iterable,
    Tuple,
)
import warnings

from eth_typing.abi import (
    Decodable,
    TypeStr,
)

from eth_abi.codec import (
    ABICodec,
)
from eth_abi.registry import (
    ABIRegistry,
    registry_packed as default_packed_registry,
)

warnings.warn(
    "Packed mode encoding is an experimental feature.  Please report any "
    "problems at https://github.com/ethereum/eth-abi/issues."
)


class ABICodecPacked(ABICodec):
    def __init__(self, registry: ABIRegistry = None):
        if registry is None:
            ABICodec.__init__(self, default_packed_registry)
        else:
            ABICodec.__init__(self, registry)

    def is_encodable(self, typ: TypeStr, arg: Any) -> bool:
        raise NotImplementedError("'is_encodable' is not  supported in packed mode")

    def decode_single(self, typ: TypeStr, data: Decodable) -> Any:
        raise NotImplementedError("'decode_single' is not supported in packed mode")

    def decode_abi(self, types: Iterable[TypeStr], data: Decodable) -> Tuple[Any, ...]:
        raise NotImplementedError("'decode_abi' is not supported in packed mode")
