#pragma once

#include "Singleton.h"
#include "Define.h"



class CKeyMgr : public CSingleton<CKeyMgr>
{
friend  CSingleton<CKeyMgr>;
private:
	CKeyMgr();
	~CKeyMgr();

public:
	bool		Key_Pressing(int _iKey);
	bool		Key_Down(int _iKey);
	bool		Key_Up(int _iKey);
	void		Key_Update();

private:
	static CKeyMgr*	m_pInstance;
	bool			m_bKeyState[VK_MAX];
};

#define KEY CKeyMgr::Get_Instance()

