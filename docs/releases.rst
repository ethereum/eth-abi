Release Notes
=============

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
