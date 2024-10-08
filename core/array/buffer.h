#pragma once
#include "types.h"

class Buffer {
 private:
  void* ptr_;
  size_t size_;

 public:
  Buffer() : ptr_(nullptr), size_(0) {};
  Buffer(size_t size);
  ~Buffer() { free(); };
  void* getPtr() { return ptr_; }
  void malloc(size_t size);
  void free();
};
