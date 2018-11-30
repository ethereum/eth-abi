.. _decoding:

Decoding
========

Decoding ABI Values
-------------------

Binary values for a given ABI type can be decoded into python values as
follows:

.. doctest::

    >>> from eth_abi import decode_single, decode_abi

    >>> decode_single('uint256', b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009')
    12345

    >>> decode_single('(bytes1,bytes1)', b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    (b'a', b'b')

    >>> decode_abi(['bytes1', 'bytes1'], b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    (b'a', b'b')

The :any:`decode_single` function can be used to perform any decoding operation
from a binary ABI value for an ABI type to a python value.  As is seen in the
example above, :any:`decode_single` supports decoding of tuple ABI values which
can be used to decode a single binary payload into a sequence of python values.

The :any:`decode_abi` function provides an alternate API for decoding tuple
values.  It accepts a list of type strings instead of a single tuple type
string.  Internally, it uses the :any:`decode_single` function to do this.
Because of this redundancy, it will eventually be removed in favor of
:any:`decode_single`.

Both the :any:`decode_single` and :any:`decode_abi` functions accept either a
python ``bytes`` or ``bytearray`` value to indicate the binary data to be
decoded.
