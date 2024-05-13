#include "Zombie.h"
#include "stdafx.h"
CZombie::CZombie()
{

}

CZombie::~CZombie()
{

}

void CZombie::Initialize()
{
	int itemp = rand() % 3;

	switch (itemp)
	{
	case 0:
		Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		m_eZtype = NORMAL_ZOMBIE;
		m_tInfo.fCX = 40.0f;
		m_tInfo.fCY = 40.0f;
		m_fSpeed = 5.0f;
		break;
	case 1:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		m_eZtype = LIGHT_ZOMBIE;
		m_tInfo.fCX = 20.0f;
		m_tInfo.fCY = 20.0f;
		m_fSpeed = 7.0f;
		break;
	case 2:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		m_eZtype = HEAVY_ZOMBIE;
		m_tInfo.fCX = 60.0f;
		m_tInfo.fCY = 60.0f;
		m_fSpeed = 2.0f;
		break;
	}
}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CZombie::Late_Update()
{
	//ȣ���� ���Լ� �̿� �÷��̾� ����
	float iPlayerY = m_pTarget->Get_Info().fY;
	float iPlayerX = m_pTarget->Get_Info().fX;
	float iZombieY = m_tInfo.fY;
	float iZombieX = m_tInfo.fX;

	//�غ� ����
	float f_bootom_side = iPlayerX - iZombieX;
	
	//���� ����
	float fR = sqrtf(((iPlayerY - iZombieY) * (iPlayerY - iZombieY)) + ((iPlayerX - iZombieX) * (iPlayerX - iZombieX)));
	//�̵��� ũ��
	float fMoveDistance = (fR >= m_fSpeed) ? m_fSpeed : fR;

	//����(��ȯ���� ���� ����)
	//180~360 �ϰ�� �ش�Ǵ� �� ��ġ ���� ��ȯ
	m_fAngle = acos(f_bootom_side / fR);
	
	//�÷��̾� ����
	//acos ġ�� ����
	if (iPlayerY > iZombieY)
	{
		m_fAngle=2.f * PI - m_fAngle;
	}
	m_tInfo.fX += fMoveDistance*(cos(m_fAngle) );
	m_tInfo.fY -= fMoveDistance*(sin(m_fAngle) );
	//--------------------------------------
	/*float iPlayerY = m_pTarget->Get_Info().fY;
	float iPlayerX = m_pTarget->Get_Info().fX;
	float iZombieY = m_tInfo.fY;
	float iZombieX = m_tInfo.fX;

	float fR = sqrtf(((iPlayerY - iZombieY) * (iPlayerY - iZombieY)) + ((iPlayerX - iZombieX) * (iPlayerX - iZombieX)));
	float normalVectorY = (fR == 0.f) ? 0.f : ((iPlayerY - iZombieY) / fR);
	float normalVectorX = (fR == 0.f) ? 0.f : ((iPlayerX - iZombieX) / fR);
	float fMoveDistance = (fR >= m_fSpeed) ? m_fSpeed : fR;
	m_tInfo.fX += (normalVectorX * fMoveDistance);
	m_tInfo.fY += (normalVectorY * fMoveDistance);*/
	////������ ����?
	//if (fR >= m_fSpeed)
	//{
	//	m_tInfo.fX += (normalVectorX * m_fSpeed);
	//	m_tInfo.fY += (normalVectorY * m_fSpeed);
	//}
	//else
	//{
	//	m_tInfo.fX += (normalVectorX * fR);
	//	m_tInfo.fY += (normalVectorY * fR);
	//}

}

void CZombie::Render(HDC _hdc)
{
	HBRUSH redBrush = Brush;
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, redBrush);
	::Ellipse(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(oldBrush);
}

void CZombie::Release()
{
}

RECT* CZombie::Get_Rect_Pointer()
{
	return &m_tRect;
}

void CZombie::SetType(ZOMBIE_TYPE _zType)
{
	m_eZtype = _zType;
}
