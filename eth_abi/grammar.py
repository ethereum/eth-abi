import parsimonious


user_types = r"""
user_types = ""+
"""[1:-1]


parser = parsimonious.Grammar(r"""
type = tuple_type / basic_type / user_types

{user_types}

tuple_type = "(" type next_type* ")"
next_type = "," type

basic_type = base sub? arrlist?

base = alphas

sub = (digits "x" digits) / digits

arrlist = (const_arr / dynam_arr)+
const_arr = "[" digits "]"
dynam_arr = "[]"

alphas = ~"[a-z]+"
digits = ~"[0-9]+"
""".format(user_types=user_types))


class ABIType:
    expr_name = None

    @classmethod
    def from_string(cls, type_str):
        return cls.from_node(parser.parse(type_str))

    @staticmethod
    def from_node(node):
        if node.expr_name == 'type':
            return ABIType.from_node(node.children[0])

        for klass in reversed(ABIType.__subclasses__()):
            if node.expr_name == klass.expr_name:
                return klass.from_node(node)

        raise ValueError('Unexpected node "{}" encountered'.format(node.expr_name))

    def __repr__(self):
        cls = type(self)

        return '<{}.{} "{}">'.format(
            cls.__module__,
            cls.__qualname__,
            str(self),
        )


class Tuple(ABIType):
    expr_name = 'tuple_type'

    def __init__(self, node, components):
        self.node = node

        self.components = components

    def __str__(self):
        return '({})'.format(
            ','.join(str(c) for c in self.components),
        )

    def __getitem__(self, key):
        return self.components[key]

    @classmethod
    def from_node(cls, node):
        from_node_ = super().from_node

        left_paren, first, rest, right_paren = node

        components = [from_node_(first)]
        for comma, abi_type in rest.children:
            components.append(from_node_(abi_type))

        return cls(components)


class Basic(ABIType):
    expr_name = 'basic_type'

    def __init__(self, node, base, sub, arrlist):
        self.node = node

        self.base = base
        self.sub = sub
        self.arrlist = arrlist

    def __str__(self):
        return '{}{}{}'.format(
            self.base.text,
            self.sub.text,
            self.arrlist.text,
        )

    @classmethod
    def from_node(cls, node):
        base, sub, arrlist = node

        return cls(node, base, sub, arrlist)


uint = ABIType.from_string('uint')
uint256 = ABIType.from_string('uint256')
fixed128x19 = ABIType.from_string('fixed128x19')
tup = ABIType.from_string('(uint,bool,fixed128x19)')
nested_tup = ABIType.from_string('(uint,bool,(fixed,address))')
