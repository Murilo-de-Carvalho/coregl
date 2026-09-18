#pragma once
#include "macros.hpp"
#include "include/linalg.hpp"

// ============================================================
//  Vec3
// ============================================================

Vec3::Vec3() {}
Vec3::Vec3(float x, float y, float z) {}
Vec3::~Vec3() {}

float Vec3::length() {}
Vec3 Vec3::normalize() {}

Vec3gl Vec3::to_vec3gl() {}
Vec3_Sphere Vec3::to_vec3_sphere() {}
Vec3gl_Sphere Vec3::to_vec3gl_sphere() {}

Vec3 Vec3::operator+(const Vec3& other) const {}
Vec3 Vec3::operator-(const Vec3& other) const {}
Vec3 Vec3::operator*(float constant) const {}
Vec3 Vec3::operator/(float constant) const {}
Vec3 Vec3::operator-() const {} // Unitary negative

Vec3& Vec3::operator+=(const Vec3& other) const {}
Vec3& Vec3::operator-=(const Vec3& other) const {}
Vec3& Vec3::operator*=(float constant) const {}
Vec3& Vec3::operator/=(float constant) const {}

bool Vec3::operator==(const Vec3& other) {}
bool Vec3::operator!=(const Vec3& other) {}



// ============================================================
//  Vec3gl
// ============================================================

Vec3gl::Vec3gl() {}
Vec3gl::Vec3gl(float x, float y, float z) {}
Vec3gl::~Vec3gl() {}

float Vec3gl::length() {}
Vec3gl Vec3gl::normalize() {}

Vec3 Vec3gl::to_vec3() {}
Vec3_Sphere Vec3gl::to_vec3_sphere() {}
Vec3gl_Sphere Vec3gl::to_vec3gl_sphere() {}

Vec3gl Vec3gl::operator+(const Vec3gl& other) const {}
Vec3gl Vec3gl::operator-(const Vec3gl& other) const {}
Vec3gl Vec3gl::operator*(float constant) const {}
Vec3gl Vec3gl::operator/(float constant) const {}
Vec3gl Vec3gl::operator-() const {} // Unitary negative

Vec3gl& Vec3gl::operator+=(const Vec3gl& other) const {}
Vec3gl& Vec3gl::operator-=(const Vec3gl& other) const {}
Vec3gl& Vec3gl::operator*=(float constant) const {}
Vec3gl& Vec3gl::operator/=(float constant) const {}

bool Vec3gl::operator==(const Vec3gl& other) {}
bool Vec3gl::operator!=(const Vec3gl& other) {}



// ============================================================
//  Vec3_Sphere
// ============================================================

Vec3_Sphere::Vec3_Sphere() {}
Vec3_Sphere::Vec3_Sphere(float rho, float theta, float phi) {}
Vec3_Sphere::~Vec3_Sphere() {}

float Vec3_Sphere::length() {}
Vec3_Sphere Vec3_Sphere::normalize() {}

Vec3 Vec3_Sphere::to_vec3() {}
Vec3gl Vec3_Sphere::to_vec3gl() {}
Vec3gl_Sphere Vec3_Sphere::to_vec3gl_sphere() {}

Vec3_Sphere Vec3_Sphere::operator+(const Vec3_Sphere& other) const {}
Vec3_Sphere Vec3_Sphere::operator-(const Vec3_Sphere& other) const {}
Vec3_Sphere Vec3_Sphere::operator*(float constant) const {}
Vec3_Sphere Vec3_Sphere::operator/(float constant) const {}
Vec3_Sphere Vec3_Sphere::operator-() const {} // Unitary negative

Vec3_Sphere& Vec3_Sphere::operator+=(const Vec3_Sphere& other) const {}
Vec3_Sphere& Vec3_Sphere::operator-=(const Vec3_Sphere& other) const {}
Vec3_Sphere& Vec3_Sphere::operator*=(float constant) const {}
Vec3_Sphere& Vec3_Sphere::operator/=(float constant) const {}

bool Vec3_Sphere::operator==(const Vec3_Sphere& other) {}
bool Vec3_Sphere::operator!=(const Vec3_Sphere& other) {}



// ============================================================
//  Vec3gl_Sphere
// ============================================================

Vec3gl_Sphere::Vec3gl_Sphere() {}
Vec3gl_Sphere::Vec3gl_Sphere(float rho, float theta, float phi) {}
Vec3gl_Sphere::~Vec3gl_Sphere() {}

float Vec3gl_Sphere::length() {}
Vec3gl_Sphere Vec3gl_Sphere::normalize() {}

Vec3 Vec3gl_Sphere::to_vec3() {}
Vec3gl Vec3gl_Sphere::to_vec3gl() {}
Vec3_Sphere Vec3gl_Sphere::to_vec3_sphere() {}

Vec3gl_Sphere Vec3gl_Sphere::operator+(const Vec3gl_Sphere& other) const {}
Vec3gl_Sphere Vec3gl_Sphere::operator-(const Vec3gl_Sphere& other) const {}
Vec3gl_Sphere Vec3gl_Sphere::operator*(float constant) const {}
Vec3gl_Sphere Vec3gl_Sphere::operator/(float constant) const {}
Vec3gl_Sphere Vec3gl_Sphere::operator-() const {} // Unitary negative

Vec3gl_Sphere& Vec3gl_Sphere::operator+=(const Vec3gl_Sphere& other) const {}
Vec3gl_Sphere& Vec3gl_Sphere::operator-=(const Vec3gl_Sphere& other) const {}
Vec3gl_Sphere& Vec3gl_Sphere::operator*=(float constant) const {}
Vec3gl_Sphere& Vec3gl_Sphere::operator/=(float constant) const {}

