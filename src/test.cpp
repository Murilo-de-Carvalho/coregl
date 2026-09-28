#include "include/macros.hpp"
#include "include/linalg.hpp"
#include "include/colors.hpp"
#include "include/application.hpp"
#include "include/shaders.hpp"

#define INITIAL_WIDTH 800
#define INITIAL_HEIGHT 800

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,

    -0.5f,  0.5f, 0.0f
};

unsigned int indices[] = {
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

    // Bullshit
    unsigned int VAO; glGenVertexArrays(1, &VAO); glBindVertexArray(VAO);

    // Create the buffer
    unsigned int buffer;
    glGenBuffers(1, &buffer);

    // Select the buffer, saying it is a generic buffer (GL_ARRAY_BUFFER)
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // Fill the buffer with data, specifying the type of the buffer,
    // how many BYTES is the data, the data pointer and the usage of the data
    glBufferData(GL_ARRAY_BUFFER, 4 * 3 * sizeof(float), vertices, GL_STATIC_DRAW);



    // Create the buffer
    unsigned int ibo;
    glGenBuffers(1, &ibo);

    // Select the buffer, saying it is a generic buffer (GL_ARRAY_BUFFER)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // Fill the buffer with data, specifying the type of the buffer,
    // how many BYTES is the data, the data pointer and the usage of the data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);



    // Tell opengl what everything is in the buffer 
    glVertexAttribPointer(
        0, // id of the attribute (0 in this case because is the first attribute)
        3, // How many items is in this attribute (in this case is a vec3, so 3 items)
        GL_FLOAT, // Which type is the data in
        GL_FALSE, // If data needs to be normalized (-1 - 1 or 0 - 1 for unsigned values), floats don't need to be normalized
        3 * sizeof(float), // Ammount of bytes between each vertex (NOT ATTRIBUTE), basically the size of a vertex
        (const void*) 0 // Offset in BYTES to the attribute (NOT VERTEX), if, the normal is after a vec3 of floats, it would be 3 * sizeof(float)
    );

    // Enables the attribute with the specified id
    glEnableVertexAttribArray(0);




    /* std::string vertex_shader = read_shader("./src/shaders/vertex.vert");
    std::string fragment_shader = read_shader("./src/shaders/fragment.frag");
    unsigned int shader = create_shader(vertex_shader, fragment_shader);
    glUseProgram(shader); */

    Shader shader("./src/shaders/vertex.vert", "./src/shaders/fragment.frag");
    use_shader(shader);

    while (!window_should_close(app)) {

        // Take care of all GLFW events
        glfwPollEvents();

        clear_background();
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(app.window);

    }

    return 0;
}