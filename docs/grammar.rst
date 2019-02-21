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

.. testcode::

    from eth_abi.grammar import (
        ABIType,
        BasicType,
        TupleType,
        parse,
    )

    tuple_type = parse('(int256,bytes,ufixed128x18,bool[])[2]')

    # Checking if a type is a tuple or a basic type
    assert isinstance(tuple_type, ABIType)
    assert isinstance(tuple_type, TupleType)
    for abi_type in tuple_type.components:
        assert isinstance(abi_type, ABIType)
        assert isinstance(abi_type, BasicType)

    int_type, bytes_type, ufixed_type, bool_type = tuple_type.components

    # Inspecting parts of types
    assert len(tuple_type.components) == 4
    assert tuple_type.arrlist == ((2,),)

    assert int_type.base == 'int'
    assert int_type.sub == 256
    assert int_type.arrlist is None

    assert bytes_type.base == 'bytes'
    assert bytes_type.sub is None
    assert bytes_type.arrlist is None

    assert ufixed_type.base == 'ufixed'
    assert ufixed_type.sub == (128, 18)
    assert ufixed_type.arrlist is None

    assert bool_type.base == 'bool'
    assert bool_type.sub is None
    assert bool_type.arrlist == ((),)

    # Checking for arrays or dynamicism
    assert tuple_type.is_array
    assert tuple_type.is_dynamic

    assert not int_type.is_array
    assert not int_type.is_dynamic

    assert not bytes_type.is_array
    assert bytes_type.is_dynamic

    assert not ufixed_type.is_array
    assert not ufixed_type.is_dynamic

    assert bool_type.is_array
    assert bool_type.is_dynamic

.. _grammar-check-types-for-validity:

Checking Types for Validity
---------------------------

Types can be checked for validity.  For example, ``uint9`` is not a valid type
because the bit-width of ``int`` types must be a multiple of ``8``:

.. testcode::

    from eth_abi.exceptions import ABITypeError
    from eth_abi.grammar import parse

    basic_type = parse('uint9')
    try:
        basic_type.validate()
    except ABITypeError:
        # The basic type is not valid because the int type's bit-width is not
        # valid
        pass
    else:
        assert False

    tuple_type = parse('(bool,uint9)')
    try:
        tuple_type.validate()
    except ABITypeError:
        # The tuple type is not valid because it contains an int type with an
        # invalid bit-width
        pass
    else:
        assert False

.. _grammar-normalizing-type-strings:

Normalizing Type Strings
------------------------

Type strings can be normalized to their canonical form.  This amounts to
converting type aliases like ``uint`` to ``uint256`` and so forth:

.. testcode::

    from eth_abi.grammar import normalize

    assert normalize('uint') == 'uint256'
    assert normalize('(uint,(ufixed,function))') == '(uint256,(ufixed128x18,bytes24))'

Internally, ``eth-abi`` will only normalize type strings just before creating
coders for a type.  This is done automatically such that type strings passed to
``eth-abi`` do not need to be normalized before hand.
