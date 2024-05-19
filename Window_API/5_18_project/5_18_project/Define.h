#pragma once
#include "Windows.h"

#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600
//��ü ���� Ȯ�ο�
#define			OBJ_NOEVENT			0
#define			OBJ_DEAD			1

#define			PI		3.141592f

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagInfo
{
	float	fX;		// ���� X
	float	fY;		// ���� Y

	float	fCX;	// ���� ������
	float	fCY;	// ���� ������

}INFO;

extern HWND g_hWnd;

//����ü
//==============
enum DIRECTION
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_LU,
	DIR_RU,
	DIR_END
};

enum OBJ_ID
{
	OBJ_PLAYER,
	OBJ_BULLET,
	OBJ_MONSTER,
	OBJ_MOUSE,
	OBJ_SHIELD,
	OBJ_END
};
//==============