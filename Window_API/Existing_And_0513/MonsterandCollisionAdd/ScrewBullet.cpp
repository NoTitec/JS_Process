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

	//ù ���۶��� ������ġ�� ������ �����ϱ����� bool ����
	m_bStart = true;
	//�Ѿ� ȸ�������� ����
	m_fRotAngle = 0.f;
	//�������� ���� �������� �Ÿ�
	m_fDistance = 20.f;
	//ȸ�� angle ���� �ӵ�
	m_fRotSpeed = 30.f;

}

int CScrewBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//���ʻ����� ������ġ�� �ʱ�ȭ
	if (m_bStart)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;

		m_bStart = false;
	}
	//���� ��ǥ�� �����Ӹ��� �ڱ������� speed*�ﰢ�Լ� ��ġ
	m_tCenter.x += long(m_fSpeed * cos(m_fAngle * (PI / 180.f)));
	m_tCenter.y -= long(m_fSpeed * sin(m_fAngle * (PI / 180.f)));
	//ȸ������ �����Ӹ��� ȸ�����ǵ常ŭ ��
	m_fRotAngle += m_fRotSpeed;
	//�ڱ� �ڽ� �׷��� ������ �������ʴ� ������+���ű���*�ﰢ�Լ� ��ġ
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
