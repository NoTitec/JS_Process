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
	//위치벡터
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	//방향벡터
	m_tInfo.vLook = { 1.f, 0.f, 0.f };

	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
	//키입력 처리
	Key_Input();
	m_tPosin.x = m_tInfo.vPos.x + m_fDistance * cos(m_fRotation * (D3DX_PI / 180.f));
	m_tPosin.x = m_tInfo.vPos.y - m_fDistance * sin(m_fRotation * (D3DX_PI / 180.f));

#pragma region 과제 풀이
	//플레이어에서 마우스 포인터쪽의 방향벡터 구하기
	//m_tInfo.vDir = Get_Mouse() - m_tInfo.vPos;
	// 
	//위치벡터 정규화
	/*float fLength = sqrt(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;*/

	//D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	// 
	//방향벡터 정규화
	/*float fLength2 = sqrt(m_tInfo.vLook.x * m_tInfo.vLook.x + m_tInfo.vLook.y * m_tInfo.vLook.y);

	m_tInfo.vLook.x /= fLength2;
	m_tInfo.vLook.y /= fLength2;
	m_tInfo.vLook.z = 0.f;*/

	//D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);


	//벡터 내적
	//float	fDot = m_tInfo.vDir.x * m_tInfo.vLook.x + m_tInfo.vDir.y * m_tInfo.vLook.y;
	//float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);
	//float	fAngle = acos(fDot);

	//if (m_tInfo.vPos.y < Get_Mouse().y)
	//	fAngle = 2.f * D3DX_PI - fAngle;

	//m_tInfo.vPos.x += cos(fAngle) * m_fSpeed;
	//m_tInfo.vPos.y -= sin(fAngle) * m_fSpeed;
#pragma endregion 과제 풀이

	// 벡터의 정규화를 수행하는 함수
	//D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	//D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);

	// 벡터의 크기를 구해주는 함수
	// float	fLength = D3DXVec3Length(&m_tInfo.vDir);

	// 두 방향 벡터의 내적의 결과를 구해주는 함수
	// float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);

	// 두 방향 벡터의 외적의 결과를 구해주는 함수
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
	// 월드행렬 생성시 반드시 아래과정 거쳐야 정상적으로 월드행렬 완성됨, D3DXMATRIX 각각 하나씩 곱하는 순서 모두 정확히 맞아야함 크자이로 외울것
	// D3DXMATRIX		matScale, matRotZ, matTrans;
	// 
	// D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	// D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	// D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f);
	// 
	// // 월드 행렬 = 크기 * 자전(회전) * 이동 * (공전(회전) * 부모)
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
		// 회전 속도 5도씩 (라디안으로 변환)
		float rotationSpeed = D3DXToRadian(1.0f);

		// 현재 회전 값에 더하기
		m_fRotation -= rotationSpeed;

		// 플레이어의 위치를 원점으로 이동
		D3DXMATRIX matTranslateToOrigin;
		D3DXMatrixTranslation(&matTranslateToOrigin, -m_tInfo.vPos.x, -m_tInfo.vPos.y, 0.0f);
		// 회전 행렬 생성
		D3DXMATRIX matRotate;
		D3DXMatrixRotationZ(&matRotate, m_fRotation);

		// 다시 원래 위치로 이동
		D3DXMATRIX matTranslateBack;
		D3DXMatrixTranslation(&matTranslateBack, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);

		// 최종 행렬 계산 (순서 중요: 원점으로 이동 -> 회전 -> 원래 위치로 이동)
		D3DXMATRIX matFinal = matTranslateToOrigin * matRotate * matTranslateBack;

		// 현재 위치 벡터 생성
		D3DXVECTOR3 currentPosition(m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);
		D3DXVECTOR3 newPosition;

		// 회전 행렬 적용
		D3DXVec3TransformCoord(&newPosition, &currentPosition, &matRotate);

		// 위치 업데이트
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
		// 회전 속도 5도씩 (라디안으로 변환)
		float rotationSpeed = D3DXToRadian(-1.0f);

		// 현재 회전 값에 더하기
		m_fRotation -= rotationSpeed;

		// 플레이어의 위치를 원점으로 이동
		D3DXMATRIX matTranslateToOrigin;
		D3DXMatrixTranslation(&matTranslateToOrigin, -m_tInfo.vPos.x, -m_tInfo.vPos.y, 0.0f);
		// 회전 행렬 생성
		D3DXMATRIX matRotate;
		D3DXMatrixRotationZ(&matRotate, m_fRotation);

		// 다시 원래 위치로 이동
		D3DXMATRIX matTranslateBack;
		D3DXMatrixTranslation(&matTranslateBack, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);

		// 최종 행렬 계산 (순서 중요: 원점으로 이동 -> 회전 -> 원래 위치로 이동)
		D3DXMATRIX matFinal = matTranslateToOrigin * matRotate * matTranslateBack;

		// 현재 위치 벡터 생성
		D3DXVECTOR3 currentPosition(m_tInfo.vPos.x, m_tInfo.vPos.y, 0.0f);
		D3DXVECTOR3 newPosition;

		// 회전 행렬 적용
		D3DXVec3TransformCoord(&newPosition, &currentPosition, &matRotate);

		// 위치 업데이트
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

