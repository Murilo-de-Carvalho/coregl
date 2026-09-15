#pragma once
#include "macros.hpp"
#include "linalg.hpp"
#include "colors.hpp"
#include <vector>

/*

class Shape {

private:

    // data

public:

    Shape() {

    }

    ~Shape() {}

};

*/

// ================================
//             2D Shapes
// ================================

// Equilateral
class Triangle {

private:

    Vec2 pos = NULL_VECTOR_2D;
    float size; // Distance between vertices and pos

    float dx_v1_v2;
    float dy_v1_v2;

    //Vec2 v1 = NULL_VECTOR_2D; // Bottom left vertex
    //Vec2 v2 = NULL_VECTOR_2D; // Top middle vertex
    //Vec2 v3 = NULL_VECTOR_2D; // Bottom right vertex

    void calculate_vertices() {

        dx_v1_v2 = size * sinf(RADIANS(60.0f));
        dy_v1_v2 = size * cosf(RADIANS(60.0f));

        //v1 = Vec2(pos.x - dx_v1_v2, pos.y - dy_v1_v2);
        //v2 = Vec2(pos.x, pos.y + size);
        //v3 = Vec2(pos.x + dx_v1_v2, pos.y - dy_v1_v2);

    }

public:

    Triangle(const Vec2& pos, float size) {

        if (size < 0.0f)
            ERROR("size must be non-negative")

        this->pos = pos;
        this->size = size;
        calculate_vertices();

    }

    ~Triangle() {}

    void translate_by(const Vec2& delta_pos) {
        pos += delta_pos;
        calculate_vertices();
    }

    void increase_size(float delta_size) {

        if (size + delta_size < 0.0f)
            ERROR("delta_size must be greater or equal to -size")

        size += delta_size;
        calculate_vertices();

    }

    void set_pos(const Vec2& new_pos) {
        pos = new_pos;
        calculate_vertices();
    }

    void set_size(float new_size) {

        if (new_size < 0.0f)
            ERROR("new_size must be non-negative")

        size = new_size;
        calculate_vertices();

    }

    Vec2 get_pos() {
        return pos;
    }

    float get_size() {
        return size;
    }

    void draw(Color color) {

        apply_color(color);

        glBegin(GL_TRIANGLES);
            glVertex2f(pos.x - dx_v1_v2, pos.y - dy_v1_v2);
            glVertex2f(pos.x, pos.y + size);
            glVertex2f(pos.x + dx_v1_v2, pos.y - dy_v1_v2);
        glEnd();

        reset_color();

    }
};

class Square {

private:

    Vec2 pos = NULL_VECTOR_2D;
    float size;

public:

    Square(const Vec2& pos, float size) {

        if (size < 0.0f)
            ERROR("size must be non-negative")

        this->pos = pos;
        this->size = size;

    }

    ~Square() {}

    void translate_by(const Vec2& delta_pos) {
        pos += delta_pos;
    }

    void increase_size(float delta_size) {

        if (size + delta_size < 0.0f)
            ERROR("delta_size must be greater or equal to -size")

        size += delta_size;

    }

    void set_pos(const Vec2& new_pos) {
        pos = new_pos;
    }

    void set_size(float new_size) {

        if (new_size < 0.0f)
            ERROR("new_size must be non-negative")

        size = new_size;

    }

    Vec2 get_pos() {
        return pos;
    }

    float get_size() {
        return size;
    }

    void draw(Color color) {

        // Relative size
        float r_size = size/2.0f;

        apply_color(color);

        glBegin(GL_QUADS);
            glVertex2f(pos.x - r_size, pos.y - r_size); // Bottom left
            glVertex2f(pos.x - r_size, pos.y + r_size); // Top left
            glVertex2f(pos.x + r_size, pos.y + r_size); // Top right
            glVertex2f(pos.x + r_size, pos.y - r_size); // Bottom right
        glEnd();

        reset_color();

    }

};

class Rectangle {

private:

    Vec2 pos = NULL_VECTOR_2D;
    float size_x;
    float size_y;

public:

    Rectangle(const Vec2& pos, float size_x, float size_y) {

        if (size_x < 0.0f || size_y < 0.0f)
            ERROR("sizes must be non-negative")

        this->pos = pos;
        this->size_x = size_x;
        this->size_y = size_y;

    }

    ~Rectangle() {}

    void translate_by(const Vec2& delta_pos) {
        pos += delta_pos;
    }

    void increase_sizes(float delta_size_x, float delta_size_y) {

        if (delta_size_x < 0.0f || delta_size_y < 0.0f)
            ERROR("delta sizes must be greater or equal to -sizes, respectively")

        size_x = delta_size_x;
        size_y = delta_size_y;

    }

    void set_pos(const Vec2& new_pos) {
        pos = new_pos;
    }

    void set_sizes(float new_size_x, float new_size_y) {

        if (new_size_x < 0.0f || new_size_y < 0.0f)
            ERROR("new sizes must be non-negative")

        size_x = new_size_x;
        size_y = new_size_y;

    }

