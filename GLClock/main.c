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

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "platform_graphics.h"
#include "platform_attributes.h"
#include "vec3f.h"
#include "geometry.h"

#pragma region Camera properties
static const float k_fov = 45.0f;
static const float k_near = 1.0f;
static const float k_far = 100.0f;

static struct vec3f g_eye = _Vec(0.0f, 0.0f, -8.0f);
static struct vec3f g_center = _Vec(0.0f, 0.0f, 0.0f);
static struct vec3f g_up = _Vec(0.0f, 1.0f, 0.0f);

static struct vec3f g_camera_rotation = _Vec(0.0f, 0.0f, 0.0f);
#pragma endregion

#pragma region Frame rate control
static const int k_max_fps = 60;
static int g_frame = 0;
#pragma endregion

#pragma region Sphere geometry
static GLint g_list_sphere;

static float g_sphere_theta = 0.0f;
static const float g_sphere_velocity = _Rad(3600);
#pragma endregion

#pragma region Local time information
struct tm *g_localtime;
#pragma endregion

static void init_scene(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    g_list_sphere = glGenLists(1);
    create_list_circle(g_list_sphere, 1.0f, 64);
}

static void update_localtime(int value _Unused)
{
    time_t tm;
    time(&tm);
    g_localtime = localtime(&tm);
    glutSetWindowTitle(asctime(g_localtime));
    glutTimerFunc(1000, update_localtime, value);
}

static void on_timer(int value _Unused)
{
    static int timestamp_initial = 0;
    int timestamp_current = glutGet(GLUT_ELAPSED_TIME);
    float dt = (timestamp_current - timestamp_initial) / 1000.0f;
    
    g_sphere_theta += g_sphere_velocity * dt;
    
    timestamp_initial = timestamp_current;
    glutTimerFunc(1000 / k_max_fps, on_timer, value);
    glutPostRedisplay();
}

static void on_display(void)
{
    if (!g_localtime)
        return;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(_Expand(g_eye), _Expand(g_center), _Expand(g_up));
    
    glRotatef(g_camera_rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef(g_camera_rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef(g_camera_rotation.z, 0.0f, 0.0f, 1.0f);
    
    glColor3f(_Expand_zero());
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 10.0f);
    glRotatef(0.6666f * g_sphere_theta, 1.0f, 1.0f, 0.0f);
    glRotatef(-0.6666f * g_sphere_theta, 0.0f, 0.0f, 1.0f);
    glutSolidCube(7.0f);
    glPopMatrix();
    
    glColor3f(_Expand_one());
    glPushMatrix();
    glScalef(1.25f, 1.25f, 1.0f);
    glRotatef(+g_sphere_theta, 1.0f, 1.0f, 0.0f);
    glCallList(g_list_sphere);
    glPopMatrix();
    
    glColor3f(_Expand_one());
    glPushMatrix();
    glScalef(1.5f, 1.5f, 1.0f);
    glRotatef(+g_sphere_theta, 1.0f, 1.0f, 0.0f);
    glRotatef(-g_sphere_theta, 1.0f, 0.0f, 0.0f);
    glCallList(g_list_sphere);
    glPopMatrix();
    
    glColor4f(_Expand_one(), 0.25);
    glPushMatrix();
    glScalef(2.5f, 2.5f, 0.0f);
    glRotatef(g_sphere_theta, 0.0f, 0.0f, 1.0f);
    glCallList(g_list_sphere);
    glPopMatrix();
    
    for (int sec = 1; sec <= 60; sec++) {
        if (g_localtime->tm_sec >= sec - 1)
            glColor4f(_Expand_one(), 0.75);
        else
            glColor4f(_Expand_one(), 0.25);
        
        glPushMatrix();
        glRotatef(sec * (360 / 60), 0.0f, 0.0f, 1.0f);
        glBegin(GL_LINES);
        
        
        if (sec % 15 == 0) {
            glVertex2f(0.0f, 0.85f);
            glVertex2f(0.0f, 0.95f);
        } else {
            glVertex2f(0.0f, 0.70f);
            glVertex2f(0.0f, 0.75f);
        }
            
        glEnd();
        glPopMatrix();
    }
    
    glColor3f(_Expand_one());
    glPushMatrix();
    glRotatef(g_localtime->tm_min * (360 / 60), 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.75f);
    glVertex2f(0.0f, 1.25f);
    glEnd();
    glPopMatrix();
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glPushMatrix();
    glRotatef((g_localtime->tm_hour % 12) * (360 / 12), 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.75f);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    glLineWidth(1.0f);
    glPopMatrix();
    
    glutSwapBuffers();
    g_frame++;
}

static void on_reshape(GLint width, GLint height)
{
    float aspect_ratio = ((float) width) / ((float) height);
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(k_fov, aspect_ratio, k_near, k_far);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("GLClock");

    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);
    glutTimerFunc(1000 / k_max_fps, on_timer, k_max_fps);
    glutTimerFunc(1000, update_localtime, 0);
    
    init_scene();
    glutMainLoop();
    
    return 0;
}
