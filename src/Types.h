#ifndef TYPES_H
#define TYPES_H

#include <utility>

#include <SDL2/SDL_render.h>

struct Point {
private:
    std::pair <int, int> coords;

public:
    Point() = delete;

    Point(int x, int y) 
        : coords(std::pair<int, int>(x, y)) 
    {}

    Point(const Point &rhs) 
        : coords(std::pair<int, int>(rhs.coords.first, rhs.coords.second)) 
    {}

    void operator = (const Point &rhs) {
        this->coords.first = rhs.coords.first;
        this->coords.second = rhs.coords.second;
    }

    int x() { return coords.first; }
    int y() { return coords.second; }
};

struct Line {
    std::pair <Point, Point> points;
};

typedef std::pair <SDL_Rect, SDL_Color>     ColoredRect;
typedef std::pair <Line, SDL_Color>         ColoredLine;

#endif  