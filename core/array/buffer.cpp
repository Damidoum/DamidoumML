#include <buffer.h>

#include <iostream>

void Buffer::free() {
  if (ptr_ != nullptr) {
    std::free(ptr_);
    ptr_ = nullptr;
  }
}

void Buffer::malloc(size_t size) {
  if (size_ > size) {
    return;
  }
  Buffer::free();
  ptr_ = std::malloc(2 * size);
  if (ptr_ == nullptr) {
    std::cerr << "Failed to allocate memory" << std::endl;
    return;
  }
}

Buffer::Buffer(size_t size) : ptr_(nullptr), size_(size) { malloc(size); }
