#include "MikoPetGuideBullet.h"
#include "EventDefine.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
CMikoPetGuideBullet::CMikoPetGuideBullet()
{
}

CMikoPetGuideBullet::~CMikoPetGuideBullet()
{
    Release();

}

void CMikoPetGuideBullet::Initialize()
{
	m_eID = OBJ_PETBULLET;
	m_tInfo.fCX = 35.f;
	m_tInfo.fCY = 35.f;

	m_fSpeed = 11.f;
	//비트이미지 가로
	m_tFrame.iFrameStart = -1;
	//비트이미지 최대 개수
	m_tFrame.iFrameEnd = 7;
	//비트이미지 세로
	m_tFrame.iMotion = 0;
	m_pFrameKey = L"PetLevel_twoAttack";
}

int CMikoPetGuideBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_pTarget = ObjMgr->Get_Near_Target_BossMonster_Monster(OBJ_MONSTER,OBJ_BOSSMONSTER,this);

	if (m_pTarget)
	{
		float	fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

		fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

		fRadian = acos(fWidth / fDiagonal);

		if (m_pTarget->Get_Info().fY > m_tInfo.fY)
			fRadian = 2 * PI - fRadian;

		m_fAngle = fRadian * 180.f / PI;
		m_tInfo.fX += cos(m_fAngle * PI / 180.f) * m_fSpeed;
		m_tInfo.fY -= sin(m_fAngle * PI / 180.f) * m_fSpeed;

	}
	else
	{
		switch (m_eDir)
		{
		case DIR_RIGHT:
			m_tInfo.fX += m_fSpeed;
			break;

		case DIR_RD:
			m_tInfo.fX += m_fSpeed;
			m_tInfo.fY += m_fSpeed;
			break;

		case DIR_RU:
			m_tInfo.fX += m_fSpeed;
			m_tInfo.fY -= m_fSpeed;
			break;
		}
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMikoPetGuideBullet::Late_Update()
{
	int iScrollY = ScrollMgr->Get_ScrollY();

	if (-20 >= m_tRect.left || WINCX <= m_tRect.right ||
		-20 >= m_tRect.top + iScrollY || WINCY <= m_tRect.bottom + iScrollY)
	{
		m_bDead = true;
	}
	__super::Move_Frame();
}

void CMikoPetGuideBullet::Render(HDC hDC)
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

void CMikoPetGuideBullet::Release()
{
}

void CMikoPetGuideBullet::OnHit(CObj* _pObj)
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
