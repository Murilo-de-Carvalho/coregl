#version 330 core

// It will eventually be casted as a vec4 for matrix multiplication, so we define it as so
// OpenGL knows the real size and it can manage it for us
// Position that we pass from cpu to gpu (in)
// Location is the id of the attribute
layout(location = 0) in vec4 pos;
layout(location = 1) in vec4 color_in;

out vec4 vertex_color;

void main() {
    gl_Position = pos;
    vertex_color = color_in;
}