    Vec2 get_pos() {
        return pos;
    }

    Vec2 get_sizes() {
        return Vec2(size_x, size_y);
    }

    float get_size_x() {
        return size_x;
    }

    float get_size_y() {
        return size_x;
    }

    void draw(Color color) {

        // Relative sizes
        float r_size_x = size_x/2.0f;
        float r_size_y = size_y/2.0f;

        apply_color(color);

        glBegin(GL_QUADS);
            glVertex2f(pos.x - r_size_x, pos.y - r_size_y); // Bottom left
            glVertex2f(pos.x - r_size_x, pos.y + r_size_y); // Top left
            glVertex2f(pos.x + r_size_x, pos.y + r_size_y); // Top right
            glVertex2f(pos.x + r_size_x, pos.y - r_size_y); // Bottom right
        glEnd();

        reset_color();

    }

};

class Circle {

private:

    Vec2 pos = NULL_VECTOR_2D;
    float radius;

public:

    Circle(const Vec2& pos, float radius) {

        if (radius < 0.0f)
            ERROR("radius must be non-negative")

        this->pos = pos;
        this->radius = radius;

    }

    ~Circle() {}

    void translate_by(const Vec2& delta_pos) {
        pos += delta_pos;
    }

    void increase_radius(float delta_radius) {

        if (radius + delta_radius < 0.0f)
            ERROR("delta_radius must be greater or equal to -radius")

        radius += delta_radius;

    }

    void set_pos(const Vec2& new_pos) {
        pos = new_pos;
    }

    void set_radius(float new_radius) {

        if (new_radius < 0.0f)
            ERROR("new_radius must be non-negative")

        radius = new_radius;

    }

    Vec2 get_pos() {
        return pos;
    }

    float get_radius() {
        return radius;
    }

    void draw(Color color) {

        apply_color(color);

        glBegin(GL_TRIANGLE_FAN);

            for (int i = 0; i < 180; i++) {

                float theta = 2.0f * PI * (float)i / 180.0;

                float x = radius * cosf(theta);
                float y = radius * sinf(theta);

                glVertex2f(x + pos.x, y + pos.y);

            }

        glEnd();

        reset_color();

    }

};

class Elipsis {

private:

    Vec2 pos = NULL_VECTOR_2D;
    float radius_x;
    float radius_y;

public:

    Elipsis(const Vec2& pos, float radius_x, float radius_y) {

        if (radius_x < 0.0f || radius_y < 0.0f)
            ERROR("radii must be non-negative")

        this->pos = pos;
        this->radius_x = radius_x;
        this->radius_y = radius_y;

    }

    ~Elipsis() {}

    void translate_by(const Vec2& delta_pos) {
        pos += delta_pos;
    }

    void increase_radii(float delta_radius_x, float delta_radius_y) {

        if (delta_radius_x < 0.0f || delta_radius_y < 0.0f)
            ERROR("delta radii must be greater or equal to -radii, respectively")

        radius_x = delta_radius_x;
        radius_y = delta_radius_y;

    }

    void set_pos(const Vec2& new_pos) {
        pos = new_pos;
    }

    void set_radii(float new_radius_x, float new_radius_y) {

        if (new_radius_x < 0.0f || new_radius_y < 0.0f)
            ERROR("new radii must be non-negative")

        radius_x = new_radius_x;
        radius_y = new_radius_y;

    }

    Vec2 get_pos() {
        return pos;
    }

    Vec2 get_radius() {
        return Vec2(radius_x, radius_y);
    }

    float get_radius_x() {
        return radius_x;
    }

    float get_radius_y() {
        return radius_y;
    }

    void draw(Color color) {

        apply_color(color);

        glBegin(GL_TRIANGLE_FAN);

            for (int i = 0; i < 180; i++) {

                float theta = 2.0f * PI * (float)i / 180.0;

                float x = radius_x * cosf(theta);
                float y = radius_y * sinf(theta);

                glVertex2f(x + pos.x, y + pos.y);

            }

        glEnd();

        reset_color();

    }

};

// Generic 2d shapes
class Poly2D {

private:

    std::vector<Vec2> vertices;

public:

    Poly2D(const std::vector<Vec2>& vertices) {

        if (vertices.size() > 255)
            ERROR("Poly2D class cannot have more than 255 vertices")

        this->vertices = vertices;
    }

    ~Poly2D() {}

    void add_vertex(const Vec2& new_vertex) {

        if (vertices.size() == 255)
            ERROR("Cannot add new vertex, already at maximum vertex count")

        vertices.push_back(new_vertex);

    }

    void translate_vertices_by(const std::vector<Vec2>& delta_vertices) {

        if (delta_vertices.size() != vertices.size())
            ERROR("vector dimensions doesn't match")

        for (uint8_t i = 0; i < vertices.size(); i++)
            vertices[i] += delta_vertices[i];

    }

    void translate_vertex_by(uint8_t vertex_index, const Vec2& delta_vertex) {
        vertices.at(vertex_index) += delta_vertex;
    }

