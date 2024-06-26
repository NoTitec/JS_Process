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
	D3DXMATRIX		m_matScale;		// ũ
	D3DXMATRIX		m_matRotZ;		// ��
	D3DXMATRIX		m_matTran;		// ��
	D3DXMATRIX		m_matRevo;		// ���� ���
	D3DXMATRIX		m_matParent;	// �θ� World ���

	// Rot
protected:
	float	m_fDstRotRad = 0.f;		// �� ȸ�� theta ��
	float	m_fPreRotRad = 0.f;		// ���� ȸ�� theta ��
	float	m_fCurRotRad = 0.f;		// ���� theta
	bool	m_bRoting = false;		// ���� �ִ��� ����
	float	m_fRotRadSpeed = 0.2f;	// ȸ�� ���ǵ�

protected:
	CObj*	m_pParent = nullptr;

};

