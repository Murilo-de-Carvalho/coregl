#pragma once
#include "macros.hpp"

inline void print_vec(vec2 vec);
inline void print_vec(vec3 vec);
inline void print_vec(vec4 vec);

void print_matrix(mat2 mat);
void print_matrix(mat3 mat);
void print_matrix(mat4 mat);

// Basically all wrappers
inline mat2 hadamard(const mat2& a, const mat2& b);
inline mat3 hadamard(const mat3& a, const mat3& b);
inline mat4 hadamard(const mat4& a, const mat4& b);