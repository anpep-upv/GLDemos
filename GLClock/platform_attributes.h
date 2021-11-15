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

#if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#define _Unused __attribute__((unused))
#define _Inline inline __attribute__((always_inline))
#elif defined(_MSC_VERSION)
#define _Unused
#define _Inline __forceinline
#endif
