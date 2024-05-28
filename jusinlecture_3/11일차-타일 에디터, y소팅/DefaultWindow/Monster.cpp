#include "stdafx.h"
#include "Monster.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 300.f;
	m_tInfo.fCY = 300.f;

	m_fSpeed = 3.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");

	m_pFrameKey = L"Monster";
	m_eRender = RENDER_GAMEOBJECT;
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

	//fWidth  = m_pTarget->Get_Info().fX - m_tInfo.fX;
	//fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	//fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	//// fWidth / fDiagonal == cos(m_fAngle)

	//fRadian = acos(fWidth / fDiagonal);

	//if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//	fRadian = 2 * PI - fRadian;

	//// radian to degree
	//m_fAngle = fRadian * 180.f / PI;

	///*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
	//	m_fAngle *= -1.f;*/

	//// degree to radian
	//m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
	//m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	/*if (WINCX <= m_tRect.right || 0 >= m_tRect.left)
		m_fSpeed *= -1.f;*/
}

void CMonster::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));
}

void CMonster::Release()
{
}
