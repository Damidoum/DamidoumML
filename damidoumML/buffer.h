#pragma once
#include "damidoumML/types.h"

class Buffer {
  /* Buffer class handle the allocation of memory for the array
    This currently suppport only float
  */

 private:
  float* ptr_;
  size_t size_;

 public:
  Buffer();                  // default constructor
  Buffer(size_t size);       // constructor with a size;
  ~Buffer();                 // destructor
  float* getPtr();           // get the pointer that point to the data
  void malloc(size_t size);  // alloc new memory
  void free();               // free current space
};
