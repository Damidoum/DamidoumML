#pragma once
#include "../utils/types.h"

template <typename T>
class Buffer
{
private:
    T *ptr_;
    size_t size_;

public:
    Buffer();
    Buffer(size_t size);
    ~Buffer();
    void allocate(size_t size);
};

template <typename T>
Buffer<T>::Buffer()
{
    ptr_ = nullptr;
    size_ = 0;
}

template <typename T>
Buffer<T>::Buffer(size_t size)
{
    ptr_ = new T[size];
    size_ = size;
}

template <typename T>
Buffer<T>::~Buffer()
{
    delete[] ptr_;
}

template <typename T>
void Buffer<T>::allocate(size_t size)
{
    delete[] ptr_;
    ptr_ = new T[size];
    size_ = size;
}