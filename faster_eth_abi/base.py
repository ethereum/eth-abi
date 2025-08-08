from typing import (
    Any,
)


class BaseCoder:
    """
    Base class for all encoder and decoder classes.
    """

    is_dynamic = False

    def __init__(self, **kwargs: Any) -> None:
        cls = type(self)

        # Ensure no unrecognized kwargs were given
        for key, value in kwargs.items():
            if not hasattr(cls, key):
                raise AttributeError(
                    "Property {key} not found on {cls_name} class. "
                    "`{cls_name}.__init__` only accepts keyword arguments which are "
                    "present on the {cls_name} class.".format(
                        key=key,
                        cls_name=cls.__name__,
                    )
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
