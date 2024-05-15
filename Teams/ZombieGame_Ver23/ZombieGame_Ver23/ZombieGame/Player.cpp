#include "pch.h"
#include "Player.h"

#include "HpBar.h"
#include "Bullet.h"
#include "Barrier.h"

#include "CKeyMgr.h"
#include "AbstractFactory.h"
CPlayer::CPlayer()
	: m_pBulletList(nullptr)
	, m_ptCursorPos{}
	, m_dwPrevCount(0)
	, m_dwCurCount(0)
	, m_fDT(0.f)
	, m_fAcc(0.f)
	, m_fDashCoolTime(0)
	, m_iDashCallCount(0)
	, m_pHpBar(nullptr)
	, m_arrState{}
	, m_iBarriersize(0)
	, m_iReboundsize(0)
	, m_fReboundSpeed(0.f)
	, m_iBulletCount(0)
{

}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = WINCX / 2.0f;
	m_tInfo.fY = WINCY / 2.0f;
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_iHP = 10;
	m_fSpeed = 3.0f;

	m_arrState[PLAYER_BARRIER] = false;
	m_arrState[PLAYER_REBOUND] = false;
	m_fReboundSpeed = 5.f;
	// 총알 타입, 총알 수
	Set_Type(0);
	m_iBulletCount = 30;


	m_dwPrevCount = GetTickCount();
	m_pHpBar = new CHpBar();
	static_cast<CHpBar*>(m_pHpBar)->Set_Target(this);
	m_pHpBar->Initialize();
}

int CPlayer::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}


	// 이전 프레임 상태값 처리.
	if (m_fDashCoolTime > 0.f)
	{
		m_fDashCoolTime -= m_fDT;
	}
	else if (m_fDashCoolTime < 0.f)
	{
		m_fDashCoolTime = 0.f;
	}
	Player_Dash();
	Player_Barrier();
	Player_Rebound();


	//
	DT_Update();
	// 마우스 커서 좌표를 기반으로 방향벡터를 구함.
	Dir_Update();
	// 방향을 기반으로 Posin 좌표를 구함.
	Posin_Update();

	Key_Update();


	CObj::Update_Rect();

	m_pHpBar->Update();
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	for (auto iter = m_pBarrierList->begin(); iter != m_pBarrierList->end(); ++iter)
	{
		static_cast<CBarrier*>(*iter)->PlayerPos_Update(Get_Pos());
	}

	m_pHpBar->Late_Update();
}

