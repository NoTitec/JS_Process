#pragma once
#include "Obj.h"
#include "stdafx.h"
class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();

public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
	virtual RECT* Get_Rect_Pointer() override;
public:
	void Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
	void SetType(ZOMBIE_TYPE _zType);
private:
	CObj* m_pTarget;
	bool	m_bStuck;
	ZOMBIE_TYPE m_eZtype;
	HBRUSH Brush;

};

