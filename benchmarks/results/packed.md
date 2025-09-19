#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001241195964179989 | 0.000515474294889088 | 58.47% | 140.79% | 2.41x | ✅ |
| `encode_packed[bool]` | 0.0007116777894276213 | 0.0003302920478692216 | 53.59% | 115.47% | 2.15x | ✅ |
| `encode_packed[bytes]` | 0.000643425432567247 | 0.0003082782844971359 | 52.09% | 108.72% | 2.09x | ✅ |
| `encode_packed[string]` | 0.000702988928621008 | 0.00033644787859245706 | 52.14% | 108.94% | 2.09x | ✅ |
| `encode_packed[tuple]` | 0.001691542385584513 | 0.0010403820635813492 | 38.50% | 62.59% | 1.63x | ✅ |
| `encode_packed[uint256]` | 0.0008574249403316115 | 0.0004595255279080091 | 46.41% | 86.59% | 1.87x | ✅ |
| `is_encodable_packed[address]` | 6.67607231196809e-05 | 5.0698476677151345e-05 | 24.06% | 31.68% | 1.32x | ✅ |
| `is_encodable_packed[bool]` | 4.6911000661618565e-05 | 4.461445073986714e-05 | 4.90% | 5.15% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.692766936158604e-05 | 4.871638293065248e-05 | -3.81% | -3.67% | 0.96x | ❌ |
| `is_encodable_packed[string]` | 4.7182618213695334e-05 | 4.450789191870243e-05 | 5.67% | 6.01% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.000261962137390462 | 0.0002454183450332543 | 6.32% | 6.74% | 1.07x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010764755632086585 | 9.930286413553913e-05 | 7.75% | 8.40% | 1.08x | ✅ |
