import damidoumPyML as daml
import pytest


def test_array_value_init():
    array = daml.Array(10, 14)
    assert array.shape() == [14]
    assert len(array) == 14


def test_get_item():
    length = 10
    array = daml.Array(-1, length)
    for i in range(length):
        array[i] = -1


def test_set_item():
    length = 10
    array = daml.Array(-1, length)
    for i in range(length):
        array[i] = i
    for i in range(length):
        assert array[i] == i


def test_zeros():
    length = 10
    array = daml.zeros(10)
    for i in range(length):
        assert array[i] == 0


def test_ones():
    length = 10
    array = daml.ones(10)
    for i in range(length):
        assert array[i] == 1


if __name__ == "__main__":
    pytest.main()
