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

    ~Vec2() {
    }

    float norm() {
        return sqrtf( (this->x * this->x) + (this->y * this->y) );
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

    ~Vec3() {
    }

    float norm() {
        return sqrtf( (this->x * this->x) + (this->y * this->y) + (this->z * this->z) );
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

    ~Vec_Sphere() {
    }

};