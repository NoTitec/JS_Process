#include "MikoPetBasicBullet.h"
#include "EventDefine.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
CMikoPetBasicBullet::CMikoPetBasicBullet()
{
}

CMikoPetBasicBullet::~CMikoPetBasicBullet()
{
	Release();
}

void CMikoPetBasicBullet::Initialize()
{
	m_eID = OBJ_PETBULLET;
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 11.f;
	//비트이미지 가로
	m_tFrame.iFrameStart = -1;
	//비트이미지 최대 개수
	m_tFrame.iFrameEnd = 3;
	//비트이미지 세로
	m_tFrame.iMotion = 0;
	m_pFrameKey = L"PetLevel_oneAttack";
}

int CMikoPetBasicBullet::Update()
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

void CMikoPetBasicBullet::Late_Update()
{
	int iScrollY = ScrollMgr->Get_ScrollY();

	if (-20 >= m_tRect.left || WINCX <= m_tRect.right ||
		-20 >= m_tRect.top + iScrollY || WINCY <= m_tRect.bottom + iScrollY)
	{
		m_bDead = true;
	}
	__super::Move_Frame();
}

void CMikoPetBasicBullet::Render(HDC hDC)
{
	HDC hMemDC = BmpMgr->Find_Img(m_pFrameKey);
	int iScrollY = ScrollMgr->Get_ScrollY();
	GdiTransparentBlt(hDC,
		m_tRect.left,
		m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		(int)m_tInfo.fCX * m_tFrame.iFrameStart,
		(int)m_tInfo.fCY * m_tFrame.iMotion,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 0, 152));
}

void CMikoPetBasicBullet::Release()
{
}

void CMikoPetBasicBullet::OnHit(CObj* _pObj)
{
	OBJ_ID pObj_ID = _pObj->Get_ID();
	switch (pObj_ID)
	{
	case OBJ_MONSTER:
	case OBJ_BOSSMONSTER:
		Set_Dead();
		break;
	}
}
