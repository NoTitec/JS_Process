#pragma once
#include "Obj.h"
class CGrenade : public CObj
{
public:
	CGrenade();
	virtual ~CGrenade();

public:
	// CObj��(��) ���� ��ӵ�
	void Initialize() override;

	int Update() override;

	void Late_Update() override;

	void Render(HDC _hdc) override;

	void Release() override;

	void Set_BombList(list<CObj*>* _pBombList) { m_pBombList = _pBombList; }

	CObj* Create_Bomb();
private:
	bool m_bTimeOver;
	list<CObj*>* m_pBombList;
};

