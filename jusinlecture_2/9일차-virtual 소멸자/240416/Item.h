#pragma once
#include "Obj.h"

class CItem : public CObj
{
public:
	CItem();
	CItem(const char* _pName, int _iAttack, int _iHp, int _iMoney);
	~CItem();

public:
	virtual void Render() override;
	virtual void SelectJob()		{}
	virtual void Set_Hp(int _iHp)	{}
};

