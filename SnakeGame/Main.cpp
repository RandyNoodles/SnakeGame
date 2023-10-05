#pragma once
#include "Main.h"

/*
TODO:
- Collision for walls & self
- NO_FOOD_LIMIT doesn't seem to be being enforced by the generateNewFood() function

- Note - Map needs to be super small for laptop
*/

#define WIN 1
#define LOSE -1
#define CONTINUE 0


int main(void) {
	
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

			mapCollisionFlag = checkMapCollision(player.getSnakeHeadLocation, map.getSize_X(), map.getSize_Y());
			if (mapCollisionFlag == TRUE) {
				//GameStatus to LOSE
			}
		}
		
	}
	//AFTER WHILE LOOP
	//Clear screen
	//Move cursor to middle
	//Display Win/Lose status (Fancy ascii box letters?)
	//Return to menu? Am I gonna do a menu?

	return 0;
}

