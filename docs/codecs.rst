.. _codecs:

Codecs
======

Though the default registry can be customized by making additional coder
registrations or by unregistering existing coders (see :ref:`registry`),
sometimes a user might wish to create their own registry entirely.  In that
case, they can still use the usual API for encoding and decoding values (see
:ref:`encoding` and :ref:`decoding`) with their own registry by using the
:class:`~eth_abi.codec.ABICodec` or :class:`~eth_abi.codec.ABIEncoder` class.

Using a Custom Registry
-----------------------

Here's an example of how you might add support for a simple "null" type using a
custom registry while continuing to use the porcelain encoding and decoding
API:

.. testcode:: custom-registry-nulltype

    from eth_abi.codec import ABICodec
    from eth_abi.exceptions import EncodingError, DecodingError
    from eth_abi.registry import ABIRegistry

    # Define and register the coders
    NULL_ENCODING = b'\x00' * 32

    def encode_null(x):
        if x is not None:
            raise EncodingError('Unsupported value')

        return NULL_ENCODING

    def decode_null(stream):
        if stream.read(32) != NULL_ENCODING:
            raise DecodingError('Not enough data or wrong data')

        return None

    registry = ABIRegistry()
    registry.register('null', encode_null, decode_null)

    # Try them out
    codec = ABICodec(registry)

    assert codec.encode(['null'], [None]) == NULL_ENCODING

    (decoded_null_val,) = codec.decode(['null'], NULL_ENCODING)
    assert decoded_null_val is None

In the above example, we define two coder callables and register them to handle
exact matches against the ``'null'`` type string in a custom registry.  For
more information about coder registrations, see
:ref:`registry-adding-simple-types`.

We then create a custom codec object with our custom registry and use this to
encode and decode byte sequences.  This allows us to continue using the
porcelain API (described in the :ref:`encoding` and :ref:`decoding` sections)
with our custom registry.

.. _copying_an_existing_registry:

Copying an Existing Registry
----------------------------

Sometimes, it's more convenient to use an existing registry but with only one or
two small modifications.  This can be done via a registry's copying or cloning
capability coupled with the use of a custom codec:

.. testcode:: custom-registry-copied

    from eth_abi.codec import ABICodec
    from eth_abi.registry import registry as default_registry

    registry = default_registry.copy()
    registry.unregister('address')

    codec = ABICodec(registry)

    try:
        codec.encode(['address'], [None])
    except ValueError:
        pass
    else:
        # We shouldn't reach this since the above code will cause an exception
        raise Exception('unreachable')

    default_codec = ABICodec(default_registry)

    # The default registry is unaffected since a copy was made
    assert (
        default_codec.encode(['address'], ['0x' + 'ff' * 20]) ==
        b'\x00' * 12 + b'\xff' * 20
    )

.. _custom_stream_class:

Using a Custom Stream Class
---------------------------

If a user wishes to customize the behavior of the internal stream class used
for decoding, they can do the following:

.. testcode:: custom-stream-class

    from eth_abi.codec import ABIEncoder, ABIDecoder
    from eth_abi.registry import registry

    class MyStream:
        # Custom behavior...
        pass

    class MyDecoder(ABIDecoder):
        stream_class = MyStream

    class MyCodec(ABIEncoder, MyDecoder):
        pass

    codec = MyCodec(registry)
