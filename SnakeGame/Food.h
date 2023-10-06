#pragma once

#include <random>
#include "Utils.h"
#include "Snake.h"

typedef struct Food {
	Coord location = { 0, 0 };
	int foodCollected = 0;


	void drawFood(void) {
		moveCursor(location.x, location.y);
		printf("*");
	}
	void eraseFood(void) {
		moveCursor(location.x, location.y);
		printf(" ");
	}

	int newFood(Coord* playerBody, int playerLength, int mapSizeX, int mapSizeY) {

		foodCollected++;
		if (foodCollected < MAX_SNAKE_LENGTH) {
			//Continue
		}
		else {
			return 1;
		}
		//Check that the food doesn't intersect with the player
		while (generateFoodCoord(playerBody, playerLength, mapSizeX, mapSizeY) != TRUE);
	}
	int generateFoodCoord(Coord* playerBody, int playerLength, int mapSizeX, int mapSizeY) {

		

		location.x = rand() % (mapSizeX - (2 * NO_FOOD_MARGIN)) + NO_FOOD_MARGIN;
		location.y = rand() % (mapSizeY - (2 * NO_FOOD_MARGIN)) + NO_FOOD_MARGIN;

		int validLocationFound = TRUE;
		//Location invalid if it intersects with the player
		for (int i = 0; i < playerLength; i++) {
			if (location.y == playerBody[i].y) {
				if (location.x != playerBody[i].x) {
					validLocationFound = FALSE;
				}
			}
		}
		//Player moves TWO cells East/West
		//Location invalid if not reachable by increments of 2
		if ((location.x + playerBody[0].x) % 2 != 0) {
			validLocationFound = FALSE;
		}
		return validLocationFound;

	}
	Coord getLocation() {
		return location;
	}
};
