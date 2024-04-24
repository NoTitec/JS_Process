#include "CArmor.h"

CArmor::CArmor()
{
	memset(&m_Info, 0, sizeof(INFO));
}

CArmor::CArmor(const char* _pname, int _iattack, int _ihp, int _imoney) : ItemBase(_pname, _iattack, _ihp, _imoney)
{
}

CArmor::~CArmor()
{
}
