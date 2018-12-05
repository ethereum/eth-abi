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

For documentation, visit [https://eth-abi.readthedocs.io/en/latest/](https://eth-abi.readthedocs.io/en/latest/).

## Development

Clone the repository and then run:

```sh
pip install -e .[dev]
```

You might want to do this inside a virtualenv.

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
