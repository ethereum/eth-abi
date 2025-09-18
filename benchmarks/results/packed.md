#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012318543165753103 | 0.0005176048930691627 | 57.98% | 137.99% | 2.38x | ✅ |
| `encode_packed[bool]` | 0.0007141598454306279 | 0.00032793214803405893 | 54.08% | 117.78% | 2.18x | ✅ |
| `encode_packed[bytes]` | 0.000646039883652879 | 0.00030426353752858115 | 52.90% | 112.33% | 2.12x | ✅ |
| `encode_packed[string]` | 0.0007215428048437192 | 0.0003360552425133301 | 53.43% | 114.71% | 2.15x | ✅ |
| `encode_packed[tuple]` | 0.0017127456666676086 | 0.0010726653903883746 | 37.37% | 59.67% | 1.60x | ✅ |
| `encode_packed[uint256]` | 0.0008835515708535387 | 0.00047124525629164515 | 46.66% | 87.49% | 1.87x | ✅ |
| `is_encodable_packed[address]` | 6.713942212052012e-05 | 5.004914943881744e-05 | 25.45% | 34.15% | 1.34x | ✅ |
| `is_encodable_packed[bool]` | 4.665692501322982e-05 | 4.465897007887227e-05 | 4.28% | 4.47% | 1.04x | ✅ |
| `is_encodable_packed[bytes]` | 4.747667235421906e-05 | 4.842162896492762e-05 | -1.99% | -1.95% | 0.98x | ❌ |
| `is_encodable_packed[string]` | 4.665512268323288e-05 | 4.344403063570568e-05 | 6.88% | 7.39% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.00025911867285940244 | 0.0002453011786942289 | 5.33% | 5.63% | 1.06x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010812458548747668 | 0.00010040344879438336 | 7.14% | 7.69% | 1.08x | ✅ |
