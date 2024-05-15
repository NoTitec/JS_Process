#pragma once
#include "Obj.h"
class CBossHpBar : public CObj
{
public:
	CBossHpBar();
	virtual ~CBossHpBar();
public:
	void Initialize();
	int Update();
	void Late_Update();
	void Render(HDC _hdc);
	void Release();
public:
	void Pos_Update();
	void Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
private:
	CObj* m_pTarget;
};

