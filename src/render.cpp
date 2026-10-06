#include "include/render.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"

// ============================================================
//  Index_Buffer
// ============================================================

Texture::Texture(const std::string& filepath) {

    glBindTexture(GL_TEXTURE_2D, 0);

    // OpenGL considers y=0 at the bottom while images understand y=0 at the top
    // That's why we're flipping vertically
    stbi_set_flip_vertically_on_load(true);
    local_buffer = stbi_load(filepath.c_str(), &width, &height, &BPP, 4);

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, local_buffer);

    glBindTexture(GL_TEXTURE_2D, 0);

    if (local_buffer)
        stbi_image_free(local_buffer);
}

Texture::~Texture() {
    glDeleteTextures(1, &id);
}



void Texture::bind(unsigned int slot) const {

    if (slot > 31)
        ERROR("slot must be between 0 and 31")

    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id);

}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}



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

void Position_Buffer::__link_to_mesh() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glEnableVertexAttribArray(__Vertex_Attributes::POSITION);
    glVertexAttribPointer(__Vertex_Attributes::POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*) 0);
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

void Normal_Buffer::__link_to_mesh() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glEnableVertexAttribArray(__Vertex_Attributes::NORMAL);
    glVertexAttribPointer(__Vertex_Attributes::NORMAL, 3, GL_SHORT, GL_TRUE, 3 * sizeof(short), (const void*) 0);
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

void UV_Buffer::__link_to_mesh() {

    glBindBuffer(GL_ARRAY_BUFFER, id);
    glEnableVertexAttribArray(__Vertex_Attributes::UV);

    if (is_vec3)
        glVertexAttribPointer(__Vertex_Attributes::UV, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*) 0);
    else
        glVertexAttribPointer(__Vertex_Attributes::UV, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*) 0);

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

void Color_Buffer::__link_to_mesh() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glEnableVertexAttribArray(__Vertex_Attributes::COLOR);
    glVertexAttribPointer(__Vertex_Attributes::COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, 3 * sizeof(byte), (const void*) 0);
}



// ============================================================
//  Untextured_Mesh
// ============================================================

Untextured_Mesh::Untextured_Mesh(const Position_Buffer& pb, const Color_Buffer& cb, const Index_Buffer& ib, const Shader& shader) {

    glBindVertexArray(0);

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    this->pb = pb;
    this->cb = cb;
    this->ib = ib;
    this->shader = shader;

    this->pb.__link_to_mesh();
    this->cb.__link_to_mesh();
    this->ib.__link_to_mesh();

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Untextured_Mesh::~Untextured_Mesh() {
    glDeleteVertexArrays(1, &id);
}



// ============================================================
//  Monochrome_Mesh
// ============================================================

Monochrome_Mesh::Monochrome_Mesh(const Position_Buffer& pb, const Index_Buffer& ib, Color color) {

    glBindVertexArray(0);

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    this->pb = pb;
    this->ib = ib;

    char vert_src[150] = "#version 330 core\n\nlayout(location = 0) in vec4 pos;\n\nvoid main() {\n\tgl_Position = pos;\n}\n";
    char frag_src[150];
    sprintf(frag_src, "#version 330 core\n\nout vec4 color_out;\n\nvoid main() {\n\tcolor_out = vec4(%.2f, %.2f, %.2f, %.2f);\n}\n", color.r/255.0, color.g/255.0, color.b/255.0, color.a/255.0);

    this->shader.impromptu(vert_src, frag_src);

    this->pb.__link_to_mesh();
    this->ib.__link_to_mesh();

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Monochrome_Mesh::~Monochrome_Mesh() {
    glDeleteVertexArrays(1, &id);
}



// ============================================================
//  Mesh
// ============================================================

Mesh::Mesh(const Position_Buffer& pb, const UV_Buffer& uvb, const Index_Buffer& ib, const Shader& shader) {

    glBindVertexArray(0);

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    this->pb = pb;
    this->ib = ib;
    this->uvb = uvb;
    this->shader = shader;

    this->pb.__link_to_mesh();
    this->uvb.__link_to_mesh();
    this->ib.__link_to_mesh();

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &id);
}