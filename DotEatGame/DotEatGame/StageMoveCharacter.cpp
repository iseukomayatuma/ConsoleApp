#pragma once
//======================================
//	ドットイートゲーム キャラクタ移動
//======================================
#include "Stage.h"
#include "Character.h"
#include "Utility.h"  // GetKey(),ARROW_XX
#include <stdio.h>

// 関数プロトタイプ
static void MoveMonsterRandom(Stage* stage, Character* ch);
static void MoveMonsterChase(Stage* stage, Character* ch);
static void MoveMonsterAmbush(Stage* stage, Character* ch);
static void MoveMonsterSiege(Stage* stage, Character* ch);
static Vector2 GetRandomPosition(Stage* stage, Character* ch);
static Vector2 GetChasePosition(Stage* stage, Character* ch, Vector2 targetPos);
static void ScanDistance(Stage* stage, Vector2 pos, int dist);
static void SetDistance(Stage* stage, int x, int y, int dist);
static int GetDistance(Stage* stage, int x, int y);
static void PrintDistance(Stage* stage);

const int INIT_DISTANCE = -1;
const int LARGE_DISTANCE = 100;

// プレーヤ移動
void MovePlayer(Stage* stage)
{
	Character* player = stage->player;
	Vector2 newPos = player->pos;
	switch (GetKey())
	{
	default:
		return;
	}
	newPos = GetLoopPosition(newPos);
	//
	// ★ここをコーディングしてください。
	// mazeの newPos位置を取得して、壁(MAZE_WALL)でなければ
	//　移動可能なので、プレーヤを移動します。
	// また mazeの newPos位置が ドット(NAZE_DOT)なら
	// プレーヤがドットを食べたことになるので、
	// mazeの newPos位置に空白(NAZE_NONE)を置きます。
	//
}
// モンスターの移動
void MoveMonsters(Stage* stage)
{
	for (int i = 0; i < stage->monsterNum; i++) {
		Character* monster = stage->monster[i];
		switch (monster->id) {
		case CHARA_RANDOM: MoveMonsterRandom(stage, monster); break;
		case CHARA_CHASE:  MoveMonsterChase(stage, monster); break;
		case CHARA_AMBUSH: MoveMonsterAmbush(stage, monster); break;
		case CHARA_SIEGE:  MoveMonsterSiege(stage, monster); break;
		}
	}
}

