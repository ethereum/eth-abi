#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.0007067571745776138 | 0.0006250285518757437 | 11.56% | 13.08% | 1.13x | ✅ |
| `contextframesbytesio_init[1024]` | 0.0007045561730058052 | 0.0006222750583343639 | 11.68% | 13.22% | 1.13x | ✅ |
| `contextframesbytesio_init[32]` | 0.0007111766928037534 | 0.0006197267382179519 | 12.86% | 14.76% | 1.15x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007078480986127152 | 0.0006211585600511458 | 12.25% | 13.96% | 1.14x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0007084266305006684 | 0.0006200690575823433 | 12.47% | 14.25% | 1.14x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.001005937994903102 | 0.0009907472812571427 | 1.51% | 1.53% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.0001290722484896747 | 0.00011752417009292233 | 8.95% | 9.83% | 1.10x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.005190746476444912 | 0.005133508742263535 | 1.10% | 1.11% | 1.01x | ✅ |
| `contextframesbytesio_push_pop[5]` | 0.0005038898528526532 | 0.00048378305290147123 | 3.99% | 4.16% | 1.04x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.0004754192591875232 | 0.00047851418703041755 | -0.65% | -0.65% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 5.973075889299724e-05 | 6.0015875295065764e-05 | -0.48% | -0.48% | 1.00x | ❌ |
| `contextframesbytesio_seek_in_frame[50]` | 0.0022850265282196923 | 0.002316825655893588 | -1.39% | -1.37% | 0.99x | ❌ |
| `contextframesbytesio_seek_in_frame[5]` | 0.00022212432205699967 | 0.00022150297777965823 | 0.28% | 0.28% | 1.00x | ✅ |
