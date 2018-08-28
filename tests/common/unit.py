from decimal import Decimal

from eth_utils import decode_hex

from eth_abi.utils.padding import (
    zpad32,
    zpad32_right,
    fpad32,
)


def make_word(description: str) -> bytes:
    r"""
    Converts a "description" of a 32-byte word into a 32-byte word.  A
    description is either a hex representation of a byte string (e.g.
    'deafbeef') or a hex representation along with a fill directive
    'leftpadchar<' or '>rightpadchar'.

    Examples:
    >>> # Left padding examples
    >>> assert make_word('0<deadbeef') == zpad32(b'\xde\xad\xbe\xef')
    >>> assert make_word('f<deadbeef') == fpad32(b'\xde\xad\xbe\xef')
    >>> assert make_word('deadbeef') == zpad32(b'\xde\xad\xbe\xef')
    >>> # Right padding examples
    >>> assert make_word('deadbeef>0') == zpad32_right(b'\xde\xad\xbe\xef')
    """
    if '<' in description:
        fill_char, hex_str = description.split('<')
        return decode_hex(hex_str.rjust(64, fill_char))

    if '>' in description:
        hex_str, fill_char = description.split('>')
        return decode_hex(hex_str.ljust(64, fill_char))

    return decode_hex(description.rjust(64, '0'))


def words(*descriptions: str) -> bytes:
    r"""
    Converts multiple word descriptions into 32-byte words joined into a single
    byte string.

    Examples:
    >>> assert words('1') == zpad32(b'\x01')
    >>> assert words('1', '2f>0') == zpad32(b'\x01') + zpad32_right(b'\x2f')
    """
    return b''.join(make_word(d) for d in descriptions)


CORRECT_TUPLE_ENCODINGS = [
    # (type string, python value, byte string)

    # Empty tuples
    (
        '()', (), b'',
    ),
    (
        '((),((),((),())))',
        ((), ((), ((), ()))),
        b'',
    ),

    # Static tuples
    (
        '(uint32)',
        (6,),
        words('6'),
    ),
    (
        '(uint32,uint32)',
        (2 ** 32 - 1, 2 ** 32 - 1),
        words('ffffffff', 'ffffffff'),
    ),
    (
        '(bytes32,bytes32)',
        (zpad32_right(b'a'), zpad32_right(b'b')),
        words('61>0', '62>0'),
    ),
    (
        '(address,uint32,bytes32,int32)',
        ('0x82a978b3f5962a5b0957d9ee9eef472ee55b42f1', 1, zpad32_right(b'stupid pink animal'), 0),
        words('82a978b3f5962a5b0957d9ee9eef472ee55b42f1', '1', '7374757069642070696e6b20616e696d616c>0', '0'),
    ),

    # Dynamic tuples
    (
        '(bytes32[])',
        ((zpad32_right(b'a'), zpad32_right(b'b')),),
        words('20', '2', '61>0', '62>0'),
    ),
    (
        '(uint256,bytes)',
        (0, b''),
        words('0', '40', '0', '0'),
    ),
    (
        '(int,(int,int[]))',
        (1, (2, (3, 3))),
        words('1', '40', '2', '40', '2', '3', '3')
    ),
    (
        '((int[],int),int)',
        (((1, 1), 2), 3),
        words('40', '3', '40', '2', '2', '1', '1')
    ),
    (
        '((bytes,bool),(bytes,bool))',
        ((b'david attenborough', False), (b'boaty mcboatface', True)),
        words(
            '40',  # offset of first (bytes,bool)
            'c0',  # offset of second (bytes,bool)
            '40',  # offset of bytes in first (bytes,bool)
            '0',  # encoding for `False`
            '12',  # length of b'david attenborough'
            '646176696420617474656e626f726f756768>0',  # encoding of b'david attenborough'
            '40',  # offset of bytes in second (bytes,bool)
            '1',  # encoding for `True`
            '10',  # length of b'boaty mcboatface'
            '626f617479206d63626f617466616365>0',  # encoding of b'boaty mcboatface'
        )
    ),

    # Tuple arrays
    (
        '((int,int)[])',
        (((1, 2), (3, 4)),),
        words('20', '2', '1', '2', '3', '4'),
    ),
    (
        '((int,int[],(int,int)[]),(int,int),int)',
        (
            (
                1,
                (2, 3),
                ((4, 5), (6, 7)),
            ),
            (8, 9),
            10,
        ),
        words(
            '80',  # offset of dynamic tuple
            '8',  # outer tuple static tuple
            '9',
            'a',  # outer tuple int
            '1',  # beginning of dynamic tuple (int)
            '60',  # offset of dynamic tuple list of ints
            'c0',  # offset of dynamic tuple list of tuples
            '2',  # size of list of ints
            '2',
            '3',
            '2',  # size of list of tuples
            '4',  # beginning of first tuple
            '5',
            '6',  # beginning of second tuple
            '7',
        ),
    ),
    (
        '(int,int)[][]',
        (
            ((1, 2),),
            ((3, 4), (5, 6)),
            ((7, 8), (9, 10), (11, 12)),
        ),
        words(
            '3',  # size of outer dynamic list
            '60',  # offset of first dynamic list
            'c0',  # offset of second dynamic list
            '160',  # offset of third dynamic list
            '1',  # size of first list
            '1',  # start of first tuple
            '2',
            '2',  # size of second list
            '3',  # start of second tuple
            '4',
            '5',  # start of third tuple
            '6',
            '3',  # size of third list
            '7',  # start of fourth tuple
            '8',
            '9',  # start of fifth tuple
            'a',
            'b',  # start of sixth tuple
            'c',
        ),
    ),
    (
        '((int,int)[][2])',
        (
            (
                ((1, 2), (3, 4)),
                ((5, 6), (7, 8), (9, 10)),
            ),
        ),
        words(
            '20',  # offset of constant size array
            '40',  # offset of first dynamic list of tuples
            'e0',  # offset of second dynamic list of tuples
            '2',  # size of first list
            '1',  # start of first tuple
            '2',
            '3',  # start of second tuple
            '4',
            '3',  # size of second list
            '5',  # start of third tuple
            '6',
            '7',  # start of fourth tuple
            '8',
            '9',  # start of fifth tuple
            'a',
        ),
    ),
]

