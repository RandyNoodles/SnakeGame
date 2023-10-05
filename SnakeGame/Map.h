#pragma once

#include "Utils.h"

 typedef struct Map {
	int xSize = DEFAULT_MAP_SIZE_X;
	int ySize = DEFAULT_MAP_SIZE_Y;

	void setSize_X(int newSize) {
		xSize = newSize;
	}
	void setSize_Y(int newSize) {
		ySize = newSize;
	}
	int getSize_X() {
		return xSize;
	}
	int getSize_Y() {
		return ySize;
	}

	void drawMap(void) {
		//Draw Top Border
		for (int i = 0; i < xSize; i++) {
			printf("#");
		}
		printf("\n");
		//Draw Sides
		for (int i = 2; i < ySize; i++) {
			printf("#");
			moveCursor(xSize, i);
			printf("#\n");
		}
		//Draw Bottom Border
		for (int i = 0; i < xSize; i++) {
			printf("#");
		}
	}
};