    void set_vertices(const std::vector<Vec2>& new_vertices) {

        if (new_vertices.size() > 255)
            ERROR("Poly2D class cannot have more than 255 vertices")

        this->vertices = new_vertices;

    }

    void set_vertex(uint8_t vertex_index, const Vec2& new_vertex) {
        vertices.at(vertex_index) = new_vertex;
    }

    uint8_t get_vertex_count() {
        return vertices.size();
    }

    Vec2 get_vertex(uint8_t vertex_index) {
        return vertices.at(vertex_index);
    }

    void draw(Color color) {

        apply_color(color);

        glBegin(GL_POLYGON);

            for (Vec2 vertex : vertices) {                
                glVertex2f(vertex.x, vertex.y);
            }

        glEnd();

        reset_color();

    }

};

// ================================
//             3D Shapes
// ================================

class Quad_Face {

private:

    Vec3 pos = NULL_VECTOR_3D;
    Vec3 normal = NULL_VECTOR_3D;
    float size;

public:

    Quad_Face(const Vec3& pos, const Vec3& normal, float size) {

        if (size < 0.0f)
            ERROR("size must be non-negative")

        this->pos = pos;
        //print_vec(pos);
        //print_vec(this->pos);
        //print_vec(normal);
        this->normal = normal.normalize();
        this->size = size;

    }

    // Returns a 1x1 face, centered at the origin and facing -Y
    Quad_Face() {
        this->pos = ORIGIN_3D;
        this->normal = -Y_AXIS_3D;
        this->size = 1.0f;
    }

    ~Quad_Face() {}

    Vec3 get_pos() const {
        return pos;
    }

    void draw(Color color) {

        // Relative size
        float r_size = size/2.0f;

        Vec3 initial_normal = Vec3(0.0f, -1.0f, 0.0f); // -Y-AXIS
        Vec3 rotation_vector = NULL_VECTOR_3D;
        float angle;

        bool are_normals_equal = (normal == initial_normal);
        bool are_normals_parallel = (normal == -initial_normal);

        // If facing Y-AXIS, just rotate the face by 180°
        if (are_normals_parallel) {
            rotation_vector = {0.0f, 1.0f, 0.0f}; // {0.0f, 0.0f, 1.0f} but in opengl coordinates
            angle = RADIANS(180.0f);
        }

        else if (!are_normals_equal) {
            rotation_vector = cross(initial_normal, normal).normalize().to_opengl_coords();
            angle = acosf(dot(initial_normal, normal));
        }

        Vec3 translated_pos = pos.to_opengl_coords();
        Vec3 translated_initial_normal = initial_normal.to_opengl_coords();

        apply_color(color);

        // Initialize the points at the origin, rotate if needed and then translate to pos
        glPushMatrix();

            glTranslatef(translated_pos.x, translated_pos.y, translated_pos.z);

            if (!are_normals_equal){
                glRotatef(DEGREES(angle), rotation_vector.x, rotation_vector.y, rotation_vector.z);
            }

            glBegin(GL_QUADS);

                // Normal gets rotated with glrotate, that's why this is the initial normal
                glNormal3f(translated_initial_normal.x, translated_initial_normal.y, translated_initial_normal.z);
                glVertex3f(0 - r_size, 0 - r_size, 0); // Bottom left
                glVertex3f(0 - r_size, 0 + r_size, 0); // Top left
                glVertex3f(0 + r_size, 0 + r_size, 0); // Top right
                glVertex3f(0 + r_size, 0 - r_size, 0); // Bottom right

            glEnd();
    
        glPopMatrix();

        reset_color();

    }

};

enum cube_faces {
    FRONT = 0,
    BACK,
    RIGHT,
    LEFT,
    UP,
    DOWN
};

class Cube {

private:

    Vec3 pos = NULL_VECTOR_3D;
    Quad_Face faces[6];
    float volume;

public:

    Cube(Vec3 pos, float volume) {

        float relative_volume = volume/2.0f;

        // Faces translate by half the volume in each direction
        // Quad_Face already handles the size, so it can be passed as it is
        this->faces[FRONT]  = {pos - Y_AXIS_3D * relative_volume, -Y_AXIS_3D, volume};
        this->faces[BACK]   = {pos + Y_AXIS_3D * relative_volume,  Y_AXIS_3D, volume};
        this->faces[RIGHT]  = {pos + X_AXIS_3D * relative_volume,  X_AXIS_3D, volume};
        this->faces[LEFT]   = {pos - X_AXIS_3D * relative_volume, -X_AXIS_3D, volume};
        this->faces[UP]     = {pos + Z_AXIS_3D * relative_volume,  Z_AXIS_3D, volume};
        this->faces[DOWN]   = {pos - Z_AXIS_3D * relative_volume, -Z_AXIS_3D, volume};

    }

    ~Cube() {}

    void draw() {

        for (uint8_t i = 0; i < 6; i++) {
            faces[i].draw(RED);
        }

    }

};