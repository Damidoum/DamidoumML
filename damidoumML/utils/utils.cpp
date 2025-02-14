#include "damidoumML/utils/utils.h"

#include <algorithm>

std::vector<int> compute_stride_from_shape(std::vector<int> shape) {
  std::vector<int> strides = {1};
  size_t size = shape.size();
  for (int i = 0; i < size - 1; i++) {
    strides.push_back(strides[i] * shape[size - i - 1]);
  }
  std::reverse(strides.begin(), strides.end());
  return strides;
}
