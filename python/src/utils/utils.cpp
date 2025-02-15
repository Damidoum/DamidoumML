#include "python/src/utils/utils.h"

namespace py = pybind11;

std::vector<int> compute_shape_of_py_list(const py::list& py_list) {
  std::vector<int> shape;
  py::object current_level = py_list;
  while (py::isinstance<py::list>(current_level)) {
    py::list current_list = py::cast<py::list>(current_level);
    shape.push_back(current_list.size());
    current_level = current_list[0];
  }
  return shape;
}
