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
	m_iHP = 3;
	m_fSpeed = 3.0f;

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


	DT_Update();
	// 마우스 커서 좌표를 기반으로 방향벡터를 구함.
	Dir_Update();
	// 방향을 기반으로 Posin 좌표를 구함.
	Posin_Update();

	Key_Update();

	if (m_fDashCoolTime > 0.f)
	{
		m_fDashCoolTime -= m_fDT;
	}
	else if (m_fDashCoolTime < 0.f)
	{
		m_fDashCoolTime = 0.f;
	}
	Player_Dash();



	CObj::Update_Rect();

	m_pHpBar->Update();
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	for (auto iter = m_pBarrierList->begin(); iter != m_pBarrierList->end(); ++iter)
	{
		dynamic_cast<CBarrier*>(*iter)->PlayerPos_Update(Get_Pos());
	}

	m_pHpBar->Late_Update();
}

void CPlayer::Render(HDC _hdc)
{
	RECT PlayerRect = Get_Rect();
	Ellipse(_hdc, PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom);

	Cursor_Render(_hdc);
	Posin_Render(_hdc);
	TCHAR	szBuf[32] = L"";

	// wsprintf : 소수점 자릿수의 출력 불가능, winapi 라이브러리에서 제공
	wsprintf(szBuf, L"DashCoolTime : %d", (int)m_fDashCoolTime);

	//swprintf_s(szBuf, L"Bullet : %f", 3.14f);	// visual c++ 라이브러리에서 제공(모든 서식 문자를 지원)
	TextOut(_hdc, 50, 50, szBuf, lstrlen(szBuf));
	m_pHpBar->Render(_hdc);
}

void CPlayer::Release()
{
	Safe_Delete(m_pHpBar);
}

void CPlayer::Key_Update()
{
	INFO PlayerInfo = Get_Info();
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
	if (KEY_TAP(KEY::NUM1))
	{
		m_iType = 0;
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
		m_arrStatus[PLAYER_DASH] = true;
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
		Create_Bullet();
	}
	if (KEY_HOLD(KEY::LSHIFT) && m_arrStatus[PLAYER_BARRIER])
	{
		Create_Barrier();
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

	HPEN yellowPen = CreatePen(PS_SOLID, 2, RGB(251, 233, 35));
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
	if (m_arrStatus[PLAYER_DASH] && g_iDashCount % 2 == 1)
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
	if (m_iDashCallCount == 3)
	{
		m_iDashCallCount = 0;
		m_arrStatus[PLAYER_DASH] = false;
		Set_Scale(30.f, 30.f);
	}
}
void CPlayer::Player_Barrier()
{
}
CObj* CPlayer::Create_Bullet()
{
	m_pBulletList->push_back(CAbstractFactory<CBullet>::Create());
	CObj* pBullet = m_pBulletList->back();
	pBullet->Set_Pos(Get_Pos()); // 플레이어 좌표
	pBullet->Set_Dir(Get_Dir()); // 방향 벡터 >>> 마우스 커서 위치 (노말라이즈 한거)
	pBullet->Set_Type(Get_type()); // 무기 타입.

	return nullptr;
}

UINT m_iBarrierCount = 0;
CObj* CPlayer::Create_Barrier()
{
	++m_iBarrierCount;
	m_pBarrierList->push_back(CAbstractFactory<CBarrier>::Create());
	CObj* pBarrier = m_pBarrierList->back();
	pBarrier->Set_Pos(Get_Pos());
	pBarrier->Set_Dir(Get_Dir());
	pBarrier->Set_Type(Get_type());
	if (m_iBarrierCount % 18 == 0)
	{
		m_arrStatus[PLAYER_BARRIER] = false;
	}
	return nullptr;
}

