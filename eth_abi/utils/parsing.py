"""
This module provided for backwards compatibility.
"""
from eth_abi.grammar import (
    TupleType,
    normalize,
    parse,
)


def process_type(type_str):
    normalized_type_str = normalize(type_str)
    abi_type = parse(normalized_type_str)

    type_str_repr = repr(type_str)
    if type_str != normalized_type_str:
        type_str_repr = '{} (normalized to {})'.format(
            type_str_repr,
            repr(normalized_type_str),
        )

    if isinstance(abi_type, TupleType):
        raise ValueError(
            "Cannot process type {}: tuple types not supported".format(
                type_str_repr,
            )
        )

    abi_type.validate()

    sub = abi_type.sub
    if isinstance(sub, tuple):
        sub = 'x'.join(map(str, sub))
    elif isinstance(sub, int):
        sub = str(sub)
    else:
        sub = ''

    arrlist = abi_type.arrlist
    if isinstance(arrlist, tuple):
        arrlist = list(map(list, arrlist))
    else:
        arrlist = []

    return abi_type.base, sub, arrlist


def collapse_type(base, sub, arrlist):
    return base + sub + ''.join(map(repr, arrlist))
