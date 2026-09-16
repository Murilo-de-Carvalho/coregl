#pragma once
#include "macros.hpp"
#include "linalg.hpp"
#include "colors.hpp"
#include "misc.hpp"

typedef std::vector<Vec3> Vertex_Buffer;
typedef std::vector<uint32_t> Index_Buffer;
typedef std::vector<Vec3> Normal_Buffer;

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

    Vec2 pos;
    float size; // Distance between vertices and pos

    float dx;
    float dy;

    //Vec2 v1; // Bottom left vertex
    //Vec2 v2; // Top middle vertex
    //Vec2 v3; // Bottom right vertex

    void calculate_vertices() {

        dx = size * sinf(RADIANS(60.0f));
        dy = size * cosf(RADIANS(60.0f));

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

    void render(Color color) const {

        apply_color(color);

        glBegin(GL_TRIANGLES);
            glVertex2f(pos.x - dx, pos.y - dy); // Left
            glVertex2f(pos.x + dx, pos.y - dy); // Right
            glVertex2f(pos.x, pos.y + size);    // Top
        glEnd();

        reset_color();

    }
};

class Square {

private:

    Vec2 pos;
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

    void render(Color color) const {

        // Relative size
        float r_size = size/2.0f;

        apply_color(color);

        glBegin(GL_QUADS);
            glVertex2f(pos.x - r_size, pos.y - r_size); // Bottom left
            glVertex2f(pos.x + r_size, pos.y - r_size); // Bottom right
            glVertex2f(pos.x + r_size, pos.y + r_size); // Top right
            glVertex2f(pos.x - r_size, pos.y + r_size); // Top left
        glEnd();

        reset_color();

    }

};

class Rectangle {

private:

    Vec2 pos;
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

    void render(Color color) const {

        // Relative sizes
        float r_size_x = size_x/2.0f;
        float r_size_y = size_y/2.0f;

        apply_color(color);

        glBegin(GL_QUADS);
            glVertex2f(pos.x - r_size_x, pos.y - r_size_y); // Bottom left
            glVertex2f(pos.x + r_size_x, pos.y - r_size_y); // Bottom right
            glVertex2f(pos.x + r_size_x, pos.y + r_size_y); // Top right
            glVertex2f(pos.x - r_size_x, pos.y + r_size_y); // Top left
        glEnd();

        reset_color();

    }

};

class Circle {

private:

    Vec2 pos;
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

