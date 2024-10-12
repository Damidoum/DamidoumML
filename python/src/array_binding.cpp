#include <pybind11/pybind11.h>

#include "core/array/array.h"

namespace py = pybind11;

PYBIND11_MODULE(damidoumPyML, m) {
  m.doc() = "Array librairy";
  py::class_<Array>(m, "Array").def(py::init<>());
}
