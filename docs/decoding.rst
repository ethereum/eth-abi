Decoding
========


These functions are intended for decoding return values from the EVM.


* ``eth_abi.decode_single(type, data)``

This function tries to decode ``data`` into the python type that corresponds
to the provided ``type``.  This function accepts both byte strings as well as
their hexidecimal representation with or without the ``0x`` prefix.


.. code-block:: python

    >>> decode_single('uint256', '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009')
    12345
    >>> decode_single('uint256', '0000000000000000000000000000000000000000000000000000000000003039')
    12345
    >>> decode_single('uint256', '0x0000000000000000000000000000000000000000000000000000000000003039')
    12345


The **value** parameter is expected to be one of the recognized EVM types.


.. note:: This function cannot be used to decode dynamic or array types such as ``bytes32[]``.


* ``eth_abi.decode_abi(types, data)``

This function decodes ``data`` into the python type corresponding to the
provided ``types``.  This function accepts both byte arrays as well as their
hexidecimal representation with or without the ``0x`` prefix.


.. code-block:: python

    >>> decode_abi(['uint256'], '\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009')
    [12345]
    >>> decode_abi(['bytes32', 'bytes32'], 'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    ['a', 'b']


The **values** parameter is expected to be an iterable whose values are all one
of the recognized EVM types.
