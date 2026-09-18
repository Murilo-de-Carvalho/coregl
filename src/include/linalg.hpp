#pragma once
#include "macros.hpp"

struct Vec3;
struct Vec3gl;
struct Vec3_Sphere;
struct Vec3gl_Sphere;

class Matrix3;
class Matrix4;

struct Vec3 {

    float x;
    float y;
    float z;

    Vec3(); // Default constructor
    Vec3(float x, float y, float z);
    ~Vec3();

    float length() const;
    Vec3 normalize();

    Vec3gl to_vec3gl() const;
    Vec3_Sphere to_vec3_sphere() const;
    Vec3gl_Sphere to_vec3gl_sphere() const;

    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator*(float constant) const;
    Vec3 operator/(float constant) const;
    Vec3 operator-() const; // Unitary negative

    Vec3& operator+=(const Vec3& other);
    Vec3& operator-=(const Vec3& other);
    Vec3& operator*=(float constant);
    Vec3& operator/=(float constant);

    bool operator==(const Vec3& other) const;
    bool operator!=(const Vec3& other) const;

};

struct Vec3gl {

    float x;
    float y;
    float z;

    Vec3gl(); // Default constructor
    Vec3gl(float x, float y, float z);
    ~Vec3gl();

    float length() const;
    Vec3gl normalize();

    Vec3 to_vec3() const;
    Vec3_Sphere to_vec3_sphere() const;
    Vec3gl_Sphere to_vec3gl_sphere() const;

    Vec3gl operator+(const Vec3gl& other) const;
    Vec3gl operator-(const Vec3gl& other) const;
    Vec3gl operator*(float constant) const;
    Vec3gl operator/(float constant) const;
    Vec3gl operator-() const; // Unitary negative

    Vec3gl& operator+=(const Vec3gl& other);
    Vec3gl& operator-=(const Vec3gl& other);
    Vec3gl& operator*=(float constant);
    Vec3gl& operator/=(float constant);

    bool operator==(const Vec3gl& other) const;
    bool operator!=(const Vec3gl& other) const;

};

struct Vec3_Sphere {

    float rho;
    float theta;
    float phi;

    Vec3_Sphere(); // Default constructor
    Vec3_Sphere(float rho, float theta, float phi);
    ~Vec3_Sphere();

    float length() const;
    Vec3_Sphere normalize();

    Vec3 to_vec3() const;
    Vec3gl to_vec3gl() const;
    Vec3gl_Sphere to_vec3gl_sphere() const;

    Vec3_Sphere operator+(const Vec3_Sphere& other) const;
    Vec3_Sphere operator-(const Vec3_Sphere& other) const;
    Vec3_Sphere operator*(float constant) const;
    Vec3_Sphere operator/(float constant) const;
    Vec3_Sphere operator-() const; // Unitary negative

    Vec3_Sphere& operator+=(const Vec3_Sphere& other);
    Vec3_Sphere& operator-=(const Vec3_Sphere& other);
    Vec3_Sphere& operator*=(float constant);
    Vec3_Sphere& operator/=(float constant);

    bool operator==(const Vec3_Sphere& other) const;
    bool operator!=(const Vec3_Sphere& other) const;

};

struct Vec3gl_Sphere {

    float rho;
    float theta;
    float phi;

    Vec3gl_Sphere(); // Default constructor
    Vec3gl_Sphere(float rho, float theta, float phi);
    ~Vec3gl_Sphere();

    float length() const;
    Vec3gl_Sphere normalize();

    Vec3 to_vec3() const;
    Vec3gl to_vec3gl() const;
    Vec3_Sphere to_vec3_sphere() const;

    Vec3gl_Sphere operator+(const Vec3gl_Sphere& other) const;
    Vec3gl_Sphere operator-(const Vec3gl_Sphere& other) const;
    Vec3gl_Sphere operator*(float constant) const;
    Vec3gl_Sphere operator/(float constant) const;
    Vec3gl_Sphere operator-() const; // Unitary negative

    Vec3gl_Sphere& operator+=(const Vec3gl_Sphere& other);
    Vec3gl_Sphere& operator-=(const Vec3gl_Sphere& other);
    Vec3gl_Sphere& operator*=(float constant);
    Vec3gl_Sphere& operator/=(float constant);

    bool operator==(const Vec3gl_Sphere& other) const;
    bool operator!=(const Vec3gl_Sphere& other) const;

};


class Matrix3 {

private:

    float det;

    // Boils down to "float data[3][3]", but with more security
    std::array<std::array<float, 3>, 3> data;

public:

