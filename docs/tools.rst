.. _tools:

Tools
=====

The ``eth_abi.tools`` module provides extra resources to users of ``eth-abi``
that are not required for typical use.  It can be installed with ``pip`` as an
extra requirement:

.. code-block:: bash

    pip install eth-abi[tools]


ABI Type Strategies
-------------------

The ``tools`` module provides the :meth:`~eth_abi.tools.get_abi_strategy`
function.  This function returns a hypothesis strategy (value generator) for any
given ABI type specified by its canonical string representation:

.. doctest::

    >>> from eth_abi.tools import get_abi_strategy

    >>> uint_st = get_abi_strategy('uint8')
    >>> uint_st
    integers(min_value=0, max_value=255)

    >>> uint_list_st = get_abi_strategy('uint8[2]')
    >>> uint_list_st
    lists(elements=integers(min_value=0, max_value=255), min_size=2, max_size=2)

    >>> fixed_st = get_abi_strategy('fixed8x1')
    >>> fixed_st
    decimals(min_value=-128, max_value=127, places=0).map(scale_by_Eneg1)

    >>> tuple_st = get_abi_strategy('(bool,string)')
    >>> tuple_st
    tuples(booleans(), text())

Hypothesis strategies can be used to conduct property testing on contract code.
For more information on property testing, visit the `Hypothesis homepage
<https://hypothesis.works>`_ or the `Hypothesis readthedocs site
<https://hypothesis.readthedocs.io/en/latest/>`_.
