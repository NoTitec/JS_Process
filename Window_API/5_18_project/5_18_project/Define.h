#pragma once
#include "Windows.h"

#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600
//��ü ���� Ȯ�ο�
#define			OBJ_NOEVENT			0
#define			OBJ_DEAD			1

#define			PI		3.141592f
#define			VK_MAX				0xff

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}
//������Ʈ ������, ũ������ ����ü
typedef struct tagInfo
{
	float	fX;		// ���� X
	float	fY;		// ���� Y

	float	fCX;	// ���� ������
	float	fCY;	// ���� ������

}INFO;

extern HWND g_hWnd;

//���� ������ ������ ��Ÿ���� ����ü
typedef struct tagLinePoint
{
	float fX;
	float fY;
	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX,float _fY) : fX(_fX),fY(_fY){}
}LINEPOINT;

typedef struct tagLine
{
	LINEPOINT LeftPoint;
	LINEPOINT RightPoint;
	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(LINEPOINT& _LeftPoint, LINEPOINT& _RightPoint) : LeftPoint(_LeftPoint), RightPoint(_RightPoint) {}
}LINE;
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
	OBJ_BOX,
	OBJ_END
};
//==============