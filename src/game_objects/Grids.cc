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
    printDebug("Grid_Fullscreen");
}