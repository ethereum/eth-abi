#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001232520584827116 | 0.0004919011417794966 | 60.09% | 150.56% | 2.51x | ✅ |
| `encode_packed[bool]` | 0.000708956032385657 | 0.0003146977996200331 | 55.61% | 125.28% | 2.25x | ✅ |
| `encode_packed[bytes]` | 0.0006513153693407876 | 0.0002992450443985904 | 54.06% | 117.65% | 2.18x | ✅ |
| `encode_packed[string]` | 0.0007045617152823181 | 0.0003247789894720723 | 53.90% | 116.94% | 2.17x | ✅ |
| `encode_packed[tuple]` | 0.0016713743018193451 | 0.0010108864563761126 | 39.52% | 65.34% | 1.65x | ✅ |
| `encode_packed[uint256]` | 0.0008444138751185062 | 0.0004420840366740144 | 47.65% | 91.01% | 1.91x | ✅ |
| `is_encodable_packed[address]` | 6.652674639804143e-05 | 4.951854842222464e-05 | 25.57% | 34.35% | 1.34x | ✅ |
| `is_encodable_packed[bool]` | 4.6272754667010185e-05 | 4.460941116595921e-05 | 3.59% | 3.73% | 1.04x | ✅ |
| `is_encodable_packed[bytes]` | 4.70857860271067e-05 | 4.8232151825633386e-05 | -2.43% | -2.38% | 0.98x | ❌ |
| `is_encodable_packed[string]` | 4.736375760474304e-05 | 4.433993452524485e-05 | 6.38% | 6.82% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.00025807416181390284 | 0.00024127150412259018 | 6.51% | 6.96% | 1.07x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010553528413857512 | 9.842088204026656e-05 | 6.74% | 7.23% | 1.07x | ✅ |
