#pragma once

#define PURE = 0
#define WINCX 800
#define WINCY 600

#define PI 3.141592

#define OBJ_NOEVENT 0
#define OBJ_DEAD	1

typedef struct tagInfo
{
	float fX;
	float fY;

	float fCX;
	float fCY;

	float fRad;
	float fDegree;

	float fNormalX;
	float fNormalY;
} INFO;

enum OBJ_ID
{
	OBJ_PLAYER,
	OBJ_BULLET,
	OBJ_GRENADE,
	OBJ_ZOMBIE,
	OBJ_ITEM,
	OBJ_BOMB,
	OBJ_END
};

enum OBJ_ITEM_TYPE
{
	GUN,
	OBJ_ITEM_TYPE_END
};

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

extern HWND g_hWnd;

/*
삼각 함수
삼각 함수 -> 직각 삼각형이라는 조건이 있어야 한다.

함수 -> input => output이 존재하는 구조
y = f(x)


선분간의 비율값이 나온다
cos 밑변 / 빗변
sin 높이 / 빗변
tan 높이 / 밑변

삼각비
각도
degree => 0~360
radian(호도법) => radius angle의 줄임말

degree -> radian으로 치환해서 넣어주어야 한다.

포신이랑 상관이 있나?
포신 = 빗변

float fAngle;
m_fDistance

*/