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
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update();
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void		Key_Input();
	void		Jump();
	template<typename T>
	CObj*		Create_Bullet();
	CObj* Create_Shield(float _Angle);
private:
	//포신 끝 위치
	POINT m_tBarrel;
	bool				m_bJump;
	float				m_fPower;
	float				m_fTime;
};

