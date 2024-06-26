#pragma once
#include "Obj.h"

class CMonster : public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	void		Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

public:
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;

private:
	CObj*		m_pPlayer;

protected:
	vector<D3DXVECTOR3> m_vecLocalPos; // resize ÇÊ¿ä
};

