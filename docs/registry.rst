.. _registry:

Registry
========

The ``eth-abi`` library uses a central registry to route encoding/decoding
operations for different ABI types to an appropriate encoder/decoder callable
or class.  Using the registry, the coding behavior of any ABI type can be
customized and additional coding behavior for new ABI types can be added.

.. _registry-adding-simple-types:

Adding Simple Types
-------------------

Here's an example of how you might add support for a simple "null" type using
callables:

.. testcode:: nulltype-callables

    from faster_eth_abi.exceptions import EncodingError, DecodingError
    from faster_eth_abi.registry import registry

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

    registry.register('null', encode_null, decode_null)

    # Try them out
    from faster_eth_abi import encode, decode

    assert encode(['null'], [None]) == NULL_ENCODING

    (decoded_null_val,) = decode(['null'], NULL_ENCODING)
    assert decoded_null_val is None

    encoded_tuple = encode(['(int,null)'], [(1, None)])
    assert encoded_tuple == b'\x00' * 31 + b'\x01' + NULL_ENCODING

    (decoded_tuple,) = decode(['(int,null)'], encoded_tuple)
    assert decoded_tuple == (1, None)

.. testcleanup:: nulltype-callables

    from faster_eth_abi.registry import registry
    registry.unregister('null')

In the above example, we define two coder callables and register them to handle
exact matches against the ``'null'`` type string.  We do this by calling
:any:`register` on the `registry` object.

