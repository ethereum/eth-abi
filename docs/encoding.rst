.. _encoding:

Encoding
========

Encoding Python Values
----------------------

Python values can be encoded into binary values for a given ABI type as
follows:

.. doctest::

    >>> from eth_abi import encode_single, encode_abi

    >>> encode_single('uint256', 12345)
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'

    >>> encode_single('(bytes32,bytes32)', [b'a', b'b'])
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

    >>> encode_abi(['bytes32', 'bytes32'], [b'a', b'b'])
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

The :any:`encode_single` function can be used to perform any encoding operation
from a python value to a binary ABI value for an ABI type.  As is seen in the
example above, :any:`encode_single` supports encoding of tuple ABI values which
can be used to encode sequences of python values in a single binary payload.

The :any:`encode_abi` function provides an alternate API for encoding tuple
values.  It accepts a list of type strings instead of a single tuple type
string.  Internally, it uses the :any:`encode_single` function to do this.
Because of this redundancy, it will eventually be removed in favor of
:any:`encode_single`.

Checking for Encodability
-------------------------

It is also possible to check whether or not a certain python value is encodable
for a given ABI type using :any:`encode_single`:

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

    >>> from eth_abi.packed import encode_single_packed, encode_abi_packed

    >>> encode_single_packed('uint32', 12345)
    b'\x00\x0009'

    >>> encode_single_packed('(int8[],uint32)', ([1, 2, 3, 4], 12345))
    b'\x01\x02\x03\x04\x00\x0009'

    >>> encode_abi_packed(['int8[]', 'uint32'], ([1, 2, 3, 4], 12345))
    b'\x01\x02\x03\x04\x00\x0009'

More information about this encoding format is available at
https://solidity.readthedocs.io/en/develop/abi-spec.html#non-standard-packed-mode.
