import pytest


def test_import_damidoumPyML():
    try:
        import damidoumPyML  # noqa: F401
    except ImportError as e:
        pytest.fail(f"Failed to import damidoumPyML: {e}")
