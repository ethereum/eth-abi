#### [faster_eth_abi.io](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/io.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_io_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `contextframesbytesio_init[0]` | 0.0006916757543106231 | 0.0006156727869169721 | 10.99% | 12.34% | 1.12x | ✅ |
| `contextframesbytesio_init[1024]` | 0.000695217647099938 | 0.0006273698026744377 | 9.76% | 10.81% | 1.11x | ✅ |
| `contextframesbytesio_init[32]` | 0.0006964992733080725 | 0.0006322335706063803 | 9.23% | 10.16% | 1.10x | ✅ |
| `contextframesbytesio_init[4096]` | 0.0007076694954288641 | 0.0006309436649380274 | 10.84% | 12.16% | 1.12x | ✅ |
| `contextframesbytesio_init[65536]` | 0.0006972213987064907 | 0.0006274050547340023 | 10.01% | 11.13% | 1.11x | ✅ |
| `contextframesbytesio_push_pop[10]` | 0.0009943395928930009 | 0.0009722449266619611 | 2.22% | 2.27% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[1]` | 0.00012426045828339832 | 0.00011284475069084935 | 9.19% | 10.12% | 1.10x | ✅ |
| `contextframesbytesio_push_pop[50]` | 0.00508092560605953 | 0.0049740819300063775 | 2.10% | 2.15% | 1.02x | ✅ |
| `contextframesbytesio_push_pop[5]` | 0.0004926642915599861 | 0.00047801598214433064 | 2.97% | 3.06% | 1.03x | ✅ |
| `contextframesbytesio_seek_in_frame[10]` | 0.00043104618620524326 | 0.00043169480463304925 | -0.15% | -0.15% | 1.00x | ❌ |
| `contextframesbytesio_seek_in_frame[1]` | 5.54606438518468e-05 | 5.533175830424088e-05 | 0.23% | 0.23% | 1.00x | ✅ |
| `contextframesbytesio_seek_in_frame[50]` | 0.0020787178993305947 | 0.0020756514016685673 | 0.15% | 0.15% | 1.00x | ✅ |
| `contextframesbytesio_seek_in_frame[5]` | 0.00020104071334579312 | 0.00020113061748738755 | -0.04% | -0.04% | 1.00x | ❌ |
