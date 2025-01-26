#include "damidoumML/array.h"

#include <iostream>
#include <stdexcept>

#include "array.h"

/* ------------ ArrayMetaData -------- */
ArrayMetaData::ArrayMetaData(size_t size) : size_(size) {
  shape_.push_back(size);
}

ArrayMetaData::ArrayMetaData(std::vector<int> shape) : shape_(shape) {
  size_t size = 1;
  for (int number_of_element : shape) {
    size *= number_of_element;
  }
  size_ = size;
}

/* ------------ Array constructors ---------------- */
Array::Array(float value, size_t size)
    : buffer_(new Buffer(size)), metaData_(ArrayMetaData(size)) {
  ptr_ = buffer_->getPtr();
  for (int i = 0; i < size; i++) ptr_[i] = value;
}

Array::Array(float value, std::vector<int> shape)
    : metaData_(ArrayMetaData(shape)) {
  buffer_ = new Buffer(metaData_.size_);
  ptr_ = buffer_->getPtr();
  for (int i = 0; i < length(); i++) ptr_[i] = value;
}

/* ----------- Array getter ----------- */
float *Array::getPtr() { return ptr_; }
std::vector<int> Array::shape() { return metaData_.shape_; }
size_t Array::dim() { return shape().size(); }
size_t Array::length() { return metaData_.size_; }

float &Array::operator[](size_t index) { return getPtr()[index]; }

/* ------------ Other constructors ---------- */
Array zeros(std::vector<int> shape) { return Array(0.f, shape); }
Array ones(std::vector<int> shape) { return Array(1.f, shape); }
