import functools
import re

import parsimonious
from parsimonious import (
    expressions,
)

from eth_abi.exceptions import (
    ABITypeError,
    ParseError,
)

grammar = parsimonious.Grammar(r"""
type = tuple_type / basic_type

tuple_type = components arrlist?
components = non_zero_tuple / zero_tuple

non_zero_tuple = "(" type next_type* ")"
next_type = "," type

zero_tuple = "()"

basic_type = base sub? arrlist?

base = alphas

sub = two_size / digits
two_size = (digits "x" digits)

arrlist = (const_arr / dynam_arr)+
const_arr = "[" digits "]"
dynam_arr = "[]"

alphas = ~"[a-z]+"
digits = ~"[1-9][0-9]*"
""")


class NodeVisitor(parsimonious.NodeVisitor):
    """
    Parsimonious node visitor which performs both parsing of type strings and
    post-processing of parse trees.  Parsing operations are cached.
    """
    grammar = grammar

    def visit_non_zero_tuple(self, node, visited_children):
        # Ignore left and right parens
        _, first, rest, _ = visited_children

        return (first,) + rest

    def visit_tuple_type(self, node, visited_children):
        components, arrlist = visited_children

        return TupleType(components, arrlist, node=node)

    def visit_next_type(self, node, visited_children):
        # Ignore comma
        _, abi_type = visited_children

        return abi_type

    def visit_zero_tuple(self, node, visited_children):
        return tuple()

    def visit_basic_type(self, node, visited_children):
        base, sub, arrlist = visited_children

        return BasicType(base, sub, arrlist, node=node)

    def visit_two_size(self, node, visited_children):
        # Ignore "x"
        first, _, second = visited_children

        return first, second

    def visit_const_arr(self, node, visited_children):
        # Ignore left and right brackets
        _, int_value, _ = visited_children

        return (int_value,)

    def visit_dynam_arr(self, node, visited_children):
        return tuple()

    def visit_alphas(self, node, visited_children):
        return node.text

    def visit_digits(self, node, visited_children):
        return int(node.text)

    def generic_visit(self, node, visited_children):
        if isinstance(node.expr, expressions.OneOf):
            # Unwrap value chosen from alternatives
            return visited_children[0]

        if isinstance(node.expr, expressions.Optional):
            # Unwrap optional value or return `None`
            if len(visited_children) != 0:
                return visited_children[0]

            return None

        return tuple(visited_children)

    @functools.lru_cache(maxsize=None)
    def parse(self, type_str):
        """
        Caches and returns results of parsing operations.  Wraps any raised
        parsing errors in a custom error class.
        """
        if not isinstance(type_str, str):
            raise TypeError('Can only parse string values: got {}'.format(type(type_str)))

        try:
            return super().parse(type_str)
        except parsimonious.ParseError as e:
            raise ParseError(e.text, e.pos, e.expr)


visitor = NodeVisitor()


class ABIType:
    """
    Base class for classes which represent the results of parsing operations on
    abi type strings after post-processing.
    """
    __slots__ = ('arrlist', 'node')

    def __init__(self, arrlist=None, node=None):
        # Any type might have a list of array dimensions
        self.arrlist = arrlist

        # The parsimonious `Node` instance associated with this parsed type may
        # be optionally included.  If a type must be validated during a parsing
        # operation, the `Node` instance is required since the `invalidate`
        # method expects it.
        self.node = node

    def __repr__(self):  # pragma: no cover
        return '<{} {}>'.format(type(self).__qualname__, repr(str(self)))

    def __eq__(self, other):
        """
        Two ABI types are equal if their canonical string representations are
        equal.
        """
        return (
            type(self) is type(other) and
            str(self) == str(other)
        )

    def __str__(self):  # pragma: no cover
        """
        An ABI type must have a canonical string representation.
        """
        raise NotImplementedError('Must implement `__str__`')

    def validate(self):  # pragma: no cover
        """
        An ABI type must be able to validate itself against the solidity ABI
        spec:
        https://solidity.readthedocs.io/en/develop/abi-spec.html
        """
        raise NotImplementedError('Must implement `validate`')

    def invalidate(self, error_msg):
        """
        Invalidates an ABI type with the given error message.  Expects that a
        parsimonious node was provided from the original parsing operation that
        yielded this type.
        """
        node = self.node

        raise ABITypeError(
            "For '{comp_str}' type at column {col} "
            "in '{type_str}': {error_msg}".format(
                comp_str=node.text,
                col=node.start + 1,
                type_str=node.full_text,
                error_msg=error_msg,
            ),
        )


