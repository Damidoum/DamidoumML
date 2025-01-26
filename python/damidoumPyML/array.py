try:
    from . import _core
except ImportError as e:
    raise ImportError(f"Failed to import _core module: {e}")


class Array(_core.Array):
    def to_list(self) -> list[float]:
        values = []
        for i in range(len(self)):
            values.append(self[i])
        return values

    def __repr__(self) -> str:
        return f"array({self.to_list()})"


def zeros(shape: int | tuple[int]) -> Array:
    return Array(0, shape)


def ones(shape: int | tuple[int]) -> Array:
    return Array(1, shape)
