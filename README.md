# Ethereum Contract

[![Build Status](https://circleci.com/gh/ethereum/eth-abi.svg?style=shield)](https://circleci.com/gh/ethereum/eth-abi)
[![Documentation Status](https://readthedocs.org/projects/eth-abi/badge/?version=latest)](https://readthedocs.org/projects/eth-abi/?badge=latest)
[![PyPi version](https://img.shields.io/pypi/v/eth-abi.svg)](https://pypi.python.org/pypi/eth-abi)


Python utilities for working with the Ethereum ABI


## Installation

```sh
pip install eth-abi
```



## Documentation

### Decoding


These functions are intended for decoding return values from the EVM.


* ``eth_abi.decode_single(type, data)``

This function tries to decode ``data`` into the python type that corresponds
to the provided ``type``.  This function accepts data of type bytes.


.. code-block:: python

    >>> decode_single('uint256', b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009')
    12345


The **value** parameter is expected to be one of the recognized EVM types.


.. note:: This function cannot be used to decode dynamic or array types such as ``bytes32[]``.


* ``eth_abi.decode_abi(types, data)``

This function decodes ``data`` into the python type corresponding to the
provided ``types``.  This function accepts arrays of type byte.


.. code-block:: python

    >>> decode_abi(['uint256'], b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009')
    [12345]
    >>> decode_abi(['bytes32', 'bytes32'], b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    ['a', 'b']


The **values** parameter is expected to be an iterable whose values are all one
of the recognized EVM types.

### Encoding


These functions are intended for encoding python values into representations
that are suitable for interacting with the EVM.


* ``eth_abi.encode_single(type, value)``

This function encodes ``value`` in the ABI encoding for the provided ``type``.


.. code-block:: python

    >>> encode_single('uint256', 12345)
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'


The **value** parameter is expected to be one of the recognized EVM types.

.. note:: This function cannot be used to encode array types such as ``bytes32[]``.


* ``eth_abi.encode_abi(types, values)``

This function encodes ``values`` in the ABI encoding for the corresponding type
provided by the ``types`` argument.


.. code-block:: python

    >>> encode_abi(['uint256'], [12345])
    b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x0009'
    >>> encode_abi(['bytes32', 'bytes32'], ['a', 'b'])
    b'a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00b\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'


The **values** parameter is expected to be an iterable whose values are all one
of the recognized EVM types.


## Development

Clone the repository and then run:

```sh
pip install -e . -r requirements-dev.txt
```


### Running the tests

You can run the tests with:

```sh
py.test tests
```

Or you can install `tox` to run the full test suite.


### Releasing

Pandoc is required for transforming the markdown README to the proper format to
render correctly on pypi.

For Debian-like systems:

```
apt install pandoc
```

Or on OSX:

```sh
brew install pandoc
```

To release a new version:

```sh
make release bump=$$VERSION_PART_TO_BUMP$$
```

#### How to bumpversion

The version format for this repo is `{major}.{minor}.{patch}` for stable, and
`{major}.{minor}.{patch}-{stage}.{devnum}` for unstable (`stage` can be alpha or beta).

To issue the next version in line, specify which part to bump,
like `make release bump=minor` or `make release bump=devnum`.

If you are in a beta version, `make release bump=stage` will switch to a stable.

To issue an unstable version when the current version is stable, specify the
new version explicitly, like `make release bump="--new-version 4.0.0-alpha.1 devnum"`
