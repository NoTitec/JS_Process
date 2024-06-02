#include "Player.h"
#include "EventDefine.h"
#include "stdafx.h"
#include "AbstractFactory.h"
#include "MikoBasicBullet.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
CPlayer::CPlayer(): m_fTime(0.f), m_iPower(0)
, m_eCurState(FORWARDMOVE), m_ePreState(ST_END)
{
    ZeroMemory(&m_tPetPoint, sizeof(POINT));

}

CPlayer::~CPlayer()
{
    Release();

}

void CPlayer::Initialize()
{
	m_eID = OBJ_PLAYER;
    m_tInfo = { 100.f, WINCY / 2.f, 32.f, 32.f };
	m_tPetPoint.x = m_tInfo.fX - 16.f;
	m_tPetPoint.y = m_tInfo.fY - 16.f;
    m_fSpeed = 8.f;
	m_dwDebugMassageTime = GetTickCount();
	//비트이미지 가로
	m_tFrame.iFrameStart = -1;
	//비트이미지 최대 개수
	m_tFrame.iFrameEnd = 2;
	//비트이미지 세로
	m_tFrame.iMotion = 0;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.dwSpeed = 100;
	m_dwBulletGenarateTime = GetTickCount();
	m_dwBulletGenarateSpeed = 150;
	m_pFrameKey = L"Miko_Fly_Forward";
	m_eCurState = FORWARDMOVE;
}

int CPlayer::Update()
{
	Key_Input();
	Create_Basic_Bullet();
	__super::Update_Rect();
	m_tPetPoint.x = m_tInfo.fX - 16.f;
	m_tPetPoint.y = m_tInfo.fY - 16.f;
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	Motion_Change();
	Offset();
	__super::Move_Frame();
#ifdef _DEBUG

	if (m_dwDebugMassageTime + 1000 < GetTickCount())
	{
		cout << "플레이어 좌표 : " << m_tInfo.fX << "\t" << m_tInfo.fY << endl;
		cout << "플레이어 파워 : " << m_iPower << endl;
		m_dwDebugMassageTime = GetTickCount();
	}



#endif // _DEBUG
}

void CPlayer::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		m_tRect.left + iScrollX,
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

void CPlayer::Release()
{
}

void CPlayer::OnHit(CObj* _pObj)
{
	OBJ_ID pObj_ID = _pObj->Get_ID();
	switch (pObj_ID)
	{
	case OBJ_ITEM:
		++m_iPower;
		m_HeadUIShow = true;
		break;
	}
}

void CPlayer::Key_Input()
{
	if (KeyMgr->Key_Pressing(VK_UP))
	{
		int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
		if (m_tInfo.fY+ iScrollY >= 16)
		m_tInfo.fY -= m_fSpeed;
	}
	if (KeyMgr->Key_Pressing(VK_DOWN))
	{
		int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
		if (m_tInfo.fY+ iScrollY <= 584)
		m_tInfo.fY += m_fSpeed;
	}
	if (KeyMgr->Key_Pressing(VK_RIGHT))
	{
		if(m_tInfo.fX<=784)
			m_tInfo.fX += m_fSpeed;
		m_pFrameKey = L"Miko_Fly_Forward";
		m_eCurState = FORWARDMOVE;
	}
	else if (KeyMgr->Key_Pressing(VK_LEFT))
	{
		if(m_tInfo.fX>=16)
			m_tInfo.fX -= m_fSpeed;
		m_pFrameKey = L"Miko_Fly_Backward";
		m_eCurState = BACKMOVE;
	}
	else
	{
		m_eCurState = FORWARDMOVE;
		m_pFrameKey = L"Miko_Fly_Forward";
	}
}

void CPlayer::Offset()
{
	int	iOffSetminX = 16;
	int	iOffSetmaxX = 784;

	int	iOffSetminY = 100;
	int	iOffSetmaxY = 500;

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (iOffSetminX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetmaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

	if (iOffSetminY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

	if (iOffSetmaxY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
}

void CPlayer::Motion_Change()
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case CPlayer::FORWARDMOVE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iMotion = 0;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 100;
			break;
		case CPlayer::BACKMOVE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 2;
			m_tFrame.iMotion = 0;
			m_tFrame.dwTime = GetTickCount();
			m_tFrame.dwSpeed = 100;
			break;
		}
		m_ePreState = m_eCurState;

	}
}

void CPlayer::Create_Basic_Bullet()
{
	if (m_dwBulletGenarateTime + m_dwBulletGenarateSpeed < GetTickCount())
	{
		int iScrollX = ScrollMgr->Get_ScrollX();
		int iScrollY = ScrollMgr->Get_ScrollY();
		ObjMgr->Add_Object(OBJ_PLAYERBULLET, CAbstractFactory<CMikoBasicBullet>::Create(m_tInfo.fX+iScrollX,m_tInfo.fY+iScrollY,DIR_RIGHT));
		m_dwBulletGenarateTime = GetTickCount();
	}
}
