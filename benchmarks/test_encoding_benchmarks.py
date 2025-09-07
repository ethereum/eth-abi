import pytest

import eth_abi
from pytest_codspeed import (
    BenchmarkFixture,
)

from benchmarks.batch import (
    batch,
)
from benchmarks.data import (
    addresses,
    booleans,
    bytes32s,
    strings,
    tuple_ids,
    tuples,
    uint256s,
)
import faster_eth_abi


# Boolean encoding
@pytest.mark.benchmark(group="BooleanEncoder")
@pytest.mark.parametrize("value", booleans)
def test_boolean_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.encode, ["bool"], [value])


@pytest.mark.benchmark(group="BooleanEncoder")
@pytest.mark.parametrize("value", booleans)
def test_faster_boolean_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.encode, ["bool"], [value])


# Address encoding
@pytest.mark.benchmark(group="AddressEncoder")
@pytest.mark.parametrize("value", addresses)
def test_address_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.encode, ["address"], [value])


@pytest.mark.benchmark(group="AddressEncoder")
@pytest.mark.parametrize("value", addresses)
def test_faster_address_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.encode, ["address"], [value])


# Unsigned integer encoding
@pytest.mark.benchmark(group="UnsignedIntegerEncoder")
@pytest.mark.parametrize("value", uint256s)
def test_uint256_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.encode, ["uint256"], [value])


@pytest.mark.benchmark(group="UnsignedIntegerEncoder")
@pytest.mark.parametrize("value", uint256s)
def test_faster_uint256_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.encode, ["uint256"], [value])


# Bytes encoding
@pytest.mark.benchmark(group="BytesEncoder")
@pytest.mark.parametrize("value", bytes32s)
def test_bytes32_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.encode, ["bytes32"], [value])


@pytest.mark.benchmark(group="BytesEncoder")
@pytest.mark.parametrize("value", bytes32s)
def test_faster_bytes32_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.encode, ["bytes32"], [value])


# String encoding
@pytest.mark.benchmark(group="TextStringEncoder")
@pytest.mark.parametrize("value", strings)
def test_string_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.encode, ["string"], [value])


@pytest.mark.benchmark(group="TextStringEncoder")
@pytest.mark.parametrize("value", strings)
def test_faster_string_encoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.encode, ["string"], [value])


# Tuple encoding
@pytest.mark.benchmark(group="TupleEncoder")
@pytest.mark.parametrize("values,types", tuples, ids=tuple_ids)
def test_tuple_encoder(benchmark: BenchmarkFixture, values, types):
    benchmark(batch, 1000, eth_abi.encode, types, list(values))


@pytest.mark.benchmark(group="TupleEncoder")
@pytest.mark.parametrize("values,types", tuples, ids=tuple_ids)
def test_faster_tuple_encoder(benchmark: BenchmarkFixture, values, types):
    benchmark(batch, 1000, faster_eth_abi.encode, types, list(values))
