#include "radar.hpp"
#include <iostream>

namespace fastsim {
    int Radar ::update(const Posture& pos, const std::shared_ptr<Map>& map)
    {
        const Goal& g = map->get_goals()[_color];
        float angle = normalize_angle_2pi(atan2(g.get_y() - pos.y(), g.get_x() - pos.x()) - pos.theta());
        float x, y;

        bool not_visible = _through_walls ? false : map->check_inter_real(pos.x(), pos.y(), g.get_x(), g.get_y(), x, y);

        if (not_visible && !_through_walls) {
            _activated_slice = -1;
            return -1;
        }

        float xi = _inc;
        for (int i = 0; i < _nb_slices + 1; ++i) {
            if (angle < xi)
                return (_activated_slice = i % _nb_slices);
            xi += _inc;
        }
        //    assert(0);
        return -1;
    }
} // namespace fastsim
