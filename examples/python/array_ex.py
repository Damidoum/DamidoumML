import damidoumPyML as daml


def f():
    return daml.ones([19])


if __name__ == "__main__":
    b = daml.ones([10])
    f()
