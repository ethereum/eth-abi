from typing import (
    Any,
    Iterable,
    Tuple,
)

from eth_typing.abi import (
    Decodable,
    TypeStr,
)

from faster_eth_abi._codec import (
    decode_c,
    encode_c,
)
from faster_eth_abi.decoding import (
    ContextFramesBytesIO,
)
from faster_eth_abi.exceptions import (
    EncodingError,
)
from faster_eth_abi.registry import (
    ABIRegistry,
)


class BaseABICoder:
    """
    Base class for porcelain coding APIs.  These are classes which wrap
    instances of :class:`~faster_eth_abi.registry.ABIRegistry` to provide last-mile
    coding functionality.
    """

    def __init__(self, registry: ABIRegistry):
        """
        Constructor.

        :param registry: The registry providing the encoders to be used when
            encoding values.
        """
        self._registry = registry


class ABIEncoder(BaseABICoder):
    """
    Wraps a registry to provide last-mile encoding functionality.
    """

    def encode(self, types: Iterable[TypeStr], args: Iterable[Any]) -> bytes:
        """
        Encodes the python values in ``args`` as a sequence of binary values of
        the ABI types in ``types`` via the head-tail mechanism.

        :param types: A list or tuple of string representations of the ABI types
            that will be used for encoding e.g.  ``('uint256', 'bytes[]',
            '(int,int)')``
        :param args: A list or tuple of python values to be encoded.

        :returns: The head-tail encoded binary representation of the python
            values in ``args`` as values of the ABI types in ``types``.
        """
        return encode_c(self, types, args)

    def is_encodable(self, typ: TypeStr, arg: Any) -> bool:
        """
        Determines if the python value ``arg`` is encodable as a value of the
        ABI type ``typ``.

        :param typ: A string representation for the ABI type against which the
            python value ``arg`` will be checked e.g. ``'uint256'``,
            ``'bytes[]'``, ``'(int,int)'``, etc.
        :param arg: The python value whose encodability should be checked.

        :returns: ``True`` if ``arg`` is encodable as a value of the ABI type
            ``typ``.  Otherwise, ``False``.
        """
        if not self.is_encodable_type(typ):
            return False

        encoder = self._registry.get_encoder(typ)

        try:
            encoder.validate_value(arg)
        except EncodingError:
            return False
        except AttributeError:
            try:
                encoder(arg)
            except EncodingError:
                return False

        return True

    def is_encodable_type(self, typ: TypeStr) -> bool:
        """
        Returns ``True`` if values for the ABI type ``typ`` can be encoded by
        this codec.

        :param typ: A string representation for the ABI type that will be
            checked for encodability e.g. ``'uint256'``, ``'bytes[]'``,
            ``'(int,int)'``, etc.

        :returns: ``True`` if values for ``typ`` can be encoded by this codec.
            Otherwise, ``False``.
        """
        return self._registry.has_encoder(typ)


class ABIDecoder(BaseABICoder):
    """
    Wraps a registry to provide last-mile decoding functionality.
    """

    stream_class = ContextFramesBytesIO

    def decode(
        self,
        types: Iterable[TypeStr],
        data: Decodable,
        strict: bool = True,
    ) -> Tuple[Any, ...]:
        """
        Decodes the binary value ``data`` as a sequence of values of the ABI types
        in ``types`` via the head-tail mechanism into a tuple of equivalent python
        values.

        :param types: A list or tuple of string representations of the ABI types that
            will be used for decoding e.g. ``('uint256', 'bytes[]', '(int,int)')``
        :param data: The binary value to be decoded.
        :param strict: If ``False``, dynamic-type decoders will ignore validations such
            as making sure the data is padded to a multiple of 32 bytes or checking that
            padding bytes are zero / empty. ``False`` is how the Solidity ABI decoder
            currently works. However, ``True`` is the default for the faster-eth-abi
            library.

        :returns: A tuple of equivalent python values for the ABI values
            represented in ``data``.
        """
        return decode_c(self, types, data, strict)


class ABICodec(ABIEncoder, ABIDecoder):
    pass
