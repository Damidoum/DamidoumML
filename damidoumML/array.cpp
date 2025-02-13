#include "damidoumML/array.h"

#include <iostream>
#include <stdexcept>

#include "damidoumML/utils/utils.h"

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

/* ------------ ArrayData ---------- */
ArrayData::ArrayData() : ptr_(nullptr), strides_(std::vector<int>()) {}

ArrayData::ArrayData(float *ptr, std::vector<int> strides)
    : ptr_(ptr), strides_(strides) {}

float *ArrayData::getPtr() { return ptr_; }

/* ------------ Array constructors ---------------- */
Array::Array(float value, size_t size)
    : buffer_(new Buffer(size)), metaData_(ArrayMetaData(size)) {
  float *ptr = buffer_->getPtr();
  std::vector<int> strides = compute_stride_from_shape(metaData_.shape_);
  data_ = ArrayData(ptr, strides);
  for (int i = 0; i < size; i++) ptr[i] = value;
}

Array::Array(float value, std::vector<int> shape)
    : metaData_(ArrayMetaData(shape)) {
  buffer_ = new Buffer(metaData_.size_);  // allocate memory
  float *ptr = buffer_->getPtr();
  std::vector<int> strides = compute_stride_from_shape(metaData_.shape_);
  data_ = ArrayData(ptr, strides);
  for (int i = 0; i < length(); i++) ptr[i] = value;
}

Array::Array(std::vector<float> vec)
    : metaData_(ArrayMetaData(vec.size())), buffer_(new Buffer(vec.size())) {
  std::vector<int> strides = compute_stride_from_shape(metaData_.shape_);
  float *ptr = buffer_->getPtr();
  data_ = ArrayData(ptr, strides);
  size_t i = 0;
  for (auto value : vec) {
    ptr[i++] = value;
  }
}

/* ----------- Array getter ----------- */
float *Array::getPtr() { return data_.ptr_; }
std::vector<int> Array::shape() { return metaData_.shape_; }
size_t Array::dim() { return shape().size(); }
size_t Array::length() { return metaData_.size_; }

float &Array::operator[](size_t index) {
  if (index > length()) {
    throw std::out_of_range("Index out of range");
  }
  return getPtr()[index];
}

/* ------------ Other constructors ---------- */
Array zeros(std::vector<int> shape) { return Array(0.f, shape); }
Array ones(std::vector<int> shape) { return Array(1.f, shape); }
