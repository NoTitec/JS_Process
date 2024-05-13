#pragma once

#include "Obj.h"
class CHpBar : public CObj
{
public:
	CHpBar();
	virtual ~CHpBar();
public:
	void	Initialize();
	int		Update();
	void	Late_Update();
	void	Render(HDC _hdc);
	void	Release();
public:
	void	Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
	void	Pos_Update();
private:
	CObj* m_pTarget;
};

