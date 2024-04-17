#include "CBase.h"

CBase::CBase()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CBase::CBase(const char* _pmonstername, int _imonsterattack, int _imonsterhp)
	: m_tInfo(_pmonstername, _imonsterattack, _imonsterhp)
{
}

CBase::CBase(const char* _pname, int _iattack, int _ihp, int _imoney)
	: m_tInfo(_pname,_iattack,_ihp,_imoney)
{}

CBase::~CBase()
{

}


