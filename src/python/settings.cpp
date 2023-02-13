#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;
        void py_settings(py::module& m){
            py::class_<Settings>(m, "Settings")
                .def(py::init<const std::string&>(),
                    py::arg("xml_file"))
                .def("map", &Settings::map)
                .def("robot", &Settings:: robot)
                .def("display", &Settings::display);
        }
    }
}