#include <raylib.h>
int map = 1;
#include "header.h"

#define GRID_CELL_SIZE 20
#define GRID_CELLS_X 30 
#define GRID_CELLS_Y 30

#define TILE_EMPTY 0
#define TILE_WALL 1
#define TILE_GOAL 2
#define TILE_ENEMY 3

typedef enum GameScreen { TITLE = 0, GAME, END} GameScreen;

int main(void){
	const int screenWidth = 600;
	const int screenHeight = 600;
	InitWindow(screenWidth , screenHeight, "tilemap");  
	GameScreen currentscreen = TITLE;

	Texture2D playerTexture = LoadTexture("assets/player_test.png");
	Texture2D testTexture = LoadTexture("assets/test_sprite.png");
	Texture2D testTextureLucht = LoadTexture("assets/lucht_test.png");
	Texture2D testTextureSpecial = LoadTexture("assets/special_test.png");
	Texture2D testTextureDefault = LoadTexture("assets/default_test.png");
	Texture2D testTextureEnemy = LoadTexture("assets/vijand_test.png");
	Texture2D testTextureBounce = LoadTexture("assets/bounce_test.png");

	Vector2 gridPosition = {0,0};
	Rectangle player = {10, screenHeight - 41, 18, 20};
	//Rectangle tile = {80, screenHeight/2, 20, 20};
	float gravity = 0.2f;
	float velocity = 0;
	float v2 = 0;
	int speed = 1;
	bool onGround = false;
	
Texture GetTileTexture(int tileType) {
    switch (tileType) {
        case TILE_EMPTY: return testTextureLucht;
        case TILE_WALL: return testTexture;
        case TILE_GOAL: return testTextureSpecial;
	case TILE_ENEMY: return testTextureEnemy;
        case TILE_BOUNCE: return testTextureBounce;
        default: return testTextureDefault;
    }
}

    	//Camera2D camera = { 0 };
    	//camera.zoom = 1.0f;
	
	SetTargetFPS(120);
	while (!WindowShouldClose()){

		//camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove()*0.1f));
		switch(currentscreen){
			case TITLE:
			{

		if (IsKeyDown(KEY_ENTER)) currentscreen = GAME;
		if(IsKeyDown(KEY_ONE)) map = 1; 
		if(IsKeyDown(KEY_TWO)) map = 2; 
		if(IsKeyDown(KEY_THREE)) map = 3;

			}break;
			case GAME:
			{
			velocity += gravity;
			player.y += velocity;
			player.x += v2;
			speed = 1;

			if(IsKeyDown(KEY_G))player.x = 10,player.y = 10;
			if(IsKeyDown(KEY_F))player.x = 450,player.y = 60;
			if(IsKeyDown(KEY_LEFT_SHIFT))speed = 2;
			if(IsKeyDown(KEY_LEFT))player.x -= speed;
			if(IsKeyDown(KEY_RIGHT))player.x += speed;
			if(IsKeyDown(KEY_UP))player.y -= 6;

			if(IsKeyDown(KEY_ONE)) map = 1; 
			if(IsKeyDown(KEY_TWO)) map = 2; 
			if(IsKeyDown(KEY_THREE)) map = 3;



			if (isCollidingWithEnemy(player)) {
				player.x = 10;
				player.y = screenHeight - 41;
				map = 1;
			}

			if(isCollidingWithSpecial(player)){
   		         	velocity -= 5;
				player.y -= 4;
   		         	onGround = false;
				map += 1;
				player.x = 10;
				player.y = screenHeight - 41;
			}

			if(isCollidingWithBounce(player)){
   		         	velocity = -3.5f;
				player.y -= 3;
   		         	onGround = false;
			}


			if (isCollidingWithWall(player)) {
			if (velocity > 0){
        	    	player.y -= velocity;
        	    	onGround = true;
			} else if (velocity < 0){
        	    	player.y -= velocity;
			}
        	    	velocity = 0;
        		} else {
        		    onGround = false;
        		}	

			if(isCollidingWithLeft(player)){
   		        	player.x -= 4;
   		         if (IsKeyDown(KEY_LEFT_SHIFT)) player.x -= 4;
			 if(IsKeyDown(KEY_UP))velocity += 10;
			}

			if(isCollidingWithRight(player)){
   		        	player.x += 4;
   		         if (IsKeyDown(KEY_LEFT_SHIFT)) player.x += 4;
			 if(IsKeyDown(KEY_UP))velocity += 10;
			}

			if(isCollidingWithCeling(player)){
				player.y += 20;
        	    		//velocity += 10.0f;
        	    		velocity = 4.0f;
			}
			if(isCollidingWithFloor(player)){
				player.y -= 2;
        	    		//velocity += 10.0f;
        	    		velocity = 4.0f;
			}

   			if (onGround && IsKeyPressed(KEY_SPACE)) {
   		         velocity = 10;
   		         onGround = false;
   		     }

   		     if (isCollidingWithWall(player)) {
   		         //if (IsKeyDown(KEY_LEFT)) player.x += 2;
   		         //if (IsKeyDown(KEY_RIGHT)) player.x -= 2;
   		         //if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_LEFT_SHIFT)) player.x += 4;
   		         //if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT_SHIFT)) player.x -= 4;
   		     }
				}break;
				case END:
				{
				}break;
		}
		

		BeginDrawing();
			ClearBackground(RAYWHITE);
		switch(currentscreen){
			case TITLE:
				DrawText("press enter", screenWidth/2, screenHeight/2, 20, RED);
				DrawText("press 1 for map 1 2 for map 2 and so forth", screenWidth/2, screenHeight/2 + 20, 20, RED);
				DrawText("There are 3 maps", screenWidth/2, screenHeight/2 + 40, 20, RED);
				DrawText(TextFormat("map %02i selected",map), 80, 70, 15, RED);
			{
			}break;
			case GAME:
			{

			if(IsKeyDown(KEY_F))DrawFPS(20,20);

			    for (int x = 0; x < GRID_CELLS_X; x++) {
			 	for (int y = 0; y < GRID_CELLS_Y; y++) {
			        int tileType = tilemap[y][x];
				switch(map){
					case 1:
			        tileType = tilemap[y][x];
					break;
					case 2:
			        tileType = tilemap2[y][x];
					break;
					case 3:
			        tileType = tilemap3[y][x];
					break;
					default:
			        tileType = tilemap[y][x];
				}
			        Color c = GetTileColor(tileType);
			        Texture t = GetTileTexture(tileType);
			        DrawRectangle(
			            (int)gridPosition.x + x * GRID_CELL_SIZE,
			            (int)gridPosition.y + y * GRID_CELL_SIZE,
			            GRID_CELL_SIZE,
			            GRID_CELL_SIZE,
			            c
			        );
				DrawTexture(t,(int)gridPosition.x + x * GRID_CELL_SIZE,(int)gridPosition.y + y * GRID_CELL_SIZE, WHITE);
			    }
			}

			
			//getTileAt();

			DrawRectangleRec(player, WHITE);
			DrawTexture(playerTexture, player.x, player.y, WHITE);
			DrawText(TextFormat("score %02i",speed), 80, 70, 15, DARKGREEN);
			DrawText(TextFormat("map %02i",map), 80, 140, 15, RED);

			}break;
			case END:
			{
			}break;
		}

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
            		//for (int y = 0; y <= GRID_CELLS_Y; y++)
            		//    DrawLine((int)gridPosition.x, (int)gridPosition.y + y*GRID_CELL_SIZE,
            		//        (int)gridPosition.x + GRID_CELLS_X*GRID_CELL_SIZE, (int)gridPosition.y + y*GRID_CELL_SIZE, RED);
            		//for (int x = 0; x <= GRID_CELLS_X; x++)
            		//    DrawLine((int)gridPosition.x + x*GRID_CELL_SIZE, (int)gridPosition.y,
            		//        (int)gridPosition.x + x*GRID_CELL_SIZE, (int)gridPosition.y + GRID_CELLS_Y*GRID_CELL_SIZE, BLUE);
            		//// Draw player
            		//DrawRectangle((int)gridPosition.x + player.cell.x*GRID_CELL_SIZE, (int)gridPosition.y + player.cell.y*GRID_CELL_SIZE,
            		//    GRID_CELL_SIZE + 1, GRID_CELL_SIZE + 1, player.color);
