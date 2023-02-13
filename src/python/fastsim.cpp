#include <pybind11/pybind11.h>
#include "map.cpp"
#include "radar.cpp"
#include "robot.cpp"
#include "posture.cpp"
#include "goal.cpp"
#include "illuminated_switch.cpp"
#include "laser.cpp"
#include "linear_camera.cpp"
#include "laser_scanner.cpp"
#include "light_sensor.cpp"
#include "settings.cpp"
#include "display.cpp"


PYBIND11_MODULE(fastsim, m) {
    using namespace fastsim::python;
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
    // py_misc(m);
    py_settings(m);
    py_goal(m);
}