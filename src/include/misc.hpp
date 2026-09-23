#pragma once
#include "macros.hpp"
#include "glad.h"

struct Application {
    GLFWwindow* window;
    GLint width;
    GLint height;
};