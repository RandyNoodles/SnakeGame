/*
	FILE			: Main.cpp
	Project			: Personal - SnakeGame
	Programmer		: Josh Rice
	First Version	: 2023-09-16
	Description		:
		Game of snake we all know and love. This is a means for me to try and brush off the rust.

*/


#pragma once
#include "Main.h"

/*
TODO:
- Make it so the display in the top right clears the line before writing the new one

- Note - Map needs to be super small for laptop


X/Y Offset:
Apparently the first line in the console is actually line 1 for each axis. I've been treating it as 0
This has implications for:
	- Collision 
	- Map Drawing?
	- Where food can spawn

	TEST: is 0,0 different than 1,1?
	Answer: Nope. They both indicate the top lefthand corner.
	
*/

#define WIN 1
#define LOSE -1
#define CONTINUE 0


int main(void) {
	
	//Init Rand
	srand((unsigned int)time(NULL));


	//Init Clockspeed
	int clockSpeed = DEFAULT_CLOCKSPEED;
	//Init Clock
	clock_t gameClock;
	gameClock = clock();
	

	//Init all elements
	Map map;
	
	Snake player;
	player.initializeSnake(map.xSize, map.ySize);
	
	Food food;
	food.newFood(player.body, player.length, map.xSize, map.ySize);

	//Draw map & elements
	map.drawMap();
	player.drawSnake();
	food.drawFood();





	int playerInput = -1;

	int foodCollisionFlag = 0;
	int mapCollisionFlag = 0;
	int selfCollisionFlag = 0;

	int tickElapsedFlag = FALSE;
	int gameStatus = CONTINUE;

	while (gameStatus == CONTINUE) {



		//Check for input
		playerInput = checkInput();
		//If input detected, change player direction
		if (playerInput != FALSE) {
			player.setDirection(playerInput);
		}
		//Check if Clock division has elapsed
		tickElapsedFlag = checkClock(&gameClock, clockSpeed);
		//If true, advance game state
		if (tickElapsedFlag == TRUE) {
			player.moveSnake();
			
			foodCollisionFlag = checkFoodCollision(player.getSnakeHeadLocation(), food.getLocation());
			if (foodCollisionFlag == TRUE) {
				food.newFood(player.getBody(), player.getLength(), map.getSize_X(), map.getSize_Y());
				food.drawFood();
				player.addLength();
			}

			mapCollisionFlag = checkMapCollision(player.getSnakeHeadLocation(), map.getSize_X(), map.getSize_Y());
			if (mapCollisionFlag == TRUE) {
				gameStatus = LOSE;
				break;
			}

			selfCollisionFlag = checkSelfCollision(player.getSnakeHeadLocation(), player.getBody(), player.getLength());
			if (selfCollisionFlag == TRUE) {
				gameStatus = LOSE;
				break;
			}


			printSnakeCoords(player.getSnakeHeadLocation().x, player.getSnakeHeadLocation().y, map.getSize_X());
			//printSnakeBodyCoords(player.getBody(), player.getLength(), map.getSize_X());
			printFoodCoords(food.getLocation().x, food.getLocation().y, map.getSize_X());
			printMapSize(map.getSize_X(), map.getSize_Y());
			printf("\t Game Status: %d", gameStatus);
		}
	}

	if (gameStatus == LOSE) {
		clearScreen();
		moveCursor(1, 5);
		drawSkull();
		printf("\n\n\n\n");
		drawGameOver();
	}
	//AFTER WHILE LOOP
	//Clear screen
	//Move cursor to middle
	//Display Win/Lose status (Fancy ascii box letters?)
	//Return to menu? Am I gonna do a menu?

	return 0;
}

