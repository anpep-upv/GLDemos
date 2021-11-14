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

#include <string>

namespace GraphicsKit {
template <typename T = float>
struct Vec3 {
    T x, y, z;

    Vec3()
        : Vec3({}, {}, {})
    {
    }

    Vec3(T all)
        : Vec3(all, all, all)
    {
    }

    Vec3(T x, T y, T z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3 normalized() const
    {
        const T magnitude = static_cast<T>(sqrt(x * x + y * y + z * z));
        if (magnitude == T())
            return {};

        return this / Vec3 { magnitude };
    }

    const std::string to_string() const
    {
        return "(" + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + ")";
    }

#pragma region Operators
    Vec3 operator+(const Vec3& other) const
    {
        return { x + other.x, y + other.y, z + other.z };
    }

    void operator+=(const Vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    Vec3 operator-(const Vec3& other) const
    {
        return { x - other.x, y - other.y, z - other.z };
    }

    void operator-=(const Vec3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    Vec3 operator*(const T& value) const
    {
        return { x * value, y * value, z * value };
    }

    void operator*=(const T& value)
    {
        x *= value;
        y *= value;
        z *= value;
    }

    Vec3 operator*(const Vec3& other) const
    {
        return { x * other.x, y * other.y, z * other.z };
    }

    void operator*=(const Vec3& other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    Vec3 operator/(const T& value) const
    {
        return { x / value, y / value, z / value };
    }

    void operator/=(const T& value)
    {
        x /= value;
        y /= value;
        z /= value;
    }

    Vec3 operator/(const Vec3& other) const
    {
        return { x / other.x, y / other.y, z / other.z };
    }

    void operator/=(const Vec3& other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
    }
#pragma endregion
};
}
