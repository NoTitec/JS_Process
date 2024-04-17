#pragma once
#include "CBase.h"
class CMonster final: public CBase
{
public:
	enum DIFFICULTY {EASY=1,NORMAL,HARD};
public:
	CMonster();
	CMonster(const char* _szname, int _iattack, int _ihp);
	~CMonster();

public:
	virtual void Render();
};

