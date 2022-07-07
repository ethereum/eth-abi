.. _encoding:

Encoding
========

Encoding Python Values
----------------------

Python values can be encoded into binary values for a given ABI type as
follows:

.. doctest::

    >>> from eth_abi import encode

    >>> # encode a single ABI type
    >>> encode(['uint256'], [12345])
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'

    >>> # encode multiple ABI types
    >>> encode(['bytes32', 'bytes32'], [b'a', b'b'])
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

    >>> # encode a single tuple type with two `bytes32` types
    >>> encode(['(bytes32,bytes32)'], [(b'a', b'b')])
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'


The :any:`encode` function provides an API for encoding python values into binary values for ABI types. It accepts a
sequence of ABI type strings as the first argument and a sequence of python values to be encoded into the respective ABI
types as the second argument.

Checking for Encodability
-------------------------

It is also possible to check whether or not a certain python value is encodable
for a given ABI type using :any:`is_encodable`:

.. doctest::

    >>> from eth_abi import is_encodable

    >>> is_encodable('int', 2)
    True

    >>> is_encodable('int', 'foo')
    False

    >>> is_encodable('(int,bool)', (0, True))
    True

    >>> is_encodable('(int,bool)', (0, 0))
    False

Non-Standard Packed Mode Encoding
---------------------------------

.. warning::

    Non-standard packed mode encoding is an experimental feature in the eth-abi
    library.  Use at your own risk and please report any problems at
    https://github.com/ethereum/eth-abi/issues.

In certain cases, the Solidity programming language uses a non-standard packed
encoding.  You can encode values in this format like so:

.. doctest::

    >>> from eth_abi.packed import encode_packed

    >>> # encode_packed for a single ABI type
    >>> encode_packed(['uint32'], [12345])
    b'\x00\x0009'

    >>> # encode_packed for multiple ABI types
    >>> encode_packed(['int8[]', 'uint32'], ([1, 2, 3, 4], 12345))
    b'\x01\x02\x03\x04\x00\x0009'

    >>> # encode_packed for a tuple with `uint8[]` and `uint32` types
    >>> encode_packed(['(int8[],uint32)'], [([1, 2, 3, 4], 12345)])
    b'\x01\x02\x03\x04\x00\x0009'


More information about this encoding format is available at
https://solidity.readthedocs.io/en/develop/abi-spec.html#non-standard-packed-mode.
