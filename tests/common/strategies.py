import decimal
import random

from eth_abi.utils.numeric import abi_decimal_context

from eth_utils import (
    encode_hex,
    add_0x_prefix,
)

import hypothesis.strategies as st


total_bits = st.integers(min_value=1, max_value=32).map(lambda n: n * 8)
frac_places = st.integers(min_value=1, max_value=80)
bytes_sizes = st.integers(min_value=1, max_value=32)

fixed_sizes = st.tuples(total_bits, frac_places)


##########################
# Type string strategies #
##########################

def join(xs):
    return ''.join(map(str, xs))


def join_with_x(xs):
    return 'x'.join(map(str, xs))


bare_type_strs = st.sampled_from([
    'uint', 'int', 'ufixed', 'fixed', 'address', 'bool', 'bytes', 'function',
    'string',
])

fixed_bytes_type_strs = bytes_sizes.map('bytes{}'.format)
uint_type_strs = total_bits.map('uint{}'.format)
int_type_strs = total_bits.map('int{}'.format)

fixed_size_strs = fixed_sizes.map(join_with_x)
ufixed_type_strs = fixed_size_strs.map('ufixed{}'.format)
fixed_type_strs = fixed_size_strs.map('fixed{}'.format)

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
    st.lists(non_tuple_type_strs, min_size=0, max_size=10),
    lambda this_strategy: st.lists(
        st.one_of(non_tuple_type_strs, this_strategy),
        min_size=0, max_size=10,
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
    st.lists(malformed_non_tuple_type_strs, min_size=1, max_size=10),
    lambda this_strategy: st.lists(
        st.one_of(malformed_non_tuple_type_strs, this_strategy),
        min_size=1, max_size=10,
    ),
).map(join_tuple)

malformed_type_strs = st.one_of(
    malformed_non_tuple_type_strs,
    malformed_tuple_type_strs,
)


#################################
# Type string w/data strategies #
#################################

MIN_LIST_SIZE = 1
MAX_LIST_SIZE = 8

uint_total_bits = st.shared(total_bits, key='uint_total_bits')
uint_strs = uint_total_bits.map('uint{}'.format)
uint_values = uint_total_bits.flatmap(lambda n: st.integers(
    min_value=0,
    max_value=2 ** n - 1,
))

int_total_bits = st.shared(total_bits, key='int_total_bits')
int_strs = int_total_bits.map('int{}'.format)
int_values = int_total_bits.flatmap(lambda n: st.integers(
    min_value=-2 ** (n - 1),
    max_value=2 ** (n - 1) - 1,
))


def scale_places(places):
    """
    Scaling must happen with adequate precision.  Otherwise, we get bounds
    checking errors.
    """
    def f(x):
        with decimal.localcontext(abi_decimal_context):
            return x / 10 ** places
    return f


ufixed_size_tuples = st.shared(fixed_sizes, key='ufixed_size_tuples')
ufixed_strs = ufixed_size_tuples.map(join_with_x).map('ufixed{}'.format)
ufixed_values = ufixed_size_tuples.flatmap(lambda sz: st.decimals(
    min_value=0,
    max_value=2 ** sz[0] - 1,
    places=0,
).map(scale_places(sz[1])))

fixed_size_tuples = st.shared(fixed_sizes, key='fixed_size_tuples')
fixed_strs = fixed_size_tuples.map(join_with_x).map('fixed{}'.format)
fixed_values = fixed_size_tuples.flatmap(lambda sz: st.decimals(
    min_value=-2 ** (sz[0] - 1),
    max_value=2 ** (sz[0] - 1) - 1,
    places=0,
).map(scale_places(sz[1])))

fixed_bytes_sizes = st.shared(bytes_sizes, key='fixed_bytes_sizes')
fixed_bytes_strs = fixed_bytes_sizes.map('bytes{}'.format)
fixed_bytes_values = fixed_bytes_sizes.flatmap(lambda n: st.binary(
    min_size=n,
    max_size=n,
))

address_strs = st.just('address')
address_values = st.binary(min_size=20, max_size=20).map(encode_hex)

bytes_strs_and_values = st.tuples(
    st.just('bytes'),
    st.binary(min_size=0, max_size=4096),
)

non_array = (
    (uint_strs, uint_values),
    (int_strs, int_values),
    (ufixed_strs, ufixed_values),
    (fixed_strs, fixed_values),
    (fixed_bytes_strs, fixed_bytes_values),
    (address_strs, address_values),
)

non_array_strs_values = st.one_of(*[
    st.tuples(type_strs, type_values) for type_strs, type_values in non_array
])

num_unsized_elements = st.integers(min_value=0, max_value=MAX_LIST_SIZE)
unsized_array_strs_values = num_unsized_elements.flatmap(
    lambda n: st.one_of([
        st.tuples(
            type_strs.map('{}[]'.format),
            st.lists(type_values, min_size=n, max_size=n).map(tuple),
        )
        for type_strs, type_values in non_array
    ])
)

num_sized_elements = st.integers(min_value=MIN_LIST_SIZE, max_value=MAX_LIST_SIZE)
sized_array_strs_values = num_sized_elements.flatmap(
    lambda n: st.one_of([
        st.tuples(
            type_strs.map(lambda ts: '{}[{}]'.format(ts, n)),
            st.lists(type_values, min_size=n, max_size=n).map(tuple),
        )
        for type_strs, type_values in non_array
    ])
)

single_strs_values = st.one_of(
    unsized_array_strs_values,
    sized_array_strs_values,
    non_array_strs_values,
    bytes_strs_and_values,
)


def to_tuple(xs):
    if not isinstance(xs, list):
        return xs

    return tuple(to_tuple(x) for x in xs)


def destructure_tuple_example(xs):
    def _recur(xs, type_strs, values):
        if not isinstance(xs, list):
            type_strs.append(xs[0])
            values.append(xs[1])
            return

        _type_strs = []
        _values = []
        for ys in xs:
            _recur(ys, _type_strs, _values)

        type_strs.append(_type_strs)
        values.append(_values)

    type_strs = []
    values = []
    _recur(xs, type_strs, values)

    return join_tuple(type_strs[0]), to_tuple(values[0])


tuple_strs_values = st.recursive(
    st.lists(single_strs_values, min_size=0, max_size=10),
    lambda this_strategy: st.lists(
        st.one_of(single_strs_values, this_strategy),
        min_size=0, max_size=10,
    ),
).map(destructure_tuple_example)


def unzip_strs_values(strs_values):
    type_strs, type_values = zip(*strs_values)

    return tuple(type_strs), tuple(type_values)


multi_strs_values = st.lists(
    single_strs_values,
    min_size=1,
    max_size=10,
).map(unzip_strs_values)
