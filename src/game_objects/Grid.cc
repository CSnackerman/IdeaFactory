#include "Grid.h"

Grid::Grid (
    int x,
    int y, 
    int width,
    int height,
    int scale,
    GridType type
) :    
    x       (x),        // Top-left   
    y       (y),        
    width   (width),    
    height  (height),
    scale   (scale),    // Size of each square cell in px
    type    (type)
{
    // Line thickness for LineGrid
    thickness = 10;

    // Colors
    primary = {110, 0, 184, 255};
    secondary = {33, 33, 33, 255};

    // Intialize selected grid
    initGrid();
}

void Grid::initGrid() {

    switch (this->type) {
        case RANDOM_GRID:
            initRandomGrid();
            break;
        
        case ALTERNATING_GRID:
            initAlternatingGrid();
            break;

        case LINE_GRID:
            initLineGrid();
            break;
        
        default:
            initAlternatingGrid();
    }
}

void Grid::initAlternatingGrid() {
    
    //Fetch window dimensions
    if(width == 0 || height == 0) {
        std::pair<int, int> dimens = Display::getWindowDimens();
        width = dimens.first;
        height = dimens.second;
    }

    //Create background rect
    ColoredRect background = {
        SDL_Rect {x, y, width, height},
        SDL_Color {secondary}
    };
    pushColoredRect(background);

    ColoredRect cell;
    SDL_Rect cellRect;

    //Generate even rows
    for(int row = y; row < height; row += scale * 2) {
        for(int col = x; col < width; col += scale * 2) {
            cellRect = {col, row, scale, scale};
            cell = {cellRect, primary};
            pushColoredRect(cell);
        }
    }

    //Generate odd rows
    for(int row = y + scale; row < height; row += scale * 2) {
        for(int col = x + scale; col < width; col += scale * 2) {
            cellRect = {col, row, scale, scale};
            cell = {cellRect, primary};
            pushColoredRect(cell);
        }
    }

}

void Grid::initRandomGrid() {
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

void Grid::initLineGrid() {
    //Fetch window dimensions
    if(width == 0 || height == 0) {
        std::pair<int, int> dimens = Display::getWindowDimens();
        width = dimens.first;
        height = dimens.second;
    }

    ColoredRect gridLine;
    SDL_Rect lineRect;

    // Generate horizontal gridlines
    for(int row = y; row <= height; row += scale) {

        //Ensure the last enclosing line draws
        if(row == height) {
            row -= thickness;
        }

        lineRect = {x, row, width, thickness};
        gridLine = {lineRect, primary};

        pushColoredRect(gridLine);
    }

    //Generate vertical gridlines
    for(int col = x; col <= width; col += scale) {

        if(col == width) {
            col -= thickness;
        }

        lineRect = {col, y, thickness, height};
        gridLine = {lineRect, primary};
        
        pushColoredRect(gridLine);
    }
    
}
