#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_laser_scanner(py::module& m)
        {
            py::class_<LaserScanner>(m, "LaserScanner")
                .def(py::init<float, float, float, float>(),
                    py::arg("angle_min"),
                    py::arg("angle_max"),
                    py::arg("angle_increment"),
                    py::arg("range_max"))
                .def("update", &LaserScanner::update,
                    py::arg("pos"),
                    py::arg("map"))
                .def("get_range_max", &LaserScanner::get_range_max)
                .def("get_angle_max", &LaserScanner::get_angle_max)
                .def("get_angle_min", &LaserScanner::get_angle_min)
                .def("get_angle_increment", &LaserScanner::get_angle_increment)
                .def("get_lasers", &LaserScanner::get_lasers);
        }
    } // namespace python
} // namespace fastsim
