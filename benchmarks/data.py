# Shared value lists for encoding/decoding/packed/abi benchmarks

from decimal import (
    Decimal,
)

# Granular lists for encoding/decoding
booleans = [True, False]

addresses = [
    b"\x00" * 19 + b"\x01",
    b"\xff" * 20,
    b"\x01" * 20,
    b"\x00" * 20,
    b"\x12" * 20,
    b"\x00" * 19 + b"\x02",
    b"\x01" * 19 + b"\x00",
]

uint256s = [
    0,
    1,
    2**256 - 1,
    2**128,
    2**64,
    12345678901234567890,
    2**255,
    2**255 - 1,
    2**32,
    2**16,
    42,
    999999999999999999999999999999,
]

bytes32s = [
    b"\x00" * 32,
    b"\xff" * 32,
    b"abc" * 10 + b"de",
    b"\x01" * 32,
    b"\x12" * 32,
    b"",  # empty
    b"\x00" * 16,  # short
]

bytes32_ids = list(map(repr, bytes32s))

strings = [
    "",
    "hello world",
    "𝔘𝔫𝔦𝔠𝔬𝔡𝔢",
    "a" * 256,
    "b" * 1024,
    "c" * 4096,
    "d" * 8192,
    "e" * 16384,
    "f" * 32768,
    "g" * 65536,
    "\0",  # null byte
    "a\nb",  # newline
    "a" * 100000,  # very long
]

string_ids = [
    "empty",
    "hello-world",
    "unicode",
    "'a' * 256",
    "'b' * 1024",
    "'c' * 4096",
    "'d' * 8192",
    "'e' * 16384",
    "'f' * 32768",
    "'g' * 65536",
    "null-byte",
    "newline",
    "very-long",
]

tuples = [
    ((1, True), ["uint256", "bool"]),
    ((b"\x00" * 32, "foo"), ["bytes32", "string"]),
    ((2**255 - 1, False, "bar"), ["int256", "bool", "string"]),
    (([1, 2, 3], [True, False]), ["uint8[3]", "bool[2]"]),
    ((b"\x01" * 20, 0), ["address", "uint8"]),
    (([b"\x00" * 32, b"\xff" * 32], ["a", "b"]), ["bytes32[2]", "string[2]"]),
]
tuple_ids = [
    "int-bool",
    "bytes-string",
    "int-bool-string",
    "arrs",
    "addr-uint8",
    "bytes32s-strings",
]

# --- Comprehensive ABI test cases for abi/packed benchmarks ---


# Primitive types
def make_fixed_decimal(bits: int, exp: int) -> Decimal:
    # For each (bits, exp), generate a value within the allowed range
    # Range: [-2**(bits-1)/10**exp, 2**(bits-1)-1/10**exp]
    max_val = (2 ** (bits - 1) - 1) / (10**exp)
    min_val = -(2 ** (bits - 1)) / (10**exp)
    # Use a value safely within the range, e.g., 1.2 or 0.1 if possible
    if max_val >= 1.2 and min_val <= -1.2:
        return Decimal("1.2").quantize(Decimal("1." + "0" * exp))
    elif max_val >= 0.1:
        return Decimal("0.1").quantize(Decimal("1." + "0" * exp))
    else:
        return Decimal(str(max_val)).quantize(Decimal("1." + "0" * exp))


def make_ufixed_decimal(bits: int, exp: int) -> Decimal:
    # For each (bits, exp), generate a value within the allowed range
    # Range: [0, 2**bits-1/10**exp]
    max_val = (2**bits - 1) / (10**exp)
    if max_val >= 1.2:
        return Decimal("1.2").quantize(Decimal("1." + "0" * exp))
    elif max_val >= 0.1:
        return Decimal("0.1").quantize(Decimal("1." + "0" * exp))
    else:
        return Decimal(str(max_val)).quantize(Decimal("1." + "0" * exp))


decimal_cases = []
for bits in (8, 16, 32, 64, 128, 256):
    for exp in (1, 2, 10, 18, 80):
        max_val_fixed = (2 ** (bits - 1) - 1) / (10**exp)
        if max_val_fixed >= 1.0:
            decimal_cases.append((f"fixed{bits}x{exp}", make_fixed_decimal(bits, exp)))
        max_val_ufixed = (2**bits - 1) / (10**exp)
        if max_val_ufixed >= 1.0:
            decimal_cases.append(
                (f"ufixed{bits}x{exp}", make_ufixed_decimal(bits, exp))
            )