void CPlayer::Render(HDC _hdc)
{
	Cursor_Render(_hdc);
	Posin_Render(_hdc);
	// 플레이어 렌더
	Vec2 vScale = Get_Scale();
	RECT PlayerRect = Get_Rect();
	if (m_arrState[PLAYER_DASH])
	{
		HBRUSH yellowBrush = CreateSolidBrush(RGB(255, 255, 71));
		HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, yellowBrush);
		::Ellipse(_hdc, m_tRect.left + 3, m_tRect.top + 3, m_tRect.right - 3, m_tRect.bottom - 3);
		::SelectObject(_hdc, oldBrush);
		::DeleteObject(yellowBrush);
	}
	else
	{
		Ellipse(_hdc, PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom);
	}


	// 대쉬 쿨타임 렌더.
	HFONT DashCoolFont1 = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("굴림"));
	HFONT oldFont = (HFONT)::SelectObject(_hdc, DashCoolFont1);
	::SetBkMode(_hdc, TRANSPARENT);
	::SetTextColor(_hdc, RGB(0, 0, 0));
	::TextOut(_hdc, 10, 10, L"대쉬 쿨타임 : ", 9);

	TCHAR	szBulletCount[16] = L"";
	HFONT BulletCountFont2 = CreateFont(16, 0, 0, 0, FW_EXTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("굴림"));
	DashCoolFont1 = (HFONT)::SelectObject(_hdc, BulletCountFont2);

	wsprintf(szBulletCount, L"%d", (int)m_fDashCoolTime);
	::TextOut(_hdc, 110, 10, szBulletCount, 2);

	BulletCountFont2 = (HFONT)::SelectObject(_hdc, DashCoolFont1);
	::TextOut(_hdc, 130, 10, L" 초", 2);
	::SetTextColor(_hdc, RGB(0, 0, 0));
	::SetBkMode(_hdc, OPAQUE);
	::SelectObject(_hdc, oldFont);
	::DeleteObject(DashCoolFont1);
	::DeleteObject(BulletCountFont2);

	// 탄창 수 렌더.
	if (m_iBulletCount > 0)
	{
		HFONT BulletCountFont1 = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("굴림"));
		HFONT oldFont = (HFONT)::SelectObject(_hdc, BulletCountFont1);
		::SetBkMode(_hdc, TRANSPARENT);
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::TextOut(_hdc, 10, 30, L"탄창 수 : ", 7);

		TCHAR	szBulletCount[16] = L"";
		HFONT BulletCountFont2 = CreateFont(16, 0, 0, 0, FW_HEAVY, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("굴림"));
		BulletCountFont1 = (HFONT)::SelectObject(_hdc, BulletCountFont2);
		wsprintf(szBulletCount, L"%d", (int)m_iBulletCount);

		::TextOut(_hdc, 80, 30, szBulletCount, 2);
		BulletCountFont2 = (HFONT)::SelectObject(_hdc, BulletCountFont1);
		::TextOut(_hdc, 100, 30, L" 발", 2);
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::SetBkMode(_hdc, OPAQUE);
		::SelectObject(_hdc, oldFont);
		::DeleteObject(BulletCountFont1);
		::DeleteObject(BulletCountFont2);
	}
	else
	{
		HFONT BulletCountFont1 = CreateFont(16, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("굴림"));

		HFONT oldFont = (HFONT)::SelectObject(_hdc, BulletCountFont1);
		::SetBkMode(_hdc, TRANSPARENT);
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::TextOut(_hdc, 10, 30, L"탄창 수 : ", 7);

		SetTextColor(_hdc, RGB(250, 50, 0));
		TCHAR	szBulletCount[16] = L"";
		HFONT BulletCountFont2 = CreateFont(16, 0, 0, 0, FW_EXTRABOLD, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("굴림"));
		BulletCountFont1 = (HFONT)::SelectObject(_hdc, BulletCountFont2);
		wsprintf(szBulletCount, L"%d", (int)m_iBulletCount);

		::TextOut(_hdc, 80, 30, szBulletCount, 2);

		BulletCountFont2 = (HFONT)::SelectObject(_hdc, BulletCountFont1);
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::TextOut(_hdc, 100, 30, L" 발", 2);
		::SetBkMode(_hdc, OPAQUE);
		::SelectObject(_hdc, oldFont);
		::DeleteObject(BulletCountFont1);
		::DeleteObject(BulletCountFont2);
	}
	/*TCHAR	szBulletCount[32] = L"";
	wsprintf(szBulletCount, L"탄창 수: %d 발", (int)m_iBulletCount);
	TextOut(_hdc, 10, 30, szBulletCount, lstrlen(szBulletCount));*/



	if (KEY_TAP(KEY::LBUTTON) && m_iBulletCount == 0 || KEY_HOLD(KEY::LBUTTON) && m_iBulletCount == 0)
	{
		SetTextColor(_hdc, RGB(250, 50, 0));
		Vec2 vPos = Get_Pos();
		Vec2 vScale = Get_Scale();
		TCHAR	szExclamation[16] = L"";
		wsprintf(szExclamation, L"!");

		HFONT ExclamationFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
		HFONT oldFont = (HFONT)::SelectObject(_hdc, ExclamationFont);
		::SetBkMode(_hdc, TRANSPARENT);
		::SetTextColor(_hdc, RGB(250, 50, 0));
		::TextOut(_hdc, vPos.fX + vScale.fX / 2.f, vPos.fY - vScale.fY / 2.f, szExclamation, lstrlen(szExclamation));
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::SetBkMode(_hdc, OPAQUE);
		::SelectObject(_hdc, oldFont);
		::DeleteObject(ExclamationFont);
	}




	m_pHpBar->Render(_hdc);
}

void CPlayer::Release()
{
	Safe_Delete(m_pHpBar);
}

