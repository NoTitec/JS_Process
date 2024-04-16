#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CObj::CObj(const char * _pName, int _iAttack, int _iHp, int _iMoney)
	: m_tInfo(_pName, _iAttack, _iHp, _iMoney)
{
	
}


CObj::~CObj()
{
}