// ランダムモンスターの移動
static void MoveMonsterRandom(Stage* stage, Character* ch)
{
	Vector2 newPos = GetRandomPosition(stage, ch);
	MoveCharacter(ch, newPos);
}
// 追いかけモンスターの移動
static void MoveMonsterChase(Stage* stage, Character* ch)
{
	//
	// ★ここをコーディングしてください
	// プレーヤの位置を targetPos にして
	// GetChasePosition()を呼び 
	// 返ってきた位置へMoveCharacter()で移動します
	//
}
// 先回りモンスターの移動
static void MoveMonsterAmbush(Stage* stage, Character* ch)
{
	//
	// ★ここをコーディングしてください
	// プレーヤの　今の位置 - 前回の位置で取得された向きへ
	// プレーヤが3歩移動した位置が targetPosです。
	// targetPosで GetChasePosition()を呼び、
	// 返ってきた位置へMoveCharacter()で移動します
	//
}
// 挟み撃ちモンスターの移動
static void MoveMonsterSiege(Stage* stage, Character* ch)
{
	Vector2 newPos;
	Character* player = stage->player;
	Character* chaser = stage->chaser;
	if (chaser == nullptr) {
		newPos = GetRandomPosition(stage, ch);
	}
	else {
		//
		// ★ここをコーディングしてください
		// プレーヤの位置 - 追いかけモンスターの位置で取得された向きベクターを
		// プレーヤの位置に足しこんで targetPosにします。
		// targetPosで GetChasePosition()を呼び、
		// 返ってきた位置が newPosです
		//
	}
	MoveCharacter(ch, newPos);
}
// キャラのランダムな移動先を取得
static Vector2 GetRandomPosition(Stage* stage, Character* ch)
{
	ClearVector2List(&stage->v2list);
	// ４方向で行ける座標をリスティング(後退はしない)
	for (int d = 0; d < DIR_MAX; d++) {
		Vector2 dir = GetDirVector2((DIRECTION)d);
		Vector2 newPos = Vector2Add(ch->pos, dir);
		newPos = GetLoopPosition(newPos);
		if (GetMaze(stage, newPos.x, newPos.y) != MAZE_WALL
			&& Vector2Equ(newPos, ch->lastPos) == false) {
			AddVector2List(&stage->v2list, newPos);
		}
	}
	// リストからランダムに選択
	int idx = GetRand(GetCountVector2List(&stage->v2list));
	return GetVector2List(&stage->v2list, idx);
}
// キャラがターゲットへ移動するための移動先を取得
static Vector2 GetChasePosition(Stage* stage, Character* ch, Vector2 targetPos)
{
	//
	//  distance[] を初期化します(INIT_DISTANCEで埋める)
	//
	for (int y = 0; y < MAZE_HEIGHT; y++) {
		for (int x = 0; x < MAZE_WIDTH; x++) {
			SetDistance(stage, x, y, INIT_DISTANCE);
		}
	}
	//
	// ScanDistance 初手(chの退路以外の経路をスキャン)
	// 
	Vector2 dir;
	Vector2 newPos;
	SetDistance(stage, ch->pos.x, ch->pos.y, 0);
	for (int d = 0; d < DIR_MAX; d++) {
		dir = GetDirVector2((DIRECTION)d);
		newPos = Vector2Add(ch->pos, dir);
		newPos = GetLoopPosition(newPos);
		if (Vector2Equ(newPos, ch->lastPos) == false) {
			ScanDistance(stage, newPos, 1);
		}
	}
	//     デバッグ(distance[]を表示してみる)
	//	PrintDistance(stage);
	//
	int dist = GetDistance(stage, targetPos.x, targetPos.y);
	if (dist != INIT_DISTANCE) {
		//
		// targetPosからさかのぼって dist=1 までたどる
		//
		ClearVector2List(&stage->v2list);
		AddVector2List(&stage->v2list, targetPos);
		while (dist > 1) {
			ClearVector2List(&stage->v2temp);
			int count = GetCountVector2List(&stage->v2list);
			for (int i = 0; i < count; i++) {
				Vector2 route = GetVector2List(&stage->v2list, i);
				for (int d = 0; d < DIR_MAX; d++) {
					Vector2 dir = GetDirVector2((DIRECTION)d);
					Vector2 pos = Vector2Add(route, dir);
					pos = GetLoopPosition(pos);
					if (GetDistance(stage, pos.x, pos.y) == dist - 1) {
						AddVector2List(&stage->v2temp, pos);
					}
				}
			}
			int cnt = GetCountVector2List(&stage->v2temp);
			if (cnt == 0) {
				// 経路なしは、ありえないはず
				printf("dist:%d\n", dist);
				PrintVector2List(&stage->v2list);
				PrintDistance(stage);
			}
			CopyVector2List(&stage->v2list, &stage->v2temp);
			dist--;
		}
		// dist=1 が移動先
		int count = GetCountVector2List(&stage->v2list);
		int idx = GetRand(count);
		Vector2 routePos = GetVector2List(&stage->v2list, idx);
		return routePos;
	}
	// targetPosにつながる経路がなければ、ランダムな行先を
	return GetRandomPosition(stage, ch);
}
// Mazeをスキャンしてdistance[]に距離を書き込む(再帰)
static void ScanDistance(Stage* stage, Vector2 pos, int dist)
{
	Vector2 dir;
	Vector2 newPos;
	pos = GetLoopPosition(pos);
	if (GetMaze(stage, pos.x, pos.y) != MAZE_WALL) {
		int tmp = GetDistance(stage, pos.x, pos.y);
		if (tmp == INIT_DISTANCE || tmp > dist) {
			SetDistance(stage, pos.x, pos.y, dist);
			//
			// ★ここをコーディングしてください。
			// 4方向を走査します。
			// posに向きベクトルを足して newPosとします。
			// newPosと dist+1 で ScanDistance()を再帰呼び出しします。
			// 
		}
	}
}
static int GetDistance(Stage* stage, int x, int y)
{
	//
	// ★ここをコーディングしてください
	// IsInMaze()を確認して、distanceの(x,y)を取得します
	// IsInMaze()外なら、LARGE_DISTANCE を返します
	// 
}
static void SetDistance(Stage* stage, int x, int y, int dist)
{
	//
	// ★ここをコーディングしてください
	// IsInMaze()を確認して、distanceの(x,y)へdistを書き込みます
	// IsInMaze()外なら、なにもしません
	//
}

static void PrintDistance(Stage* stage)
{
	for (int y = 0; y < MAZE_HEIGHT; y++) {
		for (int x = 0; x < MAZE_WIDTH; x++) {
			int dist = GetDistance(stage, x, y);
			if (dist == INIT_DISTANCE) {
				printf("■");
			}
			else {
				printf("%2d", dist);
			}
		}
		putchar('\n');
	}
	WaitKey();
	WaitKey();
	WaitKey();
	WaitKey();
	WaitKey();
}