bool Vec3gl_Sphere::operator==(const Vec3gl_Sphere& other) {}
bool Vec3gl_Sphere::operator!=(const Vec3gl_Sphere& other) {}



// ============================================================
//  Matrix3
// ============================================================

Matrix3::Matrix3() {}

Matrix3::Matrix3(
    float r1c1, float r1c2, float r1c3,
    float r2c1, float r2c2, float r2c3,
    float r3c1, float r3c2, float r3c3
) {}

Matrix3::Matrix3(const std::array<std::array<float, 3>, 3>& data) {}
Matrix3::Matrix3(const Vec3& row_1, const Vec3& row_2, const Vec3& row_3) {}
Matrix3::Matrix3(const Vec3& column_1, const Vec3& column_2, const Vec3& column_3) {}

Matrix3::~Matrix3() {}

void Matrix3::transpose() {}
void Matrix3::invert() {}
float Matrix3::determinant() {}
Matrix3 Matrix3::get_transpose() {}
Matrix3 Matrix3::get_inverse() {}

std::array<Vec3, 3> Matrix3::to_vec3_array() {}
std::array<Vec3gl, 3> Matrix3::to_vec3gl_array() {}
std::array<Vec3_Sphere, 3> Matrix3::to_vec3_sphere_array() {}
std::array<Vec3gl_Sphere, 3> Matrix3::to_vec3gl_sphere_array() {}

std::array<float, 3>& Matrix3::operator[](int index) {}

Matrix3 Matrix3::operator+(const Matrix3& other) const {}
Matrix3 Matrix3::operator-(const Matrix3& other) const {}
Matrix3 Matrix3::operator*(float constant) const {}
Matrix3 Matrix3::operator/(float constant) const {}
Matrix3 Matrix3::operator-() const {} // Unitary negative

Matrix3& Matrix3::operator+=(const Matrix3& other) const {}
Matrix3& Matrix3::operator-=(const Matrix3& other) const {}
Matrix3& Matrix3::operator*=(float constant) const {}
Matrix3& Matrix3::operator/=(float constant) const {}

bool Matrix3::operator==(const Matrix3& other) {}
bool Matrix3::operator!=(const Matrix3& other) {}



// ============================================================
//  Matrix4
// ============================================================

Matrix4::Matrix4() {}

Matrix4::Matrix4(
    float r1c1, float r1c2, float r1c3, float r1c4,
    float r2c1, float r2c2, float r2c3, float r2c4,
    float r3c1, float r3c2, float r3c3, float r3c4,
    float r4c1, float r4c2, float r4c3, float r4c4
) {}

Matrix4::Matrix4(const std::array<std::array<float, 4>, 4>& data) {}

Matrix4::~Matrix4() {}

void Matrix4::transpose() {}
void Matrix4::invert() {}
float Matrix4::determinant() {}
Matrix4 Matrix4::get_transpose() {}
Matrix4 Matrix4::get_inverse() {}

std::array<Vec3, 4> Matrix4::to_vec3_array() {}
std::array<Vec3gl, 4> Matrix4::to_vec3gl_array() {}
std::array<Vec3_Sphere, 4> Matrix4::to_vec3_sphere_array() {}
std::array<Vec3gl_Sphere, 4> Matrix4::to_vec3gl_sphere_array() {}

std::array<float, 4>& Matrix4::operator[](int index) {}

Matrix4 Matrix4::operator+(const Matrix4& other) const {}
Matrix4 Matrix4::operator-(const Matrix4& other) const {}
Matrix4 Matrix4::operator*(float constant) const {}
Matrix4 Matrix4::operator/(float constant) const {}
Matrix4 Matrix4::operator-() const {} // Unitary negative

Matrix4& Matrix4::operator+=(const Matrix4& other) const {}
Matrix4& Matrix4::operator-=(const Matrix4& other) const {}
Matrix4& Matrix4::operator*=(float constant) const {}
Matrix4& Matrix4::operator/=(float constant) const {}

bool Matrix4::operator==(const Matrix4& other) {}
bool Matrix4::operator!=(const Matrix4& other) {}



// ============================================================
//  Functions
// ============================================================

void print_vec(Vec3 vec) {}
void print_vec(Vec3gl vec) {}
void print_vec(Vec3_Sphere vec) {}
void print_vec(Vec3gl_Sphere vec) {}

Vec3 cross(const Vec3& a, const Vec3& b) {}
Vec3gl cross(const Vec3gl& a, const Vec3gl& b) {}
Vec3_Sphere cross(const Vec3_Sphere& a, const Vec3_Sphere& b) {}
Vec3gl_Sphere cross(const Vec3gl_Sphere& a, const Vec3gl_Sphere& b) {}

Vec3 dot(const Vec3& a, const Vec3& b) {}
Vec3gl dot(const Vec3gl& a, const Vec3gl& b) {}
Vec3_Sphere dot(const Vec3_Sphere& a, const Vec3_Sphere& b) {}
Vec3gl_Sphere dot(const Vec3gl_Sphere& a, const Vec3gl_Sphere& b) {}

Matrix3 hadamard(const Matrix3& a, const Matrix3& b) {}
Matrix4 hadamard(const Matrix4& a, const Matrix4& b) {}

Matrix3 matmul(const Matrix3& a, const Matrix3& b) {}
Matrix4 matmul(const Matrix4& a, const Matrix4& b) {}
// AB (NOT BA)
Vec3 matmul(const Matrix3& a, const Vec3& b) {}
