# Shared value lists for encoding/decoding/packed/abi benchmarks

import decimal

# Granular lists for encoding/decoding
booleans = [True, False]

addresses = [b"\x00" * 19 + b"\x01", b"\xff" * 20]

uint256s = [0, 1, 2**256 - 1]

bytes32s = [b"\x00" * 32, b"\xff" * 32]

strings = ["", "hello world", "𝔘𝔫𝔦𝔠𝔬𝔡𝔢"]

tuples = [
    ((1, True), ["uint256", "bool"]),
    ((b"\x00" * 32, "foo"), ["bytes32", "string"]),
]
tuple_ids = ["int-bool", "bytes-string"]

# --- Comprehensive ABI test cases for abi/packed benchmarks ---

# Primitive types
primitive_cases = [
    ("uint8", 0),
    ("uint8", 255),
    ("uint256", 0),
    ("uint256", 2**256 - 1),
    ("int8", -128),
    ("int8", 127),
    ("int256", -(2**255)),
    ("int256", 2**255 - 1),
    ("bool", True),
    ("bool", False),
    ("address", b"\x00" * 19 + b"\x01"),
    ("address", b"\xff" * 20),
    ("bytes1", b"\x01"),
    ("bytes32", b"\x00" * 32),
    ("bytes32", b"\xff" * 32),
    ("bytes", b""),
    ("bytes", b"hello world"),
    ("bytes", b"\x00" * 100),
    ("string", ""),
    ("string", "hello world"),
    ("string", "𝔘𝔫𝔦𝔠𝔬𝔡𝔢"),
    ("fixed128x18", decimal.Decimal("1.234567890123456789")),
    ("ufixed128x18", decimal.Decimal("1.234567890123456789")),
]
primitive_ids = [f"{t}-{repr(v)[:16]}" for t, v in primitive_cases]

# Arrays
array_cases = [
    ("uint8[3]", [1, 2, 3]),
    ("uint256[2]", [0, 2**256 - 1]),
    ("bool[4]", [True, False, True, False]),
    ("address[2]", [b"\x00" * 19 + b"\x01", b"\xff" * 20]),
    ("bytes32[2]", [b"\x00" * 32, b"\xff" * 32]),
    ("string[2]", ["foo", "bar"]),
    ("uint8[]", [1, 2, 3, 4, 5]),
    ("string[]", ["a", "b", "c"]),
    ("bytes[]", [b"abc", b"def", b"ghi"]),
    ("uint256[2][2]", [[1, 2], [3, 4]]),
    ("bool[][2]", [[True, False], [False, True]]),
]
array_ids = [f"{t}-{repr(v)[:16]}" for t, v in array_cases]

# Tuples
tuple_cases = [
    ("(uint256,bool)", (42, True)),
    ("(address,uint8)", (b"\x00" * 19 + b"\x01", 255)),
    ("(string,bytes)", ("foo", b"bar")),
    ("(uint256[2],string)", ([1, 2], "baz")),
    ("(uint8,(bool,string))", (7, (False, "hi"))),
    ("((uint8,uint8),uint8)", ((1, 2), 3)),
    ("(uint8[2],(string,bool[2]))", ([1, 2], ("x", [True, False]))),
]
tuple_ids_full = [f"{t}-{repr(v)[:16]}" for t, v in tuple_cases]

# Nested/complex
nested_cases = [
    ("(uint256[],(string[],bool))", ([1, 2, 3], (["a", "b"], True))),
    ("((uint8[2],(string,bool)),bytes32)", (([1, 2], ("hi", False)), b"\x00" * 32)),
    (
        "(uint8[2][2],(string[2],bool[2]))",
        ([[1, 2], [3, 4]], (["x", "y"], [True, False])),
    ),
]
nested_ids = [f"{t}-{repr(v)[:16]}" for t, v in nested_cases]

# Edge cases
edge_cases = [
    ("uint8[]", []),
    ("string[]", []),
    ("bytes", b"\x00" * 1024),
    ("string", "a" * 1024),
    ("(uint8[],string)", ([], "")),
    ("(string[],bytes[])", ([""], [b""])),
]
edge_ids = [f"{t}-{repr(v)[:16]}" for t, v in edge_cases]

# Combine all cases
all_cases = primitive_cases + array_cases + tuple_cases + nested_cases + edge_cases
all_ids = primitive_ids + array_ids + tuple_ids_full + nested_ids + edge_ids

# Packed-compatible subset (for test_packed_benchmarks.py)
packed_cases = [
    ("uint256", 123456789),
    ("address", b"\x00" * 19 + b"\x01"),
    ("bytes", b"hello world"),
    ("bool", True),
    ("string", "hello world"),
    ("(uint256,bool)", (42, False)),
]
packed_ids = ["uint256", "address", "bytes", "bool", "string", "tuple"]
