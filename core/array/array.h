#pragma once
#include <iostream>
#include <vector>

#include "core/array/buffer.h"
#include "core/utils/types.h"

class ArrayData {
  /* class containing array caracteristics*/
 private:
  size_t size_;  // readonly parameter
  std::vector<int> shape_;
  Dtype dtype_;  // data type of the array
  void setShape(std::vector<int> shape);
  void setSize();

 public:
  ArrayData();
  ArrayData(std::vector<int> shape, Dtype dtype);
  std::vector<int> getShape();
  size_t getSize();
  Dtype getDtype();
  ~ArrayData() = default;
};
class Array {
  /* Array class composed of a Buffer and an ArrayData*/
 private:
  std::shared_ptr<Buffer>
      buffer_;  // shared pointer to share memory between arrays (view)
  std::shared_ptr<ArrayData> data_;

 public:
  Array();

  template <typename T>
  Array(T value, std::vector<int> shape, Dtype dtype = typeToDtype<T>());

  ~Array() = default;

  template <typename T>
  T* getPtr() {
    return static_cast<T*>(buffer_->getPtr());
  }

  std::vector<int> shape() { return data_->getShape(); }
  size_t size() { return data_->getSize(); }
  std::string dtype() { return data_->getDtype().getName(); }
};

template <typename T>
Array::Array(T value, std::vector<int> shape,
             Dtype dtype /* = tyeToDtype<T>()*/)
    : data_(std::make_shared<ArrayData>(shape, dtype)) {
  buffer_ = std::make_shared<Buffer>(data_->getSize() * sizeof(T));
  T* ptr = getPtr<T>();
  for (int i = 0; i < data_->getSize(); i++) {
    ptr[i] = value;
  }
}

Array zeros(std::vector<int> shape);  // create an array of zeros
Array ones(std::vector<int> shape);   // create an array of ones
