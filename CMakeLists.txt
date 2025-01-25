cmake_minimum_required(VERSION 3.15)
project(DamidoumML)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

option(BUILD_PYTHON_BINDINGS "Build the Python bindings" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}) # include the root directory

message(STATUS "Building C++ library")
add_subdirectory(damidoumML)

message(STATUS "Building C++ examples")
add_subdirectory(examples/cpp)

if (BUILD_PYTHON_BINDINGS)
  message(STATUS "Building Python bindings")
  add_subdirectory(python/src)
else ()
  message(STATUS "Skipping Python bindings")
endif()
