#pragma once
#include "../utils/types.h"

template <typename T>
class Buffer
{
private:
    T *ptr_;
    size_t size_;

public:
    Buffer() : ptr_(nullptr), size_(0) {};
    Buffer(size_t size) : ptr_(new T[size]), size_(size) {};
    ~Buffer();
    void allocate(size_t size);
    T *getPtr() { return ptr_; }
};

template <typename T>
Buffer<T>::~Buffer()
{
    delete[] ptr_;
    std::cout << "Buffer deleted" << std::endl;
}

template <typename T>
void Buffer<T>::allocate(size_t size)
{
    if (size < size_)
    {
        return;
    }
    delete[] ptr_;
    ptr_ = new T[size];
    size_ = size;
}