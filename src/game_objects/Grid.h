#ifndef GRID_H
#define GRID_H

#include <random>

#include "../templates/GameObject.h"
#include "../Log.h"
#include "../Debug.h"

class Grid : public GameObject{
public:
    enum GridType {
        ALTERNATING_GRID,
        LINE_GRID,
        RANDOM_GRID
    };

protected:
    int x, y, width, height, size, scale;
    int thickness;
    GridType type;
    SDL_Color primary, secondary;

    void initAlternatingGrid();
    void initRandomGrid();
    void initLineGrid();

    void printDebug(const std::string classname);

public:
    Grid (
        int x,
        int y, 
        int width,
        int height,
        int scale,
        GridType type
    );

private:
    void initGrid();
};

#endif