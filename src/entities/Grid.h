#ifndef GRID_H
#define GRID_H

#include <random>

#include "../templates/template_entity.h"
#include "../Log.h"
#include "../Debug.h"

class Grid : public Template_Entity {
public:
    enum GridType {
        ALTERNATING_GRID,
        LINE_GRID,
        RANDOM_GRID
    };

protected:
    int x, y, width, height, scale;
    int thickness;
    GridType type;
    SDL_Color primary, secondary;

    void initGrid();
    void initAlternatingGrid();
    void initRandomGrid();
    void initLineGrid();

    void printDebug(const std::string classname);

    Grid (
        int x,
        int y, 
        int width,
        int height,
        int scale,
        GridType type
    );

    Grid();

private:
    std::string getGridTypeAsString();
};

#endif