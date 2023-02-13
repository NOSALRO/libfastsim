#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_linear_camera(py::module& m)
        {
            py::class_<LinearCamera>(m, "LinearCamera")
                .def(py::init<float, int>(),
                    py::arg("angular_range"),
                    py::arg("nb_pixels"))
                .def(py::init<>())
                .def("update", &LinearCamera::update,
                    py::arg("pos"),
                    py::arg("map"))
                .def("pixels", &LinearCamera::pixels)
                .def("get_angular_range", &LinearCamera::get_angular_range);
        }
    } // namespace python
} // namespace fastsim
