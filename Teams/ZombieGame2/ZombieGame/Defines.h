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
�ﰢ �Լ�
�ﰢ �Լ� -> ���� �ﰢ���̶�� ������ �־�� �Ѵ�.

�Լ� -> input => output�� �����ϴ� ����
y = f(x)


���а��� �������� ���´�
cos �غ� / ����
sin ���� / ����
tan ���� / �غ�

�ﰢ��
����
degree => 0~360
radian(ȣ����) => radius angle�� ���Ӹ�

degree -> radian���� ġȯ�ؼ� �־��־�� �Ѵ�.

�����̶� ����� �ֳ�?
���� = ����

float fAngle;
m_fDistance

*/