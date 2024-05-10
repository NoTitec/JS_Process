#include "Player.h"
#include "AbstractFactory.h"
#include "Bullet.h"
CPlayer::CPlayer() : m_pBulletList(nullptr)
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
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState('Z'))
	{
		m_fAngle += 5.f;
	}
	if (GetAsyncKeyState('X'))
	{
		m_fAngle -= 5.f;
	}
	/*if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_UP));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_DOWN));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LEFT));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));
		m_pBulletList->push_back(CAbstr actFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LU));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RU));

	}*/

	if (GetAsyncKeyState('W'))
	{
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tPosition.x, m_tPosition.y, m_fAngle));
	}

	/*if (GetAsyncKeyState('A'))
	{
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LEFT));

	}

	if (GetAsyncKeyState('S'))
	{
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_DOWN));

	}

	if (GetAsyncKeyState('D'))
	{
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));

	}*/
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

RECT* CPlayer::Get_Rect_Pointer()
{
	return nullptr;
}

//CObj* CPlayer::Create_Bullet(DIRECTION eDir)
//{
//    return nullptr;
//}
