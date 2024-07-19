//======================================
//	ƒŠƒo[ƒV UI
//======================================
#include "Mode.h"
#include "Reversi.h"
#include "Vector2.h"
#include "Utility.h"
#include <stdio.h>  // printf()

Mode SelectMode()
{
	static const char* modeName[] = {
		"‚P‚o@‚f‚`‚l‚d",
		"‚Q‚o@‚f‚`‚l‚d",
		"‚v‚`‚s‚b‚g"
	};
	int sel = 0;
	while (true) {
		ClearScreen();                         
		puts("ƒ‚[ƒh‚ğ@‘I‘ğ‚µ‚Ä\n‚­‚¾‚³‚¢");
		//printf("%s",modeName);
		for (int i = 0; i < MODE_MAX; i++) printf("%s\n", modeName[i]);
		switch (GetKey()) {
		case ARROW_UP:
			sel--;
			if (sel < 0) {
				sel = MODE_MAX - 1;
			}
			break;
		case ARROW_DOWN:
			sel++;
			if (sel >= MODE_MAX) {
				sel = 0;
			}
			break;
		case DECIDE:
			return (Mode)sel;
		}
	}
}
// ˆÊ’u“ü—Í
Vector2 InputPosition(Reversi* reversi)
{
	Vector2 pos = { 3,3 };
	while (true) {
		DrawScreen(reversi, pos, IN_PLAY);
		switch (GetKey()) {
		case ARROW_UP: pos.y = (pos.y + 1) % BOARD_HEI - 1; break;
		case ARROW_DOWN: pos.y = (pos.y  - 1) % BOARD_HEI - 1; break;
		case ARROW_RIGHT: pos.x = (pos.x + 1) % BOARD_HEI - 1; break;
		case ARROW_LEFT: pos.x = (pos.x - 1) % BOARD_HEI - 1; break;
		case DECIDE:
			if (CheckCanPlace(reversi, reversi->turn, pos) == false) {
				printf("‚»‚±‚É‚Í@’u‚¯‚Ü‚¹‚ñ\n");
				WaitKey();
				break;
			}
			return pos;
		}
	}
}