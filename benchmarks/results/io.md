#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.0007063370641622521 | 0.0006340939787246582 | 10.23% | 11.39% | 1.11x | ✅ |
| `contextframesbytesio_init[1024]` | 0.000710489441625765 | 0.0006300331756770045 | 11.32% | 12.77% | 1.13x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007104674862502114 | 0.0006284635122407562 | 11.54% | 13.05% | 1.13x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007132292568803228 | 0.0006242050371947101 | 12.48% | 14.26% | 1.14x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0007059292232575704 | 0.0006241206312411515 | 11.59% | 13.11% | 1.13x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.0010052998817556744 | 0.0009897633553532228 | 1.55% | 1.57% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.0001276760949057176 | 0.00011636038214397706 | 8.86% | 9.72% | 1.10x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.0051753522577174995 | 0.0051761207564772396 | -0.01% | -0.01% | 1.00x | ❌ |
| `contextframesbytesio_push_pop[5]` | 0.000506837614897834 | 0.0004889070467100895 | 3.54% | 3.67% | 1.04x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.0004671919977049081 | 0.0004759783810899251 | -1.88% | -1.85% | 0.98x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 6.07311882092939e-05 | 6.0122691580696984e-05 | 1.00% | 1.01% | 1.01x | ✅ |
| `contextframesbytesio_seek_in_frame[50]` | 0.002221380966284925 | 0.0022883506591886895 | -3.01% | -2.93% | 0.97x | ❌ |
| `contextframesbytesio_seek_in_frame[5]` | 0.00022259760441146738 | 0.00022017339197615246 | 1.09% | 1.10% | 1.01x | ✅ |
