#include "RGB.h"
#include <iostream>

RGB::RGB() : r(0), g(0), b(0) {}

RGB::RGB(int r, int g, int b) {
    setR(r);
    setG(g);
    setB(b);
}

RGB::RGB(CuColour color) {
    setColour(color);
}

int RGB::getR() const { return r; }
int RGB::getG() const { return g; }
int RGB::getB() const { return b; }

unsigned long RGB::getColour() const {
    return ((unsigned long)r << 16) | ((unsigned long)g << 8) | (unsigned long)b;
}

void RGB::setR(int r) {
    if (r >= 0 && r <= 255) {
        this->r = r;
    }
}

void RGB::setG(int g) {
    if (g >= 0 && g <= 255) {
        this->g = g;
    }
}

void RGB::setB(int b) {
    if (b >= 0 && b <= 255) {
        this->b = b;
    }
}

void RGB::setColour(CuColour color) {
    b = (color & 0xFF);         
    g = (color >> 8) & 0xFF;   
    r = (color >> 16) & 0xFF;   
}

RGB RGB::WHITE() { return RGB(255, 255, 255); }
RGB RGB::BLACK() { return RGB(0, 0, 0); }
RGB RGB::RED() { return RGB(255, 0, 0); }
RGB RGB::GREEN() { return RGB(0, 255, 0); }
RGB RGB::BLUE() { return RGB(0, 0, 255); }
