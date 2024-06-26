#pragma once
#include "Obj.h"

enum class POS
{
	CENTER,
	LT,
	RT,
	RB,
	LB,
	END = 6,
};

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void   Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	virtual void      Key_Input();

private:
	void Input_Mouse();
	void Input_KeyPad();

protected:
	INFO            m_tTargetInfo;
	vector<D3DXVECTOR3> m_vecLocalPos;
	vector<D3DXVECTOR3> m_vecWorldPos;
	D3DXVECTOR3         m_vScale;

protected:
	D3DXVECTOR3 m_vLocalPosinDir = { 0.f, -1.f, 0.f };
	D3DXVECTOR3 m_vWorldPosinDir = { 0.f, -1.f, 0.f };
	float      m_fPosinLen = 50.f;

protected:
	D3DXVECTOR3 m_vLocalLookDir = { 0.f, -1.f, 0.f };
	D3DXVECTOR3 m_vLocalDir = { 1.f, 0.f, 0.f };

	// SRT
protected:
	D3DXMATRIX m_matScale;
	D3DXMATRIX m_matRotZ;
	D3DXMATRIX m_matTran;

protected:
	D3DXVECTOR3 m_vMousePos = { 400.f, 300.f, 0.f };

protected:
	float m_fRotAngle = 0.f;

protected:
	bool m_bMoving = false;
	float m_fRotRadSpeed = 0.02f;

protected:
	float m_fDstRotRad = 0.f;
	float m_fPreRotRad = 0.f;

protected:
	float m_fCurRotRad = 0.f;
};


