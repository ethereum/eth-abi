import functools

from . import (
    decoding,
    encoding,
    exceptions,
    grammar,
)

from .base import BaseCoder


class PredicateMapping:
    """
    Acts as a mapping from predicate functions to values.  Values are retrieved
    when their corresponding predicate matches a given input.  Predicates can
    also be labeled to facilitate removal from the mapping.
    """
    def __init__(self, name):
        self._name = name
        self._values = {}
        self._labeled_predicates = {}

    def add(self, predicate, value, label=None):
        if predicate in self._values:
            raise ValueError('Matcher {} already exists in {}'.format(
                repr(predicate),
                self._name,
            ))

        if label is not None:
            if label in self._labeled_predicates:
                raise ValueError(
                    "Matcher {} with label '{}' already exists in {}".format(
                        repr(predicate),
                        label,
                        self._name,
                    ),
                )

            self._labeled_predicates[label] = predicate

        self._values[predicate] = value

    def find(self, type_str):
        results = tuple(
            (predicate, value) for predicate, value in self._values.items()
            if predicate(type_str)
        )

        if len(results) == 0:
            raise ValueError("No matching entries for '{}' in {}".format(
                type_str,
                self._name,
            ))

        predicates, values = tuple(zip(*results))

        if len(results) > 1:
            raise ValueError("Multiple matching entries for '{}' in {}: {}".format(
                type_str,
                self._name,
                ', '.join(map(repr, predicates)),
            ))

        return values[0]

    def remove_by_equality(self, predicate):
        # Delete the predicate mapping to the previously stored value
        try:
            del self._values[predicate]
        except KeyError:
            raise KeyError('Matcher {} not found in {}'.format(
                repr(predicate),
                self._name,
            ))

        # Delete any label which refers to this predicate
        try:
            label = self._label_for_predicate(predicate)
        except ValueError:
            pass
        else:
            del self._labeled_predicates[label]

    def _label_for_predicate(self, predicate):
        # Both keys and values in `_labeled_predicates` are unique since the
        # `add` method enforces this
        for key, value in self._labeled_predicates.items():
            if value is predicate:
                return key

        raise ValueError('Matcher {} not referred to by any label in {}'.format(
            repr(predicate),
            self._name,
        ))

    def remove_by_label(self, label):
        try:
            predicate = self._labeled_predicates[label]
        except KeyError:
            raise KeyError("Label '{}' not found in {}".format(label, self._name))

        del self._labeled_predicates[label]
        del self._values[predicate]

    def remove(self, predicate_or_label):
        if callable(predicate_or_label):
            self.remove_by_equality(predicate_or_label)
        elif isinstance(predicate_or_label, str):
            self.remove_by_label(predicate_or_label)
        else:
            raise TypeError('Key to be removed must be callable or string: got {}'.format(
                type(predicate_or_label),
            ))


class Predicate:
    """
    A class which represents a predicate function to be used for type matching
    in ABIRegistry.
    """
    __slots__ = tuple()

    def __call__(self, *args, **kwargs):  # pragma: no cover
        raise NotImplementedError('Must implement `__call__`')

    def __str__(self):  # pragma: no cover
        raise NotImplementedError('Must implement `__str__`')

    def __repr__(self):
        return '<{} {}>'.format(type(self).__name__, self)

    def __iter__(self):
        for attr in self.__slots__:
            yield getattr(self, attr)

    def __hash__(self):
        return hash(tuple(self))

    def __eq__(self, other):
        return (
            type(self) is type(other) and
            tuple(self) == tuple(other)
        )


class Equals(Predicate):
    """
    A predicate which matches any input equal to `value`.
    """
    __slots__ = ('value',)

    def __init__(self, value):
        self.value = value

    def __call__(self, other):
        return self.value == other

    def __str__(self):
        return '(== {})'.format(repr(self.value))


class BaseEquals(Predicate):
    """
    A predicate which matches a basic type string with a base component equal to
    `value` and no array component.  If `with_sub` is `True`, the type string
    must have a sub component to match.  If `with_sub` is `False`, the type
    string must *not* have a sub component to match.  If `with_sub` is None, the
    type string's sub component is ignored.
    """
    __slots__ = ('base', 'with_sub')

    def __init__(self, base, *, with_sub=None):
        self.base = base
        self.with_sub = with_sub

    def __call__(self, type_str):
        try:
            abi_type = grammar.parse(type_str)
        except exceptions.ParseError:
            return False

        if isinstance(abi_type, grammar.BasicType):
            if abi_type.arrlist is not None:
                return False

            if self.with_sub is not None:
                if self.with_sub and abi_type.sub is None:
                    return False
                if not self.with_sub and abi_type.sub is not None:
                    return False

            return abi_type.base == self.base

        # We'd reach this point if `type_str` did not contain a basic type
        # e.g. if it contained a tuple type
        return False

    def __str__(self):
        return '(base == {}{})'.format(
            repr(self.base),
            '' if self.with_sub is None else (
                ' and sub is not None' if self.with_sub else ' and sub is None'
            ),
        )


def has_arrlist(type_str):
    """
    A predicate which matches a type string with an array dimension list.
    """
    try:
        abi_type = grammar.parse(type_str)
    except exceptions.ParseError:
        return False

    return abi_type.arrlist is not None


