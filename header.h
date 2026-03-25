#ifndef HEADER_H
#define HEADER_H
#include <raylib.h>
#include <stdio.h>
#include "header.h"
#include "maps/map1.h"
#include "maps/map2.h"
#include "maps/map3.h"
#include "maps/map4.h"
#include "maps/map5.h"
#include "collision.h"

#define GRID_CELL_SIZE 20
#define GRID_CELLS_X 30 
#define GRID_CELLS_Y 30

#define TILE_EMPTY 0
#define TILE_WALL 1
#define TILE_GOAL 2
#define TILE_ENEMY 3

#endif
