#ifndef LOGIC_H
#define LOGIC_H

#include "Utils.h"

#define MAX_SNAKE_LENGTH 100






typedef struct Snake {
	Coord body[MAX_SNAKE_LENGTH];
	int length;
	int direction; //Use Enums NORTH SOUTH EAST WEST

	Coord* getBody(){
		return body;
	}
	int getLength() {
		return length;
	}
	int getDirection() {
		return direction;
	}

	void addLength() {
		length++;
	}

	void drawSnake(void) {
		for (int i = 0; i < length; i++) {
			moveCursor(body[i].x, body[i].y);
			printf("O");
		}
	}
	void eraseSnake(void) {
		for (int i = 0; i < length; i++) {
			moveCursor(body[i].x, body[i].y);
			printf(" ");
		}
	}


	//Call initialize immediately upon creating obj
	void initializeSnake(int mapSizeX, int mapSizeY) {
		length = 1;
		body[0].x = mapSizeX / 2;
		body[0].y = mapSizeY / 2;
		direction = WEST;
	}

	//Used for collision
	Coord getSnakeHeadLocation(void) {
		return body[0];
	}

	//Player Controls
	void setDirection(int playerInput) {
		if (playerInput != -1) {
			direction = playerInput;
		}
	}
	
	//Called by moveSnake to advance the rest of the snake
	void advanceSnakeBodyArray(Coord prevSegmentLocation) {
		Coord temp = body[0];

		
		for (int i = 1; i < length; i++) {
			temp = body[i];
			body[i] = prevSegmentLocation;
			prevSegmentLocation = temp;
		}
	}

	//Depending on direction, move head then rest of body.
	//Then erases & re-draws snake
	void moveSnake() {
		Coord prevSegmentLocation;

		eraseSnake();

		switch (direction) {
		case NORTH: {
			prevSegmentLocation = body[0];
			body[0].y--;
			advanceSnakeBodyArray(prevSegmentLocation);
			break;
		}
		case SOUTH: {
			prevSegmentLocation = body[0];
			body[0].y++;
			advanceSnakeBodyArray(prevSegmentLocation);
			break;
		}
		case EAST: {
			prevSegmentLocation = body[0];
			body[0].x += 2;
			advanceSnakeBodyArray(prevSegmentLocation);
			break;
		}
		case WEST: {
			prevSegmentLocation = body[0];
			body[0].x -= 2;
			advanceSnakeBodyArray(prevSegmentLocation);
			break;
		}
		}

		drawSnake();
	}
};


#endif