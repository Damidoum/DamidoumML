#include <damidoumML/buffer.h>

#include <iostream>

/* --------- constructors --------- */
Buffer::Buffer() : ptr_(nullptr), size_(0) {}

Buffer::Buffer(size_t size) : ptr_(new float[size]), size_(size) {}

/* --------- destructor --------- */
Buffer::~Buffer() { free(); };

/* ---------- Getter ------------ */
float *Buffer::getPtr() { return ptr_; }

/* --------- Allocation operations --------- */
void Buffer::malloc(size_t size) {
  if (size_ > size) {
    return;  // already enough memory slots allocated
  }
  Buffer::free();
  ptr_ = new float[2 * size];
  if (ptr_ == nullptr) {
    std::cerr << "Failed to allocate memory" << std::endl;
    return;
  }
}

void Buffer::free() {
  if (ptr_ != nullptr) {
    delete[] ptr_;
    ptr_ = nullptr;
  }
}
