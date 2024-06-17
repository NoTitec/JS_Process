#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	//��ġ����
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	//���⺤��
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
	//Ű�Է� ó��
	Key_Input();
	m_tPosin.x = m_tInfo.vPos.x + m_fDistance * cos(m_fRotation * (D3DX_PI / 180.f));
	m_tPosin.x = m_tInfo.vPos.y - m_fDistance * sin(m_fRotation * (D3DX_PI / 180.f));

#pragma region ���� Ǯ��
	//�÷��̾�� ���콺 ���������� ���⺤�� ���ϱ�
	//m_tInfo.vDir = Get_Mouse() - m_tInfo.vPos;
	// 
	//��ġ���� ����ȭ
	/*float fLength = sqrt(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;*/

	//D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	// 
	//���⺤�� ����ȭ
	/*float fLength2 = sqrt(m_tInfo.vLook.x * m_tInfo.vLook.x + m_tInfo.vLook.y * m_tInfo.vLook.y);

	m_tInfo.vLook.x /= fLength2;
	m_tInfo.vLook.y /= fLength2;
	m_tInfo.vLook.z = 0.f;*/

	//D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);


	//���� ����
	//float	fDot = m_tInfo.vDir.x * m_tInfo.vLook.x + m_tInfo.vDir.y * m_tInfo.vLook.y;
	//float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);
	//float	fAngle = acos(fDot);

	//if (m_tInfo.vPos.y < Get_Mouse().y)
	//	fAngle = 2.f * D3DX_PI - fAngle;

	//m_tInfo.vPos.x += cos(fAngle) * m_fSpeed;
	//m_tInfo.vPos.y -= sin(fAngle) * m_fSpeed;
