
#include "include/macros.hpp"
#include "include/linalg.hpp"
#include "include/colors.hpp"
#include "include/shapes.hpp"
#include "include/misc.hpp"

Vec2 origin = Vec2(0.0f, 0.0f);
Triangle tri = Triangle(origin, 0.8f);
Square sqr = Square(origin, 0.8f);

void draw() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tri.draw(RED);
    sqr.draw(BLUE);

    glFlush();

    return;
}

void resize_window(GLsizei w, GLsizei h) {

    if (!h) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        gluOrtho2D(-1.0f, 1.0f, -1.0f * h/w, 1.0f * h/w);
    else
        gluOrtho2D(-1.0f * w/h, 1.0f * w/h, -1.0, 1.0f);

    return;
}

void keyboard(unsigned char key, int /*x*/, int /*y*/) {

    switch (key) {

        // Esc
        case 27:
            exit(0);

        case '+':
            tri.set_size(tri.get_size() + 0.1);
            break;

        case '-':
            tri.set_size(tri.get_size() - 0.1);
            break;

        case 'W':
        case 'w':
            tri.update_pos(Vec2(0, 0.1));
            break;

        case 'A':
        case 'a':
            tri.update_pos(Vec2(-0.1, 0));
            break;

        case 'S':
        case 's':
            tri.update_pos(Vec2(0, -0.1));
            break;

        case 'D':
        case 'd':
            tri.update_pos(Vec2(0.1, 0));
            break;

        default:
            break;
    }

    glutPostRedisplay();

    return;
}

void init() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    return;
}

int main(int argc, char* argv[]) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800, 800);
    glutCreateWindow("Core");

    glutDisplayFunc(draw);

    glutReshapeFunc(resize_window);

    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;
}