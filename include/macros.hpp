#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
// #include <GL/glew.h>
// #include <GL/gl.h>
// #include <GL/glu.h>

#define PI 3.14159265358979323846f
#define ELIPSIS_SEGMENTS 180

#define byte unsigned char

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define RADIANS(deg) deg * (PI/180.0f)
#define DEGREES(radians) (radians * 180.0f) / PI

#define ERROR(msg) {fprintf(stderr, "[ERROR] %s\n", msg); exit(1);}

#define NULL_VECTOR_2D {0.0f, 0.0f}
#define NULL_VECTOR_3D {0.0f, 0.0f, 0.0f}