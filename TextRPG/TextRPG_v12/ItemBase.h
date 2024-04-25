#pragma once
#include "Define.h"

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
enum EQUIPSTATE
{
	ST_EQUIP, ST_UNEQUIP, ST_END
};

class ItemBase abstract
{
public:
	ItemBase();
	ItemBase(const ItemBase& rhs);
	ItemBase(const char* _pname, int _iattack, int _ihp, int _imoney);
	virtual ~ItemBase();

public:
	ITEMINFO Get_Info() { return m_Info; }
public:
	virtual void Render() = 0;
	virtual ITEMTYPE			Get_Type() = 0;
	virtual void	Set_Type(ITEMTYPE eType) = 0;
	virtual	EQUIPSTATE	Get_State() = 0;
	virtual void	Set_State(EQUIPSTATE eTate) = 0;
protected:
	ITEMINFO m_Info;
};