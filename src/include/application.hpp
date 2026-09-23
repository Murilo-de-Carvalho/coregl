#pragma once
#include "macros.hpp"

class Application {

private:

    GLint width;
    GLint height;
    std::string_view window_name;


public:

    // It is used all the time, better to just be public
    GLFWwindow* window;

    Application(const std::string_view window_name, const int width, const int height);
    ~Application();

    void init();

    GLint get_width();
    GLint get_height();

};

bool window_should_close(const Application& app);