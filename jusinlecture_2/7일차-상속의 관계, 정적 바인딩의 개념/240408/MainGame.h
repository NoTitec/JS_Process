#pragma once

#include "Player.h"
#include "Field.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public :
	void		Initialize();
	void		Update();
	void		Release();
	
private:
	CObj*			m_pPlayer;
	CField*			m_pField;
};

