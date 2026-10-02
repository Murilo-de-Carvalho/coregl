#include "include/render.hpp"

enum Vertex_Attributes {
    POSITION = 0,
    COLOR,
    NORMAL,
    UV
};

// ============================================================
//  Index_Buffer
// ============================================================

Index_Buffer::Index_Buffer() {
    id = 0;
}

Index_Buffer::Index_Buffer(const std::vector<unsigned int>& indices) {

    glBindVertexArray(0);

    // Copying
    data = std::vector<unsigned int>(indices);

    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);

    // Fill the buffer with data, specifying the type of the buffer,
    // how many BYTES is the data, the data pointer and the usage of the data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

Index_Buffer::~Index_Buffer() {
    glDeleteBuffers(1, &id);
}



// ============================================================
//  Position_Buffer
// ============================================================

Position_Buffer::Position_Buffer() {
    this->id = 0;
}

Position_Buffer::Position_Buffer(const std::vector<vec3> &positions) {

    glBindVertexArray(0);

    size_t size = positions.size();

    if (size > SIZE_MAX/3)
        ERROR("Size of positions is too big")

    data.reserve(size * 3);

    for (size_t i = 0; i < size; i++) {
        data.push_back(positions[i].x);
        data.push_back(positions[i].y);
        data.push_back(positions[i].z);
    }

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Position_Buffer::~Position_Buffer() {
    glDeleteBuffers(1, &id);
}



// ============================================================
//  Normal_Buffer
// ============================================================

Normal_Buffer::Normal_Buffer() {
    this->id = 0;
}

Normal_Buffer::Normal_Buffer(const std::vector<vec3> &normals) {

    glBindVertexArray(0);

    size_t size = normals.size();

    if (size > SIZE_MAX/3)
        ERROR("Size of normals is too big")

    data.reserve(size * 3);

    for (size_t i = 0; i < size; i++) {
        data.push_back(normals[i].x * SHRT_MAX);
        data.push_back(normals[i].y * SHRT_MAX);
        data.push_back(normals[i].z * SHRT_MAX);
    }

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(short) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Normal_Buffer::~Normal_Buffer() {
    glDeleteBuffers(1, &id);
}



// ============================================================
//  UV_Buffer
// ============================================================

UV_Buffer::UV_Buffer() {
    this->id = 0;
}

UV_Buffer::UV_Buffer(const std::vector<vec2> &uv_coordinates) {

    glBindVertexArray(0);

    size_t size = uv_coordinates.size();

    if (size > SIZE_MAX/2)
        ERROR("Size of uv_coordinates is too big")

    data.reserve(size * 2);
    is_vec3 = false;

    for (size_t i = 0; i < size; i++) {
        data.push_back(uv_coordinates[i].x);
        data.push_back(uv_coordinates[i].y);
    }

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

UV_Buffer::UV_Buffer(const std::vector<vec3> &uv_coordinates) {

    glBindVertexArray(0);

    size_t size = uv_coordinates.size();

    if (size > SIZE_MAX/3)
        ERROR("Size of uv_coordinates is too big")

    data.reserve(size * 3);
    is_vec3 = true;

    for (size_t i = 0; i < size; i++) {
        data.push_back(uv_coordinates[i].x);
        data.push_back(uv_coordinates[i].y);
        data.push_back(uv_coordinates[i].z); 
    }

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

UV_Buffer::~UV_Buffer() {
    glDeleteBuffers(1, &id);
}



// ============================================================
//  Color_Buffer
// ============================================================

Color_Buffer::Color_Buffer() {
    this->id = 0;
}

Color_Buffer::Color_Buffer(const std::vector<Color> &colors) {

    glBindVertexArray(0);

    size_t size = colors.size();

    if (size > SIZE_MAX/4)
        ERROR("Size of colors is too big")

    data.reserve(size * 4);

    for (size_t i = 0; i < size; i++) {
        data.push_back(colors[i].r);
        data.push_back(colors[i].g);
        data.push_back(colors[i].b);
        data.push_back(colors[i].a);
    }

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(byte) * data.size(), data.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Color_Buffer::~Color_Buffer() {
    glDeleteBuffers(1, &id);
}



// ============================================================
//  Untextured_Mesh
// ============================================================

Untextured_Mesh::Untextured_Mesh(Position_Buffer pb, Color_Buffer cb, Index_Buffer ib, Shader shader) {

    glBindVertexArray(0);

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    this->pb = pb;
    this->cb = cb;
    this->ib = ib;
    this->shader = shader;

    
    glBindBuffer(GL_ARRAY_BUFFER, pb.get_id());
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*) 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, cb.get_id());
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 4 * sizeof(byte), (const void*) 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib.get_id());
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    use_shader(this->shader);

}

Untextured_Mesh::~Untextured_Mesh() {
    glDeleteVertexArrays(1, &id);
}



void Untextured_Mesh::bind() {
    glBindVertexArray(id);
    //use_shader(shader);
}

void Untextured_Mesh::unbind() {
    glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0); // Probably not necessary but jsut to be certain
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // Probably not necessary but jsut to be certain
    clear_shader();
}
