#pragma once
#include "Obj.h"
class CPlayer :	public CObj
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
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void		Key_Input();
	CObj*		Create_Shield();

public:
	template<typename T>
	CObj * Create_Bullet();

private:
	list<CObj*>*		m_pBullet;
	list<CObj*>*		m_pShield;

	POINT				m_tPosin;
};