def is_base_tuple(type_str):
    """
    A predicate which matches a tuple type with no array dimension list.
    """
    try:
        abi_type = grammar.parse(type_str)
    except exceptions.ParseError:
        return False

    return isinstance(abi_type, grammar.TupleType) and abi_type.arrlist is None


def _clear_encoder_cache(old_method):
    def new_method(self, *args, **kwargs):
        self.get_encoder.cache_clear()
        return old_method(self, *args, **kwargs)

    return new_method


def _clear_decoder_cache(old_method):
    def new_method(self, *args, **kwargs):
        self.get_decoder.cache_clear()
        return old_method(self, *args, **kwargs)

    return new_method


class ABIRegistry:
    def __init__(self):
        self._encoders = PredicateMapping('encoder registry')
        self._decoders = PredicateMapping('decoder registry')

    @staticmethod
    def _register_coder(mapping, lookup, coder, label=None):
        if callable(lookup):
            mapping.add(lookup, coder, label)
            return

        if isinstance(lookup, str):
            mapping.add(Equals(lookup), coder, lookup)
            return

        raise TypeError(
            'Lookup must be a callable or a value of type `str`: got {}'.format(
                repr(lookup),
            )
        )

    @staticmethod
    def _unregister_coder(mapping, lookup_or_label):
        if callable(lookup_or_label):
            mapping.remove_by_equality(lookup_or_label)
            return

        if isinstance(lookup_or_label, str):
            mapping.remove_by_label(lookup_or_label)
            return

        raise TypeError(
            'Lookup/label must be a callable or a value of type `str`: got {}'.format(
                repr(lookup_or_label),
            )
        )

    def _get_coder(self, mapping, type_str):
        try:
            coder = mapping.find(type_str)
        except ValueError as e:
            if 'No matching' in e.args[0]:
                # If no matches found, attempt to parse in case lack of matches
                # was due to unparsability
                grammar.parse(type_str)

            raise

        if isinstance(coder, type) and issubclass(coder, BaseCoder):
            return coder.from_type_str(type_str, self)

        return coder

    @_clear_encoder_cache
    def register_encoder(self, lookup, encoder, label=None):
        self._register_coder(self._encoders, lookup, encoder, label=label)

    @_clear_encoder_cache
    def unregister_encoder(self, lookup_or_label):
        self._unregister_coder(self._encoders, lookup_or_label)

    @_clear_decoder_cache
    def register_decoder(self, lookup, decoder, label=None):
        self._register_coder(self._decoders, lookup, decoder, label=label)

    @_clear_decoder_cache
    def unregister_decoder(self, lookup_or_label):
        self._unregister_coder(self._decoders, lookup_or_label)

    def register(self, lookup, encoder, decoder, label=None):
        self.register_encoder(lookup, encoder, label=label)
        self.register_decoder(lookup, decoder, label=label)

    def unregister(self, lookup_or_label):
        self.unregister_encoder(lookup_or_label)
        self.unregister_decoder(lookup_or_label)

    @functools.lru_cache(maxsize=None)
    def get_encoder(self, type_str):
        return self._get_coder(self._encoders, type_str)

    @functools.lru_cache(maxsize=None)
    def get_decoder(self, type_str):
        return self._get_coder(self._decoders, type_str)


registry = ABIRegistry()

registry.register(
    BaseEquals('uint'),
    encoding.UnsignedIntegerEncoder, decoding.UnsignedIntegerDecoder,
    label='uint',
)
registry.register(
    BaseEquals('int'),
    encoding.SignedIntegerEncoder, decoding.SignedIntegerDecoder,
    label='int',
)
registry.register(
    BaseEquals('address'),
    encoding.AddressEncoder, decoding.AddressDecoder,
    label='address',
)
registry.register(
    BaseEquals('bool'),
    encoding.BooleanEncoder, decoding.BooleanDecoder,
    label='bool',
)
registry.register(
    BaseEquals('ufixed'),
    encoding.UnsignedFixedEncoder, decoding.UnsignedFixedDecoder,
    label='ufixed',
)
registry.register(
    BaseEquals('fixed'),
    encoding.SignedFixedEncoder, decoding.SignedFixedDecoder,
    label='fixed',
)
registry.register(
    BaseEquals('ureal'),
    encoding.UnsignedRealEncoder, decoding.UnsignedRealDecoder,
    label='ureal',
)
registry.register(
    BaseEquals('real'),
    encoding.SignedRealEncoder, decoding.SignedRealDecoder,
    label='real',
)
registry.register(
    BaseEquals('bytes', with_sub=True),
    encoding.BytesEncoder, decoding.BytesDecoder,
    label='bytes<M>',
)
registry.register(
    BaseEquals('bytes', with_sub=False),
    encoding.ByteStringEncoder, decoding.ByteStringDecoder,
    label='bytes',
)
registry.register(
    BaseEquals('function'),
    encoding.BytesEncoder, decoding.BytesDecoder,
    label='function',
)
registry.register(
    BaseEquals('string'),
    encoding.TextStringEncoder, decoding.StringDecoder,
    label='string',
)
registry.register(
    has_arrlist,
    encoding.BaseArrayEncoder, decoding.BaseArrayDecoder,
    label='has_arrlist',
)
registry.register(
    is_base_tuple,
    encoding.TupleEncoder, decoding.TupleDecoder,
    label='is_base_tuple',
)
