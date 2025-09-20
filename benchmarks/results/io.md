#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.0007932561095898091 | 0.000705381960112983 | 11.08% | 12.46% | 1.12x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007914556788027634 | 0.000711600585762044 | 10.09% | 11.22% | 1.11x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007831411697502067 | 0.0007096232366582766 | 9.39% | 10.36% | 1.10x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007915185407823235 | 0.0007145938943916042 | 9.72% | 10.76% | 1.11x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0007984584939488384 | 0.0007101347701271012 | 11.06% | 12.44% | 1.12x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.000976845505507159 | 0.0009492487999971416 | 2.83% | 2.91% | 1.03x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.00011932788194206986 | 0.0001127920574681299 | 5.48% | 5.79% | 1.06x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.0048952348599937065 | 0.005000028560974586 | -2.14% | -2.10% | 0.98x | ❌ |
| `contextframesbytesio_push_pop[5]` | 0.00048056513904788775 | 0.00046880156078214877 | 2.45% | 2.51% | 1.03x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00042996663028393165 | 0.0004306486082848513 | -0.16% | -0.16% | 1.00x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 5.514160515461231e-05 | 5.4670472162261095e-05 | 0.85% | 0.86% | 1.01x | ✅ |
| `contextframesbytesio_seek_in_frame[50]` | 0.0020717584617106722 | 0.002055644327051205 | 0.78% | 0.78% | 1.01x | ✅ |
| `contextframesbytesio_seek_in_frame[5]` | 0.0001965186067138313 | 0.00019672957371336193 | -0.11% | -0.11% | 1.00x | ❌ |
