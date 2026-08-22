import functools

from .grammar import (
    BasicType,
    TupleType,
    normalize,
    parse,
)


def parse_type_str(expected_base=None, with_arrlist=False):
    """
    Used by BaseCoder subclasses as a convenience for implementing the
    ``from_type_str`` method required by ``ABIRegistry``.  Useful if normalizing
    then parsing a type string with an (optional) expected base is required in
    that method.
    """

    def decorator(old_from_type_str):
        @functools.wraps(old_from_type_str)
        def new_from_type_str(cls, type_str, registry):
            normalized_type_str = normalize(type_str)
            abi_type = parse(normalized_type_str)

            type_str_repr = repr(type_str)
            if type_str != normalized_type_str:
                normalized_type_str_repr = repr(normalized_type_str)
                type_str_repr = (
                    f"{type_str_repr} (normalized to {normalized_type_str_repr})"
                )

            if expected_base is not None:
                if not isinstance(abi_type, BasicType):
                    raise ValueError(
                        f"Cannot create {cls.__name__} for non-basic type "
                        f"{type_str_repr}"
                    )
                if abi_type.base != expected_base:
                    raise ValueError(
                        f"Cannot create {cls.__name__} for type {type_str_repr}: "
                        "expected type with "
                        f"base '{expected_base}'"
                    )

            if not with_arrlist and abi_type.arrlist is not None:
                raise ValueError(
                    f"Cannot create {cls.__name__} for type {type_str_repr}: "
                    "expected type with "
                    "no array dimension list"
                )
            if with_arrlist and abi_type.arrlist is None:
                raise ValueError(
                    f"Cannot create {cls.__name__} for type {type_str_repr}: "
                    "expected type with "
                    "array dimension list"
                )

            # Perform general validation of default solidity types
            abi_type.validate()

            return old_from_type_str(cls, abi_type, registry)

        return classmethod(new_from_type_str)

    return decorator


def parse_tuple_type_str(old_from_type_str):
    """
    Used by BaseCoder subclasses as a convenience for implementing the
    ``from_type_str`` method required by ``ABIRegistry``.  Useful if normalizing
    then parsing a tuple type string is required in that method.
    """

    @functools.wraps(old_from_type_str)
    def new_from_type_str(cls, type_str, registry):
        normalized_type_str = normalize(type_str)
        abi_type = parse(normalized_type_str)

        type_str_repr = repr(type_str)
        if type_str != normalized_type_str:
            normalized_type_str_repr = repr(normalized_type_str)
            type_str_repr = (
                f"{type_str_repr} (normalized to {normalized_type_str_repr})"
            )

        if not isinstance(abi_type, TupleType):
            raise ValueError(
                f"Cannot create {cls.__name__} for non-tuple type {type_str_repr}"
            )

        abi_type.validate()

        return old_from_type_str(cls, abi_type, registry)

    return classmethod(new_from_type_str)


class BaseCoder:
    """
    Base class for all encoder and decoder classes.
    """

    is_dynamic = False

    def __init__(self, **kwargs):
        cls = type(self)

        # Ensure no unrecognized kwargs were given
        for key, value in kwargs.items():
            if not hasattr(cls, key):
                raise AttributeError(
                    f"Property {key} not found on {cls.__name__} class. "
                    f"`{cls.__name__}.__init__` only accepts keyword arguments "
                    "which are "
                    f"present on the {cls.__name__} class."
                )
            setattr(self, key, value)

        # Validate given combination of kwargs
        self.validate()

    def validate(self):
        pass

    @classmethod
    def from_type_str(cls, type_str, registry):  # pragma: no cover
        """
        Used by :any:`ABIRegistry` to get an appropriate encoder or decoder
        instance for the given type string and type registry.
        """
        raise NotImplementedError("Must implement `from_type_str`")
