#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.000711634170994221 | 0.0006280163697761712 | 11.75% | 13.31% | 1.13x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007114707400085608 | 0.0006279652996130875 | 11.74% | 13.30% | 1.13x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007133598602977412 | 0.0006261953775295877 | 12.22% | 13.92% | 1.14x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007115652326716691 | 0.0006269448451219617 | 11.89% | 13.50% | 1.13x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0007187194072484077 | 0.0006258636754546131 | 12.92% | 14.84% | 1.15x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.001011923172561264 | 0.0009850138024319855 | 2.66% | 2.73% | 1.03x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.0001285287688872737 | 0.0001163085266994592 | 9.51% | 10.51% | 1.11x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.005176489109373961 | 0.005211536796856819 | -0.68% | -0.67% | 0.99x | ❌ |
| `contextframesbytesio_push_pop[5]` | 0.0005054394469423558 | 0.0004891090035565094 | 3.23% | 3.34% | 1.03x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00047440174061638853 | 0.0004778624204649614 | -0.73% | -0.72% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 5.9528339646568815e-05 | 5.9992199509424366e-05 | -0.78% | -0.77% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[50]` | 0.002277706500006733 | 0.0022624927356226744 | 0.67% | 0.67% | 1.01x | ✅ |
| `contextframesbytesio_seek_in_frame[5]` | 0.00022148371662884065 | 0.00022182407218643096 | -0.15% | -0.15% | 1.00x | ❌ |
