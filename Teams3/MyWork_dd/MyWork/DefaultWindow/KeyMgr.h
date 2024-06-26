#pragma once
#include "Define.h"

class CKeyMgr
{
	DECLARE_SINGLE(CKeyMgr);
	
public:
	bool		Key_Pressing(int _iKey);
	bool		Key_Down(int _iKey);
	bool		Key_Up(int _iKey);
	void		Key_Update();

private:
	bool		m_bKeyState[VK_MAX];
};

