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

enum ITEMTYPE
{
	IT_WEAPON,
	IT_ARMOR,
	IT_END
};
enum ITEMCLASS
{
	BEGINNER,
	NORMAL,
	RARE,
	CLASS_END
};