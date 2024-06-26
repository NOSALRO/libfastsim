#include <vector>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include "pybind_utils.hpp"

namespace py = pybind11;

namespace fastsim {
    namespace python {
        using namespace fastsim;

        void py_map(py::module& m)
        {
            py::class_<Map, std::shared_ptr<Map>> map(m, "Map");
            map.def(py::init<const char*, float>(),
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
                .def("pixel_to_real", &Map::pixel_to_real,
                    py::arg("i"))
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
                .def("clear_goals", &Map::clear_goals)
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
                    py::arg("ly"))
                .def("__copy__", [](const Map& self) { auto mp = Map(self); for(const auto& g: self.get_goals()) mp.add_goal(g); return mp; })
                .def("__deepcopy__", [](const Map& self, py::dict) { auto mp = Map(self); for(const auto& g: self.get_goals()) mp.add_goal(g); return mp; })
                .def(py::pickle(
                    [](const Map &m) {
                        return py::make_tuple(m.get_pixel_w(), m.get_pixel_h(), m.get_real_w(), m.get_data());
                    },
                    [](py::tuple t) {
                        Map m(t[0].cast<int>(), t[1].cast<int>(), t[2].cast<float>());
                        m.set_data(t[3].cast<std::vector<Map::status_t>>());
                        return m;
                    }
                ));

            py::enum_<Map::status_t>(map, "status_t")
                .value("free", Map::status_t::free)
                .value("obstacle", Map::status_t::obstacle)
                .export_values();
        }
    } // namespace python
} // namespace fastsim
