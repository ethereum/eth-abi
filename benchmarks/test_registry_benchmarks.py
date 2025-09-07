import pytest

from eth_abi.registry import (
    registry,
)
from pytest_codspeed import (
    BenchmarkFixture,
)

from benchmarks.batch import (
    batch,
)
from benchmarks.type_strings import (
    type_strings,
)
from faster_eth_abi.registry import (
    registry as faster_registry,
)


@pytest.mark.benchmark(group="RegistryGetEncoder")
@pytest.mark.parametrize("type_str", type_strings)
def test_get_encoder(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 1000, registry.get_encoder, type_str)


@pytest.mark.benchmark(group="RegistryGetEncoder")
@pytest.mark.parametrize("type_str", type_strings)
def test_faster_get_encoder(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 1000, faster_registry.get_encoder, type_str)


@pytest.mark.benchmark(group="RegistryGetDecoder")
@pytest.mark.parametrize("type_str", type_strings)
def test_get_decoder(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 1000, registry.get_decoder, type_str)


@pytest.mark.benchmark(group="RegistryGetDecoder")
@pytest.mark.parametrize("type_str", type_strings)
def test_faster_get_decoder(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 1000, faster_registry.get_decoder, type_str)
