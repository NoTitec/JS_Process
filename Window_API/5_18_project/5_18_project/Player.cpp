#include "Player.h"
#include "Bullet.h"
#include "ScrewBullet.h"
#include "GuideBullet.h"
#include "Shield.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "KeyMgr.h"

CPlayer::CPlayer()
{
	ZeroMemory(&m_tBarrel, sizeof(POINT));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
	Key_Input();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	m_tBarrel.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle/180.f*PI));
	m_tBarrel.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));

}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	// 포신 그리기
	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	LineTo(hDC, m_tBarrel.x, m_tBarrel.y);
}

void CPlayer::Release()
{
}
template<typename T>
CObj* CPlayer::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tBarrel.x, (float)m_tBarrel.y);
	pBullet->Set_Angle(m_fAngle);

	return pBullet;
}
CObj* CPlayer::Create_Shield(float _Angle)
{
	CObj* pShield = CAbstractFactory<CShield>::Create(m_fAngle+_Angle);
	pShield->Set_Target(this);
	return pShield;
}
void CPlayer::Key_Input()
{
	// GetKeyState()

	if (GetAsyncKeyState(VK_RIGHT))
		m_fAngle -= 5.f;

	if (GetAsyncKeyState(VK_LEFT))
		m_fAngle += 5.f;

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX -= m_fSpeed * cos(m_fAngle * (PI / 180.f));
		m_tInfo.fY += m_fSpeed * sin(m_fAngle * (PI / 180.f));
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fX += m_fSpeed * cos(m_fAngle * (PI / 180.f));
		m_tInfo.fY -= m_fSpeed * sin(m_fAngle * (PI / 180.f));
	}
		

	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CBullet>());
	}
	if (CKeyMgr::Get_Instance()->Key_Down('R'))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CScrewBullet>());
	}
	if (CKeyMgr::Get_Instance()->Key_Down('G'))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CGuideBullet>());
	}
	if (CKeyMgr::Get_Instance()->Key_Down('S'))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(0.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(90.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(180.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield(270.f));

	}

}