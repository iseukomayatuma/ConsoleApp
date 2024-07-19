#pragma once
//======================================
//	���o�[�V 2D�x�N�^�[
//======================================
#ifndef __VECTOR2_H
#define __VECTOR2_H


typedef struct {
	int x;
	int y;
} Vector2;

// �W����
typedef enum {
	DIR_UP,
	DIR_UP_LEFT,
	DIR_LEFT,
	DIR_DOWN_LEFT,
	DIR_DOWN,
	DIR_DOWN_RIGHT,
	DIR_RIGHT,
	DIR_UP_RIGHT,
	DIR_MAX,
} DIRECTION;

// �x�N�^�[���Z
void AddVector2(Vector2* a, Vector2* b);
// �W�����̃x�N�^�[�擾
Vector2 GetDirVector2(DIRECTION d);

#endif  // __VECTOR2_H