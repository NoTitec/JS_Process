#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void		Key_Input();
	
	D3DXVECTOR3				m_tPosin;
	float		m_fDistance;
	float		m_fRotation;
	D3DXMATRIX		matScale, matRotZ, matTrans;
};

