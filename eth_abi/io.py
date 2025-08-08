from io import (
    BytesIO,
)
from typing import (
    Any,
    Final,
    List,
    Tuple,
    final,
)


@final
class ContextFramesBytesIO(BytesIO):
    """
    A byte stream which can track a series of contextual frames in a stack. This
    data structure is necessary to perform nested decodings using the
    :py:class:``HeadTailDecoder`` since offsets present in head sections are
    relative only to a particular encoded object.  These offsets can only be
    used to locate a position in a decoding stream if they are paired with a
    contextual offset that establishes the position of the object in which they
    are found.

    For example, consider the encoding of a value for the following type::

        type: (int,(int,int[]))
        value: (1,(2,[3,3]))

    There are two tuples in this type: one inner and one outer.  The inner tuple
    type contains a dynamic type ``int[]`` and, therefore, is itself dynamic.
    This means that its value encoding will be placed in the tail section of the
    outer tuple's encoding.  Furthermore, the inner tuple's encoding will,
    itself, contain a tail section with the encoding for ``[3,3]``.  All
    together, the encoded value of ``(1,(2,[3,3]))`` would look like this (the
    data values are normally 32 bytes wide but have been truncated to remove the
    redundant zeros at the beginnings of their encodings)::

                       offset data
        --------------------------
             ^              0 0x01
             |             32 0x40 <-- Offset of object A in global frame (64)
        -----|--------------------
        Global frame ^     64 0x02 <-- Beginning of object A (64 w/offset 0 = 64)
             |       |     96 0x40 <-- Offset of object B in frame of object A (64)
        -----|-Object A's frame---
             |       |    128 0x02 <-- Beginning of object B (64 w/offset 64 = 128)
             |       |    160 0x03
             v       v    192 0x03
        --------------------------

    Note that the offset of object B is encoded as 64 which only specifies the
    beginning of its encoded value relative to the beginning of object A's
    encoding.  Globally, object B is located at offset 128.  In order to make
    sense out of object B's offset, it needs to be positioned in the context of
    its enclosing object's frame (object A).
    """

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self._frames: Final[List[Tuple[int, int]]] = []
        self._total_offset = 0

    def seek_in_frame(self, pos: int, *args: Any, **kwargs: Any) -> None:
        """
        Seeks relative to the total offset of the current contextual frames.
        """
        self.seek(self._total_offset + pos, *args, **kwargs)

    def push_frame(self, offset: int) -> None:
        """
        Pushes a new contextual frame onto the stack with the given offset and a
        return position at the current cursor position then seeks to the new
        total offset.
        """
        self._frames.append((offset, self.tell()))
        self._total_offset += offset

        self.seek_in_frame(0)

    def pop_frame(self):
        """
        Pops the current contextual frame off of the stack and returns the
        cursor to the frame's return position.
        """
        try:
            offset, return_pos = self._frames.pop()
        except IndexError:
            raise IndexError("no frames to pop")
        self._total_offset -= offset

        self.seek(return_pos)
