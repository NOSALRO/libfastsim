#include <pybind11/pybind11.h>
#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;
        void py_radar(py::module& m){
            py::class_<Radar>(m, "Radar")
                .def(py::init<int, int, bool>(),
                    py::arg("color"),
                    py::arg("nb_slices"),
                    py::arg("through_walls") = true)
                .def("update", &Radar::update,
                    py::arg("pos"),
                    py::arg("map"))
                .def("get_activated_slice", &Radar::get_activated_slice)
                .def("get_nb_slices", &Radar::get_nb_slices)
                .def("get_color", &Radar::get_color)
                .def("get_inc", &Radar::get_inc);
        }
    }
}