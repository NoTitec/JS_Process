#pragma once
#include "Windows.h"

#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600
//객체 상태 확인용
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
//오브젝트 중점과, 크기전보 구조체
typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y

	float	fCX;	// 가로 사이즈
	float	fCY;	// 세로 사이즈

}INFO;

extern HWND g_hWnd;

//선의 두점중 한점을 나타내는 구조체
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
//열거체
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