import pkg_resources

from eth_abi.abi import (  # NOQA
    decode_single,
    decode_abi,
    encode_single,
    encode_abi,
    is_encodable,
)


__version__ = pkg_resources.get_distribution('eth-abi').version
