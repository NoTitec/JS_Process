#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	CObj(const char* _pName, int _iAttack, int _iHp);
	~CObj();

public:
	INFO		Get_Info() { return m_tInfo; }
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }

public:
	void		Render();

protected:
	INFO		m_tInfo;
};

