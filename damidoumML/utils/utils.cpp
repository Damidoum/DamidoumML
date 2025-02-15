#include "damidoumML/utils/utils.h"

#include <algorithm>

bool assert_size_compatible_with_shape(size_t size, std::vector<int> shape) {
  int number_of_elements = 1;
  for (int e : shape) {
    number_of_elements *= e;
  }
  return (number_of_elements == size);
}

std::vector<int> compute_stride_from_shape(std::vector<int> shape) {
  std::vector<int> strides = {1};
  size_t size = shape.size();
  for (int i = 0; i < size - 1; i++) {
    strides.push_back(strides[i] * shape[size - i - 1]);
  }
  std::reverse(strides.begin(), strides.end());
  return strides;
}
