#pragma once
#include "Define.h"

class CBase abstract
{
public:
	CBase();
	CBase(const char* _pmonstername, int _imonsterattack, int _imonsterhp);
	CBase(const char* _pname,int _iattack,int _ihp,int _imoney);
	virtual ~CBase();

public:
	INFO Get_Info() { return m_tInfo; }
	void Take_Damage(int _attack) { m_tInfo.iHp -= _attack; }

public:
	virtual void Render() = 0;

protected:
	INFO m_tInfo;
};

