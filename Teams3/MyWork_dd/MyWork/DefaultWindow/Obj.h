#pragma once

#include "Define.h"
#include "Structs.h"
#include "Enum.h"
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO&		Get_Info() const { return m_tInfo; }
	const D3DXVECTOR3 Get_PlayerWorldCenterPos() const { return m_vecWorldPos[int(POS::CENTER)]; }
public:
	virtual void	Initialize()		PURE;
	virtual int		Update()			PURE;
	virtual void	Late_Update()		PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release()			PURE;

public:
	D3DXMATRIX		Get_Mat_World() { return m_tInfo.matWorld; }
	D3DXMATRIX		Get_Mat_Scale() { return m_matScale; }
	D3DXMATRIX		Get_Mat_RotZ() { return m_matRotZ; }
	D3DXMATRIX		Get_Mat_Tran() { return m_matTran; }
	D3DXMATRIX		Get_Mat_Revo() { return m_matRevo; }
	D3DXMATRIX		Get_Mat_Parent() { return m_matParent; }

	
	CObj*			Get_Parent() { return m_pParent; }
	void			Set_Parent(CObj* pObj) { m_pParent = pObj; }

	bool			Get_Roting() { return m_bRoting; }
	
protected:
	INFO			m_tInfo;
	float			m_fSpeed = 0.f;
	D3DXVECTOR3		m_vScale = {0.f, 0.f, 0.f};
	D3DXVECTOR3		m_vLocalLookDir = { 0.f, -1.f, 0.f };
	D3DXVECTOR3		m_vLocalDir = { 1.f, 0.f, 0.f };

protected:
	vector<D3DXVECTOR3> m_vecLocalPos;
	vector<D3DXVECTOR3> m_vecWorldPos;

	// SRT
protected:
	D3DXMATRIX		m_matScale;		// 크
	D3DXMATRIX		m_matRotZ;		// 자
	D3DXMATRIX		m_matTran;		// 이
	D3DXMATRIX		m_matRevo;		// 공전 행렬
	D3DXMATRIX		m_matParent;	// 부모 World 행렬

	// Rot
protected:
	float	m_fDstRotRad = 0.f;		// 총 회전 theta 양
	float	m_fPreRotRad = 0.f;		// 이전 회전 theta 양
	float	m_fCurRotRad = 0.f;		// 현재 theta
	bool	m_bRoting = false;		// 돌고 있는지 유무
	float	m_fRotRadSpeed = 0.2f;	// 회전 스피드

protected:
	CObj*	m_pParent = nullptr;

};

