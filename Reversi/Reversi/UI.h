#pragma once
//======================================
//	���o�[�V UI
//======================================
#ifndef __UI_H
#define __UI_H

#include "Mode.h"
#include "Vector2.h"
#include "Reversi.h"

// ���[�h�I��
Mode SelectMode();
// �ʒu����
Vector2 InputPosition(Reversi* reversi);

#endif // __UI_H