#include "Input.h"



int toLower(int input) {
	//If in the upper case half of ASCII table, switch to lower case
	//This helps limit the # of direction definitions needed
	if (input < 97) {
		input += 32;
	}

	return input;
}

int validateInput(int input) {
	switch (input) {
	case NORTH: {
		//Valid input, do nothing
		break;
	}
	case SOUTH: {
		//Valid input, do nothing

		break;
	}
	case EAST: {
		//Valid input, do nothing
		break;
	}
	case WEST: {
		//Valid input, do nothing
		break;
	}
	default: {
		//INVALID INPUT. Return FALSE
		input = FALSE;
		break;
	}
	}

	return input;
}
#pragma warning(disable: 4996)

int checkInput(void) {
	int input = FALSE;

	if (_kbhit() != NULL) {
		input = toLower(_getch());
		input = validateInput(input);
		while (_kbhit())getch();
	}

	return input;
}

