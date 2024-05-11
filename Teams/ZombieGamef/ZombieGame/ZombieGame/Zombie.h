#pragma once
#include "Obj.h"

class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();

public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

public:
	void Update_Dir() override;

public:
	// get

	// set
	void Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
private:
	// 멤버 변수
	CObj*	m_pTarget;
	bool	m_bStuck;
};

