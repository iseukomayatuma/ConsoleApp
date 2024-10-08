//======================================
//	リバーシ UI
//======================================
#include "Mode.h"
#include "Reversi.h"
#include "Vector2.h"
#include "Utility.h"
#include <stdio.h>  // printf()

Mode SelectMode()
{
	static const char* modeName[] = {
		"１Ｐ　ＧＡＭＥ",
		"２Ｐ　ＧＡＭＥ",
		"ＷＡＴＣＨ"
	};
	int sel = 0;
	while (true) {
		ClearScreen();                         
		puts("モードを　選択して\nください");
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
// 位置入力
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
				printf("そこには　置けません\n");
				WaitKey();
				break;
			}
			return pos;
		}
	}
}