#ifndef COLLISION_H
#define COLLISION_H
#include "header.h"

#define TILE_EMPTY 0
#define TILE_WALL 1
#define TILE_GOAL 2
#define TILE_ENEMY 3

Color GetTileColor(int tileType) {
    switch (tileType) {
        case TILE_EMPTY: return SKYBLUE;
        case TILE_WALL: return DARKBROWN;
        case TILE_GOAL: return BLACK;
        case TILE_ENEMY: return BLACK;
        default: return GRAY;
    }
}


int GetTileAt(int x, int y){
    int tileX = x / GRID_CELL_SIZE;
    int tileY = y / GRID_CELL_SIZE;
    if (tileX < 0 || tileX >= GRID_CELLS_X || tileY < 0 || tileY >= GRID_CELLS_Y)
	return TILE_WALL;
    	return tilemap[tileY][tileX];
}

bool IsCollidingWithEnemy(Rectangle player) {
    if (GetTileAt(player.x, player.y) == TILE_ENEMY) return true;
    if (GetTileAt(player.x + player.width, player.y) == TILE_ENEMY) return true; 
    if (GetTileAt(player.x, player.y + player.height -1 ) == TILE_ENEMY) return true; 
    if (GetTileAt(player.x + player.width, player.y + player.height -1) == TILE_ENEMY) return true;
    return false;
}

bool IsCollidingWithWall(Rectangle player) {
    if (GetTileAt(player.x, player.y) == TILE_WALL) return true;
    if (GetTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
    if (GetTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
    if (GetTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
    return false;
}

bool IsCollidingWithCeling(Rectangle player){
    if (GetTileAt(player.x, player.y) == TILE_WALL) return true;
    if (GetTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
//	if (GetTileCeling(player.x,player.y) == TILE_WALL) return true;
//	if (GetTileCeling(player.x + player.width,player.y) == TILE_WALL)  return true;
//    	if (!IsCollidingWithWall(player)) return true; 
	return false;
}

bool IsCollidingWithFloor(Rectangle player){
    //if (GetTileAt(player.x, player.y) == TILE_WALL) return true;
    //if (GetTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
    if (GetTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
    if (GetTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
//    	if (!IsCollidingWithWall(player)) return true; 
	return false;
}
#endif 
