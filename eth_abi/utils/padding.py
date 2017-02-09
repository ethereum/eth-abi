import functools

from eth_utils import (
    pad_left,
    pad_right,
)


zpad = functools.partial(pad_left, pad_with='\x00')
zpad32 = functools.partial(pad_left, to_size=32, pad_with='\x00')
zpad_right = functools.partial(pad_right, pad_with='\x00')
zpad32_right = functools.partial(pad_right, to_size=32, pad_with='\x00')
