#pragma once
#include "Obj.h"

class CHpBar;
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;
public:
	void Key_Update();
	void DT_Update();
	void Dir_Update() override;
	void Posin_Update() override;
	void Cursor_Render(HDC _hdc);

public:
	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }
	void Set_BarrierList(list<CObj*>* _pBarrierList) { m_pBarrierList = _pBarrierList; }
public:
	// Skills
	void Player_Dash();
	void Player_Barrier();
private:
	CObj* Create_Bullet();
	CObj* Create_Barrier();
public:
	// get
	bool Get_Dash() { return m_arrStatus[PLAYER_DASH]; }
	bool Get_Barrier() { return m_arrStatus[PLAYER_BARRIER]; }
	// set
	void Set_Barrier() { m_arrStatus[PLAYER_BARRIER] = true; }
private:
	// 멤버 변수
	list<CObj*>* m_pBulletList;
	list<CObj*>* m_pBarrierList;
	POINT m_ptCursorPos;

	// 시간 관리 변수
	DWORD m_dwPrevCount;
	DWORD m_dwCurCount;
	float m_fDT;
	float m_fAcc;

	// 쿨타임 관리 변수
	float m_fDashCoolTime;
	int	  m_iDashCallCount;
	// Player 상태
	bool  m_arrStatus[PLAYER_END];

	CHpBar* m_pHpBar;
};

