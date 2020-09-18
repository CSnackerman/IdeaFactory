#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <vector>

#include <SDL2/SDL_render.h>

struct Point {
    std::pair <int, int> coords;
};

struct Line {
    std::pair <Point, Point> points;
};

typedef std::pair <SDL_Rect, SDL_Color> ColoredRect;
typedef std::pair <Line, SDL_Color> ColoredLine;

#endif