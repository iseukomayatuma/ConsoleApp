#pragma once
//======================================
//	Vector2List
//======================================
#ifndef __VECTORLIST_H
#define __VECTORLIST_H

#include "Vector2.h"
typedef struct {
	int size;        // �z��T�C�Y
	int ptr;         // �i�[�|�C���^
	Vector2* array;  // �z��
} Vector2List;

// ������
void InitializeVector2List(Vector2List* list, int size);
// ��n��
void FinalizeVector2List(Vector2List* list);
// ���X�g�ɒǉ�
void AddVector2List(Vector2List* list, Vector2 pos);
// ���X�g�̗v�f���𓾂�
int GetCountVector2List(Vector2List* list);
// ���X�g�̗v�f�𓾂�
Vector2 GetVector2List(Vector2List* list, int idx);
// ���X�g���N���A
void ClearVector2List(Vector2List* list);
// ���X�g���R�s�[
void CopyVector2List(Vector2List* dst, Vector2List* src);
// ���X�g���v�����g����
void PrintVector2List(Vector2List* list);

#endif    // __VECRTORLIST_H