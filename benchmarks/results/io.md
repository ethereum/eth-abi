#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.000709778413532847 | 0.0006311491504603054 | 11.08% | 12.46% | 1.12x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007093532315881616 | 0.0006328878537238532 | 10.78% | 12.08% | 1.12x | ✅ |
| `contextframesbytesio_init[32]` | 0.0006999869370940132 | 0.0006276296958415837 | 10.34% | 11.53% | 1.12x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007097379834054404 | 0.0006257087224013261 | 11.84% | 13.43% | 1.13x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0006980514803521202 | 0.0006171805270701306 | 11.59% | 13.10% | 1.13x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.0009917961981842967 | 0.0009809725685651454 | 1.09% | 1.10% | 1.01x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.0001271336292083499 | 0.00011743552794200428 | 7.63% | 8.26% | 1.08x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.005141117989683387 | 0.005108096302564473 | 0.64% | 0.65% | 1.01x | ✅ |
| `contextframesbytesio_push_pop[5]` | 0.000498389548642295 | 0.0004810117581095292 | 3.49% | 3.61% | 1.04x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00047186162194275946 | 0.0004787499488793966 | -1.46% | -1.44% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 5.9650868121157534e-05 | 6.003900522535208e-05 | -0.65% | -0.65% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[50]` | 0.00224156859284524 | 0.002294551341860507 | -2.36% | -2.31% | 0.98x | ❌ |
| `contextframesbytesio_seek_in_frame[5]` | 0.0002168636784387772 | 0.00021915202764085498 | -1.06% | -1.04% | 0.99x | ❌ |
