.. _grammar:

Grammar
=======

The ``eth-abi`` library exposes its type string parsing and normalization
facilities as part of its public API.

.. _grammar-parsing-a-type-string:

Parsing a Type String
---------------------

Here are some examples of how you might parse a type string into a simple AST
and do various operations with the results:

.. doctest::

    >>> from faster_eth_abi.grammar import ABIType, BasicType, TupleType, parse

    >>> tuple_type = parse('(int256,bytes,ufixed128x18,bool[])[2]')

    >>> # Checking if a type is a tuple or a basic type
    >>> isinstance(tuple_type, ABIType)
    True
    >>> isinstance(tuple_type, TupleType)
    True
    >>> [isinstance(i, ABIType) for i in tuple_type.components]
    [True, True, True, True]
    >>> [isinstance(i, BasicType) for i in tuple_type.components]
    [True, True, True, True]

    >>> int_type, bytes_type, ufixed_type, bool_type = tuple_type.components

    >>> # Inspecting parts of types
    >>> len(tuple_type.components)
    4
    >>> tuple_type.arrlist
    ((2,),)
    >>> int_type.base, int_type.sub, int_type.arrlist
    ('int', 256, None)
    >>> bytes_type.base, bytes_type.sub, bytes_type.arrlist
    ('bytes', None, None)
    >>> ufixed_type.base, ufixed_type.sub, ufixed_type.arrlist
    ('ufixed', (128, 18), None)
    >>> bool_type.base, bool_type.sub, bool_type.arrlist
    ('bool', None, ((),))

    >>> # Checking for arrays or dynamicism
    >>> tuple_type.is_array, tuple_type.is_dynamic
    (True, True)
    >>> int_type.is_array, int_type.is_dynamic
    (False, False)
    >>> bytes_type.is_array, bytes_type.is_dynamic
    (False, True)
    >>> ufixed_type.is_array, ufixed_type.is_dynamic
    (False, False)
    >>> bool_type.is_array, bool_type.is_dynamic
    (True, True)

.. _grammar-check-types-for-validity:

Checking Types for Validity
---------------------------

Types can be checked for validity.  For example, ``uint9`` is not a valid type
because the bit-width of ``int`` types must be a multiple of ``8``:

.. doctest::

    >>> from faster_eth_abi.grammar import parse

    >>> basic_type = parse('uint9')
    >>> # The basic type is not valid because the int type's bit-width is not valid
    >>> basic_type.validate()
    Traceback (most recent call last):
        ...
    faster_eth_abi.exceptions.ABITypeError: For 'uint9' type at column 1 in 'uint9': integer size must be multiple of 8

    >>> tuple_type = parse('(bool,uint9)')
    >>> # The tuple type is not valid because it contains an int type with an invalid bit-width
    >>> tuple_type.validate()
    Traceback (most recent call last):
        ...
    faster_eth_abi.exceptions.ABITypeError: For 'uint9' type at column 7 in '(bool,uint9)': integer size must be multiple of 8

.. _grammar-normalizing-type-strings:

Normalizing Type Strings
------------------------

Type strings can be normalized to their canonical form.  This amounts to
converting type aliases like ``uint`` to ``uint256`` and so forth:

.. doctest::

    >>> from faster_eth_abi.grammar import normalize
    >>> normalize('uint')
    'uint256'
    >>> normalize('(uint,(ufixed,function))')
    '(uint256,(ufixed128x18,bytes24))'

Internally, ``eth-abi`` will only normalize type strings just before creating
coders for a type.  This is done automatically such that type strings passed to
``eth-abi`` do not need to be normalized before hand.
