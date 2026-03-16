#ifndef TILEMAP_H
#define TILEMAP_H

#define GRID_CELLS_X 30 
#define GRID_CELLS_Y 30

//extern int tilemap[GRID_CELLS_Y][GRID_CELLS_X];
int tilemap[GRID_CELLS_Y][GRID_CELLS_X] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,1},
    {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

#endif
