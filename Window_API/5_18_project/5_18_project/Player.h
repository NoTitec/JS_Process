#pragma once
#include "Define.h"
#include "stdafx.h"
#include "Obj.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void		Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	void		Set_Shield(list<CObj*>* pShield) { m_pShield = pShield; }

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update();
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void		Key_Input();

	template<typename T>
	CObj*		Create_Bullet();
	CObj* Create_Shield(float _Angle);
private:
	list<CObj*>* m_pBullet;
	list<CObj*>* m_pShield;
	//포신 끝 위치
	POINT m_tBarrel;
};

