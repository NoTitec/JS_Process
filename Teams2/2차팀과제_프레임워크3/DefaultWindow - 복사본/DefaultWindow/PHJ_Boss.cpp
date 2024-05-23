#include "stdafx.h"
#include "PHJ_Boss.h"
#include "RenderMgr.h"
#include "PHJ_Bullet.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"

CPHJ_Boss::CPHJ_Boss()
{
	ZeroMemory(m_fStartY, sizeof(m_fStartY));
}

CPHJ_Boss::~CPHJ_Boss()
{
	Release();
}

void CPHJ_Boss::Initialize()
{
	m_tInfo = { 6800.f, WINCY / 2.f, 400.f, 590.f };
	m_fSpeed = 0.f;
	__super::Update_Rect();
	m_dPatternTimer = GetTickCount();
	m_ePattern = PT_END;
	m_eID = PHJ_BOSS;
	m_bPower = false;
	m_iHp = 300;
	for (int i = 0; i < 3; ++i)
	{
		m_fStartY[i] = 180.f * i + 90.f;
	}
	m_iFirstBullet = -1;
	m_iSecondBullet = -1;
}

int CPHJ_Boss::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (m_dPatternTimer + 20000 <= GetTickCount()) // 20초 지나면 행동 시작 - 원래는 플레이어와 거리 가까워져야 행동하는게 이상적
		m_bPower = true;

	if (m_bPower && m_dPatternTimer + 2000 <= GetTickCount())
	{
		int iScrollX = (int)SCROLL.Get_ScrollX();
		m_dPatternTimer = GetTickCount();
		m_ePattern = rand() % 2;
		CObj* pBullet;
		if (0 == m_ePattern) // FIRE
		{
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX - (m_tInfo.fCX / 2) - 250.f + iScrollX, m_fStartY[rand() % 3], 0.f);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Boss_Attack(FIRE);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
		}
		else if (1 == m_ePattern) // DOUBLE_BULLET
		{
			m_iFirstBullet = rand() % 3;
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX - (m_tInfo.fCX / 2) + iScrollX - 800, m_fStartY[m_iFirstBullet]);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Boss_Attack(DOUBLE_BULLET);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
			while (1) // 두번쨰 총알 위치는 첫번째와 다르게 설정
			{
				m_iSecondBullet = rand() % 3;
				if (m_iSecondBullet != m_iFirstBullet)
					break;
			}
			pBullet = CAbstractFactory<CPHJ_Bullet>::Create(m_tInfo.fX - (m_tInfo.fCX / 2) + iScrollX - 800, m_fStartY[m_iSecondBullet], 0.f);
			dynamic_cast<CPHJ_Bullet*>(pBullet)->Boss_Attack(DOUBLE_BULLET);
			OBJ.Add_Object(OBJ_BULLET, pBullet);
		}
	}
	return OBJ_NOEVENT;
}

void CPHJ_Boss::Late_Update()
{
	if (m_iHp <= 0)
		m_bDead = true;
}

void CPHJ_Boss::Render(HDC hDC)
{
	RECT rect = m_tRect;
	int iScrollX = (int)SCROLL.Get_ScrollX();
	rect.left += iScrollX;
	rect.right += iScrollX;
	RENDER.DrawRect(rect);
}

void CPHJ_Boss::Release()
{
}

void CPHJ_Boss::OnHit(CObj* _pObj)
{
	PHJ_ID ID = dynamic_cast<CPHJ_Obj*>(_pObj)->Get_ID();
	if (ID == PHJ_BULLET)
	{
		OWNER Own = dynamic_cast<CPHJ_Bullet*>(_pObj)->Get_Owner();
		if (Own == PLAYER)
			m_iHp--;
	}
}
