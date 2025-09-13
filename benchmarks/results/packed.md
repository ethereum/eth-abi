#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001216779634856195 | 0.0006576229036687543 | 45.95% | 85.03% | 1.85x | ✅ |
| `encode_packed[bool]` | 0.0006997649092971385 | 0.00047848823399726823 | 31.62% | 46.24% | 1.46x | ✅ |
| `encode_packed[bytes]` | 0.0006474165287175181 | 0.0004684514098791573 | 27.64% | 38.20% | 1.38x | ✅ |
| `encode_packed[string]` | 0.0006931604505343937 | 0.0004965794997133082 | 28.36% | 39.59% | 1.40x | ✅ |
| `encode_packed[tuple]` | 0.0016448995106374893 | 0.0013553682452570384 | 17.60% | 21.36% | 1.21x | ✅ |
| `encode_packed[uint256]` | 0.0008325970640776927 | 0.0006015385225193542 | 27.75% | 38.41% | 1.38x | ✅ |
| `is_encodable_packed[address]` | 6.634922562504611e-05 | 5.0632857506322506e-05 | 23.69% | 31.04% | 1.31x | ✅ |
| `is_encodable_packed[bool]` | 4.723589190546261e-05 | 4.4968144515503684e-05 | 4.80% | 5.04% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.683426741440734e-05 | 4.8288305154983363e-05 | -3.10% | -3.01% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 4.7599343657348824e-05 | 4.4604124255433506e-05 | 6.29% | 6.72% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.00026012856642817567 | 0.00024159893675233674 | 7.12% | 7.67% | 1.08x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010586296853258182 | 9.472271534826588e-05 | 10.52% | 11.76% | 1.12x | ✅ |
