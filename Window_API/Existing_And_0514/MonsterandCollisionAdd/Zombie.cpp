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
		m_fSpeed = 2.0f;
		break;
	case 1:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		m_eZtype = LIGHT_ZOMBIE;
		m_tInfo.fCX = 20.0f;
		m_tInfo.fCY = 20.0f;
		m_fSpeed = 3.0f;
		break;
	case 2:
		Brush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		m_eZtype = HEAVY_ZOMBIE;
		m_tInfo.fCX = 60.0f;
		m_tInfo.fCY = 60.0f;
		m_fSpeed = 1.0f;
		break;
	}
}

int CZombie::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	//=====================
	//acos 치역보정 플레이어추적 수업코드
	float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

	//가로길이
	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	//세로길이
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;
	//빗변길이
	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	// fWidth / fDiagonal == cos(m_fAngle)

	//라디안 각도
	fRadian = acos(fWidth / fDiagonal);

	//타겟 위치 자기보다 아래면 acos 반환값 보정
	/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		fRadian = 2 * PI - fRadian;*/

	// radian to degree
	//라디안은 도로변환 라디안/pi*180
	m_fAngle = fRadian/PI*180.f;
	//
	//fRadian = 2 * PI - fRadian;
	//이거대신 그냥 angle에 -취해도 원하는 각도계산 가능
	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		m_fAngle *= -1.f;

		// degree to radian
	//각을 라디안으로 변환 각*pi/180
	m_tInfo.fX += cos(m_fAngle/180.f*PI) * m_fSpeed;
	m_tInfo.fY -= sin(m_fAngle / 180.f * PI) * m_fSpeed;

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CZombie::Late_Update()
{
	//--------------------------------------------
	// 
	//호도법 역함수 이용 플레이어 추적
	//float iPlayerY = m_pTarget->Get_Info().fY;
	//float iPlayerX = m_pTarget->Get_Info().fX;
	//float iZombieY = m_tInfo.fY;
	//float iZombieX = m_tInfo.fX;

	////밑변 길이
	//float f_bootom_side = iPlayerX - iZombieX;
	//
	////빗변 길이
	//float fR = sqrtf(((iPlayerY - iZombieY) * (iPlayerY - iZombieY)) + ((iPlayerX - iZombieX) * (iPlayerX - iZombieX)));
	////이동할 크기
	//float fMoveDistance = (fR >= m_fSpeed) ? m_fSpeed : fR;

	////각도(반환값이 라디안 기준)
	////180~360 일경우 해당되는 역 위치 라디안 반환
	//m_fAngle = acos(f_bootom_side / fR);
	//
	////플레이어 추적
	////acos 치역 보정
	//if (iPlayerY > iZombieY)
	//{
	//	m_fAngle=2.f * PI - m_fAngle;
	//}
	//m_tInfo.fX += fMoveDistance*(cos(m_fAngle) );
	//m_tInfo.fY -= fMoveDistance*(sin(m_fAngle) );


	//--------------------------------------
	//방향벡터 이용 추적
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
	////원리는 몰루?
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
