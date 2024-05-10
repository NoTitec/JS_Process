#pragma once
#define			PI 3.14f
#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600

//객체 상태 확인용
#define			OBJ_NOEVENT			0
#define			OBJ_DEAD			1

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
	OBJ_MONSTER,
	OBJ_MOUSE,
	OBJ_SHIELD,
	OBJ_END
};


typedef struct tagInfo
{
	float	fX;		// 중점 X
	float	fY;		// 중점 Y

	float	fCX;	// 가로 사이즈
	float	fCY;	// 세로 사이즈

}INFO;

extern HWND g_hWnd;