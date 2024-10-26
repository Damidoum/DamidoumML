#include <core/array/buffer.h>

#include <iostream>

Buffer::Buffer(size_t size) : ptr_(nullptr), size_(0) { malloc(size); }

void Buffer::malloc(size_t size) {
  if (size_ > size || size == 0) {
    return;
  }
  void* ptr = std::malloc(2 * size);
  if (ptr == nullptr) {
    throw std::runtime_error("Buffer::malloc() failed");
  }
  copy(ptr, size);
  Buffer::free();
  ptr_ = ptr;
  size_ = 2 * size;
}

void Buffer::free() {
  if (ptr_ != nullptr) {
    std::free(ptr_);
    ptr_ = nullptr;
    size_ = 0;
  }
}

void Buffer::copy(void* target_ptr, size_t size) {
  if (ptr_ != nullptr) {
    std::memcpy(target_ptr, ptr_, size);
  }
}
