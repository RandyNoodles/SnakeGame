#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <conio.h>
#include <time.h>

//Can be changed with setSize_X(int)/setSize_Y(int)
#define DEFAULT_MAP_SIZE_X 100
#define DEFAULT_MAP_SIZE_Y 30

//No food appears in these borders
#define NO_FOOD_MARGIN 12

//Lowercase ASCII values for WASD
#define NORTH 119
#define SOUTH 115
#define EAST 100
#define WEST 97

#define TRUE 1
#define FALSE 0


//# of Milliseconds per tick
#define DEFAULT_CLOCKSPEED 300



typedef struct Coord {
	int x;
	int y;
};
/*
	Description		: Checks if user has collided with the currently active food

	Parameters		: Coord snakeHeadLocation - Retrieved via getSnakeHeadLocation
					  Coord foodLocation - Retrieved via getFoodLocation
	Return Value	: 1 if collision has occurred, else 0
*/
int checkFoodCollision(Coord snakeHeadLocation, Coord foodLocation);

/*
	Description		: Checks if user has collided with the borders of the map

	Parameters		: Coord snakeHeadLocation - Retrieved via getSnakeHeadLocation
					  int mapSize_X/mapSize_Y - X & Y sizes for map
	Return Value	: 1 if collision has occurred, else 0
*/
int checkMapCollision(Coord snakeHeadLocation, int mapSize_X, int mapSize_Y);

/*
	Description		: Checks if user has collided with their own body

	Parameters		: Coord snakeHeadLocation - Retrieved via getSnakeHeadLocation
					  Coord* snakeBodyArray - Retrieved via getBody
	Return Value	: 1 if collision has occurred, else 0
*/
int checkSelfCollision(Coord snakeHeadLocation, Coord* snakeBodyArray, int length);


/*
	Description		: Checks an internal clock struct to see if more time than clockSpeed has elapsed.

	Parameters		: Recieves a clock_t ptr - Must be initialized upon startup in main.
	Return Value	: 1 if more time than the ClockSpeed has elapsed, else 0.
*/
int checkClock(clock_t* gameClock, int clockSpeed);

/*
	Description		: Esc Codes used to move the cursor around for rendering

	Parameters		: x, y coordinates to move the cursor to.
	Return Value	: Void
*/
//Moves cursor to X,Y
void moveCursor(int x, int y);
//Clears visible screen
void clearScreen(void);

/*
	Description		: Print the coords of each object

	Parameters		: x, y coordinates to display.
	Return Value	: Void
*/
void printSnakeCoords(int x, int y, int mapSize_X);
void printSnakeBodyCoords(Coord* body, int length, int mapSize_X);
void printFoodCoords(int x, int y, int mapSize_X);
void printMapSize(int mapSize_X, int mapSize_Y);

void drawSkull();
void drawGameOver();
#endif