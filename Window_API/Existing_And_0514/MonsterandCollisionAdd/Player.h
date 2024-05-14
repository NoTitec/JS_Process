#pragma once
#include "Obj.h"
#include "stdafx.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual RECT* Get_Rect_Pointer() override;
private:
	void		Key_Input();
	CObj*		Create_Shield();
public:
	template<typename T>
	CObj* Create_Bullet();
private:
	//포신끝가르키는 x,y 좌표용 변수
	POINT m_tPosition;
};

