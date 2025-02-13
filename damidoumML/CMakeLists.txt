cmake_minimum_required(VERSION 3.15)
project(damidoumMLCore)

add_subdirectory(utils)

file(GLOB SRC_FILES "*.cpp")
add_library(damidoumMLCore STATIC ${SRC_FILES})
target_link_libraries(damidoumMLUtils)
target_include_directories(damidoumMLCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
