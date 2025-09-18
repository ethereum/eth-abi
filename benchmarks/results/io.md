#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.00071332445360797 | 0.0006326804255871865 | 11.31% | 12.75% | 1.13x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007155086582033407 | 0.0006332604675820714 | 11.50% | 12.99% | 1.13x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007102526873643414 | 0.0006313298537070716 | 11.11% | 12.50% | 1.13x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007143834970611217 | 0.0006315529202486721 | 11.59% | 13.12% | 1.13x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0007101608252887486 | 0.0006296077415978401 | 11.34% | 12.79% | 1.13x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.0010068129151318457 | 0.0009901498639106967 | 1.66% | 1.68% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.0001310708816893046 | 0.00012046516954430846 | 8.09% | 8.80% | 1.09x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.0051758803999949745 | 0.0052255835624978415 | -0.96% | -0.95% | 0.99x | ❌ |
| `contextframesbytesio_push_pop[5]` | 0.0005039965276128853 | 0.0004874462430633622 | 3.28% | 3.40% | 1.03x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00047751353016214806 | 0.0004771105372897579 | 0.08% | 0.08% | 1.00x | ✅ |
| `contextframesbytesio_seek_in_frame[1]` | 5.9426421154820975e-05 | 6.065150425572556e-05 | -2.06% | -2.02% | 0.98x | ❌ |
| `contextframesbytesio_seek_in_frame[50]` | 0.002255437291857635 | 0.002256178449308695 | -0.03% | -0.03% | 1.00x | ❌ |
| `contextframesbytesio_seek_in_frame[5]` | 0.00021960583779381818 | 0.0002219136712985773 | -1.05% | -1.04% | 0.99x | ❌ |