primitive_cases = (
    [
        ("uint8", 0),
        ("uint8", 255),
        ("uint16", 65535),
        ("uint32", 2**32 - 1),
        ("uint64", 2**64 - 1),
        ("uint128", 2**128 - 1),
        ("uint256", 0),
        ("uint256", 2**256 - 1),
        ("int8", -128),
        ("int8", 127),
        ("int16", -32768),
        ("int16", 32767),
        ("int32", -(2**31)),
        ("int32", 2**31 - 1),
        ("int64", -(2**63)),
        ("int64", 2**63 - 1),
        ("int128", -(2**127)),
        ("int128", 2**127 - 1),
        ("int256", -(2**255)),
        ("int256", 2**255 - 1),
        ("bool", True),
        ("bool", False),
        ("address", b"\x00" * 19 + b"\x01"),
        ("address", b"\xff" * 20),
        ("bytes1", b"\x01"),
    ]
    + [(f"bytes{M}", b"\x01" * M) for M in range(2, 33)]
    + [
        ("bytes", b""),
        ("bytes", b"hello world"),
        ("bytes", b"\x00" * 100),
        ("bytes", b"a" * 256),
        ("string", ""),
        ("string", "hello world"),
        ("string", "𝔘𝔫𝔦𝔠𝔬𝔡𝔢"),
        ("string", "a" * 256),
        ("string", "b" * 1024),
    ]
    + decimal_cases
    + [
        ("function", b"\x01" * 24),
        ("function", b"\x00" * 24),
        ("function", b"\xff" * 24),
    ]
)
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
    ("bytes8[4]", [b"\x01" * 8, b"\x02" * 8, b"\x03" * 8, b"\x04" * 8]),
    ("fixed32x2[2]", [Decimal("3.14"), Decimal("2.71")]),
    ("uint8[]", []),
    ("bytes[]", []),
    ("fixed32x2[]", []),
    ("uint8[10]", list(range(10))),
    ("string[5]", ["a", "b", "c", "d", "e"]),
    ("bytes16[3]", [b"\x01" * 16, b"\x02" * 16, b"\x03" * 16]),
    ("uint8[100]", list(range(100))),
    ("string[10]", list(map(str, range(10)))),
    ("bytes[10]", list(map(lambda i: i.to_bytes(8, "little"), range(10)))),
    ("uint8[][]", [[]]),
    ("string[]", []),
    ("uint8[2][]", []),
    ("uint8[2][2][]", []),
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
    ("(fixed32x2,uint8)", (Decimal("3.14"), 255)),
    (
        "(bytes1,bytes2,bytes3,bytes4)",
        (b"\x01", b"\x01\x02", b"\x01\x02\x03", b"\x01\x02\x03\x04"),
    ),
    ("(function,uint256)", (b"\x01" * 24, 123)),
    ("(uint8[3],(string[2],bool[2]))", ([1, 2, 3], (["a", "b"], [True, False]))),
    ("(bytes32[],string[])", ([b"\x00" * 32, b"\xff" * 32], ["foo", "bar"])),
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
    ("(uint8[2][2][2],string)", ([[[1, 2], [3, 4]], [[5, 6], [7, 8]]], "deep")),
    (
        "((uint8[2][2],(string[2],bool[2])),bytes32[2])",
        (([[1, 2], [3, 4]], (["x", "y"], [True, False])), [b"\x00" * 32, b"\xff" * 32]),
    ),
    (
        "(uint8[2][2][2][2],string[2])",
        (
            [
                [[[1, 2], [3, 4]], [[5, 6], [7, 8]]],
                [[[9, 10], [11, 12]], [[13, 14], [15, 16]]],
            ],
            ["deep", "deeper"],
        ),
    ),
    (
        "(uint8[2][2][2][2][2],string[2][2])",
        (
            [
                [
                    [[[1, 2], [3, 4]], [[5, 6], [7, 8]]],
                    [[[9, 10], [11, 12]], [[13, 14], [15, 16]]],
                ],
                [
                    [[[17, 18], [19, 20]], [[21, 22], [23, 24]]],
                    [[[25, 26], [27, 28]], [[29, 30], [31, 32]]],
                ],
            ],
            [["a", "b"], ["c", "d"]],
        ),
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
    ("bytes[]", []),
    ("fixed32x2[]", []),
    ("(uint8[][],string)", ([[]], "")),
    ("(string[],bytes[])", ([], [])),
    ("(uint8[2][],string[])", ([], [])),
    ("(uint8[2][2][],string[])", ([], [])),
    ("bytes[100]", list(map(lambda i: i.to_bytes(32, "little"), range(100)))),
    ("(bytes[],string[])", ([], [])),
    ("(uint8[2][2][2][2][],string[])", ([], [])),
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
