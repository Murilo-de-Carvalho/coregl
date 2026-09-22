#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <array>
#include <GL/glut.h>
#include <glm/glm.hpp>

#define PI 3.14159265358979323846f

#define byte unsigned char

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define RADIANS(deg) deg * (PI/180.0f)
#define DEGREES(radians) (radians * 180.0f) / PI

#define ERROR(msg) {fprintf(stderr, "[ERROR] %s\n", msg); exit(1);}

using glm::vec2;
using glm::vec3;
using glm::vec4;

using glm::mat2;
using glm::mat3;
using glm::mat4;

using glm::quat;