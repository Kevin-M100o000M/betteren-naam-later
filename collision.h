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


int getTileAt(int x, int y){
    int tileX = x / GRID_CELL_SIZE;
    int tileY = y / GRID_CELL_SIZE;
    if (tileX < 0 || tileX >= GRID_CELLS_X || tileY < 0 || tileY >= GRID_CELLS_Y)
	return TILE_WALL;
	switch(map){
		case 1:
    	return tilemap[tileY][tileX];
		break;
		case 2:
    	return tilemap2[tileY][tileX];
		case 3:
    	return tilemap3[tileY][tileX];
		break;
		default:
    	return tilemap[tileY][tileX];
	}
}

bool isCollidingWithEnemy(Rectangle player) {
    if (getTileAt(player.x, player.y) == TILE_ENEMY) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_ENEMY) return true; 
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_ENEMY) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_ENEMY) return true;
    return false;
}

bool isCollidingWithWall(Rectangle player) {
    if (getTileAt(player.x, player.y) == TILE_WALL) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
    return false;
}

bool isCollidingWithCeling(Rectangle player){
    if (getTileAt(player.x, player.y) == TILE_WALL) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
	return false;
}

bool isCollidingWithFloor(Rectangle player){
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
	return false;
}
#endif 
