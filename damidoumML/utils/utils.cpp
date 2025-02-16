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

int compute_index_from_tuple(std::vector<int> indices, std::vector<int> strides,
                             std::vector<int> shape) {
  int index = 0;
  for (int i = 0; i < indices.size(); i++) {
    if (indices[i] >= shape[i]) {
      throw std::invalid_argument("Index out of bound");
    }
    index += indices[i] * strides[i];
  }
  return index;
}
