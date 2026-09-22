#pragma once
#include "include/linalg.hpp"

inline void print_vec(vec2 vec) {
    printf("[vec2] = <%.2f, %.2f>\n", vec.x, vec.y);
}

inline void print_vec(vec3 vec) {
    printf("[vec3] = <%.2f, %.2f, %.2f>\n", vec.x, vec.y, vec.z);
}

inline void print_vec(vec4 vec) {
    printf("[vec4] = <%.2f, %.2f, %.2f, %.2f>\n", vec.x, vec.y, vec.z, vec.w);
}



void print_matrix(mat2 mat) {
    printf("[mat2]\n");
    printf("[%.2f, %.2f]\n", mat[0][0], mat[1][0]);
    printf("[%.2f, %.2f]\n", mat[0][1], mat[1][1]);
}

void print_matrix(mat3 mat) {
    printf("[mat3]\n");
    printf("[%.2f, %.2f, %.2f]\n", mat[0][0], mat[1][0], mat[2][0]);
    printf("[%.2f, %.2f, %.2f]\n", mat[0][1], mat[1][1], mat[2][1]);
    printf("[%.2f, %.2f, %.2f]\n", mat[0][2], mat[1][2], mat[2][2]);
}

void print_matrix(mat4 mat) {
    printf("[mat4]\n");
    printf("[%.2f, %.2f, %.2f, %.2f]\n", mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
    printf("[%.2f, %.2f, %.2f, %.2f]\n", mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
    printf("[%.2f, %.2f, %.2f, %.2f]\n", mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
    printf("[%.2f, %.2f, %.2f, %.2f]\n", mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
}



// Basically all wrappers
inline mat2 hadamard(const mat2& a, const mat2& b) {
    return glm::matrixCompMult(a, b);
}

inline mat3 hadamard(const mat3& a, const mat3& b) {
    return glm::matrixCompMult(a, b);
}

inline mat4 hadamard(const mat4& a, const mat4& b) {
    return glm::matrixCompMult(a, b);
}