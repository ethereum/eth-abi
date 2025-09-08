#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.00127121281881375 | 0.0007124315820931032 | 43.96% | 78.43% | 1.78x | ✅ |
| `encode_packed[bool]` | 0.0007198374334717412 | 0.0004964975445895707 | 31.03% | 44.98% | 1.45x | ✅ |
| `encode_packed[bytes]` | 0.0006694285476894733 | 0.0004889488160598851 | 26.96% | 36.91% | 1.37x | ✅ |
| `encode_packed[string]` | 0.0007135190458167378 | 0.000520107946721766 | 27.11% | 37.19% | 1.37x | ✅ |
| `encode_packed[tuple]` | 0.001699985130204503 | 0.0014211415517268885 | 16.40% | 19.62% | 1.20x | ✅ |
| `encode_packed[uint256]` | 0.0008618299082699775 | 0.0006386936433634158 | 25.89% | 34.94% | 1.35x | ✅ |
| `is_encodable_packed[address]` | 6.912174465896531e-05 | 5.5793772946170637e-05 | 19.28% | 23.89% | 1.24x | ✅ |
| `is_encodable_packed[bool]` | 4.679089201677269e-05 | 4.424046819855182e-05 | 5.45% | 5.76% | 1.06x | ✅ |
| `is_encodable_packed[bytes]` | 4.737825971860499e-05 | 4.765537937408061e-05 | -0.58% | -0.58% | 0.99x | ❌ |
| `is_encodable_packed[string]` | 4.70616994866798e-05 | 4.420926679628467e-05 | 6.06% | 6.45% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002659261296592961 | 0.0002522486781744398 | 5.14% | 5.42% | 1.05x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010751722694437976 | 0.00010130881866228321 | 5.77% | 6.13% | 1.06x | ✅ |
