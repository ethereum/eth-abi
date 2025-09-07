#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.012472867641017378 | 0.006952736721425319 | 44.26% | 79.40% | 1.79x | ✅ |
| `encode_packed[bool]` | 0.006975690664232528 | 0.0048343939505029725 | 30.70% | 44.29% | 1.44x | ✅ |
| `encode_packed[bytes]` | 0.006469548932436645 | 0.0046756368446546764 | 27.73% | 38.37% | 1.38x | ✅ |
| `encode_packed[string]` | 0.006964408288728093 | 0.004998149177655818 | 28.23% | 39.34% | 1.39x | ✅ |
| `encode_packed[tuple]` | 0.016641502135593005 | 0.014112202571425314 | 15.20% | 17.92% | 1.18x | ✅ |
| `encode_packed[uint256]` | 0.008414507149124898 | 0.006159197088050379 | 26.80% | 36.62% | 1.37x | ✅ |
| `is_encodable_packed[address]` | 0.0006635271068725811 | 0.0005700938580760887 | 14.08% | 16.39% | 1.16x | ✅ |
| `is_encodable_packed[bool]` | 0.0004694486876768187 | 0.00044644466229736907 | 4.90% | 5.15% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 0.00047715620422072617 | 0.0004902187672847542 | -2.74% | -2.66% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 0.0004780445925030643 | 0.00044736384157933236 | 6.42% | 6.86% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.0026164160833357735 | 0.0024873696450777296 | 4.93% | 5.19% | 1.05x | ✅ |
| `is_encodable_packed[uint256]` | 0.0010646539598269432 | 0.001020035994754669 | 4.19% | 4.37% | 1.04x | ✅ |
