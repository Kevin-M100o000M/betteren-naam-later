#ifndef COLLISION_H
#define COLLISION_H
#include "header.h"

#define TILE_EMPTY 0
#define TILE_WALL 1
#define TILE_SPECIAL 2
#define TILE_ENEMY 3
#define TILE_BOUNCE 4


Texture2D playerTexture; 
Texture2D testTexture; 
Texture2D testTextureLucht;
Texture2D testTextureSpecial;
Texture2D testTextureDefault;
Texture2D testTextureEnemy;
Texture2D testTextureBounce;


Color getTileColor(int tileType) {
    switch (tileType) {
        case TILE_EMPTY: return SKYBLUE;
        case TILE_WALL: return DARKBROWN;
        case TILE_SPECIAL: return BLACK;
        case TILE_ENEMY: return BLACK;
        default: return GRAY;
    }
}

Texture getTileTexture(const int tileType) {
    switch (tileType) {
        case TILE_EMPTY: return testTextureLucht;
        case TILE_WALL: return testTexture;
        case TILE_SPECIAL: return testTextureSpecial;
	case TILE_ENEMY: return testTextureEnemy;
        case TILE_BOUNCE: return testTextureBounce;
        default: return testTextureDefault;
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
		case 4:
    	return tilemap4[tileY][tileX];
		break;
		case 5:
    	return tilemap5[tileY][tileX];
		break;
		default:
    	return tilemap[tileY][tileX];
	}
}

bool isCollidingWithEnemy(Rectangle player) {
    if (getTileAt(player.x +2, player.y) == TILE_ENEMY) return true;
    if (getTileAt(player.x + player.width -2, player.y) == TILE_ENEMY) return true; 
    if (getTileAt(player.x +2, player.y + player.height -2 ) == TILE_ENEMY) return true; 
    if (getTileAt(player.x + player.width -2, player.y + player.height -2) == TILE_ENEMY) return true;
    return false;
}

bool isCollidingWithWall(Rectangle player) {
    if (getTileAt(player.x, player.y) == TILE_WALL) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
    return false;
}

bool isCollidingWithSpecial(Rectangle player) {
    if (getTileAt(player.x, player.y) == TILE_SPECIAL) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_SPECIAL) return true; 
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_SPECIAL) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_SPECIAL) return true;
    return false;
}

bool isCollidingWithBounce(Rectangle player) {
    if (getTileAt(player.x, player.y) == TILE_BOUNCE) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_BOUNCE) return true; 
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_BOUNCE) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_BOUNCE) return true;
    return false;
}

bool isCollidingWithCeling(Rectangle player){
    if (getTileAt(player.x, player.y) == TILE_WALL) return true;
    if (getTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
	return false;
}


bool isCollidingWithLeft(Rectangle player){
    if (getTileAt(player.x + player.width, player.y) == TILE_WALL) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
	return false;
}

bool isCollidingWithRight(Rectangle player){
    if (getTileAt(player.x, player.y) == TILE_WALL) return true;
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
	return false;
}

bool isCollidingWithFloor(Rectangle player){
    if (getTileAt(player.x, player.y + player.height -1 ) == TILE_WALL) return true; 
    if (getTileAt(player.x + player.width, player.y + player.height -1) == TILE_WALL) return true;
	return false;
}
#endif 
