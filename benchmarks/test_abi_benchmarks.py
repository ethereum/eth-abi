import pytest

import eth_abi
from pytest_codspeed import (
    BenchmarkFixture,
)

from benchmarks.batch import (
    batch,
)
from benchmarks.data import (
    all_cases,
    all_ids,
)
import faster_eth_abi

# --- ENCODE ---


@pytest.mark.benchmark(group="encode")
@pytest.mark.parametrize("abi_type,value", all_cases, ids=all_ids)
def test_encode(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 100, eth_abi.encode, [abi_type], [value])


@pytest.mark.benchmark(group="encode")
@pytest.mark.parametrize("abi_type,value", all_cases, ids=all_ids)
def test_faster_encode(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 100, faster_eth_abi.encode, [abi_type], [value])


# --- DECODE ---

decode_cases = [
    (abi_type, faster_eth_abi.encode([abi_type], [value]))
    for abi_type, value in all_cases
]
decode_ids = all_ids


@pytest.mark.benchmark(group="decode")
@pytest.mark.parametrize("abi_type,encoded", decode_cases, ids=decode_ids)
def test_decode(benchmark: BenchmarkFixture, abi_type, encoded):
    benchmark(batch, 100, eth_abi.decode, [abi_type], encoded)


@pytest.mark.benchmark(group="decode")
@pytest.mark.parametrize("abi_type,encoded", decode_cases, ids=decode_ids)
def test_faster_decode(benchmark: BenchmarkFixture, abi_type, encoded):
    benchmark(batch, 100, faster_eth_abi.decode, [abi_type], encoded)


# --- IS_ENCODABLE ---


@pytest.mark.benchmark(group="is_encodable")
@pytest.mark.parametrize("abi_type,value", all_cases, ids=all_ids)
def test_is_encodable(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 100, eth_abi.is_encodable, abi_type, value)


@pytest.mark.benchmark(group="is_encodable")
@pytest.mark.parametrize("abi_type,value", all_cases, ids=all_ids)
def test_faster_is_encodable(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 100, faster_eth_abi.is_encodable, abi_type, value)


# --- IS_ENCODABLE_TYPE ---

all_types = list({abi_type for abi_type, _ in all_cases})


@pytest.mark.benchmark(group="is_encodable_type")
@pytest.mark.parametrize("abi_type", all_types, ids=all_types)
def test_is_encodable_type(benchmark: BenchmarkFixture, abi_type):
    benchmark(batch, 100, eth_abi.is_encodable_type, abi_type)


@pytest.mark.benchmark(group="is_encodable_type")
@pytest.mark.parametrize("abi_type", all_types, ids=all_types)
def test_faster_is_encodable_type(benchmark: BenchmarkFixture, abi_type):
    benchmark(batch, 100, faster_eth_abi.is_encodable_type, abi_type)
