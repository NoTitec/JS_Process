#include "stdafx.h"
#include "SunPlayer.h"
#include "MainGame.h"
#include "KeyMgr.h"
#include "Structs.h"
#include "Func.h"
#include "Enum.h"

CSunPlayer::CSunPlayer()
{

}


CSunPlayer::~CSunPlayer()
{
	Release();
}

static float fX = 400.f;
static float fY = 300.f;

void CSunPlayer::Initialize()
{
	m_tInfo.vPos = { 0.f, 0.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };
	m_vScale = { 20.f, 20.f, 1.f };
	m_fSpeed = 1.5f;

	// Set Local Pos
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

	D3DXMatrixScaling(&m_matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&m_matRotZ, 0.f);
	D3DXMatrixTranslation(&m_matTran, fX, fY, 0.f);

	m_tInfo.matWorld = m_matScale * m_matRotZ * m_matTran;

	for (int i = 0; i < int(POS::END) - 1; ++i)
		D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);
}


int CSunPlayer::Update()
{
	Key_Input();
	Go_Strait();
	RotZ();

	return OBJ_NOEVENT;
}

void CSunPlayer::Late_Update()
{

}

void CSunPlayer::Render(HDC hDC)
{
	// Render Tank
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

	// Render Posin
	{
		//DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y);
		//DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x + (m_vWorldPosinDir * m_fPosinLen).x, m_vecWorldPos[int(POS::CENTER)].y + (m_vWorldPosinDir * m_fPosinLen).y);
	}

	// Render Pivot
	{
		DRAW_ELLIPSE(hDC, m_vecWorldPos[int(POS::RT)].x - 7.f, m_vecWorldPos[int(POS::RT)].y - 7.f, m_vecWorldPos[int(POS::RT)].x + 7.f, m_vecWorldPos[int(POS::RT)].y + 7.f);
		DRAW_ELLIPSE(hDC, m_vecWorldPos[int(POS::LT)].x - 7.f, m_vecWorldPos[int(POS::LT)].y - 7.f, m_vecWorldPos[int(POS::LT)].x + 7.f, m_vecWorldPos[int(POS::LT)].y + 7.f);
	}

	// Render Look Dir
	{
		DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y);
		DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x + (m_tInfo.vLook * 20.f).x, m_vecWorldPos[int(POS::CENTER)].y + (m_tInfo.vLook * 20.f).y);
	}

	// Render Right Dir
	{
		DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y);
		DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x + (m_tInfo.vDir * 25.f).x, m_vecWorldPos[int(POS::CENTER)].y + (m_tInfo.vDir * 25.f).y);
	}
}

void CSunPlayer::Release()
{

}

void CSunPlayer::Key_Input()
{
	// Input_KeyPad();
	Input_Mouse();
}

void CSunPlayer::Input_Mouse()
{
	if (KEYMGR->Key_Down(VK_LBUTTON))
	{
		POINT   pt{};
		GetCursorPos(&pt);
		ScreenToClient(GAME->Get_HWND(), &pt);
		m_vMousePos = { (float)pt.x, (float)pt.y, 0.f };

		D3DXVECTOR3 vDstDir = m_vMousePos - m_vecWorldPos[int(POS::CENTER)];
		D3DXVec3Normalize(&vDstDir, &vDstDir);

		float fDotLook = D3DXVec3Dot(&vDstDir, &m_tInfo.vLook);
		float fDotRight = D3DXVec3Dot(&vDstDir, &m_tInfo.vDir);
		float fTheta = 0.f;

		if (fDotLook >= 0)
		{
			fTheta = acosf(fDotLook);

			if (fDotRight <= 0)
			{
				fTheta = -fTheta;
				m_fRotRadSpeed = -0.02f;
			}
			else
				m_fRotRadSpeed = 0.02f;
		}
		else
		{
			fTheta = acosf(fDotLook);

			if (fDotRight <= 0)
			{
				fTheta = -fTheta;
				m_fRotRadSpeed = -0.02f;
			}
			else
				m_fRotRadSpeed = 0.02f;
		}

		// 2 단계
		m_fPreRotRad = m_fPreRotRad + m_fDstRotRad;
		m_fDstRotRad = fTheta;


		// Look, Right RotZ
		{
			D3DXMatrixRotationZ(&m_matRotZ, m_fDstRotRad);
			m_tInfo.matWorld = m_matRotZ;
			D3DXVec3TransformNormal(&m_tInfo.vLook, &m_tInfo.vLook, &m_tInfo.matWorld);
			D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
		}

		// 3 단계
		m_bRoting = true;
		m_fCurRotRad = m_fPreRotRad;
	}
}

