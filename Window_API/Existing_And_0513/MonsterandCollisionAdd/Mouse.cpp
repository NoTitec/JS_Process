#include "Mouse.h"

CMouse::CMouse()
{
}

CMouse::~CMouse()
{
	Release();
}

void CMouse::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
}

int CMouse::Update()
{
	POINT		ptMouse{};

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	m_tInfo.fX = (float)ptMouse.x;
	m_tInfo.fY = (float)ptMouse.y;

	__super::Update_Rect();

	ShowCursor(FALSE);

	return OBJ_NOEVENT;
}

void CMouse::Late_Update()
{
}

void CMouse::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMouse::Release()
{
}

//가상함수 몸통대충구현부
RECT* CMouse::Get_Rect_Pointer()
{
	return nullptr;
}
