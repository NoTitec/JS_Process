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

	int			Get_TileIndex(const D3DXVECTOR3& vPos);
	void		Tile_Change(const D3DXVECTOR3& vPos, const int& iDrawID);
	bool		Picking(const D3DXVECTOR3& vPos, const int& iIndex);

	bool		Picking_Dot(const D3DXVECTOR3& vPos, const int& iIndex);

	void		Set_Ratio(D3DXMATRIX* pMatrix, float fX, float fY);

public:
	void		Initialize();
	void		Update();
	void		Mini_Render();
	void		Render();
	void		Release();

private:
	vector<TILE*>		m_vecTile;
	CToolView*			m_pMainView;
};

