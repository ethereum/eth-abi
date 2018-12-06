Release Notes
=============

v1.3.0
------

Released December 6, 2018

- Bugfixes

  - Resolved an issue that was preventing discovery of type hints.

- Misc

  - Updated eth-typing dependency version to ``>=2.0.0,<3.0.0``.

v1.2.2
-------------

Released October 18, 2018

- Bugfixes

  - Expand parsimonious dependency from v0.8.0 to v0.8.*

v1.2.1
-------------

Released October 16, 2018

- Bugfixes

  - Was accidentally allowing eth-typing v2. Now it requires eth-typing v1 only.

v1.2.0
-------------

Released August 28, 2018

- New Features

  - Backported and added support for nested dynamic arrays in the Solidity
    version 2 ABI

v1.1.1
-------------

Released May 10, 2018

- Bugfixes

  - :meth:`~eth_abi.abi.is_encodable()` now returns ``False`` if a :class:`~decimal.Decimal` has
    too many digits to be encoded in the given ``fixed<M>x<N>`` type.
    (It was previously raising a :class:`ValueError`)
  - Raise an :class:`~eth_abi.exceptions.EncodingTypeError` instead of a
    :class:`TypeError` when trying to encode a :class:`float` into a ``fixed<M>x<N>`` type.

v1.1.0
-------------

Released May 8, 2018

- New Features

  - Added a Registry API (docs in progress) for looking up encoders by ABI type
  - Added support for types: tuple and fixedMxN
  - Added new is_encodable check for whether a value can be encoded with the given ABI type
- Bugfixes

  - Fix RealDecoder bug that allowed values other than 32 bytes
  - Fix bug that accepted ``stringN`` as a valid ABI type. Strings may not have a fixed length.
  - Stricter value checking when encoding a Decimal (Make sure it's not a NaN)
  - Fix typos in "missing property" exceptions
- Misc

  - Precompile regexes, for performance & clarity
  - Test fixups and switch to CircleCI
  - Readme improvements
  - Performance improvements
  - Drop Python 2 support cruft

v1.0.0
-------------

Released Feb 28, 2018

- Confirmed pypy3 compatibility
- Add support for eth-utils v1.0.0-beta2 and v1.0.1 stable
- Testing improvements

v1.0.0-beta.0
-------------

Released Feb 5, 2018

- Drop py2 support
- Add support for eth-utils v1-beta1

v0.5.0
--------

Latest stable version
