cmake_minimum_required(VERSION 3.10)
project(damidoumPyML)

find_package(Python REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

pybind11_add_module(damidoumPyML array_binding.cpp)
target_link_libraries(damidoumPyML PRIVATE DamidoumMLCore)
