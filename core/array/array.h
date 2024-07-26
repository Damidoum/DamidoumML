#pragma once
#include <iostream>
#include "../utils/types.h"
#include "buffer.h"

template <typename T>
class Array
{
private:
  T *ptr_;
  Buffer<T> buffer_;
  size_t size_;

public:
  Array() : ptr_(nullptr), buffer_(Buffer<T>()), size_(0) {};
  Array(size_t size) : ptr_(nullptr), buffer_(Buffer<T>(size)), size_(size)
  {
    ptr_ = buffer_.getPtr();
  };
  void change_element(T element, int index);
};

template <typename T>
void Array<T>::change_element(T element, int index)
{
  if (index >= size_)
  {
    throw std::out_of_range("Index out of range");
  }
  buffer_.getPtr()[index] = element;
}