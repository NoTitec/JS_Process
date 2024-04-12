#pragma once
#include "Character.h"
class CPlayer : public Character
{
public:
	CPlayer();
	~CPlayer();
public:
	enum JOBINDEX { WARRIOR = 1, WIZARD, THIEF };
	void SelectJob();
};

