import functools

from .utils.grammar import (
    BasicType,
    normalize,
    parse,
)


def parse_type_str(expected_base=None, with_arrlist=False):
    """
    Used by BaseEncoder and BaseDecoder subclasses as a convenience for
    implementing the ``from_type_str`` method required by ``ABIRegistry`` if
    normalizing then parsing a basic type string with an expected base is
    required in that method.
    """
    def decorator(old_from_type_str):
        @functools.wraps(old_from_type_str)
        def new_from_type_str(cls, type_str, registry):
            normalized_type_str = normalize(type_str)
            abi_type = parse(normalized_type_str)

            type_str_repr = repr(type_str)
            if type_str != normalized_type_str:
                type_str_repr = '{} (normalized to {})'.format(
                    type_str_repr,
                    repr(normalized_type_str),
                )

            if not isinstance(abi_type, BasicType):
                raise ValueError(
                    'Cannot create {} for non-basic type {}'.format(
                        cls.__name__,
                        type_str_repr,
                    )
                )

            if expected_base is not None and abi_type.base != expected_base:
                raise ValueError(
                    'Cannot create {} for type {}: expected type with '
                    "base '{}'".format(
                        cls.__name__,
                        type_str_repr,
                        expected_base,
                    )
                )

            if not with_arrlist and abi_type.arrlist is not None:
                raise ValueError(
                    'Cannot create {} for type {}: expected type with '
                    'no array dimension list'.format(
                        cls.__name__,
                        type_str_repr,
                        expected_base,
                    )
                )
            if with_arrlist and abi_type.arrlist is None:
                raise ValueError(
                    'Cannot create {} for type {}: expected type with '
                    'array dimension list'.format(
                        cls.__name__,
                        type_str_repr,
                        expected_base,
                    )
                )

            # Perform general validation of default solidity types
            abi_type.validate()

            return old_from_type_str(cls, abi_type, registry)

        return classmethod(new_from_type_str)

    return decorator


class BaseCoder:
    @classmethod
    def from_type_str(cls, type_str, registry):  # pragma: no cover
        """
        Used by ``ABIRegistry`` to get an appropriate encoder or decoder
        instance for the given type string and type registry.
        """
        raise NotImplementedError('Must implement `from_type_str`')