    void render(Color color) const {

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

    Vec2 pos;
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

    void render(Color color) const {

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

    void render(Color color) const {

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

/* class Quad_Face {

private:

    Vec3 pos;
    Vec3 normal;
    float size;

public:

    Quad_Face(const Vec3& pos, const Vec3& normal, float size) {

        if (size < 0.0f)
            ERROR("size must be non-negative")

        this->pos = pos;
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

    void render(Color color) const {

        // Relative size
        float r_size = size/2.0f;

        Vec3 initial_normal = Vec3(0.0f, -1.0f, 0.0f); // -Y-AXIS
        Vec3 rotation_vector;
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

}; */

enum cube_faces {
    FRONT = 0,
    BACK,
    RIGHT,
    LEFT,
    UP,
    DOWN
};

class Tri {

private:

    Vec3 vertices[3];
    Vec3 normal;

public:

    Tri(Vec3 v1, Vec3 v2, Vec3 v3) {

        if ( (v1 == v2) || (v1 == v3) || (v2 == v3) )
            ERROR("All 3 vertices must be different for a Tri")

        vertices[0] = v1.to_opengl_coords();
        vertices[1] = v2.to_opengl_coords();
        vertices[2] = v3.to_opengl_coords();

        normal = cross(v2 - v1, v3 - v1).normalize().to_opengl_coords();

    }

    ~Tri() {}

    void render(Color color) const {

        apply_color(color);

        glBegin(GL_TRIANGLES);

            // Normal gets rotated with glrotate, that's why this is the initial normal
            glNormal3f(normal.x, normal.y, normal.z);
            glVertex3f(vertices[0].x, vertices[0].y, vertices[0].z); // Left
            glVertex3f(vertices[1].x, vertices[1].y, vertices[1].z); // Right
            glVertex3f(vertices[2].x, vertices[2].y, vertices[2].z); // Top

        glEnd();

        reset_color();

    }

};

/* class Cube {

private:

    Vec3 pos;
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

    void render() {

        for (uint8_t i = 0; i < 6; i++) {
            faces[i].render(RED);
        }

    }

}; */

class Vertex {

private:

    

public:

    Vec3 pos;
    Vec2 texture;
    Vec3 normal;

    Vertex(const Vec3& pos, const Vec2& texture, const Vec3& normal) {
        this->pos = pos;
        this->texture = texture;
        this->normal = normal;
    }

    ~Vertex() {}

};

class Model {

private:

    Vertex_Buffer vb;
    Index_Buffer ibv;
    Normal_Buffer nb;
    Index_Buffer ibn;
    std::vector<Vertex> vertices;

    Vec3 pos;
    //std::vector<Vec3> vertices;

    void translate_buffers() {

        for (uint32_t i = 0; i < vb.size(); i++) {
            vb[i] += pos;
            vb[i] = vb[i].to_opengl_coords();
            nb[i] = nb[i].to_opengl_coords();
        }

    }

    void make_obj_mesh(const char* obj_filename) {

        std::vector<std::string> tokens;

        std::vector<Vec3> v;
        std::vector<Vec2> vt;
        std::vector<Vec3> vn;
        std::vector<Vertex> vertices;
        Index_Buffer ib;

        size_t vertex_count = 0;
        size_t texture_count = 0;
        size_t normal_count = 0;
        size_t tri_count = 0;

        std::string line;
        //std::vector<std::string> face_specs;

        std::ifstream file;

        /* while ( std::getline(file, line) ) {

            tokens = split(line, " ");

            if ( tokens.at(0).compare("#") == 0 ) {

                if (tokens.at(0).compare("#Vertex") == 0) {
                    this->vb.reserve(std::stoi(tokens.at(2)));
                    this->ibv.reserve(std::stoi(tokens.at(2)));
                    this->ibn.reserve(std::stoi(tokens.at(2)));
                }

                if (tokens.at(0).compare("#Face") == 0) {
                    this->vb.reserve(std::stoi(tokens.at(2)));
                }

            }

            else if (tokens.at(0).compare("v") == 0) {

                this->vb.push_back({
                    std::stof(tokens.at(1)),
                    std::stof(tokens.at(2)),
                    std::stof(tokens.at(3))
                });

            }

            else if (tokens.at(0).compare("vn") == 0) {

                this->nb.push_back({
                    std::stof(tokens.at(1)),
                    std::stof(tokens.at(2)),
                    std::stof(tokens.at(3))
                });

            }

            else if (tokens.at(0).compare("f") == 0) {

                face_specs = split(tokens.at(1), "/");
                this->ibv.push_back(std::stoi(face_specs.at(0)));
                this->ibn.push_back(std::stoi(face_specs.at(2)));

                face_specs = split(tokens.at(2), "/");
                this->ibv.push_back(std::stoi(face_specs.at(0)));
                this->ibn.push_back(std::stoi(face_specs.at(2)));

                face_specs = split(tokens.at(3), "/");
                this->ibv.push_back(std::stoi(face_specs.at(0)));
                this->ibn.push_back(std::stoi(face_specs.at(2)));

                if (tokens.size() == 5) {
                    face_specs = split(tokens.at(1), "/");
                    this->ibv.push_back(std::stoi(face_specs.at(0)));
                    this->ibn.push_back(std::stoi(face_specs.at(2)));

                    face_specs = split(tokens.at(2), "/");
                    this->ibv.push_back(std::stoi(face_specs.at(0)));
                    this->ibn.push_back(std::stoi(face_specs.at(2)));

                    face_specs = split(tokens.at(4), "/");
                    this->ibv.push_back(std::stoi(face_specs.at(0)));
                    this->ibn.push_back(std::stoi(face_specs.at(2)));
                }

            }

        } */

        file.open(obj_filename);
        while (std::getline(file, line)) {

            tokens = split(line, " ");


            if ( tokens[0].compare("v") == 0 ) {
                ++vertex_count;
            }

            else if ( tokens[0].compare("vt") == 0 ) {
                ++texture_count;
            }

            else if ( tokens[0].compare("vn") == 0 ) {
                ++normal_count;
            }

            else if ( tokens[0].compare("f") == 0 ) {
                // Counting the 'f'if there is 4 tokens (3 coords) return 1 tri
                // If 5 (4 coords) returns 2 and so on
                tri_count += tokens.size() - 3;
            }

        }
        file.close();

        v.reserve(vertex_count);
        vt.reserve(texture_count);
        vn.reserve(normal_count);
        // tri * 3 vertex * 3 floats for pos * 2 floats for texture * 3 floats for normal
        vertices.reserve(tri_count * 3 * 3 * 2 * 3);
        ib.reserve(tri_count);

        file.open(obj_filename);
        while (std::getline(file, line)) {

            tokens = split(line, " ");

            if ( !(tokens[0].compare("v")) ) {
                v.push_back(read_vec3(tokens));
            }

            else if ( !(tokens[0].compare("vt")) ) {
                vt.push_back(read_vec2(tokens));
            }

            else if ( !(tokens[0].compare("vn")) ) {
                vn.push_back(read_vec3(tokens));
            }

            else if ( !(tokens[0].compare("f")) ) {
                read_face(tokens, v, vt, vn, vertices);
            }

        }
        file.close();

        printf("Loaded %s\n", obj_filename);
        printf("\tVertex count: %ld\n", v.size());
        printf("\tVertex count: %ld\n", vertices.size());
        printf("\tTri count: %ld\n", ib.capacity());
        printf("\tTexture coords: %ld\n", vt.size());
        printf("\tNormal count: %ld\n", vn.size());

        this->vertices = vertices;

    }

    Vec2 read_vec2(const std::vector<std::string>& tokens) const {
        return {
            std::stof(tokens[1]),
            std::stof(tokens[2])
        };
    }

    Vec3 read_vec3(const std::vector<std::string>& tokens) const {
        return {
            std::stof(tokens[1]),
            std::stof(tokens[2]),
            std::stof(tokens[3])
        };
    }

    void read_face(
        const std::vector<std::string>& tokens,
        const std::vector<Vec3>& v,
        const std::vector<Vec2>& vt,
        const std::vector<Vec3>& vn,
        std::vector<Vertex>& vertices
        //Index_Buffer ib
        //std::vector<Tri>& tris
    ) {

      size_t tri_count = tokens.size() - 3;

      for (size_t i = 0; i < tri_count; i++) {
        get_face_corner(tokens[1], v, vt, vn, vertices);
        get_face_corner(tokens[2 + i], v, vt, vn, vertices);
        get_face_corner(tokens[3 + i], v, vt, vn, vertices);
      }

    }

    void get_face_corner(
        const std::string& face_description,
        const std::vector<Vec3>& v,
        const std::vector<Vec2>& vt,
        const std::vector<Vec3>& vn,
        std::vector<Vertex>& vertices
    ) {

        std::vector<std::string> v_vt_vn = split(face_description, "/");

        Vec3 pos = v[std::stol(v_vt_vn[0]) - 1];
        Vec2 tex = vt[std::stol(v_vt_vn[1]) - 1];
        Vec3 normal = vn[std::stol(v_vt_vn[2]) - 1];

        vertices.push_back({
            pos,
            tex,
            normal
        });

    }

public:

    Model(Vec3 pos, const Vertex_Buffer& vb, const Index_Buffer& ibv, const Vertex_Buffer& nb) {

        if (vb.size() == 0 || ibv.size() == 0 || nb.size() == 0)
            ERROR("Both buffers must not be empty")

        if (vb.size() != nb.size())
            ERROR("Vertex_Buffer size must match Normal_Buffer size")

        // 3 because we're in 3D
        if (ibv.size() % 3 != 0)
            ERROR("Index_Buffer size must be a multiple of 3")

        this->pos = pos;
        this->vb = vb;
        this->ibv = ibv;
        this->nb = nb;

        translate_buffers();

    }

    Model(const char* obj_filename) {

        make_obj_mesh(obj_filename);

    }
 
    ~Model() {}

    /* void render(Color color) const {

        apply_color(color);

        for (uint32_t i = 0; i < ibv.size(); i+=3) {

            //if (nb.size() > 0)

            glBegin(GL_TRIANGLES);

                if (nb.size() > 0){
                    Vec3 tri_normal = ( ( nb[ibn[i]] + nb[ibn[i+1]] + nb[ibn[i+2]] ) / 3 ).normalize();
                    glNormal3f(tri_normal.x, tri_normal.y, tri_normal.z);
                }
                glVertex3f(vb[ibv[i]].x, vb[ibv[i]].y, vb[ibv[i]].z);       // Left
                glVertex3f(vb[ibv[i+1]].x, vb[ibv[i+1]].y, vb[ibv[i+1]].z); // Right
                glVertex3f(vb[ibv[i+2]].x, vb[ibv[i+2]].y, vb[ibv[i+2]].z); // Top

            glEnd();

        }

        reset_color();

    } */

    void render(Color color) const {

        apply_color(color);

        for (uint32_t i = 0; i < vertices.size(); i+=3) {

            //if (nb.size() > 0)

            glBegin(GL_TRIANGLES);

                if (nb.size() == 0){
                    Vec3 tri_normal = ( ( vertices[i].normal + vertices[i+1].normal + vertices[i+2].normal ) / 3 ).normalize();
                    glNormal3f(tri_normal.x, tri_normal.y, tri_normal.z);
                }
                glVertex3f(vertices[i].pos.x, vertices[i].pos.y, vertices[i].pos.z);       // Left
                glVertex3f(vertices[i+1].pos.x, vertices[i+1].pos.y, vertices[i+1].pos.z); // Right
                glVertex3f(vertices[i+2].pos.x, vertices[i+2].pos.y, vertices[i+2].pos.z); // Top

            glEnd();

        }

        reset_color();

    }

};