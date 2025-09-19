import pytest

import eth_abi.grammar
from pytest_codspeed import (
    BenchmarkFixture,
)

from benchmarks.batch import (
    batch,
)
from benchmarks.type_strings import (
    type_strings,
)
import faster_eth_abi.grammar


@pytest.mark.benchmark(group="GrammarNormalize")
@pytest.mark.parametrize("type_str", type_strings)
def test_normalize(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 5000, eth_abi.grammar.normalize, type_str)


@pytest.mark.benchmark(group="GrammarNormalize")
@pytest.mark.parametrize("type_str", type_strings)
def test_faster_normalize(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 5000, faster_eth_abi.grammar.normalize, type_str)


@pytest.mark.benchmark(group="GrammarParse")
@pytest.mark.parametrize("type_str", type_strings)
def test_parse(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 5000, eth_abi.grammar.parse, type_str)


@pytest.mark.benchmark(group="GrammarParse")
@pytest.mark.parametrize("type_str", type_strings)
def test_faster_parse(benchmark: BenchmarkFixture, type_str):
    benchmark(batch, 5000, faster_eth_abi.grammar.parse, type_str)
