#version 330 core

// Variable that the gpu is gonna output
// It can be location 0, because ids in and out are differente (I think)
layout(location = 0) out vec4 color;

void main() {
    color = vec4(1.0, 0.0, 0.0, 1.0);
}