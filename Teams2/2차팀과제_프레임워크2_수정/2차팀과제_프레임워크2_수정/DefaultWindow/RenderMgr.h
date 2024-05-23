#pragma once
#include "Define.h"
#include "Singleton.h"
class CRenderMgr :public CSingleton<CRenderMgr>
{
    friend CSingleton<CRenderMgr>;
private:
    CRenderMgr();
    virtual ~CRenderMgr();

public:
    void Init();
    void Release();

public:

    void BeginRender() { PatBlt(m_hMemDC, 0, 0, WINCX, WINCY, WHITENESS); }
    void EndRender() { BitBlt(m_hDC, 0, 0, WINCX, WINCY, m_hMemDC, 0, 0, SRCCOPY); }

    // TODO: 스크롤또는 카메라와 연동 + 더블버퍼링 적용
    void DrawRect(const RECT& _tRect) { Rectangle(m_hMemDC, _tRect.left, _tRect.top, _tRect.right, _tRect.bottom); }
    void DrawEllipse(const RECT& _tRect) { Ellipse(m_hMemDC, _tRect.left, _tRect.top, _tRect.right, _tRect.bottom); }
    void DrawTxt(const int& _x, const int& _y, wstring _wstring) { TextOut(m_hMemDC, _x, _y, _wstring.c_str(), _wstring.length()); }
    void DrawLine(const Line2F& _tLine) { MoveToEx(m_hMemDC, (int)_tLine.p1.x, (int)_tLine.p1.y, NULL); LineTo(m_hMemDC, (int)_tLine.p2.x, (int)_tLine.p2.y); }
    void DrawLine(const LINE& _tLine) { MoveToEx(m_hMemDC, (int)_tLine.tLeft.fX, (int)_tLine.tLeft.fY, NULL); LineTo(m_hMemDC, (int)_tLine.tRight.fX, (int)_tLine.tRight.fY); }
    void DrawBMP(const RECT& _tRect, HDC _bmpDC) {
        GdiTransparentBlt(m_hMemDC,
            _tRect.left,
            _tRect.top,
            _tRect.right -_tRect.left,
            _tRect.top - _tRect.bottom,
            _bmpDC,
            0, 0,
            _tRect.right - _tRect.left,
            _tRect.top - _tRect.bottom,
            RGB(255, 0, 255));
    };
private:
    HDC m_hDC{};
    HDC m_hMemDC{};
    HBITMAP m_hMemBitmap{};

};
#define RENDER CRenderMgr::Get_Instance()