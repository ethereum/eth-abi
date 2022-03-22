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
    >>> encode([12345], ['uint256'])
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'

    >>> # encode multiple ABI types
    >>> encode([b'a', b'b'], ['bytes32', 'bytes32'])
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

    >>> # encode a single tuple type with two `bytes32` types
    >>> encode([(b'a', b'b')], ['(bytes32,bytes32)'],)
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'


The :meth:`~eth_abi.codec.ABIEncoder.encode` function provides an API for encoding ABI values. It accepts a sequence of values to be encoded as the
first argument and a sequence of the respective type strings for the values as the second argument.

Checking for Encodability
-------------------------

It is also possible to check whether or not a certain python value is encodable
for a given ABI type using :any:`is_encodable`:

.. doctest::

    >>> from eth_abi import is_encodable

    >>> is_encodable(2, 'int')
    True

    >>> is_encodable('foo', 'int')
    False

    >>> is_encodable((0, True), '(int,bool)')
    True

    >>> is_encodable((0, 0), '(int,bool)')
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
    >>> encode_packed([12345], ['uint32'])
    b'\x00\x0009'

    >>> # encode_packed for multiple ABI types
    >>> encode_packed(([1, 2, 3, 4], 12345), ['int8[]', 'uint32'])
    b'\x01\x02\x03\x04\x00\x0009'

    >>> # encode_packed for a tuple with `uint8[]` and `uint32` types
    >>> encode_packed([([1, 2, 3, 4], 12345)], ['(int8[],uint32)'])
    b'\x01\x02\x03\x04\x00\x0009'


More information about this encoding format is available at
https://solidity.readthedocs.io/en/develop/abi-spec.html#non-standard-packed-mode.
