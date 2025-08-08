Welcome to the eth-abi documentation!
=====================================

The ``eth-abi`` library provides low level utilities for converting python
values to and from solidity's binary ABI format.

For detailed information on ABI types and their encodings, refer to the
`solidity ABI specification
<https://solidity.readthedocs.io/en/latest/abi-spec.html>`_.

Credit
------

Though much of the code has been revised, the ``eth-abi`` library was
originally extracted from the ``pyethereum`` library which was authored by
Vitalik Buterin.

Installation
------------

.. code-block:: bash

    python -m pip install eth-abi

Table of Contents
-----------------

.. toctree::
    :maxdepth: 1
    :caption: General:

    encoding
    decoding
    registry
    codecs
    nested_dynamic_arrays
    grammar
    tools
    faster_eth_abi
    release_notes

.. toctree::
    :maxdepth: 1
    :caption: Community

    contributing
    code_of_conduct
