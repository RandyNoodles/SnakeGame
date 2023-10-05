#pragma once

#include "Utils.h"

int checkFoodCollision(Coord snakeHeadLocation, Coord foodLocation) {
	int collisionStatus = FALSE;

	if (snakeHeadLocation.x == foodLocation.x) {
		if (snakeHeadLocation.y == foodLocation.y) {
			collisionStatus = TRUE;
		}
	}

	return collisionStatus;
}

int checkMapCollision(Coord snakeHeadLocation, int mapSize_X, int mapSize_Y) {
	int collisionStatus = FALSE;

	if (snakeHeadLocation.x <= 0 || snakeHeadLocation.x >= mapSize_X) {
		collisionStatus = TRUE;
	}
	if (snakeHeadLocation.y <= 0 || snakeHeadLocation.y >= mapSize_Y) {
		collisionStatus = TRUE;
	}

	return collisionStatus;
}




int checkClock(clock_t* gameClock, int clockSpeed) {
	
	//Check current time
	clock_t currentTime = clock();

	//Determine difference between current time & last time clock was checked, convert to milliseconds
	double elapsedMilliseconds = (double)(currentTime - *gameClock) * 1000 / clockSpeed;

	//
	if (elapsedMilliseconds >= clockSpeed) {
		*gameClock = currentTime;
		return 1;
	}
	else {
		return 0;
	}

}


void moveCursor(int x, int y) {

	printf("\033[%d;%dH", y, x);

}

void clearScreen(void) {

	printf("\033[2J");

}


void printSnakeCoords(int x, int y, int mapSize_X) {
	moveCursor(mapSize_X + 10, 1);
	printf("Snake:\t(%d, %d)", x, y);
}
void printFoodCoords(int x, int y, int mapSize_X) {
	moveCursor(mapSize_X + 10, 2);
	printf("Food:\t(%d, %d)", x, y);
}
void printMapSize(int mapSize_X, int mapSize_Y) {
	moveCursor(mapSize_X + 10, 3);
	printf("Map Size:\tX: %d | Y: %d", mapSize_X, mapSize_Y);
}