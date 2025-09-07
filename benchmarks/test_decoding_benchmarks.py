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

booleans_encoded = [faster_eth_abi.encode(["bool"], [v]) for v in booleans]
addresses_encoded = [faster_eth_abi.encode(["address"], [v]) for v in addresses]
uint256s_encoded = [faster_eth_abi.encode(["uint256"], [v]) for v in uint256s]
bytes32s_encoded = [faster_eth_abi.encode(["bytes32"], [v]) for v in bytes32s]
strings_encoded = [faster_eth_abi.encode(["string"], [v]) for v in strings]
tuples_encoded = [
    (faster_eth_abi.encode(types, list(values)), types) for values, types in tuples
]


# Boolean decoding
@pytest.mark.benchmark(group="BooleanDecoder")
@pytest.mark.parametrize("value", booleans_encoded, ids=booleans)
def test_boolean_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.decode, ["bool"], value)


@pytest.mark.benchmark(group="BooleanDecoder")
@pytest.mark.parametrize("value", booleans_encoded, ids=booleans)
def test_faster_boolean_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.decode, ["bool"], value)


# Address decoding
@pytest.mark.benchmark(group="AddressDecoder")
@pytest.mark.parametrize("value", addresses_encoded, ids=addresses)
def test_address_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.decode, ["address"], value)


@pytest.mark.benchmark(group="AddressDecoder")
@pytest.mark.parametrize("value", addresses_encoded, ids=addresses)
def test_faster_address_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.decode, ["address"], value)


# Unsigned integer decoding
@pytest.mark.benchmark(group="UnsignedIntegerDecoder")
@pytest.mark.parametrize("value", uint256s_encoded, ids=uint256s)
def test_uint256_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.decode, ["uint256"], value)


@pytest.mark.benchmark(group="UnsignedIntegerDecoder")
@pytest.mark.parametrize("value", uint256s_encoded, ids=uint256s)
def test_faster_uint256_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.decode, ["uint256"], value)


# Bytes decoding
@pytest.mark.benchmark(group="BytesDecoder")
@pytest.mark.parametrize("value", bytes32s_encoded, ids=bytes32s)
def test_bytes32_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.decode, ["bytes32"], value)


@pytest.mark.benchmark(group="BytesDecoder")
@pytest.mark.parametrize("value", bytes32s_encoded, ids=bytes32s)
def test_faster_bytes32_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.decode, ["bytes32"], value)


# String decoding
@pytest.mark.benchmark(group="TextStringDecoder")
@pytest.mark.parametrize("value", strings_encoded, ids=strings)
def test_string_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, eth_abi.decode, ["string"], value)


@pytest.mark.benchmark(group="TextStringDecoder")
@pytest.mark.parametrize("value", strings_encoded, ids=strings)
def test_faster_string_decoder(benchmark: BenchmarkFixture, value):
    benchmark(batch, 1000, faster_eth_abi.decode, ["string"], value)


# Tuple decoding
@pytest.mark.benchmark(group="TupleDecoder")
@pytest.mark.parametrize("value,types", tuples_encoded, ids=tuple_ids)
def test_tuple_decoder(benchmark: BenchmarkFixture, value, types):
    benchmark(batch, 1000, eth_abi.decode, types, value)


@pytest.mark.benchmark(group="TupleDecoder")
@pytest.mark.parametrize("value,types", tuples_encoded, ids=tuple_ids)
def test_faster_tuple_decoder(benchmark: BenchmarkFixture, value, types):
    benchmark(batch, 1000, faster_eth_abi.decode, types, value)
