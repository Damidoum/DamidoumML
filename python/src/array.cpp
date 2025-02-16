#include "damidoumML/array.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "python/src/utils/utils.h"

namespace py = pybind11;

void flatten_pylist(const py::list &py_list, std::vector<float> &vec) {
  for (auto item : py_list) {
    if (py::isinstance<py::list>(item)) {
      flatten_pylist(py::cast<py::list>(item), vec);
    } else {
      vec.push_back(py::cast<float>(item));
    }
  }
}

Array array_from_list(py::list &py_list) {
  std::vector<float> vec;
  flatten_pylist(py_list, vec);
  std::vector<int> shape = compute_shape_of_py_list(py_list);
  return Array(vec, shape);
}

PYBIND11_MODULE(_core, m) {
  m.doc() = "Python wrapper of damidoumML lib written in C++";
  py::class_<Array>(m, "Array")
      .def(py::init<float, size_t>())
      .def(py::init<float, std::vector<int>>())
      .def(py::init(&array_from_list))
      .def("__len__", &Array::length)
      .def("__getitem__",
           [](Array &self, int index) -> float & { return self[index]; })
      .def("__getitem__",
           [](Array &self, std::vector<int> indices) -> float & {
             return self[indices];
           })
      .def("__setitem__",
           [](Array &self, int index, float value) { self[index] = value; })
      .def("__setitem__", [](Array &self, std::vector<int> indices,
                             float value) { self[indices] = value; })
      .def("__repr__", &Array::repr)
      .def_property_readonly("shape", &Array::shape,
                             "Get the shape of the array")
      .def_property_readonly(
          "dim", &Array::dim,
          "Get the dim of the array. The dim correspond to the number of axis");
}
