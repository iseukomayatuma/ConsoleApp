#include <stdio.h>
#include "SetBoard.h"

int main()
{
	Ini(&Board);
	for (int height = 0; height < BOARD_HEI; height++)
		for (int width = 0; width < BOARD_WID; width++)
			printf("%c", Board[height][width]);
	puts("aaaa");
	Board[0][0] = 'a';
	printf("%c", Board[0][0]);

}