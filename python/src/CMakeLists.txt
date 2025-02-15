cmake_minimum_required(VERSION 3.15...3.27)
project(${SKBUILD_PROJECT_NAME})

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 CONFIG REQUIRED)

add_subdirectory(utils)

file(GLOB SOURCES "*.cpp")
python_add_library(_core MODULE ${SOURCES})
target_link_libraries(_core PRIVATE pybind11::headers damidoumMLCore damidoumMLUtils damidoumPyMLUtils)
install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
