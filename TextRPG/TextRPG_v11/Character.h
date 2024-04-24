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
	INFO Get_Info() { return m_Info; }
	void Take_Damage(int _attack) { m_Info.iHp -= _attack; }
public:

	virtual void Render() = 0;
protected:
	INFO m_Info;
};

