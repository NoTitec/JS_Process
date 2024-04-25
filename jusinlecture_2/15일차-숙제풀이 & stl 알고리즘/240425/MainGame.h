#pragma once

#include "Player.h"
#include "Field.h"
#include "Store.h"
#include "Inven.h"

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
	CStore*			m_pStore;
	CInven*			m_pInven;
};