class TupleType(ABIType):
    """
    Represents the result of parsing a type string which contains a tuple abi
    type.

    e.g. "(int,bool)"
    """
    __slots__ = ('components',)

    def __init__(self, components, arrlist=None, *, node=None):
        super().__init__(arrlist, node)

        self.components = components

    def __str__(self):
        arrlist = self.arrlist
        if isinstance(arrlist, tuple):
            arrlist = ''.join(repr(list(a)) for a in arrlist)
        else:
            arrlist = ''
        return '({}){}'.format(','.join(str(c) for c in self.components), arrlist)

    @property
    def item_type(self):
        """
        If this type is an array type, returns the type of the array's items.
        """
        if self.arrlist is None:
            raise ValueError(
                "Cannot determine item type for non-array type '{}'".format(self)
            )

        return type(self)(
            self.components,
            self.arrlist[:-1] or None,
            node=self.node,
        )

    def validate(self):
        # A tuple type is valid if all of its components are valid i.e. if none
        # of its components contain an invalid type such as "uint7"
        for c in self.components:
            c.validate()


class BasicType(ABIType):
    """
    Represents the result of parsing a type string which contains a basic abi
    type.

    e.g. "uint", "address", "ufixed128x19[][2]"
    """
    __slots__ = ('base', 'sub')

    def __init__(self, base, sub=None, arrlist=None, *, node=None):
        super().__init__(arrlist, node)

        self.base = base
        self.sub = sub

    def __str__(self):
        sub, arrlist = self.sub, self.arrlist

        if isinstance(sub, int):
            sub = str(sub)
        elif isinstance(sub, tuple):
            sub = 'x'.join(str(s) for s in sub)
        else:
            sub = ''

        if isinstance(arrlist, tuple):
            arrlist = ''.join(repr(list(a)) for a in arrlist)
        else:
            arrlist = ''

        return self.base + sub + arrlist

    @property
    def item_type(self):
        """
        If this type is an array type, returns the type of the array's items.
        """
        if self.arrlist is None:
            raise ValueError(
                "Cannot determine item type for non-array type '{}'".format(self)
            )

        return type(self)(
            self.base,
            self.sub,
            self.arrlist[:-1] or None,
            node=self.node,
        )

    def validate(self):
        """
        A basic type is valid if it appears to be one of the default types
        described in the solidity ABI spec and its components don't violate any
        of the assumptions set forth in that spec -or- if it does not appear to
        be a default type.

        Details found here:
        https://solidity.readthedocs.io/en/develop/abi-spec.html
        """
        base, sub = self.base, self.sub

        # Check validity of string type
        if base == 'string':
            if sub is not None:
                self.invalidate('string type cannot have suffix')

        # Check validity of bytes type
        elif base == 'bytes':
            if not (sub is None or isinstance(sub, int)):
                self.invalidate('bytes type must have either no suffix or a numerical suffix')

            if isinstance(sub, int) and sub > 32:
                self.invalidate('maximum 32 bytes for fixed-length bytes')

        # Check validity of integer type
        elif base in ('int', 'uint'):
            if not isinstance(sub, int):
                self.invalidate('integer type must have numerical suffix')

            if sub < 8 or 256 < sub:
                self.invalidate('integer size out of bounds (max 256 bits)')

            if sub % 8 != 0:
                self.invalidate('integer size must be multiple of 8')

        # Check validity of fixed type
        elif base in ('fixed', 'ufixed'):
            if not isinstance(sub, tuple):
                self.invalidate(
                    'fixed type must have suffix of form <bits>x<exponent>, e.g. 128x19',
                )

            bits, minus_e = sub

            if bits < 8 or 256 < bits:
                self.invalidate('fixed size out of bounds (max 256 bits)')

            if bits % 8 != 0:
                self.invalidate('fixed size must be multiple of 8')

            if minus_e < 1 or 80 < minus_e:
                self.invalidate(
                    'fixed exponent size out of bounds, {} must be in 1-80'.format(
                        minus_e,
                    ),
                )

        # Check validity of hash type
        elif base == 'hash':
            if not isinstance(sub, int):
                self.invalidate('hash type must have numerical suffix')

        # Check validity of address type
        elif base == 'address':
            if sub is not None:
                self.invalidate('address cannot have suffix')


TYPE_ALIASES = {
    'int': 'int256',
    'uint': 'uint256',
    'fixed': 'fixed128x18',
    'ufixed': 'ufixed128x18',
    'function': 'bytes24',
}

TYPE_ALIAS_RE = re.compile(r'\b({})\b'.format(
    '|'.join(re.escape(a) for a in TYPE_ALIASES.keys())
))


def normalize(type_str):
    # Replace aliases with substitutions
    return TYPE_ALIAS_RE.sub(
        lambda match: TYPE_ALIASES[match.group(0)],
        type_str,
    )


parse = visitor.parse
