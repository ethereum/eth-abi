#### [faster_eth_abi.packed](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/packed.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_packed_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `encode_packed[address]` | 0.001217228526528344 | 0.00046599545938407887 | 61.72% | 161.21% | 2.61x | ✅ |
| `encode_packed[bool]` | 0.0007026740675978802 | 0.0002884403523552403 | 58.95% | 143.61% | 2.44x | ✅ |
| `encode_packed[bytes]` | 0.0006537045872786441 | 0.00027316979440317727 | 58.21% | 139.30% | 2.39x | ✅ |
| `encode_packed[string]` | 0.0006970656784019646 | 0.0003105855271226293 | 55.44% | 124.44% | 2.24x | ✅ |
| `encode_packed[tuple]` | 0.001671474277375398 | 0.0009702401844126651 | 41.95% | 72.27% | 1.72x | ✅ |
| `encode_packed[uint256]` | 0.0008442100009738332 | 0.00041568734869811203 | 50.76% | 103.09% | 2.03x | ✅ |
| `is_encodable_packed[address]` | 6.318270974150896e-05 | 4.772102616398081e-05 | 24.47% | 32.40% | 1.32x | ✅ |
| `is_encodable_packed[bool]` | 4.618953311439497e-05 | 4.234488149558817e-05 | 8.32% | 9.08% | 1.09x | ✅ |
| `is_encodable_packed[bytes]` | 4.462615407491695e-05 | 4.583949790441089e-05 | -2.72% | -2.65% | 0.97x | ❌ |
| `is_encodable_packed[string]` | 4.474408123598728e-05 | 4.0902075757313064e-05 | 8.59% | 9.39% | 1.09x | ✅ |
| `is_encodable_packed[tuple]` | 0.0002551335655144296 | 0.00023769331888500768 | 6.84% | 7.34% | 1.07x | ✅ |
| `is_encodable_packed[uint256]` | 0.00010300220596039246 | 9.275693841306861e-05 | 9.95% | 11.05% | 1.11x | ✅ |
