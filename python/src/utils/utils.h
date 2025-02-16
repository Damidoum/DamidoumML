#include <pybind11/pybind11.h>

#include <vector>

namespace py = pybind11;
std::vector<int> compute_shape_of_py_list(const py::list& py_list);