void CPlayer::Key_Update()
{
	INFO PlayerInfo = Get_Info();
	// 수류탄일때만 방향키 막음.
	if (!(m_arrState[PLAYER_REBOUND] && Get_Type() == GRENADE_BULLET))
	{
		if (KEY_HOLD(KEY::W))
		{
			PlayerInfo.fY -= m_fSpeed;
		}
		if (KEY_HOLD(KEY::S))
		{
			PlayerInfo.fY += m_fSpeed;
		}
		if (KEY_HOLD(KEY::A))
		{
			PlayerInfo.fX -= m_fSpeed;
		}
		if (KEY_HOLD(KEY::D))
		{
			PlayerInfo.fX += m_fSpeed;
		}
	}

	if (KEY_TAP(KEY::NUM1))
	{
		m_iType = 0;
		// 숫자키 눌러서 타입 바꾸면서 체크하고있는데 테스트용
		// 반동이 무기마다 다르거든요? 

		// 근데 곧바로 적용안되고 1번 쏘고 바꾸;ㅣㅁ 반동이 

		// 1번무기에서 >>> 2번무기로 바꿨는데 처음 1발은 1번무기 반동으로 나가고 , 2번째 발부터 바뀜 . 
		// 
	}
	if (KEY_TAP(KEY::NUM2))
	{
		m_iType = 1;
	}
	if (KEY_TAP(KEY::NUM3))
	{
		m_iType = 2;
	}
	if (KEY_TAP(KEY::NUM4))
	{
		m_iType = 3;
	}
	if (KEY_TAP(KEY::SPACE) && 0.5f >= m_fDashCoolTime)
	{
		m_arrState[PLAYER_DASH] = true;
	}
	if (KEY_HOLD(KEY::SPACE))
	{

	}
	if (KEY_AWAY(KEY::SPACE))
	{
		m_fAcc = 0.f;
		PlayerInfo.fCX = 30.f;
		PlayerInfo.fCY = 30.f;
		if (m_fDashCoolTime == 0.f)
		{
			m_fDashCoolTime = 5.f;
		}

	}
	if (KEY_TAP(KEY::LBUTTON))
	{
		int ibulletType = Get_Type();
		switch (ibulletType)
		{
		case NORMAL_BULLET:
		{
			if (m_iBulletCount)
			{
				m_iBulletCount -= 1;
				Create_Bullet();
				m_arrState[PLAYER_REBOUND] = true;
			}
			//else
			//{
			//	//m_iBulletCount = 10;
			//	Set_Type((int)NORMAL_BULLET);
			//}
		}

		break;
		case SHOTGUN_BULLET:
		{
			if (m_iBulletCount >= 3)
			{
				m_iBulletCount -= 3;
				Create_Bullet();
				Create_Bullet();
				Create_Bullet();
				m_arrState[PLAYER_REBOUND] = true;
			}
			//if (!m_iBulletCount)
			//{
			//	//m_iBulletCount = 10;
			//	Set_Type((int)NORMAL_BULLET);
			//}
		}
		break;
		case GRENADE_BULLET:
		{
			if (m_iBulletCount)
			{
				m_iBulletCount -= 1;
				Create_Bullet();
				m_arrState[PLAYER_REBOUND] = true;
			}
			//if (!m_iBulletCount)
			//{
			//	//m_iBulletCount = 11;
			//	//Set_Type((int)NORMAL_BULLET);
			//}
		}
		break;
		case BULLET_END:
			break;
		default:
			break;
		}

	}
	if (KEY_TAP(KEY::LSHIFT))
	{

	}
	Set_Info(PlayerInfo);
}

void CPlayer::DT_Update()
{
	m_dwCurCount = GetTickCount();

	m_fDT = (float)(m_dwCurCount - m_dwPrevCount) / 1000.f;
	m_dwPrevCount = m_dwCurCount;
}


void CPlayer::Dir_Update()
{
	// 마우스 좌표를 받아옴.
	GetCursorPos(&m_ptCursorPos);
	// 현재 창 기준 마우스 좌표를 받아옴.
	ScreenToClient(g_hWnd, &m_ptCursorPos);

	Vec2 vPos = Get_Pos();
	Vec2 vDir;

	vDir.fX = m_ptCursorPos.x - vPos.fX;
	vDir.fY = m_ptCursorPos.y - vPos.fY;
	// CursorPos - vPos 한 값을 Normalize.
	vDir.Normalize();

	Set_Dir(vDir);
}

void CPlayer::Posin_Update()
{
	Vec2 vDir = Get_Dir();
	Vec2 vPosin = Get_Pos();
	float fDistance = Get_Distance();

	vPosin.fX += vDir.fX * fDistance;
	vPosin.fY += vDir.fY * fDistance;

	Set_Posin(vPosin);
}

void CPlayer::Cursor_Render(HDC _hdc)
{

	HPEN yellowPen = CreatePen(PS_SOLID, 3, RGB(251, 233, 35));
	HPEN oldPen = (HPEN)::SelectObject(_hdc, yellowPen);
	//HBRUSH HollowBrush = (HBRUSH)GetStockObject(BS_HOLLOW);
	HBRUSH greenBrush = CreateSolidBrush(RGB(144, 215, 86));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, greenBrush);
	/*Ellipse(_hdc,
		m_ptCursorPos.x - 20.f, m_ptCursorPos.y - 20.f,
		m_ptCursorPos.x + 20.f, m_ptCursorPos.y + 20.f);*/
	POINT ptCursor = m_ptCursorPos;


	MoveToEx(_hdc, m_ptCursorPos.x - 15.f, m_ptCursorPos.y, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x - 3.f, m_ptCursorPos.y);
	MoveToEx(_hdc, m_ptCursorPos.x + 15.f, m_ptCursorPos.y, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x + 3.f, m_ptCursorPos.y);

	MoveToEx(_hdc, m_ptCursorPos.x, m_ptCursorPos.y - 15.f, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x, m_ptCursorPos.y - 3.f);
	MoveToEx(_hdc, m_ptCursorPos.x, m_ptCursorPos.y + 15.f, &ptCursor);
	LineTo(_hdc, m_ptCursorPos.x, m_ptCursorPos.y + 3.f);

	::SelectObject(_hdc, oldPen);
	::DeleteObject(yellowPen);
	::SelectObject(_hdc, oldBrush);
	::DeleteObject(greenBrush);

}

