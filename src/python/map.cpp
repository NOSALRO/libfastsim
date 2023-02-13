#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;
        void py_map(py::module& m){
            py::class_<Map, std::shared_ptr<Map>>(m, "Map")
                .def(py::init<const char*, float>(),
                    py::arg("fname"),
                    py::arg("real_w"))
                .def(py::init<int, int, float>(),
                    py::arg("pixel_w"),
                    py::arg("pixel_h"),
                    py::arg("real_w"))
                .def(py::init<const Map&>(),
                    py::arg("Map"))
                .def("get_data", &Map::get_data)
                .def("set_data", &Map::set_data,
                    py::arg("from"))
                .def("get_pixel", &Map::get_pixel,
                    py::arg("x"),
                    py::arg("y"))
                .def("set_pixel", &Map::set_pixel,
                    py::arg("x"),
                    py::arg("y"),
                    py::arg("v"))
                .def("get_real", &Map::get_real,
                    py::arg("x"),
                    py::arg("y"))
                .def("real_to_pixel", &Map::real_to_pixel,
                    py::arg("x"))
                .def("get_real_w", &Map::get_real_w)
                .def("get_real_h", &Map::get_real_h)
                .def("get_pixel_w", &Map::get_pixel_w)
                .def("get_pixel_h", &Map::get_pixel_h)
                .def("check_inter_pixel", &Map::check_inter_pixel,
                    py::arg("x1"),
                    py::arg("y1"),
                    py::arg("x2"),
                    py::arg("y2"),
                    py::arg("x_res"),
                    py::arg("y_res"))
                .def("check_inter_real", &Map::check_inter_real,
                    py::arg("x1"),
                    py::arg("y1"),
                    py::arg("x2"),
                    py::arg("y2"),
                    py::arg("x_res"),
                    py::arg("y_res"))
                .def("check_inter_is", &Map::check_inter_is,
                    py::arg("x1"),
                    py::arg("y1"),
                    py::arg("x2"),
                    py::arg("y2"))
                .def("get_goals", &Map::get_goals)
                .def("add_goal", &Map::add_goal,
                    py::arg("g"))
                .def("add_illuminated_switch", &Map::add_illuminated_switch,
                    py::arg("is"))
                .def("get_illuminated_switches", &Map::get_illuminated_switches)
                .def("get_illuminated_switch_by_color", &Map::get_illuminated_switch_by_color,
                    py::arg("color"))
                .def("clear_illuminated_switches", &Map::clear_illuminated_switches)
                .def("update", &Map::update,
                    py::arg("robot_pos"))
                .def("terrain_switch", &Map::terrain_switch,
                    py::arg("fname"))
                .def("draw_rect", &Map::draw_rect,
                    py::arg("x"),
                    py::arg("y"),
                    py::arg("lx"),
                    py::arg("ly"));
        }
    }
}