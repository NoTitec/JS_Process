#pragma once

#include "Obj.h"

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
	void Dir_Update() override;
	void Posin_Update() override;
	void Cursor_Render(HDC _hdc);

public:
	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }
	void Set_BarrierList(list<CObj*>* _pBarrierList) { m_pBarrierList = _pBarrierList; }
private:
	void Key_Update();
	CObj* Create_Bullet();
	CObj* Create_Barrier();
public:
	// get

	// set
private:
	// ¸â¹ö º¯¼ö
	list<CObj*>* m_pBulletList;
	list<CObj*>* m_pBarrierList;
	POINT m_ptCursorPos;

};

