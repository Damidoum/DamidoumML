cmake_minimum_required(VERSION 3.10)
project(DamidoumML)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}) # include the root directory

add_subdirectory(core)
add_subdirectory(examples/cpp)
add_subdirectory(python/src)
