#pragma once
#include "Obj.h"
#include "enumDefine.h"
#include "ScrollMgr.h"
#include "EventDefine.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "MonsterSpawnMgr.h"

class CSpinningMonster : public CObj
{
public:
	enum SPININGSTATE {IDLE,ATTACK,SPINING_ST_END};

public:
	CSpinningMonster();
	virtual ~CSpinningMonster();
public:


	// CObj을(를) 통해 상속됨
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC hDC) override;

	void Release() override;

	void OnHit(CObj* _pObj) override;
	virtual void On_Motion_End() override;
public:
	void Set_State_Idle() {
		m_eCurState = IDLE; m_pFrameKey = L"SpinningMonster";
	}
	void Change_State();
	void Pattern1();
	void Motion_Change();
	template<typename T>
	CObj* Create_Bullet();
private:
	int m_iHp;
	float m_fSaveTime;
	float m_fCoolTime;
	SPININGSTATE				m_ePreState;
	SPININGSTATE			m_eCurState;
	PATTERN					m_ePattern;
	POINT					m_Pattern1StartPoint;
	POINT					m_Pattern1EndPoint;
	bool					m_bSpawnInit;
	bool					m_AttackEnd;
	void Move_Frame_once_and_Return_Idle_State();
	DWORD					m_HitFrameSaveTime;
};

template<typename T>
inline CObj* CSpinningMonster::Create_Bullet()
{
	int iScrollY = (int)ScrollMgr->Get_ScrollY();
	CObj* pBullet = CAbstractFactory<T>::Create(m_tInfo.fX, m_tInfo.fY);
	pBullet->Set_ID(OBJ_MONSTERBULLET);
	return pBullet;
}