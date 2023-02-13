#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_goal(py::module& m)
        {
            py::class_<Goal>(m, "Goal")
                .def(py::init<float, float, float, int>(),
                    py::arg("x"),
                    py::arg("y"),
                    py::arg("diam"),
                    py::arg("color"))
                .def("get_x", &Goal::get_x)
                .def("get_y", &Goal::get_y)
                .def("get_diam", &Goal::get_diam)
                .def("get_color", &Goal::get_color);
        }
    } // namespace python
} // namespace fastsim
