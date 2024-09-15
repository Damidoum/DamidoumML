import sys
import libpy_array as daml

sys.path.append("../build/lib")


if __name__ == "__main__":
    array1 = daml.Array()
    array2 = daml.Array(2)
    array3 = daml.Array(2.2)
    print(array1)
