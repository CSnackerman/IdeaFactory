#include "Grids.h"

Grid_Fullscreen::Grid_Fullscreen(int scale, GridType type) :

    Grid (
        0, 0,
        Display::getWindowDimens().first,
        Display::getWindowDimens().second,
        scale,
        type
    )

{
    printDebug("grid_fullscreen");
}

Grid_Relative::Grid_Relative(int relscale, int relx, int rely, int relw, int relh, GridType type) :
    Grid()
{
    // Guard (ensure percents)
    if(relscale < 1 || relscale > 100) 
        relscale = 1;
    if(relx < 0 || relx > 100) 
        relx = 0;
    if(rely < 0 || rely > 100)
        rely = 0;
    if(relw < 1 || relw > 100)
        relw = 1;
    if(relh < 1 || relh > 100)
        relh = 1;

    // Get window dimensions (px)
    int w = Display::getWindowDimens().first;
    int h = Display::getWindowDimens().second;

    // Calculate relative values
    this->scale     = w * relscale / 100.0f;
    this->x         = w * relx / 100.0f;
    this->y         = h * rely / 100.0f;
    this->width     = w * relw / 100.0f;
    this->height    = h * relh / 100.0f; 

    this->type      = type;
    this->primary   = {110, 0, 184, 255};
    this->secondary = {33, 33, 33, 255};

    // Initialize the grid using calculated values
    initGrid();

    printDebug("grid_relative");
}