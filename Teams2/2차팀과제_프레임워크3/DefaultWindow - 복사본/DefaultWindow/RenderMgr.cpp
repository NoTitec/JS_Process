#include "stdafx.h"
#include "RenderMgr.h"

CRenderMgr::CRenderMgr()
{
}

CRenderMgr::~CRenderMgr()
{
    Release();
}

void CRenderMgr::Init(HDC _hMemDC)
{
    m_hDC = GetDC(g_hWnd);
    m_hMemDC = _hMemDC;
}


void CRenderMgr::Release()
{
    ReleaseDC(g_hWnd, m_hDC);
}

void CRenderMgr::Late_Update()
{
    if (m_pTarget != nullptr)
    {
        m_tPrevCameraPos = m_tCurCameraPos;
        Point2F targetPos{ m_pTarget->m_tPos };
        m_tTargetPos = m_pTarget->m_tPos - Point2F{ 0 ,100 };
        Vec2F prevtarget{ m_tTargetPos - m_tPrevCameraPos };
        m_tCurCameraPos = m_tPrevCameraPos + prevtarget * 0.05f;
        if (m_tCurCameraPos.x < m_tRegionLT.x + WINCX / 2) m_tCurCameraPos.x = m_tRegionLT.x + WINCX / 2;
        if (m_tCurCameraPos.y < m_tRegionLT.y + WINCY / 2) m_tCurCameraPos.y = m_tRegionLT.y + WINCY / 2;
        if (m_tCurCameraPos.x > m_tRegionRB.x - WINCX / 2) m_tCurCameraPos.x = m_tRegionRB.x - WINCX / 2;
        if (m_tCurCameraPos.y > m_tRegionRB.y - WINCY / 2) m_tCurCameraPos.y = m_tRegionRB.y - WINCY / 2;
        cout << m_tCurCameraPos.x << "," << m_tCurCameraPos.y << endl;
    }
}

void CRenderMgr::Set_Target(CObject* _pTarget)
{
    m_pTarget = _pTarget;
}

void CRenderMgr::Set_Region(const Point2<int>& _tLT, const Point2<int>& _tRB)
{
    m_tRegionLT = _tLT;
    m_tRegionRB = _tRB;
}

void CRenderMgr::DrawRect(const RECT& _tRect)
{
    Rectangle(m_hMemDC,
        _tRect.left - (m_tCurCameraPos.x - WINCX / 2),
        _tRect.top - (m_tCurCameraPos.y - WINCY / 2),
        _tRect.right - (m_tCurCameraPos.x - WINCX / 2),
        _tRect.bottom - (m_tCurCameraPos.y - WINCY / 2)
    );
}

void CRenderMgr::DrawEllipse(const RECT& _tRect)
{
    Ellipse(m_hMemDC,
        _tRect.left - (m_tCurCameraPos.x - WINCX / 2),
        _tRect.top - (m_tCurCameraPos.y - WINCY / 2),
        _tRect.right - (m_tCurCameraPos.x - WINCX / 2),
        _tRect.bottom - (m_tCurCameraPos.y - WINCY / 2)
    );
}

void CRenderMgr::DrawLine(const Line2F& _tLine)
{
    MoveToEx(m_hMemDC, 
        (int)_tLine.p1.x - (m_tCurCameraPos.x - WINCX / 2),
        (int)_tLine.p1.y - (m_tCurCameraPos.y - WINCY / 2),
       NULL); 

    LineTo(m_hMemDC,
        (int)_tLine.p2.x - (m_tCurCameraPos.x - WINCX / 2),
        (int)_tLine.p2.y - (m_tCurCameraPos.y - WINCY / 2)
    ); 
}

void CRenderMgr::DrawLine(const LINE& _tLine)
{
    MoveToEx(m_hMemDC, 
        (int)_tLine.tLeft.fX, 
        (int)_tLine.tLeft.fY,
        NULL); 

    LineTo(m_hMemDC, 
        (int)_tLine.tRight.fX, 
        (int)_tLine.tRight.fY
    );
}
