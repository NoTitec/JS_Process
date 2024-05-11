#pragma once

#include "Obj.h"
class CItemMgr
{
public:
	static void Create_Item(list<CObj*>* _pItemList);
	static DWORD m_dwCreateItemTime;

};

