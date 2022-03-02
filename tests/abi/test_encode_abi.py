import pytest

from eth_abi import (
    encode_abi,
)
from eth_abi.grammar import (
    parse,
)

from ..common.unit import (
    CORRECT_TUPLE_ENCODINGS,
    words,
)


@pytest.mark.parametrize(
    'tuple_type,python_value,_1,encoded_list_of_types,_2',
    CORRECT_TUPLE_ENCODINGS,
)
def test_encode_abi_as_list_of_types(tuple_type, python_value, _1, encoded_list_of_types, _2):
    abi_type = parse(tuple_type)
    if abi_type.arrlist is not None:
        pytest.skip('ABI coding functions do not support array types')

    # assert different types encoded correctly as a list
    # e.g. encode_abi(['bytes32[]', 'uint256'], ([b'a', b'b'], 22))
    #
    # compare to solidity:
    #   bytes32 a = 0x6100000000000000000000000000000000000000000000000000000000000000;
    #   bytes32 b = 0x6200000000000000000000000000000000000000000000000000000000000000;
    #   bytes32[] arr = [a,b];
    #   uint256 num = 22;
    #
    #   abi.encode(arr,num);
    separated_list_of_types = [t.to_type_str() for t in abi_type.components]
    eth_abi_encoded = encode_abi(separated_list_of_types, python_value)
    assert eth_abi_encoded == encoded_list_of_types


@pytest.mark.parametrize(
    'tuple_type,python_value,is_dynamic,encoded_list_of_types,_2',
    CORRECT_TUPLE_ENCODINGS,
)
def test_encode_abi_as_single_tuple_type(
    tuple_type, python_value, is_dynamic, encoded_list_of_types, _2
):
    # assert the tuple type is encoded correctly
    # e.g. encode_abi(['(bytes32[],uint256)'], [([b'a', b'b'], 22)])
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
    eth_abi_encoded = encode_abi([tuple_type], [python_value])

    encoded_tuple_type = (
        # 32 bytes offset for dynamic tuple types
        b''.join([words('20'), encoded_list_of_types]) if is_dynamic

        # no offset for static tuples so same encoding as if encoding a list of the types
        else encoded_list_of_types
    )
    assert eth_abi_encoded == encoded_tuple_type
