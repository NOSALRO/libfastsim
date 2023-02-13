#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_laser(py::module& m)
        {
            py::class_<Laser>(m, "Laser")
                .def(py::init<float, float, float, float>(),
                    py::arg("angle"),
                    py::arg("range"),
                    py::arg("gap_dist") = 0.0f,
                    py::arg("gap_angle") = 0.0f)
                .def("update", &Laser::update,
                    py::arg("pos"),
                    py::arg("map"))
                .def("get_dist", &Laser::get_dist)
                .def("get_angle", &Laser::get_angle)
                .def("get_range", &Laser::get_range)
                .def("get_gap_dist", &Laser::get_gap_dist)
                .def("get_gap_angle", &Laser::get_gap_angle)
                .def("get_x", &Laser::get_x)
                .def("get_y", &Laser::get_y)
                .def("get_x_pixel", &Laser::get_x_pixel)
                .def("get_y_pixel", &Laser::get_y_pixel);
        }
    } // namespace python
} // namespace fastsim
