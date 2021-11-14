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

#include <iostream>

#include "Scene.hpp"
#include "PlatformGraphics.h"

namespace GraphicsKit {
#pragma region Scene
void Scene::init()
{
}

void Scene::on_idle()
{
    if (m_timestamp_initial == 0) {
        // First idle call
        m_timestamp_initial = glutGet(GLUT_ELAPSED_TIME);
        m_dt = 0.0f;
    } else {
        // Calculate time delta for smooth animation
        const int timestamp_current = glutGet(GLUT_ELAPSED_TIME);
        const int timestamp_delta = timestamp_current - m_timestamp_initial;
        m_dt = ((float)timestamp_delta) / 1000.0f;
    }
}

void Scene::on_display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Scene::on_reshape(int new_width, int new_height)
{
    m_viewport_width = new_width;
    m_viewport_height = new_height;
}

void Scene::on_keyboard_event(bool is_key_down, char pressed_key)
{
}

void Scene::on_mouse_moved(int x, int y)
{
}
#pragma endregion

#pragma region PerspectiveScene
void PerspectiveScene::on_display()
{
    Scene::on_display();
    gluLookAt(eye.x, eye.y, eye.z,
        center.x, center.y, center.z,
        up.x, up.y, up.z);
}

void PerspectiveScene::on_reshape(int new_width, int new_height)
{
    Scene::on_reshape(new_width, new_height);
    const float aspect_ratio = (float)new_width / (float)new_height;

    glViewport(0, 0, new_width, new_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(this->fov, aspect_ratio, this->near, this->far);
}
#pragma endregion
}
