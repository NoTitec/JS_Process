#include "pch.h"
#include "Player.h"

#include "Bullet.h"
#include "Barrier.h"

#include "CKeyMgr.h"
#include "AbstractFactory.h"
CPlayer::CPlayer()
	: m_pBulletList(nullptr)
	, m_ptCursorPos{}
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
    m_tInfo.fCX = 30.0f;
    m_tInfo.fCY = 30.0f;

    m_fSpeed = 3.0f;
}

int CPlayer::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }
	// 마우스 커서 좌표를 기반으로 방향벡터를 구함.
	Dir_Update();
	// 방향을 기반으로 Posin 좌표를 구함.
	Posin_Update();
	
    Key_Update();

    CObj::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	for (auto iter = m_pBarrierList->begin(); iter != m_pBarrierList->end(); ++iter)
	{
		dynamic_cast<CBarrier*>(*iter)->PlayerPos_Update(Get_Pos());
	}
	
}

void CPlayer::Render(HDC _hdc)
{
    RECT PlayerRect = Get_Rect();
    Ellipse(_hdc, PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom);

	Cursor_Render(_hdc);
	Posin_Render(_hdc);
}

void CPlayer::Release()
{

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
	if (KEY_TAP(KEY::SPACE))
	{
		PlayerInfo.fCX = 0.f;
		PlayerInfo.fCY = 0.f;
	}
	if (KEY_HOLD(KEY::SPACE))
	{
		
	}
	if (KEY_AWAY(KEY::SPACE))
	{
		PlayerInfo.fX += 100.f * m_vDir.fX;
		PlayerInfo.fY += 100.f * m_vDir.fY;

		PlayerInfo.fCX = 30.f;
		PlayerInfo.fCY = 30.f;
	}
	if (KEY_TAP(KEY::LBUTTON))
	{
		Create_Bullet();
	}
	if (KEY_HOLD(KEY::LSHIFT))
	{
		Create_Barrier();
	}
	Set_Info(PlayerInfo);
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
	MoveToEx(_hdc, m_ptCursorPos.x + 19.f, m_ptCursorPos.y, &ptCursor);
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

CObj* CPlayer::Create_Bullet()
{
	m_pBulletList->push_back(CAbstractFactory<CBullet>::Create());
	CObj* pBullet = m_pBulletList->back();
	pBullet->Set_Pos(Get_Pos()); // 플레이어 좌표
	pBullet->Set_Dir(Get_Dir()); // 방향 벡터 >>> 마우스 커서 위치 (노말라이즈 한거)
	pBullet->Set_Type(Get_type()); // 무기 타입.

	return nullptr;
}

CObj* CPlayer::Create_Barrier()
{
	m_pBarrierList->push_back(CAbstractFactory<CBarrier>::Create());
	CObj* pBarrier = m_pBarrierList->back();
	pBarrier->Set_Pos(Get_Pos());
	pBarrier->Set_Dir(Get_Dir());
	pBarrier->Set_Type(Get_type());

	return nullptr;
}


