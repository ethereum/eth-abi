Nested Dynamic Arrays
=====================

The ``eth-abi`` library supports the Solidity ABIv2 encoding format for nested
dynamic arrays.  This means that values for data types such as the following
are legal and encodable/decodable: ``int[][]``, ``string[]``, ``string[2]``,
etc.

.. warning::

    Though Solidity's ABIv2 has mostly been finalized, the specification is
    technically still in development and may change.
