#include "damidoumML/array.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "damidoumML/types.h"

namespace py = pybind11;
PYBIND11_MODULE(_core, m) {
  m.doc() = "Python wrapper of damidoumML lib written in C++";
  py::class_<Array>(m, "Array")
      .def(py::init<float, size_t>())
      .def("shape", &Array::shape, "Get the shape of the array")
      .def("dim", &Array::dim, "Return the dim of the array")
      .def("__len__", &Array::length);
}
