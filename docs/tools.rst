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
    >>> import random

    >>> uints = get_abi_strategy('uint8')
    >>> uints
    integers(min_value=0, max_value=255)
    >>> uints.example(random.Random(0))
    10

    >>> uint_lists = get_abi_strategy('uint8[2]')
    >>> uint_lists
    lists(elements=integers(min_value=0, max_value=255), min_size=2, max_size=2)
    >>> uint_lists.example(random.Random(0))
    [66, 247]

    >>> fixed_vals = get_abi_strategy('fixed8x1')
    >>> fixed_vals
    decimals(min_value=-128, max_value=127, places=0).map(scale_by_Eneg1)
    >>> fixed_vals.example(random.Random(0))
    Decimal('9.8')

    >>> tuples = get_abi_strategy('(bool,string)')
    >>> tuples
    tuples(booleans(), text())
    >>> tuples.example(random.Random(0))
    (False, '')

.. warning::

    In the above code snippet, we use the ``example`` method on hypothesis
    strategy objects with an explicit random number generator with seed zero.
    Both the use of that method and the use of zero-seeded random number
    generators are *not* recommended for normal use.  Their use in this context
    is intended to make the code snippet reproducible.  In normal test code,
    use of the ``example`` method may prevent hypothesis from finding a useful
    sample of values.  See `here
    <https://github.com/HypothesisWorks/hypothesis/blob/31a181fb7c5ce4227d4475f667a776ce86cd412c/hypothesis-python/src/hypothesis/searchstrategy/strategies.py#L258-L266>`_
    for more information.

Hypothesis strategies can be used to conduct property testing on contract code.
For more information on property testing, visit the `Hypothesis homepage
<https://hypothesis.works>`_ or the `Hypothesis readthedocs site
<https://hypothesis.readthedocs.io/en/latest/>`_.
