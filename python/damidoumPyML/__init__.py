try:
    from . import _core
except ImportError as e:
    raise ImportError(f"Failed to import _core module: {e}")

array = _core.Array
