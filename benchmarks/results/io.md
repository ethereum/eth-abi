#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.0007063509956717679 | 0.0006930396923565831 | 1.88% | 1.92% | 1.02x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007068609069280013 | 0.0006934382902340015 | 1.90% | 1.94% | 1.02x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007083556632610131 | 0.0006985169290775493 | 1.39% | 1.41% | 1.01x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007065467238401872 | 0.0007014640676660918 | 0.72% | 0.72% | 1.01x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0007048300114848916 | 0.0006949100775826574 | 1.41% | 1.43% | 1.01x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.001022065865227221 | 0.0009965406591626754 | 2.50% | 2.56% | 1.03x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.00013360113950064556 | 0.0001215275404362228 | 9.04% | 9.93% | 1.10x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.005199129239585432 | 0.005145817881433799 | 1.03% | 1.04% | 1.01x | ✅ |
| `contextframesbytesio_push_pop[5]` | 0.00050512003385188 | 0.0004973163865345108 | 1.54% | 1.57% | 1.02x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.0004808547368944789 | 0.0004833334952439015 | -0.52% | -0.51% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 6.06772170444504e-05 | 6.130267508851424e-05 | -1.03% | -1.02% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[50]` | 0.002295994220722597 | 0.00230813459728423 | -0.53% | -0.53% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[5]` | 0.00022312138350217469 | 0.0002228885404863618 | 0.10% | 0.10% | 1.00x | ✅ |
