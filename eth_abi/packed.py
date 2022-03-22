from .codec import (
    ABIEncoder,
)
from .registry import (
    registry_packed,
)

default_encoder_packed = ABIEncoder(registry_packed)

encode_abi_packed = default_encoder_packed.encode_abi
is_encodable_packed = default_encoder_packed.is_encodable
