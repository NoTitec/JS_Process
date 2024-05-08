#pragma once
#include "Obj.h"
#include "Define.h"
#include "stdafx.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	//�÷��̾� ������ġ �� �̵��ӵ�����
	virtual void Initialize() override;
	//Ű���� �Լ� ȣ��� ���� �׷��� rect ���� ������Ʈ
	virtual int Update() override;
	//�÷��̾� �׸���
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void Set_BulletList(list<CObj*>* pBulletList) { m_pBulletList = pBulletList; }
private:
	//Ű �Է� ���� �Լ�
	void		Key_Input();
	//�Ѿ˻����Լ�
	CObj* Create_Bullet(int dx, int dy);

private:
	list<CObj*>* m_pBulletList;
};

