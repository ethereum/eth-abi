# Benchmarks for faster-eth-abi

This directory contains a comprehensive suite of benchmarks for both user-facing and internal APIs in `faster_eth_abi`, designed for contributors and maintainers to:

- Compare performance between `eth_abi` (reference) and `faster_eth_abi` (C-accelerated)
- Catch regressions and measure improvements in encoding, decoding, and registry logic
- Benchmark internals and helpers for advanced optimization

## Benchmark Files

- `test_encoding_benchmarks.py`: Compares encoding performance for all major ABI types (bool, address, uint256, bytes32, string, tuples) between `eth_abi` and `faster_eth_abi`.
- `test_decoding_benchmarks.py`: Compares decoding performance for the same types.
- `test_packed_benchmarks.py`: Benchmarks `encode_packed` and `is_encodable_packed` for both libraries.
- `test_grammar_benchmarks.py`: Benchmarks ABI type string normalization and parsing utilities.
- `test_registry_benchmarks.py`: Benchmarks registry lookups and registration operations.

## Running Benchmarks

Install all dev dependencies:
```
pip install .[dev]
```

Run all benchmarks with pytest-codspeed or pytest-benchmark:
```
pytest benchmarks/ --benchmark-only
pytest benchmarks/ --codspeed
```

## Contributing

- Add new benchmarks for any new public API or internal helper that could impact performance.
- Keep parameterizations broad to catch edge cases and stress-test the implementation.
- Use the `test_xxx` (reference) and `test_faster_xxx` (optimized) naming pattern for easy comparison.
