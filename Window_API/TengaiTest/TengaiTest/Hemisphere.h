#pragma once
#include "Obj.h"
#include "enumDefine.h"
#include "ObjMgr.h"

#include "ScrollMgr.h"
class CHemisphere :
    public CObj
{
public:
	enum BOSSSTATE { IDLE, ATTACK, BOSS_ST_END };
	enum PATTERN { ONEPATTERN, TWOPATTERN, BOSS_PATTERN_END };

public:
	CHemisphere();
	virtual ~CHemisphere();

public:


	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;

	virtual void	On_Motion_End() override;

public:
	void Set_State_Idle()
	{
		m_eCurState = IDLE; m_pFrameKey = L"Boss2_Idle"; m_tInfo.fCX = 76.f; m_tInfo.fCY = 128.f;
	}

	void Change_State();
	void Pattern1();
	void Pattern2();
	void		Motion_Change();
	template<typename T>
	CObj* Create_Bullet();
	template<typename T>
	void Create_three_Bullet();
private:
	int m_iHp;
	float m_fSaveTime;
	float m_fCoolTime;
	BOSSSTATE				m_ePreState;
	BOSSSTATE				m_eCurState;
	PATTERN					m_ePattern;
	bool					m_AttackEnd;

	DWORD					m_HitFrameSaveTime;
};

template<typename T>
inline CObj* CHemisphere::Create_Bullet()
{
	int iScrollY = (int)ScrollMgr->Get_ScrollY();
	CObj* pBullet = CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY);
	pBullet->Set_ID(OBJ_BOSSMONSTERBULLET);
	return pBullet;
}

template<typename T>
inline void CHemisphere::Create_three_Bullet()
{
	ObjMgr->Add_Object(OBJ_MONSTERBULLET, CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LEFT));
	ObjMgr->Add_Object(OBJ_MONSTERBULLET, CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY - 20.f, DIR_LD));
	ObjMgr->Add_Object(OBJ_MONSTERBULLET, CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY + 20.f, DIR_LU));

}