    Matrix3(); // Default constructor

    Matrix3(
        float r1c1, float r1c2, float r1c3,
        float r2c1, float r2c2, float r2c3,
        float r3c1, float r3c2, float r3c3
    );

    Matrix3(const std::array<std::array<float, 3>, 3>& data);
    Matrix3(const Vec3& row_1, const Vec3& row_2, const Vec3& row_3);
    Matrix3(const Vec3& column_1, const Vec3& column_2, const Vec3& column_3);

    ~Matrix3();

    void transpose();
    void invert();
    float determinant();
    Matrix3 get_transpose() const;
    Matrix3 get_inverse() const;

    std::array<Vec3, 3> to_vec3_array() const;
    std::array<Vec3gl, 3> to_vec3gl_array() const;
    std::array<Vec3_Sphere, 3> to_vec3_sphere_array() const;
    std::array<Vec3gl_Sphere, 3> to_vec3gl_sphere_array() const;

    std::array<float, 3>& operator[](int index);

    Matrix3 operator+(const Matrix3& other) const;
    Matrix3 operator-(const Matrix3& other) const;
    Matrix3 operator*(float constant) const;
    Matrix3 operator/(float constant) const;
    Matrix3 operator-() const; // Unitary negative

    Matrix3& operator+=(const Matrix3& other);
    Matrix3& operator-=(const Matrix3& other);
    Matrix3& operator*=(float constant);
    Matrix3& operator/=(float constant);

    bool operator==(const Matrix3& other) const;
    bool operator!=(const Matrix3& other) const;

};

class Matrix4 {

private:

    float det;

    // Boils down to "float data[4][4]", but with more security
    std::array<std::array<float, 4>, 4> data;

public:

    Matrix4(); // Default constructor

    Matrix4(
        float r1c1, float r1c2, float r1c3, float r1c4,
        float r2c1, float r2c2, float r2c3, float r2c4,
        float r3c1, float r3c2, float r3c3, float r3c4,
        float r4c1, float r4c2, float r4c3, float r4c4
    );

    Matrix4(const std::array<std::array<float, 4>, 4>& data);

    ~Matrix4();

    void transpose();
    void invert();
    float determinant();
    Matrix4 get_transpose() const;
    Matrix4 get_inverse() const;

    std::array<Vec3, 4> to_vec3_array() const;
    std::array<Vec3gl, 4> to_vec3gl_array() const;
    std::array<Vec3_Sphere, 4> to_vec3_sphere_array() const;
    std::array<Vec3gl_Sphere, 4> to_vec3gl_sphere_array() const;

    std::array<float, 4>& operator[](int index);

    Matrix4 operator+(const Matrix4& other) const;
    Matrix4 operator-(const Matrix4& other) const;
    Matrix4 operator*(float constant) const;
    Matrix4 operator/(float constant) const;
    Matrix4 operator-() const; // Unitary negative

    Matrix4& operator+=(const Matrix4& other);
    Matrix4& operator-=(const Matrix4& other);
    Matrix4& operator*=(float constant);
    Matrix4& operator/=(float constant);

    bool operator==(const Matrix4& other) const;
    bool operator!=(const Matrix4& other) const;

};

void print_vec(Vec3 vec);
void print_vec(Vec3gl vec);
void print_vec(Vec3_Sphere vec);
void print_vec(Vec3gl_Sphere vec);

void print_matrix(Matrix3 mat);
void print_matrix(Matrix4 mat);

Vec3 cross(const Vec3& a, const Vec3& b);
Vec3gl cross(const Vec3gl& a, const Vec3gl& b);
Vec3_Sphere cross(const Vec3_Sphere& a, const Vec3_Sphere& b);
Vec3gl_Sphere cross(const Vec3gl_Sphere& a, const Vec3gl_Sphere& b);

Vec3 dot(const Vec3& a, const Vec3& b);
Vec3gl dot(const Vec3gl& a, const Vec3gl& b);
Vec3_Sphere dot(const Vec3_Sphere& a, const Vec3_Sphere& b);
Vec3gl_Sphere dot(const Vec3gl_Sphere& a, const Vec3gl_Sphere& b);

Matrix3 hadamard(const Matrix3& a, const Matrix3& b);
Matrix4 hadamard(const Matrix4& a, const Matrix4& b);

Matrix3 matmul(const Matrix3& a, const Matrix3& b);
Matrix4 matmul(const Matrix4& a, const Matrix4& b);
// AB (NOT BA)
Vec3 matmul(const Matrix3& a, const Vec3& b);