//======================================
//	リバーシ
//======================================
#include "Reversi.h"
#include "Vector2.h"
#include "Utility.h"
#include <stdio.h>  // printf()
#include <assert.h> // assert()
// 関数プロトタイプ
bool inBoard(int x, int y);
const char* getTurnName(Cell turn);

const char* diskAA[] = {
	"・",  // NONE
	"●",  // BLACK
	"〇",  // WHITE
	"■",  // OUT
};

// ボードの指定位置に代入
void SetBoard(Reversi* reversi, int x, int y, Cell value)
{
	if (inBoard(x,y) == 1)
		reversi->board[x][y] = value;
}
// ボードの指定位置を取得
Cell GetBoard(Reversi* reversi, int x, int y)
{
	if (inBoard(x, y) == 1)
		return reversi->board[x][y];
	return OUT;
}
// 初期化
void Init(Reversi* reversi, Mode mode)
{
	reversi->mode = mode;
	reversi->board[3][3] = WHITE;
	reversi->board[3][4] = BLACK;
	reversi->board[4][3] = BLACK;
	reversi->board[4][4] = WHITE;
	reversi->turn = BLACK;
}
// 次のターンへ
void NextTurn(Reversi* reversi)
{
	reversi->turn = GetOpponent(reversi->turn);
}
// 指定位置に石がおけるか
bool CheckCanPlace(Reversi* reversi, Cell myself, Vector2 pos, bool turnOver)
{
	bool canPlace = false;
	// 既に置かれている?
	if (GetBoard(reversi, pos.x, pos.y) != NONE) {
		return false;
	}
	Cell opponent = GetOpponent(myself);
	// ８方向について、
	for (int d = 0; d < DIR_MAX; d++) {
		Vector2 scan = pos;
		Vector2 dir = GetDirVector2((DIRECTION)d);
		AddVector2(&scan, &dir);
		if (GetBoard(reversi, scan.x, scan.y) != opponent) {
			continue;
		}
		Cell tmp;
		do {
			AddVector2(&scan, &dir);
			tmp = GetBoard(reversi, scan.x, scan.y);
		} while (tmp == opponent);
		if (tmp == myself) {
			canPlace = true;
			// ひっくりかえす
			if (turnOver) {
				scan = pos;
				do {
					AddVector2(&scan, &dir);
					tmp = GetBoard(reversi, scan.x, scan.y);
					if (tmp == opponent) {
						SetBoard(reversi, scan.x, scan.y, myself);
					}
				} while (tmp == opponent);
			}
		}
		// 「置ける」turnOverしないなら、終了
		if (canPlace && turnOver == false) {
			break;
		}
	}
	return canPlace;
}
// コマの数を数える
int getDiskCount(Reversi* reversi, Cell myself)
{
	int count = 0;
	for (int y = 0; y < BOARD_HEI; y++) {
		for (int x = 0; x < BOARD_WID; x++) {
			if (GetBoard(reversi, x, y) == myself)
				count++;
		}
    }
	return count;
}
// 石がどこかに置けるか?
bool CheckCanPlaceAll(Reversi* reversi, Cell myself)
{
	for (int y = 0; y < BOARD_HEI; y++) {
		for (int x = 0; x < BOARD_WID; x++) {
			Vector2 pos = { x,y };
			if (CheckCanPlace(reversi, myself, pos)) {
				return true;
			}
		}
	}
	return false;
}
// 置ける場所をリスティング
void ListCanPlaceAll(Reversi* reversi, Cell myself, Vector2List* list)
{
	Vector2 pos;
	for (pos.y = 0; pos.y < BOARD_HEI; pos.y++) {
		for (pos.x = 0; pos.x < BOARD_WID; pos.x++) {
			if (CheckCanPlace(reversi, myself, pos)) {
				AddVector2List(list, pos);
			}
		}
	}
}
// 画面描画
void DrawScreen(Reversi* reversi, Vector2 pos, DrawStatus stat)
{
	ClearScreen();
	bool isCursor = (stat == IN_PLAY) && IsHumanPlayer(reversi);

	putchar('\n');

	switch (stat) {
	case IN_PLAY:
	case NO_PLACE:
		printf("%sのターンです\n", getTurnName(reversi->turn));
		break;
	case RESULT:
	{
		int blackCount = getDiskCount(reversi, BLACK);
		int whiteCount = getDiskCount(reversi, WHITE);
		printf("%s%d-%s%d\n",
			getTurnName(BLACK), blackCount,
			getTurnName(WHITE), whiteCount
		);
		if (blackCount == whiteCount) {
			puts("引き分けです");
		}
		else {
			Cell winner = (blackCount > whiteCount) ? BLACK : WHITE;
			printf("%sの勝ちです\n", getTurnName(winner));
		}
	}
	break;
	}
}

bool IsHumanPlayer(Reversi* reversi)
{
	switch (reversi->mode) {
	case MODE_1P:
		return reversi->turn == BLACK;
	case MODE_2P:
		return true;
	default:
	case MODE_WATCH:
		return false;
	}
}

const char* getTurnName(Cell turn)
{
	if (turn == BLACK) {
		return "黒";
	}
	if (turn == WHITE) {
		return "白";
	}
	assert(false);
	return "";
}
// 相手の色を取得
Cell GetOpponent(Cell value)
{
	if (value == WHITE) {
		return BLACK;
	}
	if (value == BLACK) {
		return WHITE;
	}
	assert(false);
	return NONE;
}
// 座標がボード内か?
bool inBoard(int x, int y)
{
	return 0 <= x && x < BOARD_WID
		&& 0 <= y && y < BOARD_HEI;
}