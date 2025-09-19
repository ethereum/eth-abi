#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.0007036586877258376 | 0.0006344098155314929 | 9.84% | 10.92% | 1.11x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007122456496199893 | 0.0006397718706289453 | 10.18% | 11.33% | 1.11x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007006943990022443 | 0.0006465469394899393 | 7.73% | 8.37% | 1.08x | ✅ |
| `contextframesbytesio_init[4096]` | 0.000683348767456734 | 0.0006353432142384471 | 7.03% | 7.56% | 1.08x | ✅ |
| `contextframesbytesio_init[65536]` | 0.000712422983382819 | 0.0006343121728143077 | 10.96% | 12.31% | 1.12x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.0010072392760783172 | 0.0009800599563508034 | 2.70% | 2.77% | 1.03x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.00012644723224366784 | 0.0001171319261883909 | 7.37% | 7.95% | 1.08x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.005111298274620534 | 0.0050245023724433315 | 1.70% | 1.73% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[5]` | 0.0004988337206331574 | 0.00047847149043595786 | 4.08% | 4.26% | 1.04x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00044175507059160564 | 0.00043781826291616413 | 0.89% | 0.90% | 1.01x | ✅ |
| `contextframesbytesio_seek_in_frame[1]` | 5.58370525436752e-05 | 5.6396381378465165e-05 | -1.00% | -0.99% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[50]` | 0.002121401490404057 | 0.0020942178624911395 | 1.28% | 1.30% | 1.01x | ✅ |
| `contextframesbytesio_seek_in_frame[5]` | 0.0002081448086869412 | 0.00022215756120306715 | -6.73% | -6.31% | 0.94x | ❌ |
