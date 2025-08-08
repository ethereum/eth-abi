Nested Dynamic Arrays
=====================

The ``faster-eth-abi`` library supports the Solidity ABIv2 encoding format for nested
dynamic arrays.  This means that values for data types such as the following
are legal and encodable/decodable: ``int[][]``, ``string[]``, ``string[2]``,
etc.
