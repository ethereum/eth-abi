from eth_abi.codec import (
    ABICodec,
)
from eth_abi.registry import (
    registry,
)

default_codec = ABICodec(registry)

encode_abi = default_codec.encode_abi
encode_single = default_codec.encode_single
decode_abi = default_codec.decode_abi
decode_single = default_codec.decode_single
is_encodable = default_codec.is_encodable
