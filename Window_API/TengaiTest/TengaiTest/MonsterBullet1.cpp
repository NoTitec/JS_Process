#include "MonsterBullet1.h"

CMonsterBullet1::CMonsterBullet1()
{
}

CMonsterBullet1::~CMonsterBullet1()
{
    Release();
}

void CMonsterBullet1::Initialize()
{
	m_eID = OBJ_MONSTERBULLET;
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 16.f;

	m_fSpeed = 6.f;

	//��Ʈ�̹��� ����
	m_tFrame.iFrameStart = -1;
	//��Ʈ�̹��� �ִ� ����
	m_tFrame.iFrameEnd = 5;
	//��Ʈ�̹��� ����
	m_tFrame.iMotion = 0;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.dwSpeed = 100;
	m_pFrameKey = L"MonsterBullet1";
	m_tFrame.bRepeat = true;
}

int CMonsterBullet1::Update()
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

	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_LD:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		break;
	}
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CMonsterBullet1::Late_Update()
{
	/*if (0 > m_tRect.right)
		m_bDead = true;*/
	__super::Move_Frame();
}

void CMonsterBullet1::Render(HDC hDC)
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
		RGB(255, 0, 212));
}

void CMonsterBullet1::Release()
{
}

void CMonsterBullet1::OnHit(CObj* _pObj)
{
	OBJ_ID pObj_ID = _pObj->Get_ID();
	switch (pObj_ID)
	{
	case OBJ_PLAYER:
		Set_Dead();
		break;
	}
}
