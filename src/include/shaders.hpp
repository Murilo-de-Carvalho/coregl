#pragma once
#include "macros.hpp"

class Shader {

private:

    unsigned int id;

    std::string read_file(const std::string& path);

    unsigned int compile(unsigned int type, const std::string& src);

public:

    Shader();
    Shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
    ~Shader();

    inline unsigned int get_id() {
        return id;
    }

};

// Wrapper for glUseProgram()
inline void use_shader(Shader shader) {
    glUseProgram(shader.get_id());
}

// Also a wrapper for glUseProgram()
// Just binds a "nothing" shader
inline void clear_shader() {
    glUseProgram(0);
}