#include "stdafx.h"
#include "Shield.h"
#include "Enum.h"
#include "Define.h"

CShield::CShield()
{
}

CShield::~CShield()
{
	Release();
}

void CShield::Initialize()
{
	m_tInfo.vPos = { 0.f, 0.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	m_vScale = { 20.f, 20.f, 0.f };
	m_fSpeed = 0.f;

	// Set Vertex
	{
		m_vecLocalPos.resize(int(POS::END));
		m_vecWorldPos.resize(int(POS::END));

		// Center
		m_vecLocalPos[int(POS::CENTER)] = m_tInfo.vPos;

		// LT
		m_vecLocalPos[int(POS::LT)] = (D3DXVECTOR3{ -m_vScale.x * 0.5f, -m_vScale.y * 0.5f, 0.f });

		// RT
		m_vecLocalPos[int(POS::RT)] = (D3DXVECTOR3{ m_vScale.x * 0.5f, -m_vScale.y * 0.5f, 0.f });

		// LB
		m_vecLocalPos[int(POS::LB)] = (D3DXVECTOR3{ -m_vScale.x * 0.5f, m_vScale.y * 0.5f, 0.f });

		// RB
		m_vecLocalPos[int(POS::RB)] = (D3DXVECTOR3{ m_vScale.x * 0.5f, m_vScale.y * 0.5f, 0.f });
	}
}

int CShield::Update()
{
	CObj* pParent = Get_Parent();
	if (nullptr != pParent)
	{
		static float fRad = 0.f;
		static float fRadRevo = 0.f;
		
		D3DXMatrixTranslation(&m_matTran, 30.f, 30.f, 0.f);
		D3DXMatrixRotationZ(&m_matRotZ, fRad);
		D3DXMatrixRotationZ(&m_matRevo, fRadRevo);

		// auto mat2 = pParent->Get_Mat_Tran();
		// m_tInfo.matWorld = m_matRotZ * m_matTran * m_matRevo * mat2;


		m_tInfo.matWorld = m_matRotZ * m_matTran * m_matRevo * pParent->Get_Mat_World();

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		fRad += 0.05f;
		fRadRevo += 0.01f;
	}

	return OBJ_NOEVENT;
}

void CShield::Late_Update()
{
	
}

void CShield::Render(HDC hDC)
{
	// LT -> RT
	DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::LT)].x, m_vecWorldPos[int(POS::LT)].y);
	DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::RT)].x, m_vecWorldPos[int(POS::RT)].y);

	// RT- > RB
	DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::RT)].x, m_vecWorldPos[int(POS::RT)].y);
	DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::RB)].x, m_vecWorldPos[int(POS::RB)].y);

	// RB -> LB
	DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::RB)].x, m_vecWorldPos[int(POS::RB)].y);
	DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::LB)].x, m_vecWorldPos[int(POS::LB)].y);

	// LB -> LT
	DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::LB)].x, m_vecWorldPos[int(POS::LB)].y);
	DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::LT)].x, m_vecWorldPos[int(POS::LT)].y);
}

void CShield::Release()
{
}

void CShield::Set_Local_Pos(D3DXVECTOR3 vPos)
{
	m_tInfo.vPos = vPos;
}
