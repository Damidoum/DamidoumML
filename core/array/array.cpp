#include "core/array/array.h"

#include <stdexcept>

/* ArrayData*/
// constuctors
ArrayData::ArrayData() : dtype_(Dtype()) { setShape(std::vector<int>(1, 0)); }
ArrayData::ArrayData(std::vector<int> shape, Dtype dtype) : dtype_(dtype) {
  setShape(shape);
}

// size getter and setter
size_t ArrayData::getSize() { return size_; }
void ArrayData::setSize() {
  size_ = 1;
  for (int i = 0; i < shape_.size(); i++) {
    size_ *= shape_[i];
  }
}

// shape getter and setter
std::vector<int> ArrayData::getShape() { return shape_; }
void ArrayData::setShape(std::vector<int> shape) {
  shape_ = shape;
  setSize();
}

// dtype getter
Dtype ArrayData::getDtype() { return dtype_; }

/* Array */
// constructors
Array::Array()
    : data_(std::make_shared<ArrayData>()),
      buffer_(std::make_shared<Buffer>()) {}

/* Init functions */
Array zeros(std::vector<int> shape) { return Array(0.0f, shape); }
Array ones(std::vector<int> shape) { return Array(1.0f, shape); }
