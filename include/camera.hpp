#pragma once
#include "macros.hpp"

class Camera_Orbital {

private:

    Vec_Sphere pos = NULL_VECTOR_3D;
    Vec3 target = NULL_VECTOR_3D;
    Vec3 up = NULL_VECTOR_3D;

public:

    Camera_Orbital(const Vec3& pos, const Vec3& target, const Vec3& up) {

        // TODO: Fix this
        float rho = pos.length();
        if (rho < 0.01f)
            ERROR("Length of pos has to be bigger than 0.01f")

        this->pos = {
            rho,
            DEGREES(atan2f(pos.y, pos.x)),
            DEGREES(acosf(pos.z/rho))
        };

        this->target = target;
        this->up = up;

    }

    ~Camera_Orbital() {}

    void rotate_horizontal(float degrees) {

        pos.theta += degrees;

        if (pos.theta >= 360.0f || pos.theta <= -360.0f)
            pos.theta = fmodf(pos.theta, 360.0f);

    }

    void rotate_vertical(float degrees) {

        // phi increases from top to bottom, just compensating for that
        pos.phi -= degrees;

        if (pos.phi - degrees >= 180.0f)
            pos.phi = 180.0f;

        else if (pos.phi - degrees <= 0.0000001f)
            pos.phi = 0.0000001f;

    }

    void increase_distance(float delta_distance) {

        if (pos.rho + delta_distance < 0.0f)
            ERROR("delta_distance must be greate or equal to -distance")

        pos.rho += delta_distance;

    }

    Vec3 get_pos() const {
        return pos.to_cartesian();
    }

    Vec3 get_target() const {
        return target;
    }

    float get_distance() const {
        return pos.rho;
    }

};