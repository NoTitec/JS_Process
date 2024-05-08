#pragma once

#include "Windows.h"
#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600
#define			SMALLWINCX 700
#define			SMALLWINCY 500

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

//중심기준 정보
typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y

	float	fCX;	// 가로 사이즈
	float	fCY;	// 세로 사이즈

}INFO;

extern HWND g_hWnd;