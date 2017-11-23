Encoding
========


These functions are intended for encoding python values into representations
that are suitable for interacting with the EVM.


* ``eth_abi.encode_single(type, value)``

This function encodes ``value`` in the ABI encoding for the provided ``type``.


.. code-block:: python

    >>> encode_single('uint256', 12345)
    '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'


The **value** parameter is expected to be one of the recognized EVM types.

.. note:: This function cannot be used to encode array types such as ``bytes32[]``.


* ``eth_abi.encode_abi(types, values)``

This function encodes ``values`` in the ABI encoding for the corresponding type
provided by the ``types`` argument.


.. code-block:: python

    >>> encode_abi(['uint256'], [12345])
    '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'
    >>> encode_abi(['bytes32', 'bytes32'], ['a', 'b'])
    'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'


The **values** parameter is expected to be an iterable whose values are all one
of the recognized EVM types.
