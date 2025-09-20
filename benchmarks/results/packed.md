#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001221845543639871 | 0.0004642012005752417 | 62.01% | 163.21% | 2.63x | ✅ |
| `encode_packed[bool]` | 0.0006967080816680966 | 0.00028568790720734247 | 58.99% | 143.87% | 2.44x | ✅ |
| `encode_packed[bytes]` | 0.0006648356074355836 | 0.00027283390351366053 | 58.96% | 143.68% | 2.44x | ✅ |
| `encode_packed[string]` | 0.0007014340944845991 | 0.0003017474559481132 | 56.98% | 132.46% | 2.32x | ✅ |
| `encode_packed[tuple]` | 0.0016531192155736685 | 0.0009755080032996226 | 40.99% | 69.46% | 1.69x | ✅ |
| `encode_packed[uint256]` | 0.0008697803909502059 | 0.00041958193733433 | 51.76% | 107.30% | 2.07x | ✅ |
| `is_encodable_packed[address]` | 6.32483402009067e-05 | 4.83600286630456e-05 | 23.54% | 30.79% | 1.31x | ✅ |
| `is_encodable_packed[bool]` | 4.520311059936889e-05 | 4.274817770483397e-05 | 5.43% | 5.74% | 1.06x | ✅ |
| `is_encodable_packed[bytes]` | 4.503768486164458e-05 | 4.754257408186839e-05 | -5.56% | -5.27% | 0.95x | ❌ |
| `is_encodable_packed[string]` | 4.504743481578362e-05 | 4.101614235698907e-05 | 8.95% | 9.83% | 1.10x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002539400301381884 | 0.00023645592489117775 | 6.89% | 7.39% | 1.07x | ✅ |
| `is_encodable_packed[uint256]` | 9.889311951932138e-05 | 9.274927826619745e-05 | 6.21% | 6.62% | 1.07x | ✅ |
