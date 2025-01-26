#include <iostream>

#include "damidoumML/array.h"

int main(int argc, char **argv) {
  Array arr(0, 10);
  Array arr_zeros = zeros({10});
  std::cout << arr.getPtr() << std::endl;
  return 0;
}
