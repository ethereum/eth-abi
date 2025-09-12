#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012877845759368554 | 0.0007132675459057151 | 44.61% | 80.55% | 1.81x | ✅ |
| `encode_packed[bool]` | 0.0007267812571435385 | 0.0004968288738020568 | 31.64% | 46.28% | 1.46x | ✅ |
| `encode_packed[bytes]` | 0.0006768702135008076 | 0.0004823037311743104 | 28.75% | 40.34% | 1.40x | ✅ |
| `encode_packed[string]` | 0.0007211363100639813 | 0.0005182021754410054 | 28.14% | 39.16% | 1.39x | ✅ |
| `encode_packed[tuple]` | 0.0017790146653371968 | 0.0014393341079770399 | 19.09% | 23.60% | 1.24x | ✅ |
| `encode_packed[uint256]` | 0.0008747629664212735 | 0.000642266899626435 | 26.58% | 36.20% | 1.36x | ✅ |
| `is_encodable_packed[address]` | 6.736015915379926e-05 | 5.620095813224932e-05 | 16.57% | 19.86% | 1.20x | ✅ |
| `is_encodable_packed[bool]` | 4.785611512583103e-05 | 4.561811384512352e-05 | 4.68% | 4.91% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.8884821956146967e-05 | 5.038318294253949e-05 | -3.07% | -2.97% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 4.8865063792902907e-05 | 4.6117232041957845e-05 | 5.62% | 5.96% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002678876648427365 | 0.00025957581345472584 | 3.10% | 3.20% | 1.03x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010797644157475159 | 0.00010403596503140046 | 3.65% | 3.79% | 1.04x | ✅ |
