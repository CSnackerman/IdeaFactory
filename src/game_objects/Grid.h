#ifndef GRID_H
#define GRID_H

#include <random>

#include "../templates/GameObject.h"
#include "../Log.h"

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