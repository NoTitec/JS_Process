#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	m_fSpeed = 2.f;

	m_vPoint[0] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y - 50.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y - 50.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y + 50.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y + 50.f, 0.f };

	//���� ��ǥ ����
	for (int i = 0; i < 4; ++i)
		m_vOriginPoint[i] = m_vPoint[i];

	m_vGunPoint = { m_tInfo.vPos.x, m_tInfo.vPos.y - 100.f, 0.f };
	m_vOriginGunPoint = m_vGunPoint;

}

int CPlayer::Update()
{
	Key_Input();

#pragma region ���� Ǯ�� 1

	/*for (int i = 0; i < 4; ++i)
	{
		//������ǥ ������
		D3DXVECTOR3	vTemp = m_vOriginPoint[i];
		//�̵�
		vTemp -= {400.f, 300.f, 0.f};
		//ȸ��
		m_vPoint[i].x = vTemp.x * cos(m_fAngle) - vTemp.y * sin(m_fAngle);
		m_vPoint[i].y = vTemp.x * sin(m_fAngle) + vTemp.y * cos(m_fAngle);
		//ȸ����Ų���� ������ Point�� �ݿ�
		m_vPoint[i] += m_tInfo.vPos;
	}

	D3DXVECTOR3	vTemp = m_vOriginGunPoint;

	vTemp -= {400.f, 300.f, 0.f};

	m_vGunPoint.x = vTemp.x * cos(m_fAngle) - vTemp.y * sin(m_fAngle);
	m_vGunPoint.y = vTemp.x * sin(m_fAngle) + vTemp.y * cos(m_fAngle);

	m_vGunPoint += m_tInfo.vPos;*/
#pragma endregion ���� Ǯ�� 1
	
#pragma region ���� Ǯ�� 2

	D3DXMATRIX		matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 4; ++i)
	{
		//���� ������ǥ�����Ѱ� �ҷ��ͼ� ������ǥ���̵��� ���� ��ȯ��� �����Ͽ� �̵�
		m_vPoint[i]  = m_vOriginPoint[i];
		m_vPoint[i] -= { 400.f, 300.f, 0.f};

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	m_vGunPoint = m_vOriginGunPoint;
	m_vGunPoint -= {400.f, 300.f, 0.f};

	D3DXVec3TransformCoord(&m_vGunPoint, &m_vGunPoint, &m_tInfo.matWorld);

#pragma endregion ���� Ǯ�� 2
	
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 4; ++i)
	{
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

		if(i > 1)
			continue;

		Ellipse(hDC,
			int(m_vPoint[i].x - 5.f),
			int(m_vPoint[i].y - 5.f),
			int(m_vPoint[i].x + 5.f),
			int(m_vPoint[i].y + 5.f));
	}
	LineTo(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y);
	
	// ���� �׸���

	MoveToEx(hDC, (int)m_tInfo.vPos.x, (int)m_tInfo.vPos.y, nullptr);
	LineTo(hDC, (int)m_vGunPoint.x, (int)m_vGunPoint.y);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState('A'))
		m_fAngle += D3DXToRadian(3.f);

	if (GetAsyncKeyState('D'))
		m_fAngle -= D3DXToRadian(3.f);

	if (GetAsyncKeyState('W'))
	{
		// m_tInfo.vDir.x = m_tInfo.vLook.x * cos(m_fAngle) - m_tInfo.vLook.y * sin(m_fAngle);
		// m_tInfo.vDir.y = m_tInfo.vLook.x * sin(m_fAngle) + m_tInfo.vLook.y * cos(m_fAngle);
		//?????
		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vLook, &m_tInfo.matWorld);

		m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
	}
		
	if (GetAsyncKeyState('S'))
	{
		m_tInfo.vDir.x = m_tInfo.vLook.x * cos(m_fAngle) - m_tInfo.vLook.y * sin(m_fAngle);
		m_tInfo.vDir.y = m_tInfo.vLook.x * sin(m_fAngle) + m_tInfo.vLook.y * cos(m_fAngle);

		m_tInfo.vPos += m_tInfo.vDir * -m_fSpeed;
	}
}
