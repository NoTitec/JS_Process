#pragma once
#include "Obj.h"

class CZombie : public CObj
{
public:
	CZombie();
	virtual ~CZombie();

public:
	// CObj��(��) ���� ��ӵ�
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
	// ��� ����
	CObj*	m_pTarget;
	bool	m_bStuck;
};

