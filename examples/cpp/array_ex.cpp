#include <iostream>
#include <vector>

#include "damidoumML/array.h"

void print_array(Array array) {
  for (int i = 0; i < array.length(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char **argv) {
  Array arr(0, 10);
  Array arr_zeros = zeros({10});
  std::vector<float> data = {12, 223, 23413, 1313, 1313, 233};
  Array arr_2d(data, std::vector<int>({2, 3}));
  print_array(arr_2d);
  return 0;
}
