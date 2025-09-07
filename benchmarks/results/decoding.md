#### [faster_eth_abi.decoding](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/decoding.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_decoding_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `address_decoder[\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01]` | 0.01689216636208161 | 0.009775391970584215 | 42.13% | 72.80% | 1.73x | ✅ |
| `address_decoder[\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff]` | 0.01707838049999517 | 0.00988935224510705 | 42.09% | 72.69% | 1.73x | ✅ |
| `boolean_decoder[False]` | 0.009068288157410339 | 0.006826170263511474 | 24.72% | 32.85% | 1.33x | ✅ |
| `boolean_decoder[True]` | 0.009085531899086789 | 0.006856732102193687 | 24.53% | 32.51% | 1.33x | ✅ |
| `bytes32_decoder[\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00]` | 0.008943264090089952 | 0.006547490598689508 | 26.79% | 36.59% | 1.37x | ✅ |
| `bytes32_decoder[\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff]` | 0.008966880504498771 | 0.006569318928106494 | 26.74% | 36.50% | 1.36x | ✅ |
| `string_decoder[\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522]` | 0.01510022919697893 | 0.011039036277780825 | 26.89% | 36.79% | 1.37x | ✅ |
| `string_decoder[]` | 0.014694073134330835 | 0.01069468781720413 | 27.22% | 37.40% | 1.37x | ✅ |
| `string_decoder[hello world]` | 0.014965869552244854 | 0.010841962549454446 | 27.56% | 38.04% | 1.38x | ✅ |
| `tuple_decoder[bytes-string]` | 0.01847987951851935 | 0.01407855745069227 | 23.82% | 31.26% | 1.31x | ✅ |
| `tuple_decoder[int-bool]` | 0.012966676266660215 | 0.010497578684211667 | 19.04% | 23.52% | 1.24x | ✅ |
| `uint256_decoder[0]` | 0.009472510247620188 | 0.007042279000000357 | 25.66% | 34.51% | 1.35x | ✅ |
| `uint256_decoder[115792089237316195423570985008687907853269984665640564039457584007913129639935]` | 0.009453984846162965 | 0.00716274510713788 | 24.24% | 31.99% | 1.32x | ✅ |
| `uint256_decoder[1]` | 0.009499126790465847 | 0.007038998077466114 | 25.90% | 34.95% | 1.35x | ✅ |
