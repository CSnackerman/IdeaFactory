#include "Grid.h"

Grid::Grid (
    int x,
    int y, 
    int width,
    int height,
    int scale,
    GridType type
) 
    :   primary {114, 41, 179, 255},
        secondary {88, 143, 219, 255},
        x(x), 
        y(y),
        width(width),
        height(height),
        scale(scale),
        thickness(1)
{   
    switch (type) {
        case RANDOM_GRID:
            generateRandomGrid();
            break;
        
        case ALTERNATING_GRID:
            generateAlternatingGrid();
            break;

        case LINE_GRID:
            generateLineGrid();
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

    //Create background rect
    ColoredRect background;
    SDL_Rect bgRect = {x, y, width, height};
    SDL_Color bgColor = secondary;
    background = { bgRect, bgColor};
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

void Grid::generateLineGrid() {
    //Fetch window dimensions
    if(width == 0 || height == 0) {
        std::pair<int, int> dimens = Display::getWindowDimens();
        width = dimens.first;
        height = dimens.second;
    }

    ColoredRect gridLine;
    SDL_Rect lineRect;

    //Generate horizontal gridlines
    for(int row = y; row <= height; row += scale) {
        lineRect = {x, row, width, thickness};

        if(row == height)
            gridLine = {lineRect, secondary};
        else
            gridLine = {lineRect, primary};

        pushColoredRect(gridLine);
    }

    //Generate vertical gridlines
    for(int col = x; col <= width; col += scale) {
        //Ensure the last enclosing line draws
        if(col == width) {
            col -= thickness;
        }

        lineRect = {col, y, thickness, height};
        
        if(col == width)
            gridLine = {lineRect, secondary};
        else
            gridLine = {lineRect, primary};
        
        pushColoredRect(gridLine);
    }
    
}