When a call is made to one of the coding functions (such as
:meth:`~faster_eth_abi.codec.ABIEncoder.encode` or :meth:`~faster_eth_abi.codec.ABIDecoder.decode`),
the type string which is provided (which we'll call ``query``) is sent to the registry.
This ``query`` will be checked against every registration in the registry.  Since we
created a registration for the exact type string ``'null'``, coding operations for that
type string will be routed to the encoder and decoder which were provided by
the call to :any:`register`.  This also works when the registered type string
appears in a compound type as with the tuple type in the example.

.. note:: As a safety measure, the registry will raise an exception if more
    than one registration matches a query.  Take care to ensure that your custom
    registrations don't conflict with existing ones.

Adding More Complex Types
-------------------------

Sometimes, it's convenient to register a single class to handle encodings or
decodings for a range of types.  For example, we shouldn't have to make
separate registrations for the ``'uint256'`` and ``'uint8'`` types or for the
``'(int,bool)'`` and ``'(int,int)'`` types.  For cases like this, we can make
registrations for custom subclasses of :any:`BaseEncoder` and
:any:`BaseDecoder`.

Let's say we want to modify our "null" type above so that we can specify the
number of 32-byte words that the encoded null value will occupy in the data
stream.  We could do that in the following way:

.. testcode:: nulltype-classes

    from faster_eth_abi.decoding import BaseDecoder
    from faster_eth_abi.encoding import BaseEncoder
    from faster_eth_abi.exceptions import EncodingError, DecodingError
    from faster_eth_abi.registry import registry

    # Define and register the coders
    NULL_ENCODING = b'\x00' * 32

    class EncodeNull(BaseEncoder):
        word_width = None

        @classmethod
        def from_type_str(cls, type_str, registry):
            word_width = int(type_str[4:])
            return cls(word_width=word_width)

        def encode(self, value):
            self.validate_value(value)
            return NULL_ENCODING * self.word_width

        def validate_value(self, value):
            if value is not None:
                raise EncodingError('Unsupported value')

    class DecodeNull(BaseDecoder):
        word_width = None

        @classmethod
        def from_type_str(cls, type_str, registry):
            word_width = int(type_str[4:])
            return cls(word_width=word_width)

        def decode(self, stream):
            byts = stream.read(32 * self.word_width)
            if byts != NULL_ENCODING * self.word_width:
                raise DecodingError('Not enough data or wrong data')

            return None

    registry.register(
        lambda x: x.startswith('null'),
        EncodeNull,
        DecodeNull,
        label='null',
    )

    # Try them out
    from faster_eth_abi import encode, decode

    assert encode(['null2'], [None]) == NULL_ENCODING * 2

    (decoded_null_val,) = decode(['null2'], NULL_ENCODING * 2)
    assert decoded_null_val is None

    encoded_tuple = encode(['(int,null2)'], [(1, None)])
    assert encoded_tuple == b'\x00' * 31 + b'\x01' + NULL_ENCODING * 2

    (decoded_tuple,) = decode(['(int,null2)'], encoded_tuple)
    assert decoded_tuple == (1, None)

.. testcleanup:: nulltype-classes

    from faster_eth_abi.registry import registry
    registry.unregister('null')

There are a few differences here from our first example.  Now, we are providing
a type string matcher function instead of a literal type string with our call
to :any:`register`.  Also, we are not using simple callables for our coding
functions.  We have created two custom coder classes which inherit from
:any:`BaseEncoder` and :any:`BaseDecoder` respectively.  Additionally, we have
given a label to this registration in case we want to easily delete the
registration later.

The matcher function ``lambda x: x.startswith('null')`` accepts a query type
string and returns ``True`` or ``False`` to indicate if the query should be
matched with our registration.  If a query is *uniquely* matched with our
registration in this way, the registry then calls :any:`from_type_str` on our
``EncodeNull`` or ``DecodeNull`` class to obtain an appropriate instance of the
class based on any additional information contained in the type string.  In
this example, that additional information is the number that appears at the end
of the type string (e.g. ``'2'`` in ``'null2'``).  Through this process, the
registry can determine an encoder or decoder for any type string of the form
``'null<M>'``.

There are a few more details here that are worth explaining.

Both of our coder subclasses have some similar aspects.  They both have a class
property ``word_width``.  They also have the same implementation for the
:any:`from_type_str` method.  The :any:`BaseEncoder` and :any:`BaseDecoder`
classes both inherit from :any:`BaseCoder` which causes any keyword arguments
passed to ``__init__`` to be used to set the value of properties on an instance
if a class property with the same name is found.  This is why our
implementations of :any:`from_type_str` instantiate our coder classes with the
keyword argument ``word_width``.  Using this pattern, coder classes can
describe what "settings" they support while providing an easy way to assign
values to those settings.  Both of our coder classes use the same settings.
The settings are initialized from the type string in the same way.  Therefore,
they have the same implementation for :any:`from_type_str`.  For clarity, the
same ``word_width`` property and :any:`from_type_str` implementation appear in
both classes but they could also have been extracted out into a mixin class.

Our coder classes also implement the :any:`BaseEncoder.encode` and
:any:`BaseDecoder.decode` methods.  These methods work in the same way as the
simple callable coders in our first example except that they have access to the
settings which were extracted from the type string when the class was
instantiated via the :any:`from_type_str` method by the registry.  This allows
them to handle null values of an arbitrary width in the data stream.  As with
the callable coders, the :any:`BaseEncoder.encode` and
:any:`BaseDecoder.decode` implementations are polite and raise an appropriate
exception when anything goes wrong.  ``EncodeNull`` does this via an
implementation of :any:`BaseEncoder.validate_value`.  For encoder classes, it
is necessary to implement this method since it is used by the
:any:`is_encodable` function to determine if a value is encodable without doing
the extra work of encoding it.  For certain data types, this can be more
efficient than simply attempting to encode a value.



Handling Malformed Strings
--------------------------

Sometimes a ``string`` we receive is malformed, i.e. not utf-8 decodeable.
This will throw an error by default, but we can adjust how it is handled by
registering a new decoder with our preferred handler.

The :class:`StringDecoder` class uses the Python :meth:`bytes.decode` method at its core,
which accepts an ``errors`` argument to define how un-decodeable bytes are handled.
:class:`StringDecoder` uses ``errors=strict`` by default, but can also accept
``surrogateescape``, ``ignore``, ``replace``, or ``backslashreplace``. You can read
more about each of these options in the Python
`docs <https://docs.python.org/3/library/codecs.html#error-handlers>`_.

The ability to handle malformed strings is only available for decoding. It is assumed
that attempting to encode a malformed string indicates user error.

.. testcode:: handle-malformed-strings

    from faster_eth_abi import decode, encode
    from faster_eth_abi.decoding import StringDecoder
    from faster_eth_abi.encoding import TextStringEncoder
    from faster_eth_abi.registry import registry

    # encode a string
    test_string = encode(["string"], ["cat"])
    assert (test_string == b"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00 \x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03cat\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    )

    # insert an un-decodeable byte
    bad_string = test_string[:65] + b"\xff" + test_string[66:]

    # verify the original test_string decodes properly
    assert decode(["string"], test_string) == ("cat",)

    # default `StringDecoder` will throw an error
    try:
        decode(["string"], bad_string)

    except UnicodeDecodeError as e:
        assert "'utf-8' codec can't decode byte 0xff" in str(e)

    # If we want to handle un-decodeable strings, we can register multiple string
    # decoders, each with its own `handle_string_errors` option

    registry.register(
        "surrogateescape_string",
        TextStringEncoder,
        StringDecoder(handle_string_errors="surrogateescape")
    )
    registry.register(
        "backslashreplace_string",
        TextStringEncoder,
        StringDecoder(handle_string_errors="backslashreplace"),
    )

    assert decode(["surrogateescape_string"], bad_string) == ("c\udcfft",)
    assert decode(["backslashreplace_string"], bad_string) == ("c\\xfft",)

.. testcleanup:: handle-malformed-strings

    from faster_eth_abi.registry import registry
    registry.unregister('surrogateescape_string')
    registry.unregister('backslashreplace_string')
