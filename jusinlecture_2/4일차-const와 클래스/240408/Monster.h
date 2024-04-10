#pragma once

#include "Define.h"

class CMonster
{
public:
	CMonster();
	CMonster(const char* _pName, int _iAttack, int _iHp);
	~CMonster();

public:
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }
	INFO		Get_Info() { return m_tInfo; }

public:
	void	Render();

private:
	INFO	m_tInfo;
};

