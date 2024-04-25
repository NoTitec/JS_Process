#include "ItemBase.h"

ItemBase::ItemBase()
{
	memset(&m_Info, 0, sizeof(ITEMINFO));
}

ItemBase::ItemBase(const ItemBase& rhs)
	:m_Info(rhs.m_Info)
{
}

ItemBase::ItemBase(const char* _pname, int _iattack, int _ihp, int _imoney)
	:m_Info(_pname,_iattack,_ihp,_imoney)
{

}

ItemBase::~ItemBase()
{
}
