#ifndef INC_3D_SOLID_MAIN_H
#define INC_3D_SOLID_MAIN_H

#include <iostream>
#include <SDL.h>
#include "vec3f.h"

using namespace std;

void redraw(SDL_Surface *screen);

int showSDLError(const string &msg);

void putPixel(SDL_Surface *surface, int x, int y, uint8_t r, uint8_t g, uint8_t b);

void renderMesh(const SDL_Surface *screen);

struct Point {
    uint16_t x{0}, y{0};

    Point() = default;

    Point(uint16_t x, uint16_t y) : x(x), y(y) {}
};

#endif //INC_3D_SOLID_MAIN_H
