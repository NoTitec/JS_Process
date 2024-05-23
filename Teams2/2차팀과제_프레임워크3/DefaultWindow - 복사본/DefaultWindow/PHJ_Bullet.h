#pragma once
#include "PHJ_Obj.h"

class CPHJ_Bullet : public CPHJ_Obj
{

public:

	CPHJ_Bullet();
	virtual ~CPHJ_Bullet();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;
	void			Player_Attack(WEAPON_TYPE _WT);
	void			Boss_Attack(PATTERN _PT);
	OWNER			Get_Owner() {return m_eOwn;}
};

