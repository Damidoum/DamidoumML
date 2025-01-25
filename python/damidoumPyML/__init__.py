try:
    from . import _core
except ImportError as e:
    raise ImportError(f"Failed to import _core module: {e}")


class array(_core.Array):
    def to_list(self) -> list[float]:
        values = []
        for i in range(len(self)):
            values.append(self[i])
        return values

    def __repr__(self) -> str:
        return f"array({self.to_list()})"
