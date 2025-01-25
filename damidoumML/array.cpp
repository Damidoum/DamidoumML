#include "damidoumML/array.h"

#include <iostream>

/* ------------ ArrayMetaData -------- */
ArrayMetaData::ArrayMetaData(size_t size) : size_(size) {
  shape_.push_back(size);
}

/* ------------ Array constructors ---------------- */
Array::Array(float value, size_t size)
    : buffer_(new Buffer(size)), metaData_(ArrayMetaData(size)) {
  float *ptr = getPtr();
  for (int i = 0; i < size; i++) ptr[i] = value;
}

/* ----------- Array getter ----------- */
float *Array::getPtr() { return buffer_->getPtr(); }
std::vector<int> Array::shape() { return metaData_.shape_; }
int Array::dim() { return shape().size(); }
int Array::length() {
  int length = 1;  // final len
  for (int e : shape()) {
    length *= e;
  }
  return length;
}
