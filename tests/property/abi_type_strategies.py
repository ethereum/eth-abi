import itertools
import random

from eth_utils import (
    encode_hex,
    add_0x_prefix,
)

import hypothesis.strategies as st


##########################
# Type string strategies #
##########################

join = lambda xs: ''.join(map(str, xs))
join_with_x = lambda xs: 'x'.join(map(str, xs))

bare_type_strs = st.sampled_from([
    'uint', 'int', 'ufixed', 'fixed', 'address', 'bool', 'bytes', 'function',
    'string',
])

total_bits = st.integers(min_value=1, max_value=32).map(lambda n: n * 8)
frac_places = st.integers(min_value=1, max_value=80)
bytes_sizes = st.integers(min_value=1, max_value=32)

fixed_sizes = st.tuples(total_bits, frac_places)
fixed_size_strs = fixed_sizes.map(join_with_x)

fixed_bytes_type_strs = st.tuples(st.just('bytes'), bytes_sizes).map(join)
uint_type_strs = st.tuples(st.just('uint'), total_bits).map(join)
int_type_strs = st.tuples(st.just('int'), total_bits).map(join)

ufixed_type_strs = st.tuples(st.just('ufixed'), fixed_size_strs).map(join)
fixed_type_strs = st.tuples(st.just('fixed'), fixed_size_strs).map(join)

non_array_type_strs = st.one_of(
    bare_type_strs,
    fixed_bytes_type_strs,
    uint_type_strs,
    int_type_strs,
    ufixed_type_strs,
    fixed_type_strs,
)

dynam_array_components = st.just(tuple())
fixed_array_components = st.integers(min_value=1).map(lambda x: (x,))
array_components = st.one_of(dynam_array_components, fixed_array_components)

array_lists = st.lists(array_components, min_size=1, max_size=6)
array_list_strs = array_lists.map(lambda x: ''.join(repr(list(i)) for i in x))

array_type_strs = st.tuples(non_array_type_strs, array_list_strs).map(join)

non_tuple_type_strs = st.one_of(non_array_type_strs, array_type_strs)


def join_tuple(xs):
    if not isinstance(xs, list):
        return xs

    return '({})'.format(','.join(join_tuple(x) for x in xs))


tuple_type_strs = st.recursive(
    st.lists(non_tuple_type_strs, min_size=2, max_size=2),
    lambda this_strategy: st.lists(
        st.one_of(non_tuple_type_strs, this_strategy),
        min_size=2, max_size=10,
    ),
).map(join_tuple)

type_strs = st.one_of(non_tuple_type_strs, tuple_type_strs)


def guaranteed_permute(xs):
    len_xs = len(xs)
    indices = tuple(range(len_xs))

    shuffled_indices = indices
    while indices == shuffled_indices:
        shuffled_indices = tuple(random.sample(indices, k=len_xs))

    return tuple(xs[i] for i in shuffled_indices)


malformed_non_tuple_type_strs = st.tuples(
    st.one_of(bare_type_strs, st.text()),
    st.one_of(total_bits, fixed_size_strs),
    array_list_strs,
).map(guaranteed_permute).map(join)

malformed_tuple_type_strs = st.recursive(
    st.lists(malformed_non_tuple_type_strs, min_size=2, max_size=2),
    lambda this_strategy: st.lists(
        st.one_of(malformed_non_tuple_type_strs, this_strategy),
        min_size=2, max_size=10,
    ),
).map(join_tuple)

malformed_type_strs = st.one_of(
    malformed_non_tuple_type_strs,
    malformed_tuple_type_strs,
)


#################################
# Type string w/data strategies #
#################################

strat_int256 = st.integers(min_value=-1 * 2**255, max_value=2**255 - 1)
strat_uint256 = st.integers(min_value=0, max_value=2**256 - 1)

MAX_LIST_SIZE = 8
MIN_LIST_SIZE = 1


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
