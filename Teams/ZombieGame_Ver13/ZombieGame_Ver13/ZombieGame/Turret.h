#pragma once

#include "Obj.h"
class CTurret : public CObj
{
public:
	CTurret();
	virtual ~CTurret();
public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC _hdc) override;

	void Release() override;

public:
	void Set_Build() { m_bBuild = true; }
	void Set_ZombieList(list<CObj*>* _pZombieList) { m_pZombieList = _pZombieList; }
	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }
	void Set_DeadTime() { dw_deadTime = dw_surviveTime + iSurviveTime; }
	void Set_SurviveTime() { dw_surviveTime = GetTickCount(); }

public:
	CObj* Create_Bullet();
	float Get_SurviveRatio();
private:
	bool	m_bBuild;
	int		m_iHp;
	
	DWORD	dw_fireTime;
	DWORD	dw_surviveTime;
	DWORD	dw_deadTime;

	list<CObj*>* m_pZombieList;
	list<CObj*>* m_pBulletList;

	static int iSurviveTime;
	static int iFireTime;
};