#pragma endregion ���� Ǯ��

	// ������ ����ȭ�� �����ϴ� �Լ�
	//D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	//D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);

	// ������ ũ�⸦ �����ִ� �Լ�
	// float	fLength = D3DXVec3Length(&m_tInfo.vDir);

	// �� ���� ������ ������ ����� �����ִ� �Լ�
	// float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);

	// �� ���� ������ ������ ����� �����ִ� �Լ�
	// D3DXVECTOR3	vAxis;
	// vAxis = *D3DXVec3Cross(&vAxis, &m_tInfo.vDir, &m_tInfo.vLook);

	//float	fAngle = acos(fDot);
	//
	/*if (m_tInfo.vPos.y < Get_Mouse().y)
		fAngle = 2.f * D3DX_PI - fAngle;*/
	//
	//m_tInfo.vPos.x += cos(fAngle) * m_fSpeed;
	//m_tInfo.vPos.y -= sin(fAngle) * m_fSpeed;
	//
	// ������� ������ �ݵ�� �Ʒ����� ���ľ� ���������� ������� �ϼ���, D3DXMATRIX ���� �ϳ��� ���ϴ� ���� ��� ��Ȯ�� �¾ƾ��� ũ���̷� �ܿ��
	// D3DXMATRIX		matScale, matRotZ, matTrans;
	// 
	// D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	// D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	// D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f);
	// 
	// // ���� ��� = ũ�� * ����(ȸ��) * �̵� * (����(ȸ��) * �θ�)
	// m_tInfo.matWorld = matScale * matRotZ * matTrans;
	
	//m_tPosin.x= m_tInfo.vPos.x + cos(fAngle) * m_fDistance;
	//m_tPosin.y = m_tInfo.vPos.y- sin(fAngle) * m_fDistance;
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_tInfo.vPos.x - 50.f,(int)m_tInfo.vPos.y - 50.f,NULL);
	LineTo(hDC, m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y - 50.f);

	MoveToEx(hDC, (int)m_tInfo.vPos.x + 50.f, (int)m_tInfo.vPos.y - 50.f, NULL);
	LineTo(hDC, m_tInfo.vPos.x + 50.f, m_tInfo.vPos.y + 50.f);

	MoveToEx(hDC, (int)m_tInfo.vPos.x + 50.f, (int)m_tInfo.vPos.y + 50.f, NULL);
	LineTo(hDC, m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y + 50.f);

	MoveToEx(hDC, (int)m_tInfo.vPos.x - 50.f, (int)m_tInfo.vPos.y + 50.f, NULL);
	LineTo(hDC, m_tInfo.vPos.x - 50.f, m_tInfo.vPos.y - 50.f);

	MoveToEx(hDC, (int)m_tInfo.vPos.x , (int)m_tInfo.vPos.y , NULL);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);

	/*Rectangle(hDC, 
		int(m_tInfo.vPos.x - 50.f), 
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));*/
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	// GetKeyState()
	if (CKeyMgr::Get_Instance()->Key_Pressing('W'))
	{
		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);

		D3DXMATRIX matTranslate;
		D3DXMatrixTranslation(&matTranslate, 0.0f, -m_fSpeed, 0.0f);

		D3DXVECTOR3 currentPosition(m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);
		D3DXVECTOR3 newPosition;

		D3DXVec3TransformCoord(&newPosition, &currentPosition, &matTranslate);

		m_tInfo.vPos.x = newPosition.x;
		m_tInfo.vPos.y = newPosition.y;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('A'))
	{
		// ȸ�� �ӵ� 5���� (�������� ��ȯ)
		float rotationSpeed = D3DXToRadian(1.0f);

		// ���� ȸ�� ���� ���ϱ�
		m_fRotation -= rotationSpeed;

		// �÷��̾��� ��ġ�� �������� �̵�
		D3DXMATRIX matTranslateToOrigin;
		D3DXMatrixTranslation(&matTranslateToOrigin, -m_tInfo.vPos.x, -m_tInfo.vPos.y, 0.0f);
		// ȸ�� ��� ����
		D3DXMATRIX matRotate;
		D3DXMatrixRotationZ(&matRotate, m_fRotation);

		// �ٽ� ���� ��ġ�� �̵�
		D3DXMATRIX matTranslateBack;
		D3DXMatrixTranslation(&matTranslateBack, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);

		// ���� ��� ��� (���� �߿�: �������� �̵� -> ȸ�� -> ���� ��ġ�� �̵�)
		D3DXMATRIX matFinal = matTranslateToOrigin * matRotate * matTranslateBack;

		// ���� ��ġ ���� ����
		D3DXVECTOR3 currentPosition(m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);
		D3DXVECTOR3 newPosition;

		// ȸ�� ��� ����
		D3DXVec3TransformCoord(&newPosition, &currentPosition, &matRotate);

		// ��ġ ������Ʈ
		m_tInfo.vPos.x = newPosition.x;
		m_tInfo.vPos.y = newPosition.y;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('S'))
	{
		// Create an identity matrix
		D3DXMATRIX matIdentity;
		D3DXMatrixIdentity(&matIdentity);

		// Create a translation matrix
		D3DXMATRIX matTranslate;
		D3DXMatrixTranslation(&matTranslate, 0.0f, m_fSpeed, 0.0f);

		// Create a vector for the current position
		D3DXVECTOR3 currentPosition(m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);
		D3DXVECTOR3 newPosition;

		// Apply the translation to the current position
		D3DXVec3TransformCoord(&newPosition, &currentPosition, &matTranslate);

		// Update the position
		m_tInfo.vPos.x = newPosition.x;
		m_tInfo.vPos.y = newPosition.y;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('D'))
	{
		// ȸ�� �ӵ� 5���� (�������� ��ȯ)
		float rotationSpeed = D3DXToRadian(-1.0f);

		// ���� ȸ�� ���� ���ϱ�
		m_fRotation -= rotationSpeed;

		// �÷��̾��� ��ġ�� �������� �̵�
		D3DXMATRIX matTranslateToOrigin;
		D3DXMatrixTranslation(&matTranslateToOrigin, -m_tInfo.vPos.x, -m_tInfo.vPos.y, 0.0f);
		// ȸ�� ��� ����
		D3DXMATRIX matRotate;
		D3DXMatrixRotationZ(&matRotate, m_fRotation);

		// �ٽ� ���� ��ġ�� �̵�
		D3DXMATRIX matTranslateBack;
		D3DXMatrixTranslation(&matTranslateBack, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);

		// ���� ��� ��� (���� �߿�: �������� �̵� -> ȸ�� -> ���� ��ġ�� �̵�)
		D3DXMATRIX matFinal = matTranslateToOrigin * matRotate * matTranslateBack;

		// ���� ��ġ ���� ����
		D3DXVECTOR3 currentPosition(m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);
		D3DXVECTOR3 newPosition;

		// ȸ�� ��� ����
		D3DXVec3TransformCoord(&newPosition, &currentPosition, &matRotate);

		// ��ġ ������Ʈ
		m_tInfo.vPos.x = newPosition.x;
		m_tInfo.vPos.y = newPosition.y;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_fRotation += 5.f;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		m_fRotation -= 5.f;
	}
}

