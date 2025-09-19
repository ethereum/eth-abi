#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012218056117223645 | 0.000499024863667985 | 59.16% | 144.84% | 2.45x | ✅ |
| `encode_packed[bool]` | 0.0006986817579133135 | 0.00030964609507991026 | 55.68% | 125.64% | 2.26x | ✅ |
| `encode_packed[bytes]` | 0.000643178050356039 | 0.0002949331742535305 | 54.14% | 118.08% | 2.18x | ✅ |
| `encode_packed[string]` | 0.0006884896560634515 | 0.00032358926290224185 | 53.00% | 112.77% | 2.13x | ✅ |
| `encode_packed[tuple]` | 0.0016779708165488125 | 0.0009862057352017725 | 41.23% | 70.14% | 1.70x | ✅ |
| `encode_packed[uint256]` | 0.0008490996906102318 | 0.0004380363347916079 | 48.41% | 93.84% | 1.94x | ✅ |
| `is_encodable_packed[address]` | 6.602636639706557e-05 | 5.029008226705936e-05 | 23.83% | 31.29% | 1.31x | ✅ |
| `is_encodable_packed[bool]` | 4.682922459833507e-05 | 4.4531335417097164e-05 | 4.91% | 5.16% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.708881598487672e-05 | 4.766449787117443e-05 | -1.22% | -1.21% | 0.99x | ❌ |
| `is_encodable_packed[string]` | 4.706462815966669e-05 | 4.41854180060975e-05 | 6.12% | 6.52% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.00026280705552773534 | 0.0002434514550880064 | 7.36% | 7.95% | 1.08x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010570515261037898 | 9.868018331353514e-05 | 6.65% | 7.12% | 1.07x | ✅ |
