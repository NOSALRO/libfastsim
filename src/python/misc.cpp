#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;
        void py_robot(py::module& m){
            py::class_<Robot>(m, "Robot")
                .def(py::init<float>(),)
        }
    }
}