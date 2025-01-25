#pragma once
#include <vector>

#include "damidoumML/buffer.h"
#include "damidoumML/types.h"

struct ArrayMetaData {
 public:
  int size_;
  std::vector<int> shape_;
  ArrayMetaData(size_t size);
};

class Array {
 private:
  Buffer *buffer_;
  ArrayMetaData metaData_;

 public:
  Array(float value, size_t size);
  ~Array() = default;
  float *getPtr();
  std::vector<int> shape();
  int dim();
  int length();

  float &operator[](size_t index);
};

Array zeros(size_t size);
Array ones(size_t size);
