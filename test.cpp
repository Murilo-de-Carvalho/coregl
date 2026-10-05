#include "include/macros.hpp"
#include "include/linalg.hpp"
#include "include/colors.hpp"
#include "include/application.hpp"
#include "include/shaders.hpp"
#include "include/render.hpp"

#define INITIAL_WIDTH 800
#define INITIAL_HEIGHT 800

std::vector<vec3> vertices = {
    {-0.5f, -0.5f, 0.0f},
     {0.5f, -0.5f, 0.0f},
     {0.5f,  0.5f, 0.0f},

    {-0.5f,  0.5f, 0.0f}
};

std::vector<Color> colors = {
    RED,
    RED,
    RED,
    RED,
};

std::vector<unsigned int> indices = {
    0, 1, 2,
    0, 2, 3
};

int main() {

    Application app = Application(
        "Test",         // Window name
        INITIAL_WIDTH,  // Width
        INITIAL_HEIGHT  // Height
    );

    app.init();

    set_background_color(FULL_BLACK);

    /* // Tell opengl what everything is in the buffer 
    glVertexAttribPointer(
        0, // id of the attribute (0 in this case because is the first attribute)
        3, // How many items is in this attribute (in this case is a vec3, so 3 items)
        GL_FLOAT, // Which type is the data in
        GL_FALSE, // If data needs to be normalized (-1 - 1 or 0 - 1 for unsigned values), floats don't need to be normalized
        3 * sizeof(float), // Ammount of bytes between each vertex (NOT ATTRIBUTE), basically the size of a vertex
        (const void*) 0 // Offset in BYTES to the attribute (NOT VERTEX), if, the normal is after a vec3 of floats, it would be 3 * sizeof(float)
    ); */

    Shader shader("./src/shaders/vertex.vert", "./src/shaders/fragment.frag");

    Position_Buffer pb = {vertices};
    Color_Buffer cb = {colors};
    Index_Buffer ib = {indices};

    Untextured_Mesh mesh = {pb, cb, ib, shader};
    mesh.bind();

    while (!window_should_close(app)) {

        // Take care of all GLFW events
        glfwPollEvents();

        clear_background();

        mesh.render();

        glfwSwapBuffers(app.window);

    }

    return 0;
}