UINT g_iDashCount = 0;
void CPlayer::Player_Dash()
{
	++g_iDashCount;
	if (m_arrState[PLAYER_DASH] && g_iDashCount % 2 == 1)
	{
		++m_iDashCallCount;
		Vec2 vPos = Get_Pos();
		Vec2 vScale = Get_Scale();
		Vec2 vDir = Get_Dir();

		if (abs(vDir.fX) > abs(vDir.fY))
		{
			vScale.fX = 40.f;
			vScale.fY = 20.f;
		}
		else
		{
			vScale.fX = 20.f;
			vScale.fY = 40.f;
		}


		vPos = vPos + vDir * 40.f;
		Set_Scale(vScale);
		Set_Pos(vPos);
	}
	if (m_iDashCallCount == 4)
	{
		m_iDashCallCount = 0;
		m_arrState[PLAYER_DASH] = false;
		Set_Scale(30.f, 30.f);
	}
}
void CPlayer::Player_Barrier()
{
	Create_Barrier();
}
UINT g_iReboundCount;
void CPlayer::Player_Rebound()
{
	UINT iWeaponType = Get_Type();
	Vec2 vPos = Get_Pos();
	Vec2 vScale = Get_Scale();
	Vec2 vDir = Get_Dir();
	switch (iWeaponType)
	{
	case NORMAL_BULLET:
		if (g_iReboundCount > 10)
		{
			g_iReboundCount = 0;
			m_fReboundSpeed = 5.f;
			m_arrState[PLAYER_REBOUND] = false;
		}
		if (m_arrState[PLAYER_REBOUND])
		{
			++g_iReboundCount;
			m_fReboundSpeed -= 0.3f;
			vPos.fX -= vDir.fX * m_fReboundSpeed;
			vPos.fY -= vDir.fY * m_fReboundSpeed;
		}
		break;

	case SHOTGUN_BULLET:
		if (g_iReboundCount > 10)
		{
			g_iReboundCount = 0;
			m_fReboundSpeed = 6.f;
			m_arrState[PLAYER_REBOUND] = false;
		}
		if (m_arrState[PLAYER_REBOUND])
		{
			++g_iReboundCount;
			m_fReboundSpeed -= 0.1f;
			vPos.fX -= vDir.fX * m_fReboundSpeed;
			vPos.fY -= vDir.fY * m_fReboundSpeed;
		}
		break;
	case GRENADE_BULLET:
		if (g_iReboundCount > 20)
		{
			g_iReboundCount = 0;
			m_fReboundSpeed = 5.f;
			m_arrState[PLAYER_REBOUND] = false;
		}
		if (m_arrState[PLAYER_REBOUND])
		{
			++g_iReboundCount;
			m_fReboundSpeed -= 0.1f;
			vPos.fX -= vDir.fX * m_fReboundSpeed;
			vPos.fY -= vDir.fY * m_fReboundSpeed;
		}
		break;
	case BULLET_END:
		break;
	default:
		break;
	}


	Set_Pos(vPos);
	Set_Scale(vScale);
}
CObj* CPlayer::Create_Bullet()
{
	m_pBulletList->push_back(CAbstractFactory<CBullet>::Create());
	CObj* pBullet = m_pBulletList->back();
	pBullet->Set_Pos(Get_Pos()); // 플레이어 좌표
	pBullet->Set_Dir(Get_Dir()); // 방향 벡터 >>> 마우스 커서 위치 (노말라이즈 한거)
	pBullet->Set_Type(Get_Type()); // 무기 타입.

	if (m_iType == (int)GRENADE_BULLET)
	{
		pBullet->Set_Speed(12.f);
	}
	
	return nullptr;
}
int iBarrierCallCount = 0;
CObj* CPlayer::Create_Barrier()
{
	if (m_arrState[PLAYER_BARRIER])
	{
		++m_iBarriersize;
		m_pBarrierList->push_back(CAbstractFactory<CBarrier>::Create());
		CObj* pBarrier = m_pBarrierList->back();
		pBarrier->Set_Pos(Get_Pos());
		pBarrier->Set_Dir(Get_Dir());
		//pBarrier->Set_Type(Get_Type());
	}
	if (m_iBarriersize % 18 == 0)
	{
		m_arrState[PLAYER_BARRIER] = false;
		m_iBarriersize = 0;
	}
	if (m_arrState[PLAYER_BARRIER] && iBarrierCallCount < 30)
	{
		++iBarrierCallCount;
	}
	else
	{
		iBarrierCallCount = 0;
	}
	return nullptr;
}
