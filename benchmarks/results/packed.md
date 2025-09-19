#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.0012056952028399255 | 0.000470146210410864 | 61.01% | 156.45% | 2.56x | ✅ |
| `encode_packed[bool]` | 0.0007047480643347444 | 0.00028475864330960066 | 59.59% | 147.49% | 2.47x | ✅ |
| `encode_packed[bytes]` | 0.0006573860803877143 | 0.00027388580606433407 | 58.34% | 140.02% | 2.40x | ✅ |
| `encode_packed[string]` | 0.0007105976773174352 | 0.00030927076828997233 | 56.48% | 129.77% | 2.30x | ✅ |
| `encode_packed[tuple]` | 0.0016656375362274964 | 0.0009564049467568282 | 42.58% | 74.16% | 1.74x | ✅ |
| `encode_packed[uint256]` | 0.0008407794280191587 | 0.0004167490040866705 | 50.43% | 101.75% | 2.02x | ✅ |
| `is_encodable_packed[address]` | 6.360671613247366e-05 | 4.8242051215308094e-05 | 24.16% | 31.85% | 1.32x | ✅ |
| `is_encodable_packed[bool]` | 4.340236014358792e-05 | 4.087990401565931e-05 | 5.81% | 6.17% | 1.06x | ✅ |
| `is_encodable_packed[bytes]` | 4.4287549496891685e-05 | 4.459167235981895e-05 | -0.69% | -0.68% | 0.99x | ❌ |
| `is_encodable_packed[string]` | 4.417007530185965e-05 | 4.1408762360419267e-05 | 6.25% | 6.67% | 1.07x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002526411614311424 | 0.000234728402685928 | 7.09% | 7.63% | 1.08x | ✅ |
| `is_encodable_packed[uint256]` | 9.704856734937285e-05 | 9.126393806412811e-05 | 5.96% | 6.34% | 1.06x | ✅ |
