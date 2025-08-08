from typing import (
    Final,
)

from faster_eth_abi.codec import (
    ABICodec,
)
from faster_eth_abi.registry import (
    registry,
)

default_codec: Final = ABICodec(registry)

encode: Final = default_codec.encode
decode: Final = default_codec.decode
is_encodable: Final = default_codec.is_encodable
is_encodable_type: Final = default_codec.is_encodable_type
