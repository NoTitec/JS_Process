#pragma once

#include "Include.h"

class CToolView;
class CTerrain
{
public:
	CTerrain();
	~CTerrain();

public:
	void		Set_MainView(CToolView* pMainView) { m_pMainView = pMainView; }

public:
	void		Initialize();
	void		Update();
	void		Render();
	void		Release();

private:
	vector<TILE*>		m_vecTile;
	CToolView*			m_pMainView;
};

