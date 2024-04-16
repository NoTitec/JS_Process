#pragma once

#include "Obj.h"

class CPlayer final : public CObj
{
public:
	enum JOBINDEX { WARRIOR = 1, WIZARD, THIEF, END };

public:
	CPlayer();
	~CPlayer();

public:
	void		Set_Hp(int _iHp)		 { m_tInfo.iHp = _iHp; }
	void		SelectJob();

public:
	virtual void		Render();
};

