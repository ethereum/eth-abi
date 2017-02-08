import functools

from eth_utils import (
    pad_left,
)


zpad = functools.partial(pad_left, pad_with='\x00')
zpad32 = functools.partial(pad_left, to_size=32, pad_with='\x00')
