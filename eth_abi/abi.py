from eth_abi.codec import (
    ABICodec,
)
from eth_abi.registry import (
    registry,
)

default_codec = ABICodec(registry)

encode_abi = default_codec.encode_abi
decode_abi = default_codec.decode_abi
is_encodable = default_codec.is_encodable
is_encodable_type = default_codec.is_encodable_type
