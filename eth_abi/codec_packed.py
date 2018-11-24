import warnings

from eth_abi.codec import (
    BaseABICodecEncoder,
)
from eth_abi.registry import (
    ABIRegistry,
    registry_packed as default_registry_packed,
)

warnings.warn(
    "Packed mode encoding is an experimental feature.  Please report any "
    "problems at https://github.com/ethereum/eth-abi/issues."
)


class ABICodecPacked(BaseABICodecEncoder):
    """
    Codec used to encode values in packed mode. Decoding of values in not
    supported.
    """

    def __init__(self, registry: ABIRegistry=None):
        """
        Constructor.

        :param registry: The registry providing the encoders and decoders
            to be used when encoding and decoding values. If no ``registry``
            is provided, `~eth_abi.registry.default_registry_packed` will be used.

        :returns: An instance of `~eth_abi.codec_packed.ABICodecPacked`.
        """
        if registry is None:
            BaseABICodecEncoder.__init__(self, default_registry_packed)
        else:
            BaseABICodecEncoder.__init__(self, registry)