CORRECT_SINGLE_ENCODINGS = CORRECT_TUPLE_ENCODINGS + [
    # encode_single/decode_single accept tuple of type components
    (('uint', '256', []), 2 ** 256 - 1, words('f<f')),

    #####
    # (type string, python value, byte string)
    #####

    # uint<M>
    ('uint8', 255, words('ff')),
    ('uint8', 21, words('15')),
    ('uint8', 1, words('1')),
    ('uint256', 2 ** 256 - 1, words('f<f')),
    ('uint256', 2 ** 256 - 100, words('f<9c')),
    ('uint256', 21, words('15')),
    ('uint256', 1, words('1')),

    # int<M>
    ('int8', 21, words('15')),
    ('int8', 1, words('1')),
    ('int8', -1, words('f<f')),
    ('int8', -100, words('f<9c')),
    ('int256', 21, words('15')),
    ('int256', 1, words('1')),
    ('int256', -1, words('f<f')),
    ('int256', -100, words('f<9c')),

    # address
    ('address', '0x0000000000000000000000000000000000000000', words('0')),
    ('address', '0xd3cda913deb6f67967b99d67acdfa1712c293601', words('d3cda913deb6f67967b99d67acdfa1712c293601')),
    ('address', '0x0005c901078781c232a2a521c2af7980f8385ee9', words('0005c901078781c232a2a521c2af7980f8385ee9')),
    ('address', '0x5c901078781c232a2a521c2af7980f8385ee9000', words('5c901078781c232a2a521c2af7980f8385ee9000')),

    # uint, int
    ('uint', 2 ** 256 - 1, words('f<f')),
    ('uint', 2 ** 256 - 100, words('f<9c')),
    ('uint', 21, words('15')),
    ('uint', 1, words('1')),
    ('int', 21, words('15')),
    ('int', 1, words('1')),
    ('int', -1, words('f<f')),
    ('int', -100, words('f<9c')),

    # bool
    ('bool', True, words('1')),
    ('bool', False, words('0')),

    # fixed<M>x<N>
    ('fixed8x1', Decimal('127e-1'), words('7f')),
    ('fixed8x1', Decimal('1e-1'), words('1')),
    ('fixed8x1', Decimal('0'), words('0')),
    ('fixed8x1', Decimal('-1e-1'), words('f<f')),
    ('fixed8x1', Decimal('-128e-1'), words('f<80')),

    ('fixed128x18', Decimal('127e-18'), words('7f')),
    ('fixed128x18', Decimal('1e-18'), words('1')),
    ('fixed128x18', Decimal('0'), words('0')),
    ('fixed128x18', Decimal('-1e-18'), words('f<f')),
    ('fixed128x18', Decimal('-128e-18'), words('f<80')),

    ('fixed256x80', Decimal('127e-80'), words('7f')),
    ('fixed256x80', Decimal('1e-80'), words('1')),
    ('fixed256x80', Decimal('0'), words('0')),
    ('fixed256x80', Decimal('-1e-80'), words('f<f')),
    ('fixed256x80', Decimal('-128e-80'), words('f<80')),

    # ufixed<M>x<N>
    ('ufixed8x1', Decimal('255e-1'), words('ff')),
    ('ufixed8x1', Decimal('254e-1'), words('fe')),
    ('ufixed8x1', Decimal('1e-1'), words('1')),
    ('ufixed8x1', Decimal('0'), words('0')),

    ('ufixed128x18', Decimal('255e-18'), words('ff')),
    ('ufixed128x18', Decimal('254e-18'), words('fe')),
    ('ufixed128x18', Decimal('1e-18'), words('1')),
    ('ufixed128x18', Decimal('0'), words('0')),

    ('ufixed256x80', Decimal('255e-80'), words('ff')),
    ('ufixed256x80', Decimal('254e-80'), words('fe')),
    ('ufixed256x80', Decimal('1e-80'), words('1')),
    ('ufixed256x80', Decimal('0'), words('0')),

    # fixed, ufixed
    ('fixed', Decimal('127e-18'), words('7f')),
    ('fixed', Decimal('1e-18'), words('1')),
    ('fixed', Decimal('0'), words('0')),
    ('fixed', Decimal('-1e-18'), words('f<f')),
    ('fixed', Decimal('-128e-18'), words('f<80')),
    ('ufixed', Decimal('255e-18'), words('ff')),
    ('ufixed', Decimal('254e-18'), words('fe')),
    ('ufixed', Decimal('1e-18'), words('1')),
    ('ufixed', Decimal('0'), words('0')),

    # bytes<M>
    ('bytes32', zpad32_right(b'test'), words('74657374>0')),
    ('bytes32', zpad32_right(b'abcdefghijklmnopqrstuvwxyz'), words('6162636465666768696a6b6c6d6e6f707172737475767778797a>0')),
    ('bytes32', zpad32_right(b'0123456789!@#$%^&*()'), words('3031323334353637383921402324255e262a2829>0')),
    ('bytes32', zpad32_right(b'abc' + 5 * b'\x00' + b'abc'), words('6162630000000000616263>0')),
    ('bytes1', b'a', words('61>0')),

    # bytes
    ('bytes', b'', words('0', '0')),
    ('bytes', b'\xde', words('1', 'de>0')),
]
