#ifndef GRID_H
#define GRID_H

#include <random>

#include "../templates/GameObject.h"

class Grid : public GameObject{
private:
    SDL_Color primary, secondary;
    int x, y, width, height, size, scale;
    int thickness;

    void generateAlternatingGrid();
    void generateRandomGrid();
    void generateLineGrid();
    
public:
    enum GridType {
        RANDOM_GRID,
        ALTERNATING_GRID,
        LINE_GRID
    };

    Grid(
        int x,
        int y, 
        int width,
        int height,
        int scale,
        GridType type
    );
};

#endif