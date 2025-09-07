#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012424578206929285 | 0.0006906224914193296 | 44.41% | 79.90% | 1.80x | ✅ |
| `encode_packed[bool]` | 0.000701808866051717 | 0.0004824208672701166 | 31.26% | 45.48% | 1.45x | ✅ |
| `encode_packed[bytes]` | 0.0006457758826000325 | 0.00046667062265906155 | 27.73% | 38.38% | 1.38x | ✅ |
| `encode_packed[string]` | 0.0006903113860621948 | 0.0004952233363633589 | 28.26% | 39.39% | 1.39x | ✅ |
| `encode_packed[tuple]` | 0.0016842065783830632 | 0.0013842748724026087 | 17.81% | 21.67% | 1.22x | ✅ |
| `encode_packed[uint256]` | 0.0008657544901412313 | 0.0006192079745557169 | 28.48% | 39.82% | 1.40x | ✅ |
| `is_encodable_packed[address]` | 6.621475091958854e-05 | 5.5622131735079554e-05 | 16.00% | 19.04% | 1.19x | ✅ |
| `is_encodable_packed[bool]` | 4.7101500361981966e-05 | 4.496146822069466e-05 | 4.54% | 4.76% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.6934542730493314e-05 | 4.824404799583859e-05 | -2.79% | -2.71% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 4.687742216041781e-05 | 4.427070418486778e-05 | 5.56% | 5.89% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.00026402546200227496 | 0.000255464315959008 | 3.24% | 3.35% | 1.03x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010716383139841588 | 0.00010184991969553102 | 4.96% | 5.22% | 1.05x | ✅ |
