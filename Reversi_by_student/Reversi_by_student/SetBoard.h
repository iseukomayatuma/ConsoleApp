#pragma once
#include <stdio.h>
//オブジェクト形式マクロ
#ifndef BOARD_HEI
#define BOARD_HEI 8  // vertical
#define BOARD_WID 8  // holizon

typedef enum BOARD {
	BLACK,
	WHITE,
	EMPTY
}Cell;

Cell Board[BOARD_HEI][BOARD_WID];  // 8*8盤作成
// 関数フロトタイプ

void Ini(Board* cell);   // 初期化 
#endif