#### [faster_eth_abi.encoding](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/encoding.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_encoding_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `address_encoder[\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01]` | 0.012440972974364065 | 0.006999943971634898 | 43.73% | 77.73% | 1.78x | ✅ |
| `address_encoder[\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff]` | 0.01247490302565287 | 0.007006500781692883 | 43.84% | 78.05% | 1.78x | ✅ |
| `boolean_encoder[False]` | 0.007064947297873482 | 0.004892857105525978 | 30.74% | 44.39% | 1.44x | ✅ |
| `boolean_encoder[True]` | 0.007050301071430048 | 0.004859979148519225 | 31.07% | 45.07% | 1.45x | ✅ |
| `bytes32_encoder[\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00]` | 0.006960818041956519 | 0.004855252810943175 | 30.25% | 43.37% | 1.43x | ✅ |
| `bytes32_encoder[\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff]` | 0.006981376894369968 | 0.004862125465351845 | 30.36% | 43.59% | 1.44x | ✅ |
| `string_encoder[\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522]` | 0.011702408682355567 | 0.007188975123188561 | 38.57% | 62.78% | 1.63x | ✅ |
| `string_encoder[]` | 0.011510994325587574 | 0.006963955492959889 | 39.50% | 65.29% | 1.65x | ✅ |
| `string_encoder[hello world]` | 0.011651472517646385 | 0.007072861599998045 | 39.30% | 64.73% | 1.65x | ✅ |
| `tuple_encoder[bytes-string]` | 0.013505837972592704 | 0.008642320877201152 | 36.01% | 56.28% | 1.56x | ✅ |
| `tuple_encoder[int-bool]` | 0.010228197484538607 | 0.007540741638466058 | 26.27% | 35.64% | 1.36x | ✅ |
| `uint256_encoder[0]` | 0.00859957565486401 | 0.006245444112501985 | 27.37% | 37.69% | 1.38x | ✅ |
| `uint256_encoder[115792089237316195423570985008687907853269984665640564039457584007913129639935]` | 0.008685947756515341 | 0.006250273717946642 | 28.04% | 38.97% | 1.39x | ✅ |
| `uint256_encoder[1]` | 0.008551316747825102 | 0.006154532607595258 | 28.03% | 38.94% | 1.39x | ✅ |
