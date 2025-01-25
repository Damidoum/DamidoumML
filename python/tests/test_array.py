import damidoumPyML as daml
import pytest


def test_array_value_init():
    array = daml.array(10, 14)
    assert array.shape() == [14]
    assert len(array) == 14


def test_get_item():
    length = 10
    array = daml.array(-1, length)
    for i in range(length):
        array[i] = -1


def test_set_item():
    length = 10
    array = daml.array(-1, length)
    for i in range(length):
        array[i] = i
    for i in range(length):
        assert array[i] == i


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
