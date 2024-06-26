#include "stdafx.h"
#include "SunPlayer.h"
#include "MainGame.h"
#include "KeyMgr.h"
#include "Structs.h"
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
	m_vScale = { 50.f, 50.f, 0.f };
	m_fSpeed = 2.f;

	//m_fPreAngle = 0.f; 
	m_bMoving = false;
	m_fRotRadSpeed = 0.f;
	m_fPreRotRad = 0.f;
	m_fCurRotRad = 0.f;
	
	m_vecLocalPos.resize(int(POS::END));
	m_vecWorldPos.resize(int(POS::END));

	m_vecLocalPos[int(POS::CENTER)] = m_tInfo.vPos;
	m_vecLocalPos[int(POS::LT)] = (D3DXVECTOR3{ -m_vScale.x * 0.5f, -m_vScale.y * 0.5f, 0.f });
	m_vecLocalPos[int(POS::RT)] = (D3DXVECTOR3{ m_vScale.x * 0.5f, -m_vScale.y * 0.5f, 0.f });
	m_vecLocalPos[int(POS::LB)] = (D3DXVECTOR3{ -m_vScale.x * 0.5f, m_vScale.y * 0.5f, 0.f });
	m_vecLocalPos[int(POS::RB)] = (D3DXVECTOR3{ m_vScale.x * 0.5f, m_vScale.y * 0.5f, 0.f });

	D3DXMatrixScaling(&m_matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&m_matRotZ, 0.f);
	D3DXMatrixTranslation(&m_matTran, WINCX / 2.f, WINCY / 2.f, 0.f);

	m_tInfo.matWorld = m_matScale * m_matRotZ * m_matTran;

	for (int i = 0; i < int(POS::END) - 1; ++i)
	{
		D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);
	}
	D3DXVec3TransformNormal(&m_tInfo.vLook, &m_vLocalLookDir, &m_matRotZ);

}

int CSunPlayer::Update()
{
	//Sun_Key_Input();
	Input_Mouse();
	RotZ();
	Go_Straight();
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
		//������ǥ�� �÷��̾� ����
		DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y);
		//������ǥ�� ��������
		DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x + (m_vWorldPosinDir * m_fPosinLen).x, m_vecWorldPos[int(POS::CENTER)].y + (m_vWorldPosinDir * m_fPosinLen).y);
	}

	// Render Pivot
	{
		DRAW_ELLIPSE(hDC, m_vecWorldPos[int(POS::RT)].x - 7.f, m_vecWorldPos[int(POS::RT)].y - 7.f, m_vecWorldPos[int(POS::RT)].x + 7.f, m_vecWorldPos[int(POS::RT)].y + 7.f);
		DRAW_ELLIPSE(hDC, m_vecWorldPos[int(POS::LT)].x - 7.f, m_vecWorldPos[int(POS::LT)].y - 7.f, m_vecWorldPos[int(POS::LT)].x + 7.f, m_vecWorldPos[int(POS::LT)].y + 7.f);
	}

	// Render Look Dir
	{
		DRAW_START_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y);
		DRAW_END_LINE(hDC, m_vecWorldPos[int(POS::CENTER)].x + (m_tInfo.vLook * (m_fPosinLen-20.f)).x, m_vecWorldPos[int(POS::CENTER)].y + (m_tInfo.vLook * (m_fPosinLen-20.f)).y);
	}
}

void CSunPlayer::Release()
{
}

