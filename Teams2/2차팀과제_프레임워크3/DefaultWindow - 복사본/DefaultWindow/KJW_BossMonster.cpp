#include "stdafx.h"
#include "KJW_BossMonster.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
CKJW_BossMonster::CKJW_BossMonster()
{
}
CKJW_BossMonster::~CKJW_BossMonster()
{
	Release();
}
void CKJW_BossMonster::Initialize()
{
	m_iCellSize = 350;
	m_iCharacterSize = 250;
	m_tInfo.fCX = m_iCharacterSize;
	m_tInfo.fCY = m_iCharacterSize;
	m_tInfo.fX = MAPCX - m_iCharacterSize ;
	m_tInfo.fY = MAPCY/2 ;

	m_fSpeed = 5.f;
	m_fJumpPower = 15.f;
	m_fJumpTime = 0.f;
	m_bJump = true;
	m_fXSpd = 0;
	m_fYSpd = 0;
	m_fFootHeight = m_fSpeed;
	m_iHP = 100;

	m_fPatternDelay = 5000;
	//m_tShootPoint = { m_tInfo.fX ,  m_tInfo.fY - m_tInfo.fCY / 2 };
	//m_fShootTime = g_dwTime;
	//m_fShootDelay = 200.f;

	m_eDir = DIR_LEFT;
	m_pFrameKey = L"Boss";
	m_eCurState = IDLE;
	m_eCurPattern = NONE;
}

int CKJW_BossMonster::Update()
{
	Update_Pattern();
	Update_Position();
	KJW_Update_Rect();
	return OBJ_NOEVENT;
}

void CKJW_BossMonster::Update_Pattern()
{
	if (m_pTarget!= nullptr && m_pTarget->Get_Dead())
	{
		m_pTarget = nullptr;
	}
	if (m_pTarget == nullptr)
		return;

	if (m_eCurPattern = NONE)    
	{
		if (m_fPatternDelay + m_fPatternTime < g_dwTime)
		{
			m_eCurPattern = (PATTERN)(rand() % PT_END);
			switch (m_eCurPattern)
			{
			case CKJW_BossMonster::RUSH:
				if (m_tInfo.fX > m_pTarget->Get_Info().fX)
				{
					m_fXSpd = -15.f;
				}
				else
				{
					m_fXSpd = 15.f;
				}
				break;
			case CKJW_BossMonster::SUMMON:
				break;
			default:
				break;
			}
			m_fPatternTime = g_dwTime;
		}
	}
	
}

void CKJW_BossMonster::Update_Position()
{
	if (m_bJump)
	{
		m_fYSpd += 9.8 * m_fJumpTime;
		cout << m_fYSpd << ", " << m_fJumpTime << ", " << m_tInfo.fY << endl;
		m_fJumpTime += 0.015f;
		float fNextYSolution = WINCY;
		m_eCurState = JUMP;
		if (Check_Front_Wall())
		{
			m_fXSpd = 0;
		}
		if (Check_Crossing_Line(fNextYSolution))
		{
			cout << " JUMP END" << endl;
			m_bJump = false;
			m_fYSpd = 0;
			m_tInfo.fY = fNextYSolution;
			m_fJumpTime = 0;
			m_eCurState = IDLE;
		}

		m_tInfo.fY += m_fYSpd;
	}
	else
	{

		if (m_fXSpd != 0)
		{
			float fNextYSolution;
			if (Check_Front_Wall())
			{
				m_fXSpd = 0;
			}
			else if (Check_Front_Floor(fNextYSolution))
			{
				m_tInfo.fY = fNextYSolution;
			}
			else
			{
				m_bJump = true;
				m_eCurState = JUMP;
			}
		}

	}

	m_tInfo.fX += m_fXSpd;

}

void CKJW_BossMonster::Late_Update()
{
	Change_Motion();
	Move_Frame();
}

void CKJW_BossMonster::Render(HDC hDC)
{
	float fScollX = SCROLL.Get_ScrollX();
	float fScollY = SCROLL.Get_ScrollY();
	Rectangle(hDC, m_tRect.left + (long)fScollX,
		m_tRect.top,
		m_tRect.right + (long)fScollX,
		m_tRect.bottom);
	m_hMemDC = BMP.Find_Img(m_pFrameKey);
	GdiTransparentBlt(hDC,// 복사 받을 최종적인 그리기 DC
		m_tRect.left + fScollX,// 복사 받을 위치 X좌표
		m_tRect.top + fScollY,// 복사 받을 위치 Y좌표
		(int)m_tInfo.fCX,// 복사 받을 가로 사이즈
		(int)m_tInfo.fCY,// 복사 받을 세로 사이즈
		m_hMemDC,			// 복사할 이미지 DC
		m_iCellSize* m_tFrame.iFrameStart + (m_iCellSize -m_iCharacterSize)/2,
	m_iCellSize * m_tFrame.iMotion + (m_iCellSize - m_iCharacterSize),// 복사할 이미지의 출력 시작 좌표(left,top)
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		BLUEGREEN);//투명화할 색상;

}

void CKJW_BossMonster::Release()
{
}

void CKJW_BossMonster::Change_Motion()
{
	if (m_ePreState != m_eCurState)
	{
		m_tFrame.iMotion = m_eCurState;
		m_tFrame.dwTime = g_dwTime;
		switch (m_eCurState)
		{
		case CKJW_BossMonster::IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.bRepeat = true;
			break;
		case CKJW_BossMonster::JUMP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.bRepeat = false;
			break;
		case CKJW_BossMonster::DEAD:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.dwSpeed = 200;
			m_tFrame.bRepeat = true;
			break;
		default:
			break;
		}
	}
}

void CKJW_BossMonster::OnHit(CObj* _pObj)
{
}