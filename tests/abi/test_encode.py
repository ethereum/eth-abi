import pytest

from eth_abi import (
    encode,
)
from eth_abi.grammar import (
    parse,
)

from ..common.unit import (
    CORRECT_DYNAMIC_ENCODINGS,
    CORRECT_STATIC_ENCODINGS,
    CORRECT_TUPLE_ENCODINGS,
    words,
)


@pytest.mark.parametrize(
    "tuple_type,python_value,solidity_abi_encoded,_",
    CORRECT_TUPLE_ENCODINGS,
)
def test_abi_encode_for_multiple_types_as_list(
    tuple_type, python_value, solidity_abi_encoded, _
):
    abi_type = parse(tuple_type)
    if abi_type.arrlist is not None:
        pytest.skip("ABI coding functions do not support array types")

    # assert different types encoded correctly as a list
    # e.g. encode(['bytes32[]', 'uint256'], ([b'a', b'b'], 22))
    #
    # compare to solidity:
    #   bytes32 a = 0x6100000000000000000000000000000000000000000000000000000000000000;
    #   bytes32 b = 0x6200000000000000000000000000000000000000000000000000000000000000;
    #   bytes32[] arr = [a,b];
    #   uint256 num = 22;
    #
    #   abi.encode(arr,num);
    separated_list_of_types = [t.to_type_str() for t in abi_type.components]
    eth_abi_encoded = encode(separated_list_of_types, python_value)

    assert eth_abi_encoded == solidity_abi_encoded


@pytest.mark.parametrize(
    "single_abi_type,python_value,solidity_abi_encoded,_",
    CORRECT_STATIC_ENCODINGS,
)
def test_abi_encode_for_single_static_types(
    single_abi_type, python_value, solidity_abi_encoded, _
):
    # If single_abi_type is a tuple, assert the tuple type is encoded correctly
    # e.g. encode(['(bytes32[],uint256)'], [([b'a', b'b'], 22)])
    #
    # compare to solidity:
    #   struct TupleExample {
    #     bytes32[] arg1;
    #     uint256 arg2;
    #   }
    #   bytes32 a = 0x6100000000000000000000000000000000000000000000000000000000000000;
    #   bytes32 b = 0x6200000000000000000000000000000000000000000000000000000000000000;
    #   bytes32[] arr = [a,b];
    #   uint256 num = 22;
    #
    #   abi.encode(TupleExample(arr,num));
    eth_abi_encoded = encode([single_abi_type], [python_value])

    assert eth_abi_encoded == solidity_abi_encoded


@pytest.mark.parametrize(
    "single_abi_type,python_value,solidity_abi_encoded,_",
    CORRECT_DYNAMIC_ENCODINGS,
)
def test_abi_encode_for_single_dynamic_types(
    single_abi_type, python_value, solidity_abi_encoded, _
):
    # Same test as the single static types test above but with dynamic types
    eth_abi_encoded = encode([single_abi_type], [python_value])

    solidity_abi_encoded = (
        # 32 bytes offset for dynamic types
        b"".join([words("20"), solidity_abi_encoded])
    )

    assert eth_abi_encoded == solidity_abi_encoded


@pytest.mark.parametrize(
    "non_list_like_value",
    (
        "",
        123,
        b"",
        b"\xff",
        b"david attenborough",
        bytearray(b"\x01\xff"),
        {"key": "val"},
        {1, 2},
    ),
)
def test_abi_encode_raises_for_non_list_like_params(non_list_like_value):
    # test raises when `types` param is not list-like
    with pytest.raises(
        TypeError,
        match=f"The `types` value type must be one of list or tuple. "
        f"Got {type(non_list_like_value)}",
    ):
        encode(non_list_like_value, ["bytes"])

    # test raises when `args` param is not list-like
    with pytest.raises(
        TypeError,
        match=f"The `args` value type must be one of list or tuple. "
        f"Got {type(non_list_like_value)}",
    ):
        encode(["valid_string_value"], non_list_like_value)
