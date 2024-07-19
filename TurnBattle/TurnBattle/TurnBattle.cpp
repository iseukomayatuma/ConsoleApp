//======================================
//	ターン制バトル
//======================================
#include "TurnBattle.h"
#include "Utility.h"
#include <stdio.h>  // printf()

// 関数プロトタイプ
static void execCommand(TurnBattle* btl, Command cmd, Character* offense, Character* defense);

// ターンバトル設定
void SetTurnBattle(TurnBattle* btl, Character* player, Character* enemy)
{
	btl->player = player;
	btl->enemy = enemy;
}
// イントロ「～が現れた!!」表示
void IntroTurnBattle(TurnBattle* btl)
{
	DrawBattleScreen(btl);
	printf("%sが現れた!!", btl->enemy->name);
	WaitKey();
}
// バトル開始
void StartTurnBattle(TurnBattle* btl)
{
	btl->turn = 1;
	StartCharacter(btl->player);
	StartCharacter(btl->enemy);
}
// バトル画面を描画
void DrawBattleScreen(TurnBattle* btl)
{
	ClearScreen();
	IndicatePlayer(btl->player);
	putchar('\n');
	IndicateEnemy(btl->enemy);
	putchar('\n');
}
// プレーヤのターン実行
bool ExecPlayerTurn(TurnBattle* btl, Command cmd)
{
	execCommand(btl, cmd, btl->player, btl->enemy);
	if (IsDeadCharacter(btl->enemy)) {
		SetEraseAa(btl->enemy);
		DrawBattleScreen(btl);
		printf("%sを　たおした!", btl->enemy->name);
		WaitKey();
		return true;
	}
	return IsEscapeCharacter(btl->player);
}
// 敵のターン実行
bool ExecEnemyTurn(TurnBattle* btl, Command cmd)
{
	execCommand(btl, cmd, btl->enemy, btl->player);
	if (IsDeadCharacter(btl->player)) {
		DrawBattleScreen(btl);
		printf("あなたは　しにました");
		WaitKey();
		return true;
	}
	return false;
}
// コマンド実行(offense:攻撃キャラ defense:防御キャラ)
static void execCommand(TurnBattle* btl, Command cmd, Character* offense, Character* defense)
{
	int dmg;
	switch (cmd) {
	case COMMAND_FIGHT:
		DrawBattleScreen(btl);
		printf("%sの　こうげき!", offense->name);
		WaitKey();

		dmg = CalcDamage(offense);
		DamageCharacter(defense, dmg);
		DrawBattleScreen(btl);
		printf("%sに%dの　ダメージ!",defense->name,dmg);
		WaitKey();

		break;
	case COMMAND_SPELL:
		if (CanSpellCharacter(offense) == false) {
			DrawBattleScreen(btl);
			printf("MPが　たりない！");
			WaitKey();
			break;
		}
		UseSpellCharacter(offense);
		DrawBattleScreen(btl);
		printf("%sは　ヒールを　となえた！", offense->name);
		WaitKey();

		RecoverCharacter(offense);
		DrawBattleScreen(btl);
		printf("%sのきずが　回復した！", offense->name);
		WaitKey();
		break;

	case COMMAND_ESCAPE:
		DrawBattleScreen(btl);
		printf("%sは　にげだした！", offense->name);
		WaitKey();
		SetEscapeCharacter(offense);
		break;
	}
}
// 次のターンへ
void NextTurnBattle(TurnBattle* btl)
{
	btl->turn++;
}