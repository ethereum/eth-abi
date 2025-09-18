#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001229880834244322 | 0.0005136166431764248 | 58.24% | 139.46% | 2.39x | ✅ |
| `encode_packed[bool]` | 0.0007063573982450989 | 0.0003281111755171297 | 53.55% | 115.28% | 2.15x | ✅ |
| `encode_packed[bytes]` | 0.0006551254795218796 | 0.00030628789765581034 | 53.25% | 113.89% | 2.14x | ✅ |
| `encode_packed[string]` | 0.0006990517642220693 | 0.00033424756800793547 | 52.19% | 109.14% | 2.09x | ✅ |
| `encode_packed[tuple]` | 0.0016840898989100887 | 0.0010737208908654665 | 36.24% | 56.85% | 1.57x | ✅ |
| `encode_packed[uint256]` | 0.0008608854785134845 | 0.00047728578199834334 | 44.56% | 80.37% | 1.80x | ✅ |
| `is_encodable_packed[address]` | 6.838782271791304e-05 | 5.005989882387871e-05 | 26.80% | 36.61% | 1.37x | ✅ |
| `is_encodable_packed[bool]` | 4.640402023509547e-05 | 4.428423375569392e-05 | 4.57% | 4.79% | 1.05x | ✅ |
| `is_encodable_packed[bytes]` | 4.675529979780707e-05 | 4.8075590655379536e-05 | -2.82% | -2.75% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 4.670026561647273e-05 | 4.4206790645957006e-05 | 5.34% | 5.64% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.00025972692406965646 | 0.00024728006744351307 | 4.79% | 5.03% | 1.05x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010777714582217768 | 9.884972527220044e-05 | 8.28% | 9.03% | 1.09x | ✅ |
