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

};

class Position_Buffer {

private:

    unsigned int id;
    std::vector<float> data;

public:
    
    Position_Buffer();
    Position_Buffer(const std::vector<vec3>& positions);

    ~Position_Buffer();

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

    virtual void bind() {}
    virtual void unbind() {}

    virtual inline void render() {}

    inline unsigned int get_id() const {
        return id;
    }

    inline size_t get_elem_count() const {
        return ib.get_count();
    }

};

class Untextured_Mesh : public Mesh_Class {

private:

    Color_Buffer cb;

public:

    Untextured_Mesh(Position_Buffer pb, Color_Buffer cb, Index_Buffer ib, Shader shader);
    // TODO: Untextured_Mesh(Position_Buffer pb, Color_Buffer cb, Index_Buffer ib);
    ~Untextured_Mesh();

    void bind();
    void unbind();

    inline void render() {
        glDrawElements(GL_TRIANGLES, ib.get_count(), GL_UNSIGNED_INT, nullptr);
    }

};