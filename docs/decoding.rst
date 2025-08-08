.. _decoding:

Decoding
========

Decoding ABI Values
-------------------

Binary values for a given ABI type can be decoded into python values as
follows:

.. doctest::

    >>> from faster_eth_abi import decode

    >>> # decode a single ABI type
    >>> decode(['uint256'], b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009')
    (12345,)

    >>> # decode multiple ABI types
    >>> decode(['bytes1', 'bytes1'], b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    (b'a', b'b')

    >>> # decode a single tuple type with two `bytes1` types
    >>> decode(['(bytes1,bytes1)'], b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    ((b'a', b'b'),)

The :py:meth:`faster_eth_abi.decoding.BaseDecoder.decode` function provides an API for
decoding binary values for ABI types into python values. It accepts a sequence of
ABI type strings as the first argument and the binary data to be decoded, as a python
``bytes`` or ``bytearray`` value, as the second argument.

Strict Mode
-----------

By default, the decoder will raise an exception if the binary data to be decoded
is not padded to the next 32-byte boundary. This behavior can be disabled for the
``ByteStringDecoder`` (the default decoder for ``bytes`` and ``string`` types) by
passing ``strict=False`` to the :py:meth:`faster_eth_abi.abi.decode` method. Turning off
strict mode will also ignore any trailing bytes beyond the data size specified. This
means that if there is any padding, the validation for only empty bytes in the padding
area is also ignored.

.. doctest::

    >>> from faster_eth_abi import abi

    >>> # decode a bytes value without strict mode
    >>> hex_val = (
    ...     # offset to data is 32 bytes:
    ...     "0000000000000000000000000000000000000000000000000000000000000020"
    ...     # length of data is 1 byte:
    ...     "0000000000000000000000000000000000000000000000000000000000000001"
    ...     # b"\x01" with less than 32 bytes of padding
    ...     # and not strictly padded with only zero bytes:
    ...     "0100000000000001020300"
    ... )
    >>> (decoded,) = abi.decode(['bytes'], bytes.fromhex(hex_val), strict=False)
    >>> decoded
    b'\x01'
