try:
    from . import _core
except ImportError as e:
    raise ImportError("Failed to import _core module") from e


class Array(_core.Array):
    def to_list(self) -> list:
        """
        Convert an Array to a Python list of float
        """
        shape = self.shape
        if len(shape) == 1:
            return [self[i] for i in range(shape[0])]
        if len(shape) == 2:
            return [[self[i, j] for j in range(shape[1])] for i in range(shape[0])]
        raise NotImplementedError(
            "Array with more than 2 dimensions is not yet supported"
        )

    def __iter__(self):
        raise NotImplementedError("Array is not yet iterable")


def zeros(shape: int | tuple[int]) -> Array:
    return Array(0, shape)


def ones(shape: int | tuple[int]) -> Array:
    return Array(1, shape)
