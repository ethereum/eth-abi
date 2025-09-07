from typing import (
    Any,
    Callable,
)


def batch(iterations: int, func: Callable[..., Any], *args: Any, **kwargs: Any) -> None:
    for _ in range(iterations):
        func(*args, **kwargs)
