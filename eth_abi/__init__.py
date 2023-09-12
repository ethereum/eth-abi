try:
    from importlib.metadata import (
        version as __version,
    )
except ImportError:
    # Python 3.7
    def __version(package_name: str) -> str:  # type: ignore
        from pkg_resources import (
            get_distribution,
        )

        return get_distribution(package_name).version


from eth_abi.abi import (  # NOQA
    decode,
    encode,
    is_encodable,
    is_encodable_type,
)

__version__ = __version("eth-abi")
