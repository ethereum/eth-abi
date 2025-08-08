import functools
from typing import (
    TYPE_CHECKING,
    Any,
    Callable,
    Optional,
    Type,
    TypeVar,
)

from eth_typing import (
    TypeStr,
)

from .grammar import (
    ABIType,
    BasicType,
    TupleType,
    normalize,
    parse,
)

if TYPE_CHECKING:
    from .base import (
        BaseCoder,
    )


TType = TypeVar("TType", bound=Type["BaseCoder"])
OldFromTypeStr = Callable[["BaseCoder", ABIType, Any], TType]
NewFromTypeStr = classmethod[TType, [TypeStr, Any], TType]


def parse_type_str(
    expected_base: Optional[str] = None,
    with_arrlist: bool = False,
) -> Callable[[OldFromTypeStr[TType]], NewFromTypeStr[TType]]:
    """
    Used by BaseCoder subclasses as a convenience for implementing the
    ``from_type_str`` method required by ``ABIRegistry``.  Useful if normalizing
    then parsing a type string with an (optional) expected base is required in
    that method.
    """

    def decorator(old_from_type_str: OldFromTypeStr[TType]) -> NewFromTypeStr[TType]:
        @functools.wraps(old_from_type_str)
        def new_from_type_str(cls: TType, type_str: TypeStr, registry: Any) -> TType:
            normalized_type_str = normalize(type_str)
            abi_type = parse(normalized_type_str)

            type_str_repr = repr(type_str)
            if type_str != normalized_type_str:
                type_str_repr = (
                    f"{type_str_repr} (normalized to {normalized_type_str!r})"
                )

            if expected_base is not None:
                if not isinstance(abi_type, BasicType):
                    raise ValueError(
                        "Cannot create {} for non-basic type {}".format(
                            cls.__name__,
                            type_str_repr,
                        )
                    )
                if abi_type.base != expected_base:
                    raise ValueError(
                        "Cannot create {} for type {}: expected type with "
                        "base '{}'".format(
                            cls.__name__,
                            type_str_repr,
                            expected_base,
                        )
                    )

            if not with_arrlist and abi_type.arrlist is not None:
                raise ValueError(
                    "Cannot create {} for type {}: expected type with "
                    "no array dimension list".format(
                        cls.__name__,
                        type_str_repr,
                    )
                )
            if with_arrlist and abi_type.arrlist is None:
                raise ValueError(
                    "Cannot create {} for type {}: expected type with "
                    "array dimension list".format(
                        cls.__name__,
                        type_str_repr,
                    )
                )

            # Perform general validation of default solidity types
            abi_type.validate()

            return old_from_type_str(cls, abi_type, registry)

        return classmethod(new_from_type_str)

    return decorator


def parse_tuple_type_str(
    old_from_type_str: OldFromTypeStr[TType],
) -> NewFromTypeStr[TType]:
    """
    Used by BaseCoder subclasses as a convenience for implementing the
    ``from_type_str`` method required by ``ABIRegistry``.  Useful if normalizing
    then parsing a tuple type string is required in that method.
    """

    @functools.wraps(old_from_type_str)
    def new_from_type_str(cls: TType, type_str: TypeStr, registry: Any) -> TType:
        normalized_type_str = normalize(type_str)
        abi_type = parse(normalized_type_str)

        if not isinstance(abi_type, TupleType):
            type_str_repr = repr(type_str)
            if type_str != normalized_type_str:
                type_str_repr = "{} (normalized to {})".format(
                    type_str_repr,
                    repr(normalized_type_str),
                )
            raise ValueError(
                "Cannot create {} for non-tuple type {}".format(
                    cls.__name__,
                    type_str_repr,
                )
            )

        abi_type.validate()

        return old_from_type_str(cls, abi_type, registry)

    return classmethod(new_from_type_str)
