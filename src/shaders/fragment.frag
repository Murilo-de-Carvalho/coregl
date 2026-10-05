#version 330 core

// Variable that the gpu is gonna output
// It can be location 0, because ids in and out are differente (I think)
in vec4 vertex_color;
out vec4 color_out;

//uniform vec4 u_color; // Naming convention: u_{name} is always a uniform

void main() {
    color_out = vertex_color;
    //color_out = vec4(1.0, 0.0, 0.0, 1.0);
}