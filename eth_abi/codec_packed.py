import warnings

from eth_abi.codec import (
    BaseABICodecEncoder,
)
from eth_abi.registry import (
    ABIRegistry,
    registry_packed as default_packed_registry,
)

warnings.warn(
    "Packed mode encoding is an experimental feature.  Please report any "
    "problems at https://github.com/ethereum/eth-abi/issues."
)


class ABICodecPacked(BaseABICodecEncoder):
    def __init__(self, registry: ABIRegistry=None):
        if registry is None:
            BaseABICodecEncoder.__init__(self, default_packed_registry)
        else:
            BaseABICodecEncoder.__init__(self, registry)
