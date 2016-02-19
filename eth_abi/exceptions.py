class EncodingError(Exception):
    pass


class ValueOutOfBounds(EncodingError):
    """
    Raised when trying to encode a value which is out bounds for the desired
    type.
    """
    pass


class DecodingError(Exception):
    pass
