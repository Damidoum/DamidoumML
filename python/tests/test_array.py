import damidoumPyML as daml
import pytest


def test_array_value_init() -> None:
    array = daml.Array(10, 14)
    assert array.shape == [14]
    assert len(array) == 14


def test_get_item() -> None:
    length = 10
    array = daml.Array(-1, length)
    for i in range(length):
        array[i] = -1


def test_set_item() -> None:
    length = 10
    array = daml.Array(-1, length)
    for i in range(length):
        array[i] = i
    for i in range(length):
        assert array[i] == i


def test_zeros() -> None:
    length = 10
    array = daml.zeros(10)
    for i in range(length):
        assert array[i] == 0


def test_ones() -> None:
    length = 10
    array = daml.ones(10)
    for i in range(length):
        assert array[i] == 1

def test_shape() -> None:
    array = daml.Array(5, [2, 3])
    assert array.shape == [2, 3]


def test_dim() -> None:
    array = daml.Array(5, [2, 3])
    assert array.dim == 2


def test_length() -> None:
    array = daml.Array(5, 10)
    assert array.length == 10


if __name__ == "__main__":
    pytest.main()
