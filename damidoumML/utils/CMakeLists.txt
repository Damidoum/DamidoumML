cmake_minimum_required(VERSION 3.15)
project(damidoumMLUtils)

file(GLOB SRC_FILES "*.cpp")
add_library(damidoumMLUtils STATIC ${SRC_FILES})
target_include_directories(damidoumMLUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
