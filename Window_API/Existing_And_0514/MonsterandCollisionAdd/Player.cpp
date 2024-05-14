#include "Player.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "Bullet.h"
#include "ScrewBullet.h"
#include "FollowBullet.h"
#include "Shield.h"
CPlayer::CPlayer()
{
	ZeroMemory(&m_tPosition, sizeof(POINT));
}

CPlayer::~CPlayer()
{
    Release();
}

void CPlayer::Initialize()
{
    //중점설정
    m_tInfo = { WINCX / 2.f, WINCY * 0.7f, 70.f, 70.f };
    m_fSpeed = 8.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
    Key_Input();

    __super::Update_Rect();

    return OBJ_NOEVENT;
}
void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	else if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState('A'))
	{
		m_fAngle += 5.f;
	}
	if (GetAsyncKeyState('D'))
	{
		m_fAngle -= 5.f;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		//m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tPosition.x, m_tPosition.y, m_fAngle));
		//m_pBulletList->push_back(Create_Bullet<CBullet>());
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CBullet>());
	}
	if (GetAsyncKeyState('S'))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield());
	}
	if (GetAsyncKeyState('R'))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CScrewBullet>());
	}
	if (GetAsyncKeyState('F'))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, Create_Bullet<CFollowBullet>());
	}
}

CObj* CPlayer::Create_Shield()
{
	CObj* pShield = CAbstractFactory<CShield>::Create();
	pShield->Set_Target(this);

	return pShield;
}

void CPlayer::Late_Update()
{
	m_tPosition.x = LONG(m_tInfo.fX + m_fDistance * cos(m_fAngle * (PI / 180.f)));
	m_tPosition.y = LONG(m_tInfo.fY - m_fDistance * sin(m_fAngle * (PI / 180.f)));
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, NULL);
	LineTo(hDC, m_tPosition.x, m_tPosition.y);
}

void CPlayer::Release()
{
}

//총알생성 템플릿 함수
template<typename T>
CObj* CPlayer::Create_Bullet()
{
	CObj* pBullet = CAbstractFactory<T>::Create((float)m_tPosition.x, (float)m_tPosition.y);
	//pBullet->Set_Angle(m_fAngle);

	return pBullet;
}
RECT* CPlayer::Get_Rect_Pointer()
{
	return &m_tRect;
}
