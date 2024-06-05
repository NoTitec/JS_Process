#pragma once

#define			PURE	= 0

#define			WINCX	800
#define			WINCY	600

#define			OBJ_NOEVENT			0
#define			OBJ_DEAD			1

#define			PI					3.141592f
#define			VK_MAX				0xff

#define			TILECX  64
#define			TILECY  64

#define			TILEX	30
#define			TILEY	20

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
	OBJ_UI,
	OBJ_END
};

enum RENDERID
{
	RENDER_BACK,
	RENDER_GAMEOBJECT,
	RENDER_EFFECT,
	RENDER_UI,
	RENDER_END
};

enum CHANNELID
{
	SOUND_EFFECT,
	SOUND_BGM,
	MAXCHANNEL
};



typedef struct tagInfo
{
	float	fX;		// ���� X
	float	fY;		// ���� Y

	float	fCX;	// ���� ������
	float	fCY;	// ���� ������

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
	int		iFrameStart;		// ��𿡼����� ����(�ε���)
	int		iFrameEnd;			// ������(�� �ε���)
	int		iMotion;			// � ���
	DWORD	dwSpeed;			// ��������Ʈ �ӵ�
	DWORD	dwTime;				// ��������Ʈ ��ȯ �ð�

}FRAME;

struct DeleteObj
{
	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}

};

struct DeleteMap
{
	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp.second)
		{
			delete Temp.second;
			Temp.second = nullptr;
		}
	}

};


extern HWND g_hWnd;