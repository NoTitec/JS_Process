#include "stdafx.h"
#include "KJW_Player.h"
#include "RenderMgr.h"
#include "KeyMgr.h"
#include "KJW_LineMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

void CKJW_Player::Initialize()
{
    m_tInfo.fCX = 100.f;
    m_tInfo.fCY = 100.f;
    m_tInfo.fX = WINCX / 2;
    m_tInfo.fY = WINCY/ 2;

	m_fSpeed = 10.f;
	m_fJumpPower = 15.f;
	m_fJumpTime = 0.f;
    m_bJump = true;
	m_fXSpd = 10.f;
	m_fYSpd = 0;
	m_fFootHeight = 10.f;

	BMP.Insert_Bmp(L"../Image/KJW_Chr001.bmp", L"Player");
}

int CKJW_Player::Update()
{

    Key_Input();
	Update_Position();
    CKJW_Obj::KJW_Update_Rect();
    return OBJ_NOEVENT;
}

void CKJW_Player::Key_Input()
{

	if (KEY.Key_Pressing(VK_RIGHT))
		m_fXSpd = m_fSpeed;
	else if (KEY.Key_Pressing(VK_LEFT))
		m_fXSpd = -m_fSpeed;
	else
		m_fXSpd = 0;
	if (KEY.Key_Down(VK_SPACE) )
	{
		m_bJump = true;
		m_fYSpd = -m_fJumpPower;
	}
	if (KEY.Key_Pressing(VK_SPACE))
	{
		if(m_bJump == false)
			m_fYSpd = -m_fJumpPower;
        m_bJump = true;
	}
}

void CKJW_Player::Update_Position()
{

	//Point2F tNextP = { m_tInfo.fX + m_fXSpd , m_tInfo.fY + m_fYSpd };
	//float fNextYSolution=  KJW_LINE.Get_Land_Y(tNextP);
	//Point2F tNextFootP = { tNextP.x , tNextP.y - m_fFootHeight};
	//float fNextFootYSolution=  KJW_LINE.Get_Land_Y(tNextFootP);

	if (m_bJump)
	{
		m_fYSpd += 9.8 * m_fJumpTime;
		m_fJumpTime += 0.015f;
		Point2F tCurrentP = { m_tInfo.fX , m_tInfo.fY };
		float fCurrentYSolution ,fNextYSolution = WINCY;
		CLine* pCurrentLine = KJW_LINE.Get_Current_Line(tCurrentP, fCurrentYSolution);
		if(pCurrentLine)
			fNextYSolution = KJW_LINE.Get_Line_Y_Solution(pCurrentLine, tCurrentP.x + m_fXSpd);
		if ((fNextYSolution <= m_tInfo.fY + m_fYSpd)
			&&(fCurrentYSolution >= m_tInfo.fY ))
		{ 
			m_bJump = false;
			m_fYSpd = 0;
			m_tInfo.fY = fNextYSolution;
			m_fJumpTime = 0;
			return;
		}

		m_tInfo.fY += m_fYSpd;

	}
	else
	{
		if (m_fXSpd != 0)
		{
			float fNextYSolution = KJW_LINE.Get_Floor_Y({ m_tInfo.fX + m_fXSpd , m_tInfo.fY + m_fYSpd - m_fFootHeight });
			float fNextXSolution = KJW_LINE.Get_Wall_X({ m_tInfo.fX  , m_tInfo.fY  - m_fFootHeight }, m_fXSpd > 0);
			if (m_fXSpd > 0)
			{
				if (fNextXSolution < m_tInfo.fX + m_fXSpd)
				{
					return;
				}
			}
			else
			{
				if (fNextXSolution > m_tInfo.fX + m_fXSpd)
				{
					return;
				}
			}
			if ((fNextYSolution - (m_tInfo.fY + m_fYSpd)) > m_fFootHeight)
			{
				m_bJump = true;
			}
			else
			{
				m_tInfo.fY = fNextYSolution;

			}
		}

	}

	m_tInfo.fX += m_fXSpd;
}

void CKJW_Player::Late_Update()
{
	Offset();
}

void CKJW_Player::Render(HDC hDC)
{
	HDC hMemDC = BMP.Find_Img(L"Player");
	float fScollX = SCROLL.Get_ScrollX();
	Rectangle(hDC, m_tRect.left + (long)fScollX,
		m_tRect.top ,
		m_tRect.right + (long)fScollX,
		m_tRect.bottom );
	GdiTransparentBlt(hDC,// 복사 받을 최종적인 그리기 DC
		m_tRect.left + fScollX,// 복사 받을 위치 X좌표
		m_tRect.top,// 복사 받을 위치 Y좌표
		(int)m_tInfo.fCX,// 복사 받을 가로 사이즈
		(int)m_tInfo.fCY,// 복사 받을 가로 사이즈
		hMemDC,			// 복사할 이미지 DC
		0, 100,// 복사할 이미지의 출력 시작 좌표(left,top)
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

	int	iScrollX = SCROLL.Get_ScrollX();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(-m_fSpeed);

}



