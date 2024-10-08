#pragma once
#include <vector>

#include "buffer.h"
#include "types.h"
class ArrayData {
 public:
  void* ptr_;
  size_t size_;
  std::vector<int> shape_;
  std::vector<int> strides_;
  Dtype dtype_;  // data type of the array
  ArrayData() : ptr_(nullptr), size_(0), shape_({}), strides_({}) {};
  template <typename T>
  ArrayData(size_t size, std::vector<int> shape, std::vector<int> strides,
            Dtype dtype);
  ~ArrayData() = default;
};
class Array {
 private:
  Buffer buffer_;

 public:
  ArrayData data_;
  Array();
  ~Array() = default;
  template <typename T>
  T* getPtr() {
    return static_cast<T*>(data_.ptr_);
  }
};

template <typename T>
ArrayData::ArrayData(size_t size, std::vector<int> shape,
                     std::vector<int> strides, Dtype dtype)
    : ptr_(nullptr),
      size_(size),
      shape_(shape),
      strides_(strides),
      dtype_(dtype){};
