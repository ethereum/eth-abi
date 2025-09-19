#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012219874743439457 | 0.00047283622410503235 | 61.31% | 158.44% | 2.58x | ✅ |
| `encode_packed[bool]` | 0.000716401856017768 | 0.00028780166796061143 | 59.83% | 148.92% | 2.49x | ✅ |
| `encode_packed[bytes]` | 0.000655177926358037 | 0.0002700914091331561 | 58.78% | 142.58% | 2.43x | ✅ |
| `encode_packed[string]` | 0.0007002126340307804 | 0.0003050923223201857 | 56.43% | 129.51% | 2.30x | ✅ |
| `encode_packed[tuple]` | 0.0016729555111148194 | 0.0009722460852171327 | 41.88% | 72.07% | 1.72x | ✅ |
| `encode_packed[uint256]` | 0.0008552179805422823 | 0.0004178483315237977 | 51.14% | 104.67% | 2.05x | ✅ |
| `is_encodable_packed[address]` | 6.428034448261394e-05 | 4.870457423293942e-05 | 24.23% | 31.98% | 1.32x | ✅ |
| `is_encodable_packed[bool]` | 4.4434584033926474e-05 | 4.147265496741318e-05 | 6.67% | 7.14% | 1.07x | ✅ |
| `is_encodable_packed[bytes]` | 4.5656341473481054e-05 | 4.627828117457766e-05 | -1.36% | -1.34% | 0.99x | ❌ |
| `is_encodable_packed[string]` | 4.49460362522218e-05 | 4.158172672226004e-05 | 7.49% | 8.09% | 1.08x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002537932197137793 | 0.0002379921337238862 | 6.23% | 6.64% | 1.07x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010160612326972158 | 9.318524904230477e-05 | 8.29% | 9.04% | 1.09x | ✅ |
