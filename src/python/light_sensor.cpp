#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;
        void py_light_sensor(py::module& m){
            py::class_<LightSensor>(m, "LightSensor")
                .def(py::init<int, float, float>(),
                    py::arg("color"),
                    py::arg("angle"),
                    py::arg("range"))
                .def("update", &LightSensor::update,
                    py::arg("pos"),
                    py::arg("map"))
                .def("get_color", &LightSensor::get_color)
                .def("get_angle", &LightSensor::get_angle)
                .def("get_range", &LightSensor::get_range)
                .def("get_activated", &LightSensor::get_activated)
                .def("get_num", &LightSensor::get_num)
                .def("get_distance", &LightSensor::get_distance);
        }
    }
}