void CSunPlayer::Sun_Key_Input()
{
	if (KEYMGR->Key_Pressing('W'))
	{
		m_vecWorldPos[int(POS::CENTER)] += m_tInfo.vLook * m_fSpeed;

		D3DXMatrixRotationZ(&m_matRotZ, m_fCurRotRad);
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		// Update Posin Pos
		/*{
			D3DXVec3TransformNormal(&m_vWorldPosinDir, &m_vLocalPosinDir, &m_matTran);
		}*/
	}

	if (KEYMGR->Key_Pressing('S'))
	{
		//������ǥ�� �ڱ� ����*�ӵ���ŭ +
		m_vecWorldPos[int(POS::CENTER)] += m_tInfo.vLook * -m_fSpeed;

		D3DXMatrixRotationZ(&m_matRotZ, m_fCurRotRad);
		D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
		m_tInfo.matWorld = m_matRotZ * m_matTran;

		for (int i = 0; i < int(POS::END) - 1; ++i)
			D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

		// Update Posin Pos
		/*{
			D3DXVec3TransformNormal(&m_vWorldPosinDir, &m_vLocalPosinDir, &m_matTran);
		}*/
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

	if (KEYMGR->Key_Pressing(VK_LEFT))
	{
		m_fPosinRotAngle += -2.f;
		D3DXMatrixRotationZ(&m_matRotZ, D3DXToRadian(m_fPosinRotAngle));
		m_tInfo.matWorld = m_matRotZ;
		D3DXVec3TransformNormal(&m_vWorldPosinDir, &m_vLocalPosinDir, &m_matRotZ);
		
	}
	if (KEYMGR->Key_Pressing(VK_RIGHT))
	{
		m_fPosinRotAngle += 2.f;
		D3DXMatrixRotationZ(&m_matRotZ, D3DXToRadian(m_fPosinRotAngle));
		m_tInfo.matWorld = m_matRotZ;
		D3DXVec3TransformNormal(&m_vWorldPosinDir, &m_vLocalPosinDir, &m_matRotZ);

	}
	//if (KEYMGR->Key_Down(VK_LBUTTON))
	//{
	//	POINT   pt{};
	//	GetCursorPos(&pt);
	//	ScreenToClient(GAME->Get_HWND(), &pt);
	//	m_vMousePos = { (float)pt.x, (float)pt.y, 0.f };

	//	D3DXVECTOR3 vDstDir = m_vMousePos - m_vecWorldPos[int(POS::CENTER)];
	//	D3DXVec3Normalize(&vDstDir, &vDstDir);

	//	float fDotLook = D3DXVec3Dot(&vDstDir, &m_tInfo.vLook);
	//	float fDotRight = D3DXVec3Dot(&vDstDir, &m_tInfo.vDir);

	//	// 1. ���� ���� ���� 0~PI���� PI~2PI���� �б� ó���Ѵ�.
	//	// 1-1. ������ ���� ����� ���
	//	// (��ī��Ʈ ��ǥ�� �������� 3~4��и� ��򰡿� vDir�� ������ �ִ�.)
	//	if (fDotLook >= 0)
	//	{
	//		float fTheta = acosf(fDotLook);

	//		// vDstDir�� ����Ű�� ������ 3��и����� 4��и����� �б��ϱ� ���� �÷��̾��� right ���� ���Ϳ� ������ �ѹ��� �����Ѵ�.
	//		// 
	//		// 
	//		// ������ ���� ������ vDstDir�� ������ 4��и鿡 ��� ����Ŵ
	//		// (��ī��Ʈ ����)
	//		// ������ ���� ������� vDstDir�� ������ 3��и鿡 ��� ����Ŵ
	//		// (��ī��Ʈ ����)
	//		if (fDotRight <= 0)
	//			fTheta = -fTheta;

	//		m_fDstRotRad = fTheta;
	//	}
	//	// 1-2. ������ ���� �����ΰ��
	//	// (��ī��Ʈ ��ǥ�� �������� 1~2�� �и� ��򰡿� vDir������ �ִ�.)
	//	else
	//	{
	//		float fTheta = acosf(fDotLook);

	//		// vDstDir�� ����Ű�� ������ 1��и����� 2��и����� �б��ϱ� ���� �÷��̾��� right ���� ���Ϳ� ������ �ѹ��� �����Ѵ�.
	//		// ������ ���� ������ vDstDir�� ������ 4��и鿡 ��� ����Ŵ
	//		// (��ī��Ʈ ����)
	//		// ������ ���� ������� vDstDir�� ������ 3��и鿡 ��� ����Ŵ
	//		// (��ī��Ʈ ����)

	//		if (fDotRight <= 0)
	//			fTheta = -fTheta;

	//		m_fDstRotRad = fTheta;
	//	}

	//	D3DXMatrixRotationZ(&m_matRotZ, m_fDstRotRad);
	//	D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);

	//	m_tInfo.matWorld = m_matRotZ * m_matTran;

	//	for (int i = 0; i < int(POS::END) - 1; ++i)
	//	{
	//		D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);
	//	}


	//	D3DXVec3TransformNormal(&m_tInfo.vLook, &m_tInfo.vLook, &m_tInfo.matWorld);
	//	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);

	//	m_bMoving = true;
	//}
	// 
	// 
	//���콺 �����µ��� �̵��ϴ� ��� �ϴ� ������� �ּ�ó��
	//if (KEYMGR->Key_Pressing(VK_LBUTTON))
	//{

	//	//���콺 ��ǥ get
	//	POINT	ptMouse{};

	//	GetCursorPos(&ptMouse);
	//	ScreenToClient(g_hWnd, &ptMouse);

	//	//���콺�� ���⺤�� ���ϱ�
	//	m_tInfo.vDir.x = (float)ptMouse.x - m_vecWorldPos[int(POS::CENTER)].x;
	//	m_tInfo.vDir.y = (float)ptMouse.y - m_vecWorldPos[int(POS::CENTER)].y;

	//	//���� ����ȭ
	//	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	//	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);

	//	//����
	//	float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);
	//	//float	fAngle = acos(fDot);
	//	//���� �ڱ� vpos.y ���� ġ�� ����
	//	//���� �ڱ� vpos.y ���� ���콺 y�� ũ�� �������ϴ����� �ڱ⺸�� �Ʒ��Ƿ� �����ؾ���
	//	//if (m_tInfo.vPos.y < ptMouse.y)
	//		//fAngle = 2.f * D3DX_PI - fAngle;

	//	//�ٶ󺸴� ���⸸ŭ�� ȸ����� ����
	//	//m_fRotAngle = fAngle;
	//	float	fAngle = acos(fDot);
	//	
	//	if (m_vecWorldPos[int(POS::CENTER)].x >= ptMouse.x)
	//		fAngle = D3DXToRadian(360) - fAngle;
	//	D3DXMatrixRotationZ(&m_matRotZ, fAngle);
	//	// Update Look Dir
	//	{
	//		//D3DXVec3TransformNormal(&m_tInfo.vLook, &m_vLocalLookDir, &m_matRotZ);
	//		//m_tInfo.vLook = m_tInfo.vDir;
	//	}
	//	//���� ��ǥ pos ����
	//	m_vecWorldPos[int(POS::CENTER)] += m_tInfo.vDir * m_fSpeed;
	//	D3DXMatrixTranslation(&m_matTran, m_vecWorldPos[int(POS::CENTER)].x, m_vecWorldPos[int(POS::CENTER)].y, 0.f);
	//	m_tInfo.matWorld = m_matRotZ*m_matTran;

	//	for (int i = 0; i < int(POS::END) - 1; ++i)
	//		D3DXVec3TransformCoord(&m_vecWorldPos[i], &m_vecLocalPos[i], &m_tInfo.matWorld);

	//	
	//}
}

void CSunPlayer::RotZ()
{
	// 4�ܰ�
	if (m_bMoving)
	{
		if (m_fRotRadSpeed >= 0)
		{
			if ((m_fCurRotRad + m_fRotRadSpeed) < (m_fDstRotRad + m_fPreRotRad))
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
				// m_fCurRotRad = 0.f;
				m_bMoving = false;
			}
		}
		else
		{
			if ((m_fCurRotRad + m_fRotRadSpeed) > (m_fDstRotRad + m_fPreRotRad))
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
				// m_fCurRotRad = 0.f;
				m_bMoving = false;
			}
		}
	}
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

		// 2 �ܰ�
		m_fPreRotRad = m_fPreRotRad + m_fDstRotRad;
		m_fDstRotRad = fTheta;


		// Look, Right RotZ
		{
			D3DXMatrixRotationZ(&m_matRotZ, m_fDstRotRad);
			m_tInfo.matWorld = m_matRotZ;
			D3DXVec3TransformNormal(&m_tInfo.vLook, &m_tInfo.vLook, &m_tInfo.matWorld);
			D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
		}

		// 3 �ܰ�
		m_bMoving = true;
		m_fCurRotRad = m_fPreRotRad;
	}
}

void CSunPlayer::Go_Straight()
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
