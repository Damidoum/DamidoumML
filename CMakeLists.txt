cmake_minimum_required(VERSION 3.10)
project(DamidoumML)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
add_subdirectory(core/array)
add_subdirectory(core/utils)
add_subdirectory(python/array)

add_executable(DamidoumML core/main.cpp)
target_link_libraries(DamidoumML array)
target_include_directories(DamidoumML PUBLIC "${CMAKE_SOURCE_DIR}/core/array")
