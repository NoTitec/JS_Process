#pragma once

#include "Obj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

public:
	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }
	void Set_GetShotgun() { m_bGetShotgun = true; }

private:
	void Set_Theta_And_Degree();
	void Key_Press();
	CObj* Create_Bullet(float _fInterval);
private:
	POINT m_mousePos;
	list<CObj*>* m_pBulletList;

	bool m_bGetShotgun;
	DWORD m_dwShotgunTime;
	
};

