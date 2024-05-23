#include "stdafx.h"
#include "RenderMgr.h"

CRenderMgr::CRenderMgr()
{
}

CRenderMgr::~CRenderMgr()
{
    Release();
}

void CRenderMgr::Init()
{
    m_hDC = GetDC(g_hWnd);
    m_hMemDC = CreateCompatibleDC(m_hDC);
    m_hMemBitmap = CreateCompatibleBitmap(m_hMemDC, WINCX, WINCY);
    HBITMAP hOldBitmap{ (HBITMAP)SelectObject(m_hMemDC, m_hMemBitmap) };
    DeleteObject(hOldBitmap);
}


void CRenderMgr::Release()
{
    DeleteObject(m_hMemBitmap);
    DeleteDC(m_hMemDC);
    ReleaseDC(g_hWnd, m_hDC);
}