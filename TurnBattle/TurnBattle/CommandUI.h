#pragma once
//======================================
//	�R�}���hUI
//======================================
#ifndef __COMMAMDUI_H
#define __COMMAMDUI_H

#include "Command.h"
#include "TurnBattle.h"

// �v���[���̃R�}���h�擾
Command GetPlayerCommand(TurnBattle* btl);
// �G�̃R�}���h�擾
Command GetEnemyCommand();

#endif    // __COMMANDUI_H