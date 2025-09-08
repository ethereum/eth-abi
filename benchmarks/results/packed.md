#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012352296136043993 | 0.0006972202670419901 | 43.56% | 77.16% | 1.77x | ✅ |
| `encode_packed[bool]` | 0.0007015725982577993 | 0.000483235445888248 | 31.12% | 45.18% | 1.45x | ✅ |
| `encode_packed[bytes]` | 0.0006479526323080355 | 0.0004673560168024468 | 27.87% | 38.64% | 1.39x | ✅ |
| `encode_packed[string]` | 0.000694240838098371 | 0.0004951634730866254 | 28.68% | 40.20% | 1.40x | ✅ |
| `encode_packed[tuple]` | 0.0016595742241929414 | 0.0013895637346355363 | 16.27% | 19.43% | 1.19x | ✅ |
| `encode_packed[uint256]` | 0.0008492259086498018 | 0.000611530823780934 | 27.99% | 38.87% | 1.39x | ✅ |
| `is_encodable_packed[address]` | 6.564427340897645e-05 | 5.6118050021575566e-05 | 14.51% | 16.98% | 1.17x | ✅ |
| `is_encodable_packed[bool]` | 4.627602503600989e-05 | 4.352883039688898e-05 | 5.94% | 6.31% | 1.06x | ✅ |
| `is_encodable_packed[bytes]` | 4.6725327041884185e-05 | 4.765882031859852e-05 | -2.00% | -1.96% | 0.98x | ❌ |
| `is_encodable_packed[string]` | 4.6890284010477374e-05 | 4.4276264874353503e-05 | 5.57% | 5.90% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.00025731088729884536 | 0.0002501853906418298 | 2.77% | 2.85% | 1.03x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010659410109692489 | 0.00010102193145785179 | 5.23% | 5.52% | 1.06x | ✅ |
