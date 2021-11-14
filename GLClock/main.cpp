// GLClock -- SGI Lab Task 6
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
#include <cmath>

#include <GraphicsKit/PlatformGraphics.h>
#include <GraphicsKit/Scene.hpp>
#include <GraphicsKit/Vec3.hpp>

using namespace GraphicsKit;

struct MyScene : PerspectiveScene {
    void init() override
    {
    }

    void on_idle() override
    {
        PerspectiveScene::on_idle();
    }

    void on_display() override
    {
        PerspectiveScene::on_display();
        glFlush();
    }

    void on_reshape(int width, int height) override
    {
        PerspectiveScene::on_reshape(width, height);
    }
};

int main(int argc, char* argv[])
{
    static MyScene scene;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);

    glutCreateWindow("GLClock");

    scene.init();

    glutIdleFunc([]() { scene.on_idle(); });
    glutDisplayFunc([]() { scene.on_display(); });
    glutReshapeFunc([](int w, int h) { scene.on_reshape(w, h); });

    glutMainLoop();

    return 0;
}
