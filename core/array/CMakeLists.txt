add_library(array array.cpp buffer.cpp)
target_link_libraries(array PUBLIC utils)
target_include_directories(array PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
