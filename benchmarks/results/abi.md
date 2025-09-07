#### [faster_eth_abi.abi](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/faster_eth_abi/abi.py) - [view benchmarks](https://github.com/BobTheBuidler/faster-eth-abi/blob/master/benchmarks/test_abi_benchmarks.py)

| Function | Reference Mean | Faster Mean | % Change | Speedup (%) | x Faster | Faster |
|----------|---------------|-------------|----------|-------------|----------|--------|
| `decode_eth_abi[((uint8,uint8),uint8)-((1, 2), 3)]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[((uint8[2],(string,bool)),bytes32)-(([1, 2], ('hi',]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(address,uint8)-(b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(string,bytes)-('foo', b'bar')]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(string[],bytes[])-([''], [b''])]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint256,bool)-(42, True)]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint256[2],string)-([1, 2], 'baz')]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint256[],(string[],bool))-([1, 2, 3], (['a]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint8,(bool,string))-(7, (False, 'hi']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint8[2],(string,bool[2]))-([1, 2], ('x', []` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint8[2][2],(string[2],bool[2]))-([[1, 2], [3, 4]]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[(uint8[],string)-([], '')]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[address-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[address-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[address[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bool-False]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bool-True]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bool[4]-[True, False, Tr]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bool[][2]-[[True, False], ]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes-b'']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes-b'\\x00\\x00\\x00\\x0]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes-b'\\x00\\x00\\x00\\x1]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes-b'hello world']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes1-b'\\x01']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes32-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes32-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes32[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[bytes[]-[b'abc', b'def',]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[fixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[int256--578960446186580]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[int256-5789604461865809]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[int8--128]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[int8-127]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string-'']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string-'\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string-'aaaaaaaaaaaaaaa]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string-'hello world']` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string[2]-['foo', 'bar']]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string[]-['a', 'b', 'c']]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[string[]-[]]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[ufixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint256-0]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint256-1157920892373161]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint256[2]-[0, 115792089237]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint256[2][2]-[[1, 2], [3, 4]]]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint8-0]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint8-255]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint8[3]-[1, 2, 3]]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint8[]-[1, 2, 3, 4, 5]]` |  |  |  |  |  | ➖ |
| `decode_eth_abi[uint8[]-[]]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[((uint8,uint8),uint8)-((1, 2), 3)]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[((uint8[2],(string,bool)),bytes32)-(([1, 2], ('hi',]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(address,uint8)-(b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(string,bytes)-('foo', b'bar')]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(string[],bytes[])-([''], [b''])]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint256,bool)-(42, True)]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint256[2],string)-([1, 2], 'baz')]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint256[],(string[],bool))-([1, 2, 3], (['a]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint8,(bool,string))-(7, (False, 'hi']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint8[2],(string,bool[2]))-([1, 2], ('x', []` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint8[2][2],(string[2],bool[2]))-([[1, 2], [3, 4]]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[(uint8[],string)-([], '')]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[address-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[address-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[address[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bool-False]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bool-True]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bool[4]-[True, False, Tr]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bool[][2]-[[True, False], ]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes-b'']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes-b'\\x00\\x00\\x00\\x0]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes-b'\\x00\\x00\\x00\\x1]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes-b'hello world']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes1-b'\\x01']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes32-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes32-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes32[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[bytes[]-[b'abc', b'def',]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[fixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[int256--578960446186580]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[int256-5789604461865809]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[int8--128]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[int8-127]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string-'']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string-'\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string-'aaaaaaaaaaaaaaa]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string-'hello world']` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string[2]-['foo', 'bar']]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string[]-['a', 'b', 'c']]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[string[]-[]]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[ufixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint256-0]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint256-1157920892373161]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint256[2]-[0, 115792089237]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint256[2][2]-[[1, 2], [3, 4]]]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint8-0]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint8-255]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint8[3]-[1, 2, 3]]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint8[]-[1, 2, 3, 4, 5]]` |  |  |  |  |  | ➖ |
| `decode_faster_eth_abi[uint8[]-[]]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[((uint8,uint8),uint8)-((1, 2), 3)]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[((uint8[2],(string,bool)),bytes32)-(([1, 2], ('hi',]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(address,uint8)-(b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(string,bytes)-('foo', b'bar')]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(string[],bytes[])-([''], [b''])]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint256,bool)-(42, True)]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint256[2],string)-([1, 2], 'baz')]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint256[],(string[],bool))-([1, 2, 3], (['a]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint8,(bool,string))-(7, (False, 'hi']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint8[2],(string,bool[2]))-([1, 2], ('x', []` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint8[2][2],(string[2],bool[2]))-([[1, 2], [3, 4]]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[(uint8[],string)-([], '')]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[address-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[address-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[address[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bool-False]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bool-True]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bool[4]-[True, False, Tr]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bool[][2]-[[True, False], ]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes-b'']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes-b'\\x00\\x00\\x00\\x0]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes-b'\\x00\\x00\\x00\\x1]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes-b'hello world']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes1-b'\\x01']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes32-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes32-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes32[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[bytes[]-[b'abc', b'def',]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[fixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[int256--578960446186580]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[int256-5789604461865809]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[int8--128]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[int8-127]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string-'']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string-'\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string-'aaaaaaaaaaaaaaa]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string-'hello world']` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string[2]-['foo', 'bar']]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string[]-['a', 'b', 'c']]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[string[]-[]]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[ufixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint256-0]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint256-1157920892373161]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint256[2]-[0, 115792089237]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint256[2][2]-[[1, 2], [3, 4]]]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint8-0]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint8-255]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint8[3]-[1, 2, 3]]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint8[]-[1, 2, 3, 4, 5]]` |  |  |  |  |  | ➖ |
| `encode_eth_abi[uint8[]-[]]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[((uint8,uint8),uint8)-((1, 2), 3)]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[((uint8[2],(string,bool)),bytes32)-(([1, 2], ('hi',]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(address,uint8)-(b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(string,bytes)-('foo', b'bar')]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(string[],bytes[])-([''], [b''])]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint256,bool)-(42, True)]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint256[2],string)-([1, 2], 'baz')]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint256[],(string[],bool))-([1, 2, 3], (['a]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint8,(bool,string))-(7, (False, 'hi']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint8[2],(string,bool[2]))-([1, 2], ('x', []` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint8[2][2],(string[2],bool[2]))-([[1, 2], [3, 4]]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[(uint8[],string)-([], '')]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[address-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[address-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[address[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bool-False]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bool-True]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bool[4]-[True, False, Tr]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bool[][2]-[[True, False], ]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes-b'']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes-b'\\x00\\x00\\x00\\x0]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes-b'\\x00\\x00\\x00\\x1]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes-b'hello world']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes1-b'\\x01']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes32-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes32-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes32[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[bytes[]-[b'abc', b'def',]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[fixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[int256--578960446186580]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[int256-5789604461865809]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[int8--128]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[int8-127]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string-'']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string-'\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string-'aaaaaaaaaaaaaaa]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string-'hello world']` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string[2]-['foo', 'bar']]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string[]-['a', 'b', 'c']]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[string[]-[]]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[ufixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint256-0]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint256-1157920892373161]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint256[2]-[0, 115792089237]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint256[2][2]-[[1, 2], [3, 4]]]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint8-0]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint8-255]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint8[3]-[1, 2, 3]]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint8[]-[1, 2, 3, 4, 5]]` |  |  |  |  |  | ➖ |
| `encode_faster_eth_abi[uint8[]-[]]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[((uint8,uint8),uint8)-((1, 2), 3)]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[((uint8[2],(string,bool)),bytes32)-(([1, 2], ('hi',]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(address,uint8)-(b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(string,bytes)-('foo', b'bar')]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(string[],bytes[])-([''], [b''])]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint256,bool)-(42, True)]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint256[2],string)-([1, 2], 'baz')]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint256[],(string[],bool))-([1, 2, 3], (['a]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint8,(bool,string))-(7, (False, 'hi']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint8[2],(string,bool[2]))-([1, 2], ('x', []` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint8[2][2],(string[2],bool[2]))-([[1, 2], [3, 4]]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[(uint8[],string)-([], '')]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[address-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[address-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[address[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bool-False]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bool-True]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bool[4]-[True, False, Tr]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bool[][2]-[[True, False], ]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes-b'']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes-b'\\x00\\x00\\x00\\x0]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes-b'\\x00\\x00\\x00\\x1]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes-b'hello world']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes1-b'\\x01']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes32-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes32-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes32[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[bytes[]-[b'abc', b'def',]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[fixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[int256--578960446186580]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[int256-5789604461865809]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[int8--128]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[int8-127]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string-'']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string-'\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string-'aaaaaaaaaaaaaaa]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string-'hello world']` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string[2]-['foo', 'bar']]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string[]-['a', 'b', 'c']]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[string[]-[]]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[ufixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint256-0]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint256-1157920892373161]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint256[2]-[0, 115792089237]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint256[2][2]-[[1, 2], [3, 4]]]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint8-0]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint8-255]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint8[3]-[1, 2, 3]]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint8[]-[1, 2, 3, 4, 5]]` |  |  |  |  |  | ➖ |
| `is_encodable_eth_abi[uint8[]-[]]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[((uint8,uint8),uint8)-((1, 2), 3)]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[((uint8[2],(string,bool)),bytes32)-(([1, 2], ('hi',]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(address,uint8)-(b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(string,bytes)-('foo', b'bar')]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(string[],bytes[])-([''], [b''])]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint256,bool)-(42, True)]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint256[2],string)-([1, 2], 'baz')]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint256[],(string[],bool))-([1, 2, 3], (['a]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint8,(bool,string))-(7, (False, 'hi']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint8[2],(string,bool[2]))-([1, 2], ('x', []` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint8[2][2],(string[2],bool[2]))-([[1, 2], [3, 4]]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[(uint8[],string)-([], '')]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[address-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[address-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[address[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bool-False]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bool-True]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bool[4]-[True, False, Tr]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bool[][2]-[[True, False], ]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes-b'']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes-b'\\x00\\x00\\x00\\x0]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes-b'\\x00\\x00\\x00\\x1]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes-b'hello world']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes1-b'\\x01']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes32-b'\\x00\\x00\\x00\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes32-b'\\xff\\xff\\xff\\x]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes32[2]-[b'\\x00\\x00\\x00\\]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[bytes[]-[b'abc', b'def',]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[fixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[int256--578960446186580]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[int256-5789604461865809]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[int8--128]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[int8-127]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string-'']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string-'\U0001d518\U0001d52b\U0001d526\U0001d520\U0001d52c\U0001d521\U0001d522']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string-'aaaaaaaaaaaaaaa]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string-'hello world']` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string[2]-['foo', 'bar']]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string[]-['a', 'b', 'c']]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[string[]-[]]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[ufixed128x18-Decimal('1.23456]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint256-0]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint256-1157920892373161]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint256[2]-[0, 115792089237]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint256[2][2]-[[1, 2], [3, 4]]]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint8-0]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint8-255]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint8[3]-[1, 2, 3]]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint8[]-[1, 2, 3, 4, 5]]` |  |  |  |  |  | ➖ |
| `is_encodable_faster_eth_abi[uint8[]-[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[((uint8,uint8),uint8)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[((uint8[2],(string,bool)),bytes32)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(address,uint8)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(string,bytes)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(string[],bytes[])]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint256,bool)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint256[2],string)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint256[],(string[],bool))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint8,(bool,string))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint8[2],(string,bool[2]))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint8[2][2],(string[2],bool[2]))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[(uint8[],string)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[address[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[address]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bool[4]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bool[][2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bool]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bytes1]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bytes32[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bytes32]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bytes[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[bytes]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[fixed128x18]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[int256]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[int8]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[string[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[string[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[string]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[ufixed128x18]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[uint256[2][2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[uint256[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[uint256]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[uint8[3]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[uint8[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_eth_abi[uint8]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[((uint8,uint8),uint8)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[((uint8[2],(string,bool)),bytes32)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(address,uint8)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(string,bytes)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(string[],bytes[])]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint256,bool)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint256[2],string)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint256[],(string[],bool))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint8,(bool,string))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint8[2],(string,bool[2]))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint8[2][2],(string[2],bool[2]))]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[(uint8[],string)]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[address[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[address]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bool[4]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bool[][2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bool]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bytes1]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bytes32[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bytes32]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bytes[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[bytes]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[fixed128x18]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[int256]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[int8]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[string[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[string[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[string]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[ufixed128x18]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[uint256[2][2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[uint256[2]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[uint256]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[uint8[3]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[uint8[]]` |  |  |  |  |  | ➖ |
| `is_encodable_type_faster_eth_abi[uint8]` |  |  |  |  |  | ➖ |
