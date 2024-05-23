#include "stdafx.h"
#include "KHR_Player.h"
#include "AbstractFactory.h"
#include "KHR_Bullet.h"

#include "KHR_LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "ObjMgr.h"

CKHR_Player::CKHR_Player()
    : m_fPower(0.f)
    , m_fTime(0.f)
    , m_bIsJump(false)
	, m_ePlayerScene(PLAYER_START)
	, m_ePreState(STATE_END)
	, m_eCurState(IDLE)
{
}

CKHR_Player::~CKHR_Player()
{
}

void CKHR_Player::Initialize()
{
    m_tInfo = { 100.f, WINCY / 2.f, 100.f, 130.f };
    m_fSpeed = 5.f;

    m_fPower = 15.f;
    m_fTime = 0.f;

	Set_FrameInfo(0, 4, 0, g_dwTime, 200);
	
	BMP.Insert_Bmp(L"../Image/KHR/Player/KHR_Player_Left.bmp", L"KHR_Player_Left");
	BMP.Insert_Bmp(L"../Image/KHR/Player/KHR_Player_Right.bmp", L"KHR_Player_Right");

	m_pFrameKey = L"KHR_Player_Right";
	m_eCurState = IDLE;
}

int CKHR_Player::Update()
{
    Key_Input();
    __super::Update_Rect();

    return 0;
}

void CKHR_Player::Late_Update()
{
	if (m_ePlayerScene == CKHR_Player::PLAYER_START) {

	}

	Jump();
	Offset();
	Change_Motion();

	__super::Move_Frame();
}

void CKHR_Player::Render(HDC hDC)
{
	int iScroll = SCROLL.Get_ScrollX();

	HDC hMemDC = BMP.Find_Img(m_pFrameKey);
	GdiTransparentBlt(hDC, 
		m_tRect.left + iScroll, m_tRect.top, 
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC,
		(int)m_tInfo.fCX * m_tFrame.iFrameStart, (int)m_tInfo.fCY * m_tFrame.iMotion,
		(int)m_tInfo.fCX, (int)m_tInfo.fCY,
		RGB(227, 198, 25));

}

void CKHR_Player::Release()
{
}

void CKHR_Player::Key_Input()
{
	if (KEY.Key_Pressing(VK_LEFT))
	{
		if (m_tInfo.fX - (m_tInfo.fCX * 0.5f) + SCROLL.Get_ScrollX() >= 0.f)
			m_tInfo.fX -= m_fSpeed;
		m_pFrameKey = L"KHR_Player_Left";
		m_eCurState = WALK;
	}
	else if (KEY.Key_Pressing(VK_RIGHT))
	{
		if (m_tInfo.fX + (m_tInfo.fCX * 0.5f) + SCROLL.Get_ScrollX() <= WINCX)
			m_tInfo.fX += m_fSpeed;
		m_pFrameKey = L"KHR_Player_Right";
		m_eCurState = WALK;
	}
	else if (KEY.Key_Pressing('E'))
	{
		CObj* pBullet = CAbstractFactory<CKHR_Bullet>::Create();
		pBullet->Set_Pos(m_tInfo.fX + 30.f, m_tInfo.fY + 20.f);
		if (!lstrcmp(m_pFrameKey, L"KHR_Player_Right"))
			pBullet->Set_Angle(0);
		else
			pBullet->Set_Angle(180);
		OBJ.Add_Object(OBJ_PLAYER_BULLET, pBullet);

		m_eCurState = ATTACK;
	}
	else
		m_eCurState = IDLE;

	if (KEY.Key_Down(VK_SPACE))
	{
		m_bIsJump = true;
		m_eCurState = JUMP;
	}
}

void CKHR_Player::Jump()
{
	float fY(0.f);
	
	bool bLineCol = KHR_Line.Collision_Line(m_tInfo.fX, m_tInfo.fY - (m_tInfo.fCY * 0.5f), &fY);

	if (m_bIsJump)
	{
		m_eCurState = JUMP;

		m_tInfo.fY -= (m_fPower * m_fTime) - ((9.8f * m_fTime * m_fTime) * 0.5f);

		m_fTime += 0.1f;

		if (bLineCol && (fY < m_tInfo.fY - 10.f))
		{
			m_bIsJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = fY;
		}
	}
	else if (bLineCol)		// 선 탈 때 
	{
		if (30.f > fY - m_tInfo.fY) {	// 그냥 선 타기 
			m_tInfo.fY = fY;
			m_fTime = 0.f;
		}
		else {							// 아래에 선이 있으면 선까지 낙하
			m_fTime += 0.1f;
			m_tInfo.fY += 0.5 * 9.8 * m_fTime * m_fTime;
		}
	}
	else if (!bLineCol)		// 선 탈 때, 아래에 선이 없으면(함정) 아래로 낙하
	{
		m_fTime += 0.1f;
		m_tInfo.fY += 0.5 * 9.8 * m_fTime * m_fTime;
	}
}

void CKHR_Player::Offset()
{
	int	iOffSetminX = 300;
	int	iOffSetmaxX = 500;

	int	iScrollX = (int)SCROLL.Get_ScrollX();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		SCROLL.Set_ScrollX(-m_fSpeed);
}

void CKHR_Player::Change_Motion()
{
	if (m_ePreState != m_eCurState) {
		switch (m_eCurState) {
		case CKHR_Player::IDLE:
			Set_FrameInfo(0, 4, 0, g_dwTime, 700);
			break;
		case CKHR_Player::WALK:
			Set_FrameInfo(0, 12, 1, g_dwTime, 200);
			break;
		case CKHR_Player::JUMP:
			Set_FrameInfo(0, 1, 2, g_dwTime, 200);
			break;
		case CKHR_Player::ATTACK:
			Set_FrameInfo(0, 4, 3, g_dwTime, 200);
			break;
		}

		m_ePreState = m_eCurState;
	}
}

void CKHR_Player::Move_Frame()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < g_dwTime)
	{
		++m_tFrame.iFrameStart;

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;

		m_tFrame.dwTime = g_dwTime;
	}
}

void CKHR_Player::OnHit(CObj* _pObj)
{
}