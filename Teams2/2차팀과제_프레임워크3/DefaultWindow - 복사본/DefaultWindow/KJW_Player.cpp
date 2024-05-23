#include "stdafx.h"
#include "KJW_Player.h"
#include "KeyMgr.h"
#include "KJW_LineMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "KJW_Bullet.h"

CKJW_Player::CKJW_Player()
{
}

CKJW_Player::~CKJW_Player()
{
	Release();
}

void CKJW_Player::Initialize()
{
	m_iCellSize = 100;
	m_iCharacterSize = 50;
    m_tInfo.fCX = m_iCharacterSize;
    m_tInfo.fCY = m_iCharacterSize;
    m_tInfo.fX = WINCX / 2;
    m_tInfo.fY = WINCY/ 2;

	m_fSpeed = 5.f;
	m_fJumpPower = 11.f;
	m_fJumpTime = 0.f;
    m_bJump = true;
	m_fXSpd = 10.f;
	m_fYSpd = 0;
	m_fFootHeight = m_fSpeed;

	m_tShootPoint = { m_tInfo.fX ,  m_tInfo.fY - m_tInfo.fCY /2 };
	m_fShootTime = g_dwTime;
	m_fShootDelay = 200.f;

	m_eDir = DIR_LEFT;
	m_pFrameKey = L"Player_LEFT";
	m_eCurState = BORN;
}

int CKJW_Player::Update()
{

    Key_Input();
	Update_Position();
    KJW_Update_Rect();
    return OBJ_NOEVENT;
}

void CKJW_Player::KJW_Update_Rect()
{
	m_tRect.left = long(m_tInfo.fX - m_tInfo.fCX / 2.f);
	m_tRect.top = long(m_tInfo.fY - m_tInfo.fCY);
	m_tRect.right = long(m_tInfo.fX + m_tInfo.fCX / 2.f);
	m_tRect.bottom = long(m_tInfo.fY);
}

void CKJW_Player::Key_Input()
{

	if (KEY.Key_Pressing(VK_RIGHT))
	{
		m_fXSpd = m_fSpeed;
		m_eDir = DIR_RIGHT;
		m_pFrameKey = L"Player_RIGHT";
		m_eCurState = WALK;
	}
	else if (KEY.Key_Pressing(VK_LEFT))
	{
		m_fXSpd = -m_fSpeed;
		m_eDir = DIR_LEFT;
		m_pFrameKey = L"Player_LEFT";
		m_eCurState = WALK;
	}
	else
	{
		m_fXSpd = 0;
		m_eCurState = IDLE;
	}


	if (KEY.Key_Pressing(VK_SPACE))
	{
		if (m_bJump == false)
		{
			
			cout << " JUMP START" << endl;
			m_bJump = true;
			m_fYSpd = -m_fJumpPower;
			m_eCurState = JUMP;
		}
	}

	if (KEY.Key_Pressing('Z'))
	{
		Shoot();
	}
}

void CKJW_Player::Update_Position()
{
	
	if (m_bJump)
	{
		m_fYSpd += 9.8 * m_fJumpTime;
		cout << m_fYSpd<<", "<< m_fJumpTime<< ", "<< m_tInfo.fY << endl;
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
			m_eCurState = LAND;
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
				m_eCurState = PUSH;
			}
			else if (Check_Front_Floor(fNextYSolution))
			{
 				m_tInfo.fY = fNextYSolution;
				m_eCurState = WALK;
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

void CKJW_Player::Late_Update()
{
	Offset(); 
	Change_Motion();
	Move_Frame();
}

void CKJW_Player::Render(HDC hDC)
{
	float fScollX = SCROLL.Get_ScrollX();
	float fScollY = SCROLL.Get_ScrollY();
	Rectangle(hDC, m_tRect.left + (long)fScollX,
		m_tRect.top ,
		m_tRect.right + (long)fScollX,
		m_tRect.bottom );
	m_hMemDC = BMP.Find_Img(m_pFrameKey);
	GdiTransparentBlt(hDC,// 복사 받을 최종적인 그리기 DC
		m_tRect.left + fScollX ,// 복사 받을 위치 X좌표
		m_tRect.top + fScollY ,// 복사 받을 위치 Y좌표
		(int)m_tInfo.fCX,// 복사 받을 가로 사이즈
		(int)m_tInfo.fCY,// 복사 받을 가로 사이즈
		m_hMemDC,			// 복사할 이미지 DC
		(int)m_tInfo.fCX/2 + m_iCellSize * m_tFrame.iFrameStart ,
		(int)m_tInfo.fCY + m_iCellSize * m_tFrame.iMotion,// 복사할 이미지의 출력 시작 좌표(left,top)
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		BLUEGREEN);//투명화할 색상;

}

void CKJW_Player::Release()
{
}

void CKJW_Player::Offset()
{
	int	iOffSetminX = 300;
	int	iOffSetmaxX = 500;
	int	iOffSetminY = 200;
	int	iOffSetmaxY = 400;

	int	iScrollX = SCROLL.Get_ScrollX();
	int	iScrollY = SCROLL.Get_ScrollY();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(-m_fSpeed);

	if (iOffSetminY > m_tInfo.fY + iScrollY)
		SCROLL.Set_ScrollY(m_fYSpd);

	if (iOffSetmaxY < m_tInfo.fY + iScrollY)
		SCROLL.Set_ScrollY(-m_fYSpd);

}



void CKJW_Player::Shoot()
{
	if (m_fShootTime + m_fShootDelay < g_dwTime)
	{
		m_eCurState = THROW;
		m_tShootPoint = { m_tInfo.fX ,  m_tInfo.fY /*- m_tInfo.fCY / 2 */};
		OBJ.Add_Object(OBJ_PLAYER_BULLET, CAbstractFactory<CKJW_Bullet>::Create(m_tShootPoint.x, m_tShootPoint.y, m_eDir));
		m_fShootTime = g_dwTime;
	}
}

void CKJW_Player::Change_Motion()
{
	if (m_ePreState != m_eCurState)
	{
		m_tFrame.iMotion = m_eCurState;
		m_tFrame.dwTime = g_dwTime;
		switch (m_eCurState)
		{
		case CKJW_Player::BORN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::JUMP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.dwSpeed = 100;
			break;
		case CKJW_Player::LAND:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::RUN:
			break;
		case CKJW_Player::PUSH:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::BUBBLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::DEAD:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::THROW:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.dwSpeed = 200;
			break;
		case CKJW_Player::ST_END:
			break;
		default:
			break;
		}

		m_ePreState = m_eCurState;
	}
}
void CKJW_Player::OnMotionEnd()
{
	m_eCurState = IDLE;
}
void CKJW_Player::OnHit(CObj* _pObj)
{
}



