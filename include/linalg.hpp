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

    ~Vec2() {}

    float norm() {
        return sqrtf( (x * x) + (y * y) );
    }

    Vec2 operator+(const Vec2& other) {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other) {
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(float constant) {
        return Vec2(x * constant, y * constant);
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

    ~Vec3() {}

    float norm() {
        return sqrtf( (x * x) + (y * y) + (z * z) );
    }

    Vec3 operator+(const Vec3& other) {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

};

class Vec_Polar {

private:

    float theta;
    float r;

public:

    Vec_Polar(float theta, float r) {
        this->theta = theta;
        this->r = r;
    }

    ~Vec_Polar() {}

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
    float phi;
    float theta;

    Vec_Sphere(float rho, float phi, float theta) {
        this->rho = rho;
        this->phi = phi;
        this->theta = theta;
    }

    ~Vec_Sphere() {}

};