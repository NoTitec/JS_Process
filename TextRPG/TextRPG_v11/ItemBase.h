#pragma once
#include "Define.h"

class ItemBase abstract
{
public:
	ItemBase();
	ItemBase(const char* _pname, int _iattack, int _ihp, int _imoney);
	virtual ~ItemBase();

public:
	INFO Get_Info() { return m_Info; }
public:

	virtual void Render() = 0;
protected:
	INFO m_Info;

};

