#pragma once

#include "Define.h"

class CObj abstract
{
public:
	CObj();
	CObj(const char* _pName, int _iAttack, int _iHp, int _iMoney = 0);
	~CObj();

public:
	INFO		Get_Info() { return m_tInfo; }
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }

public:
	virtual void		Render() = 0;

	virtual void		SelectJob() = 0;
	virtual void		Set_Hp(int _iHp) = 0;

protected:
	INFO		m_tInfo;
};

