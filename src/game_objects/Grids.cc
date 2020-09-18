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
    printf("[INSTANCE] GO:Grid_Fullscreen\n");
}