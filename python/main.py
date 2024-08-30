import sys

sys.path.append("../build/lib")

from libpy_array import *

if __name__ == "__main__":
    array1 = Array()
    array2 = Array(2)
    array3 = Array(2.2)
    print(array1)
