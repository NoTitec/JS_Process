#pragma once
#include "Define.h"

class Character abstract
{
public:
	Character();
	Character(const char* _pname, int _iattack, int _ihp);
	Character(const char* _pname, int _iattack, int _ihp, int _imoney);
	virtual ~Character();

public:
	CHARACTERINFO Get_Info() { return m_Info; }
	void Take_Damage(int _attack) { m_Info.iHp -= _attack; }
	void Set_Hp(int _ihp) { m_Info.iHp = _ihp; }

public:

	virtual void Render() = 0;
protected:
	CHARACTERINFO m_Info;
};
