# Ethereum Contract

[![Build Status](https://travis-ci.org/ethereum/eth-abi.png)](https://travis-ci.org/ethereum/eth-abi)
[![Documentation Status](https://readthedocs.org/projects/eth-abi/badge/?version=latest)](https://readthedocs.org/projects/eth-abi/?badge=latest)
[![PyPi version](https://pypip.in/v/eth-abi/badge.png)](https://pypi.python.org/pypi/eth-abi)
[![PyPi downloads](https://pypip.in/d/eth-abi/badge.png)](https://pypi.python.org/pypi/eth-ipc-utils)
   

Python utilities for working with the Ethereum ABI


## Installation

```sh
pip install eth-abi
```

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
bumpversion $$VERSION_PART_TO_BUMP$$
git push && git push --tags
make release
```


#### How to bumpversion

The version format for this repo is `{major}.{minor}.{patch}` for stable, and
`{major}.{minor}.{patch}-{stage}.{devnum}` for unstable (`stage` can be alpha or beta).

To issue the next version in line, use bumpversion and specify which part to bump,
like `bumpversion minor` or `bumpversion devnum`.

If you are in a beta version, `bumpversion stage` will switch to a stable.

To issue an unstable version when the current version is stable, specify the
new version explicitly, like `bumpversion --new-version 4.0.0-alpha.1 devnum`
