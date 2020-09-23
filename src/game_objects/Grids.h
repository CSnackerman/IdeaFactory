#ifndef GRIDS_H
#define GRIDS_H

#include "Grid.h"

class Grid_Fullscreen : public Grid {
    public:
    Grid_Fullscreen(int scale, GridType);
};

class Grid_Relative : public Grid {
    public:
    Grid_Relative(int relscale, int relx, int rely, int relw, int relh, GridType);
};

#endif