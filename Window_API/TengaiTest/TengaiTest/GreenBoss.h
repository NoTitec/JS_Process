#pragma once
#include "Obj.h"
#include "enumDefine.h"
#include "ScrollMgr.h"
class CGreenBoss : public CObj
{
public:
	enum BOSSSTATE { IDLE, ATTACK, BOSS_ST_END };
	enum PATTERN { ONEPATTERN, TWOPATTERN, BOSS_PATTERN_END };

public:
	CGreenBoss();
	virtual ~CGreenBoss();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnHit(CObj* _pObj) override;
	virtual void	On_Motion_End() override;
public:
	void Set_State_Idle() {
		m_fSpeed = 1.f; m_eCurState = IDLE; m_tInfo.fCX = 82.f; m_tInfo.fCY = 72.f; m_pFrameKey = L"GreenBoss_Idle"; m_fAngle = rand() % 360;
	}
	void Change_State();
	void Pattern1();
	void Pattern2();
	void		Motion_Change();
	template<typename T>
	CObj* Create_Bullet();
private:
	int m_iHp;
	float m_fSaveTime;
	float m_fCoolTime;
	BOSSSTATE				m_ePreState;
	BOSSSTATE				m_eCurState;
	PATTERN					m_ePattern;
	POINT					m_Pattern1StartPoint;
	POINT					m_Pattern1EndPoint;
	bool					m_bMoveForward;
	void Move_Frame_once_and_Return_Idle_State();
	DWORD					m_HitFrameSaveTime;
};

template<typename T>
inline CObj* CGreenBoss::Create_Bullet()
{
	int iScrollY = (int)ScrollMgr->Get_ScrollY();
	CObj* pBullet = CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY);
	pBullet->Set_ID(OBJ_BOSSMONSTERBULLET);
	return pBullet;
}