void CSunPlayer::Input_KeyPad()
{
	if (KEYMGR->Key_Pressing('W'))
	{
		m_vecWorldPos[int(POS::CENTER)] += m_tInfo.vLook * m_fSpeed;

		D3DXMatrixRotationZ(&m_matRotZ, D3DXToRadian(m_fRotAngle));
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		// Update Posin Pos
		{
			D3DXVec3TransformNormal(&m_vWorldPosinDir, &m_vLocalPosinDir, &m_matTran);
		}
	}

	if (KEYMGR->Key_Pressing('S'))
	{
		m_vecWorldPos[int(POS::CENTER)] += m_tInfo.vLook * -m_fSpeed;

		D3DXMatrixRotationZ(&m_matRotZ, D3DXToRadian(m_fRotAngle));
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		// Update Posin Pos
		{
			D3DXVec3TransformNormal(&m_vWorldPosinDir, &m_vLocalPosinDir, &m_matTran);
		}
	}

	if (KEYMGR->Key_Pressing('A'))
	{
		m_fRotAngle -= 1.f;

		D3DXMatrixRotationZ(&m_matRotZ, D3DXToRadian(m_fRotAngle));
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		// Update Look Dir
		{
			D3DXVec3TransformNormal(&m_tInfo.vLook, &m_vLocalLookDir, &m_matRotZ);
		}
	}

	if (KEYMGR->Key_Pressing('D'))
	{
		m_fRotAngle += 1.f;

		D3DXMatrixRotationZ(&m_matRotZ, D3DXToRadian(m_fRotAngle));
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);

		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		// Update Look Dir
		{
			D3DXVec3TransformNormal(&m_tInfo.vLook, &m_vLocalLookDir, &m_matRotZ);
		}
	}
}

void CSunPlayer::RotZ()
{
	// 4단계
	if (m_bRoting)
	{
		// 양수 회전 (오른쪽으로 회전하는 경우)
		if (m_fRotRadSpeed >= 0)
		{
			if ((m_fCurRotRad + m_fRotRadSpeed) <= (m_fDstRotRad + m_fPreRotRad))
			{
				m_fCurRotRad += m_fRotRadSpeed;
				D3DXMatrixRotationZ(&m_matRotZ, m_fCurRotRad);
				D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
				m_tInfo.matWorld = m_matRotZ * m_matTran;

				for (int i = 0; i < int(POS::END) - 1; ++i)
					D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);
			}
			else
			{
				m_bRoting = false;
			}
		}
		// 음수 회전 (왼쪽으로 회전하는 경우)
		else
		{
			if ((m_fCurRotRad + m_fRotRadSpeed) >= (m_fDstRotRad + m_fPreRotRad))
			{
				m_fCurRotRad += m_fRotRadSpeed;
				D3DXMatrixRotationZ(&m_matRotZ, m_fCurRotRad);
				D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
				m_tInfo.matWorld = m_matRotZ * m_matTran;

				for (int i = 0; i < int(POS::END) - 1; ++i)
					D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);
			}
			else
			{
				m_bRoting = false;
			}
		}
	}
}

void CSunPlayer::Go_Strait()
{
	if (Equals(m_vMousePos.x, m_vecWorldPos[int(POS::CENTER)].x) == false && Equals(m_vMousePos.y, m_vecWorldPos[int(POS::CENTER)].y) == false)
	{
		m_vecWorldPos[int(POS::CENTER)] += m_tInfo.vLook * m_fSpeed;
		D3DXMatrixRotationZ(&m_matRotZ, m_fCurRotRad);
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
		{
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);
		}
	}
}