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
public:

	void Change_State();
	void Pattern1();
	void Pattern2();
	void		Motion_Change();
	template<typename T>
	CObj* Create_Bullet();
private:

	float m_fSaveTime;
	float m_fCoolTime;
	BOSSSTATE				m_ePreState;
	BOSSSTATE				m_eCurState;
	PATTERN					m_ePattern;
};

template<typename T>
inline CObj* CGreenBoss::Create_Bullet()
{
	int	iScrollX = (int)ScrollMgr->Get_ScrollX();
	int iScrollY = (int)ScrollMgr->Get_ScrollY();
	CObj* pBullet = CAbstractFactory<T>::Create(m_tInfo.fX + iScrollX, m_tInfo.fY+iScrollY);
	//pBullet->Set_ID(OBJ_BOSSMONSTERBULLET);
	return pBullet;
}


