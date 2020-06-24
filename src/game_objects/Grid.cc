#include "Grid.h"

Grid::Grid (
    int x,
    int y, 
    int width,
    int height,
    int scale,
    GridType type
) 
    :
    primary {114, 41, 179, 255},
    secondary {88, 143, 219, 255},
    x(x), 
    y(y),
    width(width),
    height(height),
    scale(scale)
{   
    switch (type) {
        case RANDOM_GRID:
            generateRandomGrid();
            break;
        
        case ALTERNATING_GRID:
            generateAlternatingGrid();
            break;
        
        default:
            generateAlternatingGrid();
    }
}

void Grid::generateAlternatingGrid() {
    //Fetch window dimensions
    if(width == 0 || height == 0) {
        std::pair<int, int> dimens = Display::getWindowDimens();
        width = dimens.first;
        height = dimens.second;
    }

    bool alternator = true;
    ColoredRect coloredRect;
    for(int row = y; row < height; row += scale) {
        for(int col = x; col < width; col += scale) {

            SDL_Rect gridSquare {col, row, scale, scale};

            if(alternator) {
                coloredRect = {gridSquare, primary};
                alternator = !alternator;
            }
            else {
                coloredRect = {gridSquare, secondary};
                alternator = !alternator;
            }

            pushColoredRect(coloredRect);
        }

        //Stagger the rows
        alternator = !alternator;
    }
}

void Grid::generateRandomGrid() {
    std::random_device rand;

    //Fetch window dimensions
    if(width == 0 || height == 0) {
        std::pair<int, int> dimens = Display::getWindowDimens();
        width = dimens.first;
        height = dimens.second;
    }

    ColoredRect coloredRect;
    for(int row = y; row < height; row += scale) {
        for(int col = x; col < width; col += scale) {

            Uint8 r, g, b;
            r = (Uint8) rand();
            g = (Uint8) rand();
            b = (Uint8) rand();

            SDL_Rect gridSquare {col, row, scale, scale};
            SDL_Color color {r, g, b, 255};
            coloredRect = {gridSquare, color};
            pushColoredRect(coloredRect);
        }
    }
}
