#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012219228289868098 | 0.0006478444272448083 | 46.98% | 88.61% | 1.89x | ✅ |
| `encode_packed[bool]` | 0.0007056401636516347 | 0.0004828079248264734 | 31.58% | 46.15% | 1.46x | ✅ |
| `encode_packed[bytes]` | 0.0006604111530577269 | 0.00046504883410998163 | 29.58% | 42.01% | 1.42x | ✅ |
| `encode_packed[string]` | 0.0006954503310024442 | 0.0004948546275837563 | 28.84% | 40.54% | 1.41x | ✅ |
| `encode_packed[tuple]` | 0.001660124387787065 | 0.0013544963239605589 | 18.41% | 22.56% | 1.23x | ✅ |
| `encode_packed[uint256]` | 0.0008361188966504178 | 0.0006087914785934612 | 27.19% | 37.34% | 1.37x | ✅ |
| `is_encodable_packed[address]` | 6.713967405309677e-05 | 5.005693013287788e-05 | 25.44% | 34.13% | 1.34x | ✅ |
| `is_encodable_packed[bool]` | 4.6254523386652955e-05 | 4.471250982394081e-05 | 3.33% | 3.45% | 1.03x | ✅ |
| `is_encodable_packed[bytes]` | 4.744071872395083e-05 | 4.814804754916712e-05 | -1.49% | -1.47% | 0.99x | ❌ |
| `is_encodable_packed[string]` | 4.721375532467133e-05 | 4.4657027956601053e-05 | 5.42% | 5.73% | 1.06x | ✅ |
| `is_encodable_packed[tuple]` | 0.00025962329001562133 | 0.00024052753185360677 | 7.36% | 7.94% | 1.08x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010700797089903256 | 9.626486706238215e-05 | 10.04% | 11.16% | 1.11x | ✅ |
