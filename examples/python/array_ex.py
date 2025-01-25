import damidoumPyML as daml

if __name__ == "__main__":
    a = daml.array(0, 10)
    print(f"Shape of the array: {a.shape()}")
    print(f"Len of the array: {len(a)} ; Dim of the array: {a.dim()}")
