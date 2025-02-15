#pragma once
#include <vector>

#include "damidoumML/types.h"

bool assert_size_compatible_with_shape(size_t size, std::vector<int> shape);
std::vector<int> compute_stride_from_shape(std::vector<int> shape);
