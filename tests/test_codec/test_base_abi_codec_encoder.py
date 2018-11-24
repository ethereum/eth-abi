import pytest

from eth_abi.codec import (
    BaseABICodecEncoder,
)


def test_init_raises_error_for_null_registry():
    with pytest.raises(ValueError):
        BaseABICodecEncoder(None)
