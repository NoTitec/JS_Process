#pragma once

#include "Define.h"

class CPlayer
{
public:
	enum JOBINDEX { WARRIOR = 1, WIZARD, THIEF, END };

public:
	CPlayer();
	~CPlayer();

public:
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }
	int			Get_Attack()			 { return m_tInfo.iAttack; }
	int			Get_Hp()				 { return m_tInfo.iHp; }
	void		Set_Hp(int _iHp)		 { m_tInfo.iHp = _iHp; }

public:
	void		SelectJob();
	void		Render();

private:
	INFO		m_tInfo;

};

