#pragma once
//======================================
//	コマンドUI
//======================================
#ifndef __COMMAMDUI_H
#define __COMMAMDUI_H

#include "Command.h"
#include "TurnBattle.h"

// プレーヤのコマンド取得
Command GetPlayerCommand(TurnBattle* btl);
// 敵のコマンド取得
Command GetEnemyCommand();

#endif    // __COMMANDUI_H