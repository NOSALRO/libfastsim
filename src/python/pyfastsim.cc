#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace fastsim {
    namespace python {
        void py_robot(py::module& m);
        void py_map(py::module& m);
        void py_radar(py::module& m);
        void py_posture(py::module& m);
        void py_illuminated_switch(py::module& m);
        void py_laser(py::module& m);
        void py_linear_camera(py::module& m);
        void py_display(py::module& m);
        void py_laser_scanner(py::module& m);
        void py_light_sensor(py::module& m);
        void py_settings(py::module& m);
        void py_goal(py::module& m);
    } // namespace python
} // namespace fastsim

PYBIND11_MODULE(pyfastsim, m)
{
    using namespace fastsim::python;

    m.doc() = "pyfastsim: Python API of libfastsim";

    py_robot(m);
    py_map(m);
    py_radar(m);
    py_posture(m);
    py_illuminated_switch(m);
    py_laser(m);
    py_linear_camera(m);
    py_display(m);
    py_laser_scanner(m);
    py_light_sensor(m);
    py_settings(m);
    py_goal(m);
}