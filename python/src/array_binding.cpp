#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // for automatic conversion of std::vector<int>

#include "core/array/array.h"

namespace py = pybind11;

PYBIND11_MODULE(damidoumPyML, m) {
  m.doc() = "Array library";
  py::class_<Array>(m, "Array")
      .def(py::init<>())
      .def(py::init<float, std::vector<int>>())
      .def_property_readonly("shape", &Array::shape)
      .def_property_readonly("size", &Array::size)
      .def_property_readonly("dtype", &Array::dtype);
  m.def("zeros", &zeros, "Create an array of zeros");
  m.def("ones", &ones, "Create an array of ones");
}
