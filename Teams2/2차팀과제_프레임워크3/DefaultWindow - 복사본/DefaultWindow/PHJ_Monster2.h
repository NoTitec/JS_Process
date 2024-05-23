#pragma once
#include "PHJ_Obj.h"

class CPHJ_Monster2 : public CPHJ_Obj // 죠스처럼 아래에서 튀어나왔다 다시 들어가는 박치기공룡
{

public:
	CPHJ_Monster2();
	virtual ~CPHJ_Monster2();

	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnHit(CObj* _pObj) override;

private:
	float	m_fJumptimer;
};

