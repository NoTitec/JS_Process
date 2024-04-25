#pragma once

#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

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
enum STATE
{
	ST_EQUIP, ST_UNEQUIP, ST_END
};

typedef struct tagInfo
{
	char	szName[32];
	int		iAttack;
	int		iHp;
	int		iMoney;

	tagInfo() {}
	tagInfo(const char* _pName, int _iAttack, int _iHp, int _iMoney)
	{
		strcpy_s(szName, sizeof(szName), _pName);
		iAttack = _iAttack;
		iHp = _iHp;
		iMoney = _iMoney;
	}

}INFO;

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

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