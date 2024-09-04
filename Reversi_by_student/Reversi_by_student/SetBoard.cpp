#include <stdio.h>
#include "SetBoard.h"

void Ini(Board)
{
	for (int height = 0; height < BOARD_HEI; height++)
		for (int width = 0; width < BOARD_WID; width++)
			cell[height][width] = EMPTY;

	Board[3][3] = BLACK;
	Board[3][4] = WHITE;
	Board[4][3] = WHITE;
	Board[4][4] = BLACK;

	//for (int height = 0; height < BOARD_HEI; height++)
	//	for (int width = 0; width < BOARD_WID; width++)
	//		printf("%c", Board[height][width]);
}