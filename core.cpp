#include "include/macros.hpp"
#include "include/linalg.hpp"
#include "include/colors.hpp"
#include "include/shapes.hpp"
#include "include/misc.hpp"
#include "include/camera.hpp"

float angle, f_aspect;

Vec3 origin = {0.0f, 0.0f, 0.0f};
Vec3 target = {0.0f, 0.0f, 0.0f};
Vec3 normal = {0.0f, -1.0f, 0.0f};
Vec3 cam_pos = {0.0f, -5.0f, 2.5f};
Vec3 cam_up = {0.0f, 0.0f, 1.0f};

Camera_Orbital cam = Camera_Orbital(cam_pos, target, cam_up);

Model m = Model("models/Nissan.obj");

void display(void) {

    // Limpa a janela e o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m.render(RED);
    glutSwapBuffers();

}

void init (void) {

    float ambient_light[4]={0.2,0.2,0.2,1.0};
    float diffuse_light[4]={0.7,0.7,0.7,1.0};     // "Color" 
    float specular_light[4]={1.0, 1.0, 1.0, 1.0}; // "Brightness" 
    float light_pos[4]={0.0, 50.0, 50.0, 1.0};

    // Material's brightness capacity
    float specularity[4]={1.0,1.0,1.0,1.0};
    GLint material_specularity = 60;

    // Set background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Enable Gouraud colorizing model
    glShadeModel(GL_SMOOTH);

    // Set material's reflectance
    glMaterialfv(GL_FRONT,GL_SPECULAR, specularity);

    // Define a concentração do brilho
    // Set brightness concentration
    glMateriali(GL_FRONT,GL_SHININESS,material_specularity);

    // Enable ambient light
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

    // Set LIGHT0 parameters
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    // Enable setting the material color based on the current color
    glEnable(GL_COLOR_MATERIAL);

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Enable LIGHT0
    glEnable(GL_LIGHT0);

    // Enable depth-buffering
    glEnable(GL_DEPTH_TEST);

    angle=45.0f;
}

void configure_visualization(void) {

    // Set the projection coordinate system
    glMatrixMode(GL_PROJECTION);

    // Initialize the projection coordinate system
    glLoadIdentity();

    // Set the projection perspective
    gluPerspective(angle, f_aspect, 0.4, 500);

    // Set the model coordinate system
    glMatrixMode(GL_MODELVIEW);

    // Initialize the model coordinate system
    glLoadIdentity();

    // Camera specs
    Vec3 cam_pos = cam.get_pos().to_opengl_coords();
    Vec3 cam_target = cam.get_target().to_opengl_coords();

    gluLookAt(
        cam_pos.x, cam_pos.y, cam_pos.z, // Cam pos
        cam_target.x, cam_target.y, cam_target.z, // Target
        0.0f, 1.0f, 0.0f  // Up vector
    );

}

void resize_window(int w, int h) {

    // To avoid division by zero
    if ( h == 0 ) h = 1;

    // Set viewport size;
    glViewport(0, 0, w, h);
 
    // Determine aspect correction
    f_aspect = (float) w / (float) h;

    configure_visualization();
}

void mouse(int button, int state, int, int) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        if (angle >= 10) angle -= 5; // Zoom-in


    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        if (angle <= 130) angle += 5; // Zoom-out

    configure_visualization();

    glutPostRedisplay();
}

void keyboard(unsigned char key, int, int) {

    switch (key) {

        // Esc
        case 27:
            exit(0);
            break;

        case 'A':
        case 'a':
            cam.rotate_horizontal(-5.0f);
            break;

        case 'D':
        case 'd':
            cam.rotate_horizontal(5.0f);
            break;

        case 'W':
        case 'w':
            cam.rotate_vertical(5.0f);
            break;

        case 'S':
        case 's':
            cam.rotate_vertical(-5.0f);
            break;

        case 'L':
        case 'l':
            cam = Camera_Orbital(cam.get_pos() + X_AXIS_3D * 0.25f, cam.get_target() + X_AXIS_3D * 0.25f, cam_up);
            break;

        case 'H':
        case 'h':
            cam = Camera_Orbital(cam.get_pos() - X_AXIS_3D * 0.25f, cam.get_target() - X_AXIS_3D * 0.25f, cam_up);
            break;

        case 'J':
        case 'j':
            cam = Camera_Orbital(cam.get_pos() + Y_AXIS_3D * 0.25f, cam.get_target() + Y_AXIS_3D * 0.25f, cam_up);
            break;

        case 'K':
        case 'k':
            cam = Camera_Orbital(cam.get_pos() - Y_AXIS_3D * 0.25f, cam.get_target() - Y_AXIS_3D * 0.25f, cam_up);
            break;

    }

    configure_visualization();

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800,800);
    glutCreateWindow("coregl");

    glutDisplayFunc(display);

    glutReshapeFunc(resize_window);

    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();
}