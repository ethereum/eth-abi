def just(value, length, fillerchar, direction='left'):
    if isinstance(value, str):
        _fillerchar = fillerchar.decode()
    elif isinstance(value, bytes):
        _fillerchar = fillerchar
    if direction == 'left':
        return value.rjust(length, _fillerchar)
    if direction == 'right':
            return value.ljust(length, _fillerchar)


def zpad(value, length):
    return just(value, length, b'\x00')


def zpad32(value):
    return just(value, 32, b'\x00')


def zpad_right(value, length):
    return just(value, length, b'\x00', direction='right')


def zpad32_right(value):
    return just(value, 32, b'\x00', direction='right')


def fpad(value, length):
    return just(value, length, b'\xff')


def fpad32(value):
    return just(value, 32, b'\xff')
