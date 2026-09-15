#pragma once
#include "macros.hpp"

class Vec2 {

private:

    /* data */

public:

    float x;
    float y;

    Vec2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    // Return a null vector (0,0)
    Vec2() {
        this->x = 0.0f;
        this->y = 0.0f;
    }

    ~Vec2() {}

    float length() const {
        return sqrtf( (x * x) + (y * y) );
    }

    Vec2 normalize() const {
        float len = length();
        if (len > 0.0f) return {x / len, y / len};
        return NULL_VECTOR_2D;
    }

    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const {
        return {x - other.x, y - other.y};
    }

    Vec2 operator*(float constant) const {
        return {x * constant, y * constant};
    }

    Vec2 operator/(float constant) const {
        if (constant == 0.0f) ERROR("constant must be non-zero")
        return {x / constant, y / constant};
    }

    Vec2& operator+=(const Vec2& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vec2& operator*=(float constant) {
        this->x *= constant;
        this->y *= constant;
        return *this;
    }

    Vec2& operator/=(float constant) {
        if (constant == 0.0f) ERROR("constant must be non-zero")
        this->x /= constant;
        this->y /= constant;
        return *this;
    }

};

class Vec3 {

private:

    /* data */

public:

    float x;
    float y;
    float z;

    Vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Return a null vector (0,0,0)
    Vec3() {
        this->x = 0.0f;
        this->y = 0.0f;
        this->z = 0.0f;
    }

    ~Vec3() {}

    float length() const {
        return sqrtf( (x * x) + (y * y) + (z * z) );
    }

    Vec3 normalize() const {
        float len = length();
        if (len > 0.0f) return {x / len, y / len, z / len};
        return NULL_VECTOR_3D;
    }

    Vec3 to_spherical() const {
        float rho = length();
        return {
            rho,
            atan2f(y, x),
            acosf(z/rho)
        };
    }

    // X is right, Y is up and Z is Backwards (facing YOU)
    Vec3 to_opengl_coords() {
        return {
            x,
            z,
            -y
        };
    }

    Vec3 operator+(const Vec3& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vec3 operator-(const Vec3& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vec3 operator*(float constant) const {
        return {x * constant, y * constant, z * constant};
    }

    Vec3 operator/(float constant) const {
        if (constant == 0.0f) ERROR("constant must be non-zero")
        return {x / constant, y / constant, z / constant};
    }

    Vec3& operator+=(const Vec3& other) {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& other) {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Vec3& operator*=(float constant) {
        this->x *= constant;
        this->y *= constant;
        this->z *= constant;
        return *this;
    }

    Vec3& operator/=(float constant) {
        if (constant == 0.0f) ERROR("constant must be non-zero")
        this->x /= constant;
        this->y /= constant;
        this->z /= constant;
        return *this;
    }

    bool operator==(const Vec3& other) {
        return ( (x == other.x) && (y == other.y) && (z == other.z) );
    }

    // Unary sign for negative
    Vec3 operator-() const {
        float neg_x = x == 0.0f? x : -x;
        float neg_y = y == 0.0f? y : -y;
        float neg_z = z == 0.0f? z : -z;
        return {neg_x, neg_y, neg_z};
    }

};

class Vec_Polar {

private:

    float r;
    float theta;

public:

    Vec_Polar(float r, float theta) {
        this->r = r;
        this->theta = theta;
    }

    ~Vec_Polar() {}

    // Return a unit vector (1,0)
    Vec_Polar() {
        this->r = 0.0f;
        this->theta = 0.0f;
    }

    Vec2 to_cartesian() {

        return Vec2 (
            r * cosf(theta),
            r * sinf(theta)
        );

    }

};

class Vec_Sphere {

private:

    /* data */

public:

    float rho;
    float theta; // Degrees
    float phi;   // Degrees

    Vec_Sphere(float rho, float theta, float phi) {

        if (rho < 0.0f)
            ERROR("rho must be non-negative")

        this->rho = rho;
        this->theta = theta;
        this->phi = phi;

    }

    // Return a unit vector (1,0,0)
    Vec_Sphere() {
        this->rho = 1.0f;
        this->theta = 0.0f;
        this->phi = 0.0f;
    }

    ~Vec_Sphere() {}

    Vec3 to_cartesian() const {

        if (rho < 0.0f)
            ERROR("rho must be non-negative")

        return {
            rho * sinf(RADIANS(phi)) * cosf(RADIANS(theta)),
            rho * sinf(RADIANS(phi)) * sinf(RADIANS(theta)),
            rho * cosf(RADIANS(phi))
        };

    }

    Vec_Sphere operator+(const Vec_Sphere& other) const {
        return {rho + other.rho, theta + other.theta, phi + other.phi};
    }

    Vec_Sphere operator-(const Vec_Sphere& other) const {
        return {rho - other.rho, theta - other.theta, phi - other.phi};
    }

    Vec_Sphere operator*(float constant) const {
        return {rho * constant, theta, phi};
    }

    Vec_Sphere operator/(float constant) const {
        if (constant == 0.0f) ERROR("constant must be non-zero")
        return {rho / constant, theta, phi};
    }

    Vec_Sphere& operator+=(const Vec_Sphere& other) {
        this->rho += other.rho;
        this->theta += other.theta;
        this->phi += other.phi;
        return *this;
    }

    Vec_Sphere& operator-=(const Vec_Sphere& other) {
        this->rho -= other.rho;
        this->theta -= other.theta;
        this->phi -= other.phi;
        return *this;
    }

    Vec_Sphere& operator*=(float constant) {
        this->rho *= constant;
        this->theta *= constant;
        this->phi *= constant;
        return *this;
    }

    Vec_Sphere& operator/=(float constant) {
        if (constant == 0.0f) ERROR("constant must be non-zero")
        this->rho /= constant;
        return *this;
    }

};

Vec3 cross(const Vec3& a, const Vec3& b) {
    return {
        ( (a.y * b.z) - (a.z * b.y) ),
        ( (a.z * b.x) - (a.x * b.z) ),
        ( (a.x * b.y) - (a.y * b.x) )
    };
}

float dot(const Vec3& a, const Vec3& b) {
    return ( (a.x * b.x) + (a.y * b.y) + (a.z * b.z) );
}

void print_vec(const Vec2& vec) {
    printf("X = %.2f\n", vec.x);
    printf("Y = %.2f\n", vec.y);
}

void print_vec(const Vec3& vec) {
    printf("X = %.2f\n", vec.x);
    printf("Y = %.2f\n", vec.y);
    printf("Z = %.2f\n", vec.z);
}

void print_vec(const Vec_Sphere& vec) {
    printf("Rho = %.2f\n", vec.rho);
    printf("Theta = %.2f\n", vec.theta);
    printf("Phi = %.2f\n", vec.phi);
}

const Vec3 X_AXIS_3D = {1.0f, 0.0f, 0.0f};
const Vec3 Y_AXIS_3D = {0.0f, 1.0f, 0.0f};
const Vec3 Z_AXIS_3D = {0.0f, 0.0f, 1.0f};

const Vec3 ORIGIN_3D = {0.0f, 0.0f, 0.0f};