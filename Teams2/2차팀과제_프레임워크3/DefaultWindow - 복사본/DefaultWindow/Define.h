#pragma once

#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600

#define			OBJ_NOEVENT			0
#define			OBJ_DEAD			1

#define			PI					3.141592f
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
	OBJ_PLAYER_BULLET,
	OBJ_MONSTER_BULLET,
	OBJ_MONSTER,
	OBJ_MOUSE,
	OBJ_SHIELD,
	OBJ_LINE,
	OBJ_END
};


typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y

	float	fCX;	// 가로 사이즈
	float	fCY;	// 세로 사이즈

}INFO;

typedef	struct tagLinePoint
{
	float	fX;
	float	fY;

	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY){}

}LINEPOINT;

typedef	struct tagLine
{
	tagLinePoint		tLeft;
	tagLinePoint		tRight;

	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(tagLinePoint& _tLeft, tagLinePoint& _tRight) : tLeft(_tLeft), tRight(_tRight) {}

}LINE;

typedef struct tagFrame
{
	int		iFrameStart;		// 어디에서부터 시작(인덱스)
	int		iFrameEnd;			// 어디까지(끝 인덱스)
	int		iMotion;			// 어떤 모션
	DWORD	dwSpeed;			// 스프라이트 속도
	DWORD	dwTime;				// 스프라이트 전환 시간

}FRAME;
extern HWND g_hWnd;
extern DWORD g_dwTime;

#include "HGH.h"
#include "KSH.h"
#include "KJW.h"
#include "PHJ.h"
#include "KHR.h"