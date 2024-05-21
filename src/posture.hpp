
/*
** posture.hh
** Login : <mouret@asuncion.lip6.fr>
** Started on  Mon Jan 14 16:39:35 2008 Jean-Baptiste MOURET
** $Id$
**
** Copyright (C) 2008 Jean-Baptiste MOURET
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef POSTURE_HH_
#define POSTURE_HH_
#include <iostream>
#include <cmath>

namespace fastsim {
    class Posture {
    public:
        Posture(float x, float y, float theta) : _x(x), _y(y), _theta(theta) {}

        Posture() {}
        Posture(const Posture& p) : _x(p._x),
                                    _y(p._y),
                                    _theta(p._theta) {}

        Posture& operator=(const Posture& o)
        {
            _x = o._x;
            _y = o._y;
            _theta = o._theta;
            return *this;
        }
        //
        float theta() const { return _theta; }
        void set_theta(float t) { _theta = t; }
        void set_x(float x) { _x = x; }
        void set_y(float y) { _y = y; }
        float x() const { return _x; }
        float y() const { return _y; }
        float get_x() const { return _x; }
        float get_y() const { return _y; }

        //
        float dist_to(const Posture& p) const
        {
            return dist_to(p.x(), p.y());
        }

        float dist_to(float x, float y) const
        {
            float xx = _x - x;
            float yy = _y - y;
            return sqrtf(xx * xx + yy * yy);
        }

        //
        const Posture& rotate(float theta)
        {
            float x_ = cos(theta) * x() - sin(theta) * y();
            float y_ = cos(theta) * y() + sin(theta) * x();
            _x = x_;
            _y = y_;
            _theta += theta;
            return *this;
        }

        Posture operator+(const Posture& o) const
        {
            Posture p;
            p._x = _x + o._x;
            p._y = _y + o._y;
            // p._x = std::max(0.f, std::min(p._x, 600.0f));
            // p._y = std::max(0.f, std::min(p._y, 600.0f));
            p._theta = normalize_angle(_theta + o._theta);
            return p;
        }

        const Posture& move(float d_l, float d_r, float wheels_dist)
        {
            Posture old_pos = *this;
            float d = wheels_dist;
            float r = 1.0;
            float phi_dot = r / (2 * d) * (d_r - d_l);
            float x_dot = (r / 2) * cos(old_pos.theta()) * (d_l + d_r);
            float y_dot = (r / 2) * sin(old_pos.theta()) * (d_l + d_r);

            *this = old_pos + Posture(x_dot, y_dot, phi_dot);
            return *this;
        }

        template <typename T>
        static inline T normalize_angle(T a)
        {
            while (a > M_PI)
                a -= 2 * M_PI;
            while (a < -M_PI)
                a += 2 * M_PI;
            return a;
        }

    protected:
        float _x, _y;
        float _theta;
    };

} // namespace fastsim

#endif /* !POSTURE_HH_ */
