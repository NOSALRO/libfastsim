#include <pybind11/cast.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_posture(py::module& m)
        {
            py::class_<Posture>(m, "Posture")
                .def(py::init<float, float, float>(),
                    py::arg("x"),
                    py::arg("y"),
                    py::arg("theta"))
                .def(py::init<>())
                .def(py::init<const Posture&>(),
                    py::arg("p"))
                .def("__eq__", &Posture::operator=)
                .def("theta", &Posture::theta)
                .def("set_theta", &Posture::set_theta,
                    py::arg("t"))
                .def("set_x", &Posture::set_x,
                    py::arg("x"))
                .def("set_y", &Posture::set_y,
                    py::arg("y"))
                .def("x", &Posture::x)
                .def("y", &Posture::y)
                .def("get_x", &Posture::get_x)
                .def("get_y", &Posture::get_y)
                .def("dist_to", static_cast<float (Posture::*)(const Posture&) const>(&Posture::dist_to),
                py::arg("p"))
                .def("dist_to", static_cast<float (Posture::*)(float, float) const>(&Posture::dist_to),
                py::arg("x"),
                py::arg("y"))
                .def("rotate", &Posture::rotate,
                    py::arg("theta"))
                .def("__add__", &Posture::operator+,
                    py::arg("o"))
                .def("move", &Posture::move,
                    py::arg("d_l"),
                    py::arg("d_r"),
                    py::arg("wheels_dist"))
                .def("__copy__", [](const Posture& self) { return Posture(self); })
                .def("__deepcopy__", [](const Posture& self, py::dict) { return Posture(self); })
                .def(py::pickle(
                    [](const Posture &p) {
                        return py::make_tuple(p.get_x(), p.get_y(), p.theta());
                    },
                    [](py::tuple t) {
                        // Posture p(new Posture(t[0], t[1], t[2]));
                        Posture p;
                        return p;
                    }
                ));
        }
    } // namespace python
} // namespace fastsim
