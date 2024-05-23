#include "stdafx.h"
#include "KJW_Bullet.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"


CKJW_Bullet::CKJW_Bullet()
{
}

CKJW_Bullet::~CKJW_Bullet()
{
	Release();
}

void CKJW_Bullet::Initialize()
{
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
	m_fSpeed = 10.f;
	m_fFootHeight = m_fSpeed;
	m_fXSpd = 10.f;
	m_fYSpd = -2.f;
	m_fAngle = 0.f;

	m_fT = 0.f;
	m_pFrameKey = L"Player_Bullet_RIGHT";
	m_pFrameKey = L"Player_Bullet_LEFT";
	m_eCurState = LAUNCH;
}

int CKJW_Bullet::Update()
{
    Update_Position();
    CKJW_Obj::KJW_Update_Rect();
    return m_bDead? OBJ_DEAD : OBJ_NOEVENT;
}

void CKJW_Bullet::Update_Position()
{
	float fY;
	bool bCollisionWall = Check_Front_Wall();
	bool bCollisionFloor = Check_Crossing_Line(fY);
	fY = bCollisionWall? m_tInfo.fY : fY;
	if (bCollisionFloor || bCollisionWall)
	{
		if(m_eCurState != DEAD)
			m_tDeadPos = {m_tInfo.fX+ m_fXSpd, fY};
		m_eCurState = DEAD;
		return;
	}
	m_fYSpd += G * m_fT;
	m_fXSpd -= G * m_fT* 0.1f;
	m_fT += 0.015f;
	switch (m_eDir)
	{
	case DIR_LEFT:
		m_fXSpd  = -10.f;
		break;
	case DIR_RIGHT:
		m_fXSpd  = 10.f;
		break;
	default:
		break;
	}
    m_tInfo.fY += m_fYSpd;
	m_tInfo.fX += m_fXSpd ;

}

void CKJW_Bullet::Late_Update()
{
    Change_Motion();
    Move_Frame();
}

void CKJW_Bullet::Change_Motion()
{
	if (m_ePreState != m_eCurState)
	{
		m_tFrame.iMotion = m_eCurState;
		m_tFrame.dwTime = g_dwTime;
		switch (m_eCurState)
		{
		case CKJW_Bullet::LAUNCH:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.dwSpeed = 100;
			m_tFrame.bRepeat = false;
			m_pFrameKey = m_eDir == DIR_LEFT ?  L"Player_Bullet_LEFT" : L"Player_Bullet_RIGHT";
			break;
		case CKJW_Bullet::DEAD:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.dwSpeed = 75;
			m_tFrame.bRepeat= false;
			m_pFrameKey = L"Player_Bullet_EFFECT";
			break;
		case CKJW_Bullet::ST_END:
			break;
		default:
			break;
		}

		m_ePreState = m_eCurState;
	}
}

void CKJW_Bullet::Render(HDC hDC)
{
	float fScollX = SCROLL.Get_ScrollX();
	float fScollY = SCROLL.Get_ScrollY();
	m_hMemDC = BMP.Find_Img(m_pFrameKey);
	if (m_eCurState == LAUNCH)
	{
	GdiTransparentBlt(hDC,// ���� ���� �������� �׸��� DC
		m_tRect.left + fScollX,// ���� ���� ��ġ X��ǥ
		m_tRect.top  + fScollY,// ���� ���� ��ġ Y��ǥ
		(int)m_tInfo.fCX,// ���� ���� ���� ������
		(int)m_tInfo.fCY,// ���� ���� ���� ������
		m_hMemDC,			// ������ �̹��� DC
		(int)m_tInfo.fCX / 2 + 100 * m_tFrame.iFrameStart,
		(int)m_tInfo.fCY/2 + 100 * m_tFrame.iMotion,// ������ �̹����� ��� ���� ��ǥ(left,top)
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		BLUEGREEN);//����ȭ�� ����;
	}
	else
	{
		GdiTransparentBlt(hDC,// ���� ���� �������� �׸��� DC
			m_tDeadPos.x -16 + fScollX,// ���� ���� ��ġ X��ǥ
			m_tDeadPos.y - 16 + fScollY,// ���� ���� ��ġ Y��ǥ
			16*2,// ���� ���� ���� ������
			16*2,// ���� ���� ���� ������
			m_hMemDC,			// ������ �̹��� DC
			 16 * m_tFrame.iFrameStart,
			0,// ������ �̹����� ��� ���� ��ǥ(left,top)
			16,
			16,
			BLUEGREEN);//����ȭ�� ����;
	}
}

void CKJW_Bullet::Release()
{
}

void CKJW_Bullet::OnHit(CObj* _pObj)
{
	if (m_eCurState != DEAD)
		m_tDeadPos = { m_tInfo.fX + m_fXSpd, m_tInfo.fY };
	m_eCurState = DEAD;
}

void CKJW_Bullet::OnMotionEnd()
{
	if(m_eCurState == DEAD)
		m_bDead = true;
}

