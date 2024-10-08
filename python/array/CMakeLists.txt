set(CMAKE_CXX_STANDARD 17)

add_library(damidoumPyML MODULE array_binding.cpp)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 REQUIRED)

if(pybind11_FOUND)
  target_include_directories(damidoumPyML PRIVATE ${pybind11_INCLUDE_DIRS})
  target_link_libraries(damidoumPyML PRIVATE pybind11::module)
  target_link_libraries(damidoumPyML PRIVATE array)
endif()

set_target_properties(damidoumPyML PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}")
