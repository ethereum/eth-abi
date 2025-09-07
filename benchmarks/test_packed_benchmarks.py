import pytest

import eth_abi.packed
from pytest_codspeed import (
    BenchmarkFixture,
)

from benchmarks.batch import (
    batch,
)
from benchmarks.data import (
    packed_cases,
    packed_ids,
)
import faster_eth_abi.packed


# Packed encoding
@pytest.mark.benchmark(group="PackedEncoder")
@pytest.mark.parametrize("abi_type,value", packed_cases, ids=packed_ids)
def test_encode_packed(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 1000, eth_abi.packed.encode_packed, [abi_type], [value])


@pytest.mark.benchmark(group="PackedEncoder")
@pytest.mark.parametrize("abi_type,value", packed_cases, ids=packed_ids)
def test_faster_encode_packed(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 1000, faster_eth_abi.packed.encode_packed, [abi_type], [value])


# Packed is_encodable
@pytest.mark.benchmark(group="PackedIsEncodable")
@pytest.mark.parametrize("abi_type,value", packed_cases, ids=packed_ids)
def test_is_encodable_packed(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 1000, eth_abi.packed.is_encodable_packed, abi_type, value)


@pytest.mark.benchmark(group="PackedIsEncodable")
@pytest.mark.parametrize("abi_type,value", packed_cases, ids=packed_ids)
def test_faster_is_encodable_packed(benchmark: BenchmarkFixture, abi_type, value):
    benchmark(batch, 1000, faster_eth_abi.packed.is_encodable_packed, abi_type, value)
