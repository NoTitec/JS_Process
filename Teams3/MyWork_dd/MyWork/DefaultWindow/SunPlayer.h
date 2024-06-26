#pragma once
#include "Obj.h"
class CSunPlayer :
    public CObj
{
public:
	CSunPlayer();
	virtual ~CSunPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void	Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	virtual void		Key_Input();

private:
	void Input_Mouse();
	void Input_KeyPad();

private:
	void RotZ();
	void Go_Strait();

public:
	void Set_Shield(CObj* pObj) { m_vecShield.push_back(pObj); }

private:
	D3DXVECTOR3 m_vLocalPosinDir = { 0.f, -1.f, 0.f };
	D3DXVECTOR3 m_vWorldPosinDir = { 0.f, -1.f, 0.f };
	float		m_fPosinLen = 50.f;

private:
	D3DXVECTOR3 m_vMousePos = { 400.f, 300.f, 0.f };

private:
	float	m_fRotAngle = 0.f; // 키보드 입력으로 회전할 때 필요한 멤버 변수

private:
	vector<CObj*> m_vecShield;
};

