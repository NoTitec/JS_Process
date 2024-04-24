#include "Character.h"

Character::Character()
{
	memset(&m_Info, 0, sizeof(INFO));
}

Character::Character(const char* _pname, int _iattack, int _ihp)
	:m_Info(_pname, _iattack, _ihp)
{
}

Character::Character(const char* _pname, int _iattack, int _ihp, int _imoney)
	:m_Info(_pname,_iattack,_ihp,_imoney)
{
}

Character::~Character()
{
}
