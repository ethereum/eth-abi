from eth_abi.codec import (
    ABICodec,
)

default_codec = ABICodec()

encode_abi = default_codec.encode_abi
encode_single = default_codec.encode_single
decode_abi = default_codec.decode_abi
decode_single = default_codec.decode_single
is_encodable = default_codec.is_encodable
