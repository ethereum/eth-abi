class EncodingError(Exception):
    pass


class EncodingTypeError(EncodingError):
    """
    Raised when trying to encode a value which is of the wrong type for the
    desired encoding type.
    """
    pass


class ValueOutOfBounds(EncodingError):
    """
    Raised when trying to encode a value which is out bounds for the desired
    type.
    """
    pass


class DecodingError(Exception):
    pass


class InsufficientDataBytes(DecodingError):
    pass


class NonEmptyPaddingBytes(DecodingError):
    pass
