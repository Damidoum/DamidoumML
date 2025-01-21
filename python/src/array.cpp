#include "damidoumML/array.h"

#include <pybind11/pybind11.h>

namespace py = pybind11;
PYBIND11_MODULE(_core, m) {
  m.doc() = "Python wrapper of damidoumML lib written in C++";
  py::class_<Array>(m, "Array").def(py::init<>());
}
