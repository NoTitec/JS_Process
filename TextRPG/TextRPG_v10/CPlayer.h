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
	//깊은복사
	void Set_Weapon(CBase* weapon);
	//얕은복사
	void Set_Armor(CBase* armor) { m_pItem_Armor = armor; }
	//오직 플레이어만 필요한 함수(부모클래스에 없는함수)
	void SelectJob();

public:
	//CBase 모든 자식은 이함수를 쓰므로 virtual 설계
	virtual void Render();

private:
	CBase* m_pItem_Weapon;
	CBase* m_pItem_Armor;

};

