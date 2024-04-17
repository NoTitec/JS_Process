#pragma once
#include "CBase.h"
class CPlayer final: public CBase
{
public:
	enum JOBINDEX {WARRIOR=1,WIZARD,THIEF};

public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Set_Hp(int _ihp) { m_tInfo.iHp = _ihp; }
	//��������
	void Set_Weapon(CBase* weapon);
	//��������
	void Set_Armor(CBase* armor) { m_pItem_Armor = armor; }
	//���� �÷��̾ �ʿ��� �Լ�(�θ�Ŭ������ �����Լ�)
	void SelectJob();

public:
	//CBase ��� �ڽ��� ���Լ��� ���Ƿ� virtual ����
	virtual void Render();

private:
	CBase* m_pItem_Weapon;
	CBase* m_pItem_Armor;

};

