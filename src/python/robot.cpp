#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim
{
    namespace python
    {
        using namespace fastsim;

        void py_robot(py::module &m)
        {
            py::class_<Robot, std::shared_ptr<Robot>>(m, "Robot")
                .def(py::init<float>(),
                     py::arg("radius"))
                .def(py::init<float, const Posture &>(),
                     py::arg("radius"),
                     py::arg("pos"))
                .def("reinit", &Robot::reinit)
                .def("move", &Robot::move,
                     py::arg("v1"),
                     py::arg("v2"),
                     py::arg("m"),
                     py::arg("sticky_walls") = true)
                .def("get_pos", &Robot::get_pos)
                .def("set_pos", &Robot::set_pos,
                     py::arg("pos"))
                .def("get_vx", &Robot::get_vx)
                .def("get_vy", &Robot::get_vy)
                .def("get_va", &Robot::get_va)
                .def("get_bb", &Robot::get_bb)
                .def("get_radius", &Robot::get_radius)
                .def("get_collision", &Robot::get_collision)
                .def("get_left_bumper", &Robot::get_left_bumper)
                .def("get_right_bumper", &Robot::get_right_bumper)
                .def("add_laser", &Robot::add_laser,
                     py::arg("l"))
                .def("add_laser_scanner", &Robot::add_laser_scanner,
                     py::arg("l"))
                .def("get_lasers", &Robot::get_lasers)
                .def("get_laser_scanners", &Robot::get_laser_scanners)
                .def("add_radar", &Robot::add_radar,
                     py::arg("r"))
                .def("get_radars", &Robot::get_radars)
                .def("add_light_sensor", &Robot::add_light_sensor,
                     py::arg("l"))
                .def("get_light_sensors", &Robot::get_light_sensors)
                .def("set_color", &Robot::set_color,
                     py::arg("color"))
                .def("color", &Robot::color)
                .def("use_camera", static_cast<void (Robot::*)(const LinearCamera &)>(&Robot::use_camera),
                     py::arg("c"))
                .def("use_camera", static_cast<void (Robot::*)()>(&Robot::use_camera))
                .def("get_camera", &Robot::get_camera)
                .def("camera_enabled", &Robot::camera_enabled)
                .def("use_camera", static_cast<void (Robot::*)()>(&Robot::use_camera))
                .def("__copy__", [](const Robot &self)
                     { return Robot(self); })
                .def("__deepcopy__", [](const Robot &self, py::dict)
                     { return Robot(self); });
        }
    } // namespace python
} // namespace fastsim
