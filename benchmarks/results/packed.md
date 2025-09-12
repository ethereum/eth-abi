#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001238279579018855 | 0.000672911849227638 | 45.66% | 84.02% | 1.84x | ✅ |
| `encode_packed[bool]` | 0.0007018525975411625 | 0.0004967190987444151 | 29.23% | 41.30% | 1.41x | ✅ |
| `encode_packed[bytes]` | 0.0006605570166627424 | 0.0004875383735315632 | 26.19% | 35.49% | 1.35x | ✅ |
| `encode_packed[string]` | 0.0006990667922864798 | 0.0005115240028463519 | 26.83% | 36.66% | 1.37x | ✅ |
| `encode_packed[tuple]` | 0.001687364689787401 | 0.0014124371909105954 | 16.29% | 19.46% | 1.19x | ✅ |
| `encode_packed[uint256]` | 0.0008455865390628592 | 0.000635923446823259 | 24.79% | 32.97% | 1.33x | ✅ |
| `is_encodable_packed[address]` | 6.700322864948366e-05 | 5.033209757832473e-05 | 24.88% | 33.12% | 1.33x | ✅ |
| `is_encodable_packed[bool]` | 4.661526186412434e-05 | 4.477308851563733e-05 | 3.95% | 4.11% | 1.04x | ✅ |
| `is_encodable_packed[bytes]` | 4.718225991809653e-05 | 4.7975231220626915e-05 | -1.68% | -1.65% | 0.98x | ❌ |
| `is_encodable_packed[string]` | 4.899017321073881e-05 | 4.4953049724950836e-05 | 8.24% | 8.98% | 1.09x | ✅ |
| `is_encodable_packed[tuple]` | 0.00026424778090849483 | 0.0002537773636623082 | 3.96% | 4.13% | 1.04x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010691686212882553 | 9.510146493515127e-05 | 11.05% | 12.42% | 1.12x | ✅ |
