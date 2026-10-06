#pragma once
#include "macros.hpp"
#include "colors.hpp"
#include "shaders.hpp"

class Index_Buffer;
class Position_Buffer;
class Normal_Buffer;
class UV_Buffer;
class Color_Buffer;

class Mesh_Class;
class Mesh;

enum __Vertex_Attributes {
    POSITION = 0,
    UV = 1,
    NORMAL = 2,
    COLOR = 3
};


class Texture {

private:

    unsigned int id;
    byte* local_buffer;
    int width;
    int height;
    int BPP; // Bytes per pixel

public:

    Texture(const std::string& filepath);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    inline int get_width() const {
        return width;
    }

    inline int get_height() const {
        return height;
    }

};



class Index_Buffer {

private:

    unsigned int id;
    std::vector<unsigned int> data;

public:

    Index_Buffer();
    Index_Buffer(const std::vector<unsigned int>& indices);

    ~Index_Buffer();

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_count() const {
        return data.size();
    }

    inline void __link_to_mesh() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    }

};

class Position_Buffer {

private:

    unsigned int id;
    std::vector<float> data;

public:
    
    Position_Buffer();
    Position_Buffer(const std::vector<vec3>& positions);

    ~Position_Buffer();

    void __link_to_mesh();

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_count() const {
        return data.size()/3;
    }

};

class Normal_Buffer {

private:

    unsigned int id;
    std::vector<short> data; //! This MUST be normalized later

public:

    Normal_Buffer();
    Normal_Buffer(const std::vector<vec3>& normals);

    ~Normal_Buffer();

    void __link_to_mesh();

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_count() const {
        return data.size()/3;
    }

};

class UV_Buffer {

private:

    bool is_vec3;
    unsigned int id;
    std::vector<float> data;

public:

    UV_Buffer();
    UV_Buffer(const std::vector<vec2>& uv_coordinates);
    UV_Buffer(const std::vector<vec3>& uv_coordinates);

    ~UV_Buffer();

    void __link_to_mesh();

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_count() const {
        return data.size()/3;
    }

};

class Color_Buffer {

private:

    unsigned int id;
    std::vector<byte> data;

public:

    Color_Buffer();
    Color_Buffer(const std::vector<Color>& positions);

    ~Color_Buffer();

    void __link_to_mesh();

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_count() const {
        return data.size()/4;
    }

};



class Mesh_Class {

protected:

    unsigned int id;

    Position_Buffer pb;
    Normal_Buffer nb;
    Index_Buffer ib;

    Shader shader;

public:

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_elem_count() const {
        return ib.get_count();
    }

    inline void bind() const {
        glBindVertexArray(id);
        shader.bind();
    }

    inline void unbind() const {
        glBindVertexArray(0);
        shader.unbind();
    }

    inline void render() const {
        glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
    }

};

class Untextured_Mesh : public Mesh_Class {

private:

    Color_Buffer cb;

public:

    Untextured_Mesh(const Position_Buffer& pb, const Color_Buffer& cb, const Index_Buffer& ib, const Shader& shader);
    // TODO: Untextured_Mesh(Position_Buffer pb, Color_Buffer cb, Index_Buffer ib);
    ~Untextured_Mesh();

    void bind() const;
    void unbind() const;

    inline void render() const {
        glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
    }

};

class Monochrome_Mesh : public Mesh_Class {

public:

    Monochrome_Mesh(const Position_Buffer& pb, const Index_Buffer& ib, Color color);
    // TODO: Monochrome_Mesh(const Position_Buffer& pb, const Index_Buffer& ib, Color color, const Shader& shader);
    ~Monochrome_Mesh();

    inline void render() const {
        glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
    }

};

class Mesh : public Mesh_Class {

private:

    UV_Buffer uvb;

public:

    Mesh(const Position_Buffer& pb, const UV_Buffer& uvb, const Index_Buffer& ib, const Shader& shader);
    ~Mesh();

};