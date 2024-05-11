#pragma once
#include "Obj.h"
#include "stdafx.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void		Set_BulletList(list<CObj*>* pBullet) { m_pBulletList = pBullet; }

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual RECT* Get_Rect_Pointer() override;
private:
	void		Key_Input();

private:
	list<CObj*>* m_pBulletList;
	//���ų�����Ű�� x,y ��ǥ�� ����
	POINT m_tPosition;
};

