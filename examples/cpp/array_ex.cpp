#include <iostream>

#include "damidoumML/array.h"

int main(int argc, char **argv) {
  Array arr;
  std::cout << arr.getPtr<int>() << std::endl;
  return 0;
}
