cmake_minimum_required(VERSION 3.15...3.27)
project(${SKBUILD_PROJECT_NAME})

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

python_add_library(_array MODULE array.cpp)
target_link_libraries(_array PRIVATE pybind11::headers)
install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
