#include "MikoBasicBullet.h"
#include "EventDefine.h"
#include "BmpMgr.h"
CMikoBasicBullet::CMikoBasicBullet()
{
}

CMikoBasicBullet::~CMikoBasicBullet()
{
    Release();
}

void CMikoBasicBullet::Initialize()
{
    m_tInfo.fCX = 18.f;
    m_tInfo.fCY = 18.f;

    m_fSpeed = 12.f;

	//��Ʈ�̹��� ����
	m_tFrame.iFrameStart = 0;
	//��Ʈ�̹��� �ִ� ����
	m_tFrame.iFrameEnd = 9;
	//��Ʈ�̹��� ����
	m_tFrame.iMotion = 0;
	m_pFrameKey = L"MikoBasicAttack";
	iFrameindex = rand() % 10;
}

int CMikoBasicBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eDir)
	{
	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;

	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;

	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;

	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_RU:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	}
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CMikoBasicBullet::Late_Update()
{
	if (-20 >= m_tRect.left || WINCX <= m_tRect.right ||
		-20 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}

void CMikoBasicBullet::Render(HDC hDC)
{
	HDC hMemDC = BmpMgr->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tRect.left, //+ iScrollX,
		m_tRect.top, //+ iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		(int)m_tInfo.fCX * iFrameindex,
		(int)m_tInfo.fCY * m_tFrame.iMotion,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 0, 152));
}

void CMikoBasicBullet::Release()
{
}