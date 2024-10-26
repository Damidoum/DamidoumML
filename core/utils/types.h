#pragma once
#include <string>

typedef unsigned long size_t;

struct Dtype {
 private:
  size_t size_;  // number of bytes
  std::string name_;

 public:
  Dtype() : size_(4), name_("float") {};
  Dtype(size_t size, std::string name) : size_(size), name_(name) {};
  std::string getName() { return name_; };
};  // struct to manage data types inside arrays

template <typename T>
Dtype typeToDtype() {
  if (std::is_same<T, int8_t>::value) {
    return Dtype(sizeof(int8_t), "int8_t");
  } else if (std::is_same_v<T, uint8_t>) {
    return Dtype(sizeof(uint8_t), "uint8_t");
  } else if (std::is_same_v<T, int16_t>) {
    return Dtype(sizeof(int16_t), "int16_t");
  } else if (std::is_same_v<T, uint16_t>) {
    return Dtype(sizeof(uint16_t), "uint16_t");
  } else if (std::is_same_v<T, int32_t>) {
    return Dtype(sizeof(int32_t), "int32_t");
  } else if (std::is_same_v<T, uint32_t>) {
    return Dtype(sizeof(uint32_t), "uint32_t");
  } else if (std::is_same_v<T, int64_t>) {
    return Dtype(sizeof(int64_t), "int64_t");
  } else if (std::is_same_v<T, uint64_t>) {
    return Dtype(sizeof(uint64_t), "uint64_t");
  } else if (std::is_same_v<T, float>) {
    return Dtype(sizeof(float), "float");
  } else if (std::is_same_v<T, double>) {
    return Dtype(sizeof(double), "double");
  } else {
    throw std::invalid_argument("Type not supported");
  }
}  // function to convert C++ types to dtype struct
