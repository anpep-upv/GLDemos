// GraphicsKit -- Utility library for OpenGL applications
// Copyright (c) 2021 Ángel Pérez <aperpor@upv.edu.es>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#pragma once

#include <GraphicsKit/Vec3.hpp>

namespace GraphicsKit {
struct Scene {
    virtual void init();
    virtual void on_idle();
    virtual void on_display();
    virtual void on_reshape(int new_width, int new_height);

    virtual void on_keyboard_event(bool is_key_down, char pressed_key);
    virtual void on_mouse_moved(int x, int y);

    int width() const { return m_viewport_width; }
    int height() const { return m_viewport_height; }
    
    float dt() const { return m_dt; }

private:
    int m_viewport_width, m_viewport_height;
    int m_timestamp_initial = 0;
    float m_dt = 0.0f;
};

struct PerspectiveScene : Scene {
    float fov = 45.0f;
    float near = 1.0f;
    float far = 100.0f;

    Vec3<float> eye { 0.0f, 0.0f, -1.0f };
    Vec3<float> center { 0.0f, 0.0f, 0.0f };
    Vec3<float> up { 0.0f, 1.0f, 0.0f };

    virtual void on_display() override;
    virtual void on_reshape(int new_width, int new_height) override;
};
}
