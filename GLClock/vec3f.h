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

struct vec3f {
    float x, y, z;
};

#define _Expand_zero() 0.0f, 0.0f, 0.0f
#define _Expand_one() 1.0f, 1.0f, 1.0f
#define _Expand(v) v.x, v.y, v.z
#define _Vec(_x, _y, _z) ((struct vec3f) { .x = (_x), .y = (_y), .z = (_z) })

