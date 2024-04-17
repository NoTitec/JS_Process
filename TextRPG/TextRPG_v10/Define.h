#pragma once
#include"stdafx.h"
#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p;p=nullptr;}

typedef struct tagInfo
{
	char szName[32];
	int iAttack;
	int iHp;
	int iMoney;

	tagInfo() {
		memset(&szName, 0, sizeof(szName));
		iAttack = 0;
		iHp = 0;
		iMoney = 0;
	}
	tagInfo(const char* _pname, int _iattack, int _ihp) {
		strcpy_s(szName, sizeof(szName), _pname);
		iAttack = _iattack;
		iHp = _ihp;
		iMoney = 0;
	}
	tagInfo(const char* _pname, int _iattack, int _ihp, int _imoney)
	{
		strcpy_s(szName, sizeof(szName), _pname);
		iAttack = _iattack;
		iHp = _ihp;
		iMoney = _imoney;
	}
}INFO;

enum ITEMTYPE
{
	IT_WEAPON,
	IT_ARMOR,
	IT_END
};
enum ITEMCLASS
{
	BEGINNER,
	NORMAL,
	RARE,
	CLASS_END
};
