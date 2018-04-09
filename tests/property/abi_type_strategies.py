import itertools

from eth_utils import (
    encode_hex,
    add_0x_prefix,
)

import hypothesis.strategies as st


strat_int256 = st.integers(min_value=-1 * 2**255, max_value=2**255 - 1)
strat_uint256 = st.integers(min_value=0, max_value=2**256 - 1)

MAX_LIST_SIZE = 8
MIN_LIST_SIZE = 0


uint_raw_strats = [
    ('uint' + str(sub), st.integers(min_value=0, max_value=2**sub - 1))
    for sub in range(8, 257, 8)
]
uint_strats = [
    st.tuples(st.just(key), strat) for key, strat in uint_raw_strats
]


int_raw_strats = [
    ('int' + str(sub), st.integers(min_value=-1 * 2**(sub - 1), max_value=2**(sub - 1) - 1))
    for sub in range(8, 257, 8)
]
int_strats = [
    st.tuples(st.just(key), strat) for key, strat in int_raw_strats
]


sized_bytes_raw_strats = [
    ('bytes' + str(sub), st.binary(min_size=sub, max_size=sub))
    for sub in range(1, 33)
]
sized_bytes_strats = [
    st.tuples(st.just(key), strat) for key, strat in sized_bytes_raw_strats
]


address_raw_strat = st.binary(min_size=20, max_size=20).map(encode_hex).map(add_0x_prefix)
address_strat = st.tuples(
    st.just('address'),
    address_raw_strat,
)


bytes_raw_strat = st.binary(min_size=0, max_size=4096)
bytes_strat = st.tuples(
    st.just('bytes'),
    bytes_raw_strat,
)


all_basic_raw_strats = list(itertools.chain(
    int_raw_strats,
    uint_raw_strats,
    sized_bytes_raw_strats,
    [('address', address_raw_strat)],
))
all_basic_strats = list(itertools.chain(
    int_strats,
    uint_strats,
    sized_bytes_strats,
    [address_strat],
))


unsized_list_raw_strats = [
    (type_str + "[]", st.lists(type_strat, min_size=0, max_size=MAX_LIST_SIZE).map(tuple))
    for type_str, type_strat in all_basic_raw_strats
]
unsized_list_strats = [
    st.tuples(st.just(type_str), type_strat)
    for type_str, type_strat in unsized_list_raw_strats
]


sized_list_strats = [
    st.tuples(
        st.shared(
            st.integers(min_value=MIN_LIST_SIZE, max_value=MAX_LIST_SIZE),
            key="sized_list_strats",
        ).map(lambda n, type_str=type_str: type_str + "[{0}]".format(n)),
        st.shared(
            st.integers(min_value=MIN_LIST_SIZE, max_value=MAX_LIST_SIZE),
            key="sized_list_strats",
        ).flatmap(lambda n, type_strat=type_strat: st.lists(type_strat, min_size=n, max_size=n).map(tuple))
    ) for type_str, type_strat in all_basic_raw_strats
]


def zip_types_and_values(types_and_values):
    types, values = zip(*types_and_values)
    return tuple(types), tuple(values)


single_abi_strats = st.one_of(itertools.chain(
    all_basic_strats,
    [bytes_strat],
))


multi_abi_strats = st.lists(
    st.one_of(itertools.chain(
        unsized_list_strats,
        sized_list_strats,
        all_basic_strats,
        [bytes_strat],
    )),
    min_size=1,
    max_size=10,
).map(zip_types_and_values)
