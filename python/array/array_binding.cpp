#include <array.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(libpy_array, m) {
  m.doc() = "Array library";
  py::class_<Array<int>>(m, "Array").def(py::init<>()).def(py::init<size_t>());
}
