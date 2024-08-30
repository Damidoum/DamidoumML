set(CMAKE_CXX_STANDARD 17)

add_library(py_array MODULE array_binding.cpp)

set(PYBIND11_FINDPYTHON ON)
find_package(Python REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)
if(pybind11_FOUND)
  include_directories(${pybind11_INCLUDE_DIRS})
  target_link_libraries(py_array PRIVATE pybind11::module)
  target_include_directories(py_array PUBLIC "${CMAKE_SOURCE_DIR}/core/array")
endif()
