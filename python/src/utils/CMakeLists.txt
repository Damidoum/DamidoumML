cmake_minimum_required(VERSION 3.15)
project(damidoumPyMLUtils)

file(GLOB SRC_FILES "*.cpp")

find_package(pybind11 CONFIG REQUIRED)

add_library(damidoumPyMLUtils STATIC ${SRC_FILES})

target_link_libraries(damidoumPyMLUtils PUBLIC pybind11::headers )
target_include_directories(damidoumPyMLUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${pybind11_INCLUDE_DIRS})
