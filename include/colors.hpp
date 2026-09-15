#pragma once
#include "macros.hpp"

class Color {

private:
    /* data */
public:

    byte r;
    byte g;
    byte b;
    byte a;

    Color(byte red, byte green, byte blue, byte alpha) {
        this->r = red;
        this->g = green;
        this->b = blue;
        this->a = alpha;
    }

    ~Color() {}

};

const Color RED     =  {219, 0,   0,   255};
const Color GREEN   =  {0,   146, 62,  255};
const Color BLUE    =  {1,   33,  105, 255};

const Color YELLOW  =  {248, 193, 0,   255};
const Color CYAN    =  {19,  218, 233, 255};
const Color MAGENTA =  {250, 45,  208, 255};

const Color PURPLE  =  {174, 55,  255, 255};
const Color ORANGE  =  {255, 124, 5,   255};
const Color GREY    =  {169, 169, 169, 255};

void apply_color(Color color) {
    glColor4ub(color.r, color.g, color.b, color.a);
}

void reset_color() {
    glColor4ub(255, 0, 255, 255); // Classic "I fucked up" magenta
}