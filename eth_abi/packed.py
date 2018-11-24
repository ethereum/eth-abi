from eth_abi.codec_packed import (
    ABICodecPacked,
)

default_codec_packed = ABICodecPacked()

encode_single_packed = default_codec_packed.encode_single
encode_abi_packed = default_codec_packed.encode_abi
is_encodable_packed = default_codec_packed.is_encodable
