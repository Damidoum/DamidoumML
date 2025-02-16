#pragma once
#include <vector>

#include "damidoumML/buffer.h"

struct ArrayMetaData {
 public:
  int size_;
  std::vector<int> shape_;
  ArrayMetaData(size_t size);
  ArrayMetaData(std::vector<int> shape);
};

struct ArrayData {
 public:
  float *ptr_;
  std::vector<int> strides_;
  ArrayData();
  ArrayData(float *ptr, std::vector<int> strides);
  float *getPtr();
};

class Array {
 private:
  Buffer *buffer_;
  ArrayMetaData metaData_;
  ArrayData data_;
  void print_array_recursive(std::ostringstream &oss, float *data,
                             std::vector<int> shape, size_t dim, int offset);

 public:
  Array(float value, size_t size);
  Array(float value, std::vector<int> shape);
  Array(std::vector<float> vec);
  Array(std::vector<float> vec, std::vector<int> shape);
  ~Array() = default;

  float *getPtr();
  std::vector<int> shape();
  size_t dim();
  size_t length();

  std::string repr();

  float &operator[](size_t index);
  float &operator[](std::vector<int> indices);
};

Array zeros(std::vector<int> shape);
Array ones(std::vector<int> shape);
