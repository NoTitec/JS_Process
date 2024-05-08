#include "CPlayer.h"
#include "Bullet.h"
#include "stdafx.h"
CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX / 2.f, WINCY / 2.f, 100.f, 100.f };
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	Key_Input();

	__super::Update_Rect();

	return 0;
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CPlayer::Release()
{
}

//x축 방향 0: 없음 1:왼쪽 2:오른쪽
//y축 방향 0: 없음 1:위 2:아래
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
	//wasd랑 스페이스입력처리

	if (GetAsyncKeyState('W'))
	{
		m_pBulletList->push_back(Create_Bullet(0,1));
	}
	if (GetAsyncKeyState('S'))
	{
		m_pBulletList->push_back(Create_Bullet(0, 2));
	}
	if (GetAsyncKeyState('A'))
	{
		m_pBulletList->push_back(Create_Bullet(1, 0));
	}
	if (GetAsyncKeyState('D'))
	{
		m_pBulletList->push_back(Create_Bullet(2, 0));
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBulletList->push_back(Create_Bullet(0, 1));
		m_pBulletList->push_back(Create_Bullet(1, 1));
		m_pBulletList->push_back(Create_Bullet(2, 1));
	}
}

CObj* CPlayer::Create_Bullet(int dx, int dy)
{
	//생성후 밖에서 dx&&dy!=0 이면 대각선이며 이경우 속도 맞추기위해 m_fSpeed/=sqrt(2); 하고 push
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	//인자로받은 dx,dy로 총알 방향과 대각선인지 지정
	dynamic_cast<CBullet*>(pBullet)->Set_Direction(dx, dy);
	//대각선이 true면
	if (dynamic_cast<CBullet*>(pBullet)->Get_Diagonal())
	{
		//속도맞추기위해 속도*루트2
		pBullet->Set_Speed();
	}
	return pBullet;
}
