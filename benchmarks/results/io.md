#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.000702280488052767 | 0.0006382221722782764 | 9.12% | 10.04% | 1.10x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0006943204311424767 | 0.0006345107430032696 | 8.61% | 9.43% | 1.09x | ✅ |
| `contextframesbytesio_init[32]` | 0.0006918167610549579 | 0.0006314859462371962 | 8.72% | 9.55% | 1.10x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007012421439532523 | 0.0006449629926185438 | 8.03% | 8.73% | 1.09x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0006877057086890958 | 0.0006397177643656916 | 6.98% | 7.50% | 1.08x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.0009936983895857546 | 0.0009744818895555855 | 1.93% | 1.97% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.00012321094111397403 | 0.00011419937323606464 | 7.31% | 7.89% | 1.08x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.005054517293804087 | 0.005016226919596691 | 0.76% | 0.76% | 1.01x | ✅ |
| `contextframesbytesio_push_pop[5]` | 0.0004894251588894565 | 0.0004754618571430774 | 2.85% | 2.94% | 1.03x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00043287136469707385 | 0.0004358993385679164 | -0.70% | -0.69% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 5.6591158920751485e-05 | 5.550135223094932e-05 | 1.93% | 1.96% | 1.02x | ✅ |
| `contextframesbytesio_seek_in_frame[50]` | 0.0020701084862628756 | 0.0020686947023485633 | 0.07% | 0.07% | 1.00x | ✅ |
| `contextframesbytesio_seek_in_frame[5]` | 0.0001987498279641506 | 0.00020104154928934467 | -1.15% | -1.14% | 0.99x | ❌ |
