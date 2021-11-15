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

#include <math.h>

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

#ifndef M_TAU
#define M_TAU 6.283185307179586
#endif

#define _Rad(theta) ((theta) * M_PI / 180);

#include "platform_attributes.h"
#include "platform_graphics.h"

_Inline void create_list_circle(GLint gl_list, float radius, int vertices)
{
    glNewList(gl_list, GL_COMPILE);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < vertices; i++) {
        float point = M_TAU * ((float)i / (float)vertices);
        glVertex2f(radius * cosf(point), radius * sinf(point));
    }
    glEnd();
    glEndList();
}

