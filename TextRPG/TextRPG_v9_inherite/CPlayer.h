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
	void Render() const;
	void SetItem(const char* itemname);
private:
	char m_item[30];
};

