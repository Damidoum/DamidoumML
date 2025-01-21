import damidoumPyML as daml
import pytest


def test_array_creation():
    arr_default = daml.array()
    assert arr_default.shape == [0]
    assert arr_default.size == 0
    assert arr_default.dtype == "float"

    shape = [2, 3]
    arr_float = daml.array(1.0, shape)
    assert arr_float.shape == [2, 3]
    assert arr_float.size == 6
    assert arr_float.dtype == "float"


"""
def test_zeros():
    shape = [2, 2]
    arr_zeros = daml.zeros(shape)
    assert arr_zeros.shape == [2, 2]
    assert arr_zeros.size == 4


def test_ones():
    shape = [3, 2]
    arr_ones = daml.ones(shape)
    assert arr_ones.shape == [3, 2]
    assert arr_ones.size == 6
"""

if __name__ == "__main__":
    pytest.main()
