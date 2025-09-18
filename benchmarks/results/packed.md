#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012153883599461163 | 0.0006689159443616623 | 44.96% | 81.70% | 1.82x | ✅ |
| `encode_packed[bool]` | 0.0006956601602175397 | 0.00048756719687118586 | 29.91% | 42.68% | 1.43x | ✅ |
| `encode_packed[bytes]` | 0.0006471948340412071 | 0.00047236513717888206 | 27.01% | 37.01% | 1.37x | ✅ |
| `encode_packed[string]` | 0.0006953514669313346 | 0.00050313927799467 | 27.64% | 38.20% | 1.38x | ✅ |
| `encode_packed[tuple]` | 0.0016632274938355354 | 0.0013845730941726105 | 16.75% | 20.13% | 1.20x | ✅ |
| `encode_packed[uint256]` | 0.0008553505999999467 | 0.0006120787665042423 | 28.44% | 39.75% | 1.40x | ✅ |
| `is_encodable_packed[address]` | 6.775125880745628e-05 | 4.9916809623381495e-05 | 26.32% | 35.73% | 1.36x | ✅ |
| `is_encodable_packed[bool]` | 4.678532283483881e-05 | 4.4457605824089264e-05 | 4.98% | 5.24% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.731860066333984e-05 | 4.8552754063753013e-05 | -2.61% | -2.54% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 4.6846002319904555e-05 | 4.419589533807449e-05 | 5.66% | 6.00% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002608965390242676 | 0.0002443975028680138 | 6.32% | 6.75% | 1.07x | ✅ |
| `is_encodable_packed[uint256]` | 0.0001079148221705568 | 9.536934697945999e-05 | 11.63% | 13.15% | 1.13x | ✅ |
