#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012312349145158089 | 0.0007030976655675555 | 42.89% | 75.12% | 1.75x | ✅ |
| `encode_packed[bool]` | 0.0006914987920915087 | 0.0004861761514797005 | 29.69% | 42.23% | 1.42x | ✅ |
| `encode_packed[bytes]` | 0.0006491009008728941 | 0.00047043267394747423 | 27.53% | 37.98% | 1.38x | ✅ |
| `encode_packed[string]` | 0.0006961942015850005 | 0.0005015811336220698 | 27.95% | 38.80% | 1.39x | ✅ |
| `encode_packed[tuple]` | 0.0016662918594283515 | 0.0014007813544504146 | 15.93% | 18.95% | 1.19x | ✅ |
| `encode_packed[uint256]` | 0.0008461000841312005 | 0.0006198235493178331 | 26.74% | 36.51% | 1.37x | ✅ |
| `is_encodable_packed[address]` | 6.619917415214063e-05 | 5.504205633212067e-05 | 16.85% | 20.27% | 1.20x | ✅ |
| `is_encodable_packed[bool]` | 4.6470407776545095e-05 | 4.3791712300374426e-05 | 5.76% | 6.12% | 1.06x | ✅ |
| `is_encodable_packed[bytes]` | 4.686568912131492e-05 | 4.786427787106958e-05 | -2.13% | -2.09% | 0.98x | ❌ |
| `is_encodable_packed[string]` | 4.707747141267917e-05 | 4.4176903813881686e-05 | 6.16% | 6.57% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.00026001374224398987 | 0.0002493589246729029 | 4.10% | 4.27% | 1.04x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010734920240079085 | 0.00010060948772064698 | 6.28% | 6.70% | 1.07x | ✅ |
