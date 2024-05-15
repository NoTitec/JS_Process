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
	void Player_Rebound();
private:
	CObj* Create_Bullet();
	CObj* Create_Barrier();
public:
	// get
	bool Get_Dash() { return m_arrState[PLAYER_DASH]; }
	bool Get_Barrier() { return m_arrState[PLAYER_BARRIER]; }

	// set
	void Set_Barrier() { m_arrState[PLAYER_BARRIER] = true; }
	// �Ѿ� �� ä��� �Լ�.
	void Set_BulletCount(UINT _iBulletCount) { m_iBulletCount = _iBulletCount; }

private:
	// ��� ����
	list<CObj*>* m_pBulletList;
	list<CObj*>* m_pBarrierList;
	POINT m_ptCursorPos;

	// �ð� ���� ����
	DWORD m_dwPrevCount;
	DWORD m_dwCurCount;
	float m_fDT;
	float m_fAcc;

	// ��Ÿ�� ���� ����
	float m_fDashCoolTime;
	int	  m_iDashCallCount;

	UINT  m_iBarriersize;
	UINT  m_iReboundsize;
	float m_fReboundSpeed;
	// Player ����
	bool  m_arrState[PLAYER_END];
	// Bullet źâ
	UINT m_iBulletCount;

	CHpBar* m_pHpBar;
};

