#include "damidoumML/array.h"

#include <cassert>
#include <iomanip>
#include <sstream>

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

Array::Array(std::vector<float> vec, std::vector<int> shape)
    : metaData_(ArrayMetaData(shape)), buffer_(new Buffer(vec.size())) {
  assert(assert_size_compatible_with_shape(vec.size(), shape));
  std::vector<int> strides = compute_stride_from_shape(metaData_.shape_);
  float *ptr = buffer_->getPtr();
  data_ = ArrayData(ptr, strides);
  size_t i = 0;
  for (auto value : vec) {
    ptr[i++] = value;
  }
}

void Array::print_array_recursive(std::ostringstream &oss, float *data,
                                  std::vector<int> shape, size_t dim,
                                  int offset) {
  const int max_elements_per_dim = 5;
  if (dim == shape.size() - 1) {
    oss << "[";
    for (int i = 0; i < std::min(shape[dim], max_elements_per_dim); ++i) {
      if (i > 0) oss << ", ";
      oss << std::fixed << std::setprecision(2) << data[offset + i];
    }
    if (shape[dim] > max_elements_per_dim) {
      oss << ", ...";
    }
    oss << "]";
  } else {
    oss << "[\n";
    int stride = 1;
    for (size_t i = dim + 1; i < shape.size(); ++i) {
      stride *= shape[i];
    }
    for (int i = 0; i < std::min(shape[dim], max_elements_per_dim); ++i) {
      if (i > 0) oss << ",\n";
      print_array_recursive(oss, data, shape, dim + 1, offset + i * stride);
    }
    if (shape[dim] > max_elements_per_dim) {
      oss << ",\n  ...";
    }
    oss << "\n]";
  }
}

std::string Array::repr() {
  std::ostringstream oss;
  oss << "Array(";
  print_array_recursive(oss, getPtr(), shape(), dim(), data_.strides_[0]);
  oss << ")";
  return oss.str();
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

float &Array::operator[](std::vector<int> indices) {
  if (indices.size() != dim()) {
    throw std::invalid_argument("Invalid number of indices");
  }
  int index = compute_index_from_tuple(indices, data_.strides_, shape());
  return getPtr()[index];
}

/* ------------ Other constructors ---------- */
Array zeros(std::vector<int> shape) { return Array(0.f, shape); }
Array ones(std::vector<int> shape) { return Array(1.f, shape); }
