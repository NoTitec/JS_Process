#include "stdafx.h"
#include "ScrewBullet.h"

CScrewBullet::CScrewBullet()
{
	ZeroMemory(&m_tCenter, sizeof(POINT));
}

CScrewBullet::~CScrewBullet()
{
	Release();
}

void CScrewBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;

	//첫 시작때는 포신위치서 렌더링 시작하기위한 bool 변수
	m_bStart = true;
	//총알 회전각위한 변수
	m_fRotAngle = 0.f;
	//포신으로 부터 떨어지는 거리
	m_fDistance = 20.f;
	//회전 angle 각도 속도
	m_fRotSpeed = 30.f;

}

int CScrewBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//최초생성시 포신위치로 초기화
	if (m_bStart)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;

		m_bStart = false;
	}
	//센터 좌표는 프레임마다 자기중점서 speed*삼각함수 위치
	m_tCenter.x += long(m_fSpeed * cos(m_fAngle * (PI / 180.f)));
	m_tCenter.y -= long(m_fSpeed * sin(m_fAngle * (PI / 180.f)));
	//회전각을 프레임마다 회전스피드만큼 합
	m_fRotAngle += m_fRotSpeed;
	//자기 자신 그려줄 중점은 보이지않는 센터점+포신길이*삼각함수 위치
	m_tInfo.fX = m_tCenter.x + (m_fDistance * cos(m_fRotAngle * (PI / 180.f)));
	m_tInfo.fY = m_tCenter.y - (m_fDistance * sin(m_fRotAngle * (PI / 180.f)));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CScrewBullet::Late_Update()
{
	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right ||
		100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}

void CScrewBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CScrewBullet::Release()
{
}

RECT* CScrewBullet::Get_Rect_Pointer()
{
	return nullptr;
}
