#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_display(py::module& m)
        {
            py::class_<Display>(m, "Display")
                .def(py::init<std::shared_ptr<Map>, std::shared_ptr<Robot>>(),
                    py::arg("m"),
                    py::arg("r"))
                .def("update", &Display::update)
                .def("update_map", &Display::update_map);
        }
    } // namespace python
} // namespace fastsim
