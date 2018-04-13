import parsimonious


class EncodingError(Exception):
    pass


class EncodingTypeError(EncodingError):
    """
    Raised when trying to encode a value which is of the wrong type for the
    desired encoding type.
    """
    pass


class IllegalValue(EncodingError):
    """
    Raised when trying to encode a value which is not considered legal for a
    data type.

    Examples:
    fixed128x19_encoder(Decimal('NaN'))  # cannot encode NaN
    ufixed8x1_encoder(Decimal('25.6'))  # out of bounds
    """
    pass


class ValueOutOfBounds(IllegalValue):
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


class ParseError(parsimonious.ParseError):
    def __str__(self):
        return "Parse error at '{}' (column {}) in type string '{}'".format(
            self.text[self.pos:self.pos + 5],
            self.column(),
            self.text,
        )


class ABITypeError(ValueError):
    pass
