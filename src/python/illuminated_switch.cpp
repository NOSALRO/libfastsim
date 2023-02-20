#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_illuminated_switch(py::module& m)
        {
            py::class_<IlluminatedSwitch, std::shared_ptr<IlluminatedSwitch>>(m, "IlluminatedSwitch")
                .def(py::init<int, float, float, float, bool>(),
                    py::arg("color"),
                    py::arg("radius"),
                    py::arg("x"),
                    py::arg("y"),
                    py::arg("on"))
                .def("try_to_activate", &IlluminatedSwitch::try_to_activate,
                    py::arg("robot_pos"))
                .def("activate", &IlluminatedSwitch::activate)
                .def("deactivate", &IlluminatedSwitch::deactivate)
                .def("set_on", &IlluminatedSwitch::set_on,
                    py::arg("x"))
                .def("set_off", &IlluminatedSwitch::set_off)
                .def("get_on", &IlluminatedSwitch::get_on)
                .def("get_off", &IlluminatedSwitch::get_off)
                .def("get_color", &IlluminatedSwitch::get_color)
                .def("get_radius", &IlluminatedSwitch::get_radius)
                .def("get_x", &IlluminatedSwitch::get_x)
                .def("get_y", &IlluminatedSwitch::get_y)
                .def("set_pos", &IlluminatedSwitch::set_pos,
                    py::arg("x"),
                    py::arg("y"))
                .def("get_activated", &IlluminatedSwitch::get_activated)
                .def("link", &IlluminatedSwitch::link,
                    py::arg("o"));

            py::class_<ClosestSwitch_f>(m, "ClosestSwitch_f")
                .def(py::init<float, float>(),
                    py::arg("x"),
                    py::arg("y"))
                .def("__call__", &ClosestSwitch_f::operator(),
                    py::arg("i1"),
                    py::arg("i2"));
        }
    } // namespace python
} // namespace fastsim
