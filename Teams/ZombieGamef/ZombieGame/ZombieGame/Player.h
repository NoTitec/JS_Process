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
	void Update_Dir() override;

public:
	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }

private:
	void Key_Update();
	//CObj* Create_Bullet();
public:
	// get

	// set
private:
	// ¸â¹ö º¯¼ö
	list<CObj*>* m_pBulletList;
	POINT m_CursorPos;

};

