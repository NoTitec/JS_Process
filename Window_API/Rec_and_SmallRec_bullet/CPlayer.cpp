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

//x�� ���� 0: ���� 1:���� 2:������
//y�� ���� 0: ���� 1:�� 2:�Ʒ�
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
	//wasd�� �����̽��Է�ó��

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
	//������ �ۿ��� dx&&dy!=0 �̸� �밢���̸� �̰�� �ӵ� ���߱����� m_fSpeed/=sqrt(2); �ϰ� push
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	//���ڷι��� dx,dy�� �Ѿ� ����� �밢������ ����
	dynamic_cast<CBullet*>(pBullet)->Set_Direction(dx, dy);
	//�밢���� true��
	if (dynamic_cast<CBullet*>(pBullet)->Get_Diagonal())
	{
		//�ӵ����߱����� �ӵ�*��Ʈ2
		pBullet->Set_Speed();
	}
	return pBullet;
}
