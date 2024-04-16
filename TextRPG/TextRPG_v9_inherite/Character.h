#pragma once
#include "Stat.h"
class Character
{
public:
	Character() : m_Stat{"",0,0} {}
	~Character();

public:
	void Take_Damage(int iAttack);
	int Get_Attack();
	int Get_Hp();
	void Set_Hp(int iHp);
	virtual void Render() const;
protected:
	STAT m_Stat;
};

