#include "damidoumML/utils/utils.h"

std::vector<int> compute_stride_from_shape(std::vector<int> &shape) {
  std::vector<int> strides = shape;
  int s = 1;
  for (auto it = strides.rbegin(); it != strides.rend(); ++it) {
    *it = s;
    s *= *it;
  }
  std::reverse(strides.begin(), strides.end());
  return strides;
}
