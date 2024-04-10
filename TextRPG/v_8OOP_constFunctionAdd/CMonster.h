#pragma once
#include "Status.h"


class CMonster
{
public:

	enum Difficulty
	{
		EASY=1,
		NORMAL,
		HARD
	};
public:
	CMonster() : m_tInfo{ "",0,0 } {}
	CMonster(const char* _pName, int _iAttack, int _iHp);
	~CMonster();

public:
	void Take_Damage(int iAttack);
	INFO Get_Info() { return m_tInfo; }
	int Get_Hp() { return m_tInfo.iHp; }
	int Get_Attack() { return m_tInfo.iAttack; }
public:
	void Render() const;

private:
	INFO m_tInfo;
};

