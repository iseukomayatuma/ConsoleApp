#pragma once
#include <stdio.h>
//�I�u�W�F�N�g�`���}�N��
#ifndef BOARD_HEI
#define BOARD_HEI 8  // vertical
#define BOARD_WID 8  // holizon

typedef enum BOARD {
	BLACK,
	WHITE,
	EMPTY
}Cell;

Cell Board[BOARD_HEI][BOARD_WID];  // 8*8�Ս쐬
// �֐��t���g�^�C�v

void Ini(Board* cell);   // ������ 
#endif