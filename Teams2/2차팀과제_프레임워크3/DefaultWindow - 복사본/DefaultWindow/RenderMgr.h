#pragma once
#include "Define.h"
#include "Singleton.h"
#include "Object.h"
class CRenderMgr :public CSingleton<CRenderMgr>
{
    friend CSingleton<CRenderMgr>;
private:
    CRenderMgr();
    virtual ~CRenderMgr();

public:
    void Init(HDC _hMemDC);
    void Release();

public:
    void BeginRender() { PatBlt(m_hMemDC, 0, 0, WINCX, WINCY, WHITENESS); }
    void EndRender() { BitBlt(m_hDC, 0, 0, WINCX, WINCY, m_hMemDC, 0, 0, SRCCOPY); }

public:
    void Late_Update();
    void Set_Target(CObject* _pTarget);
    void Set_Region(const Point2<int>& _tLT, const Point2<int>& _tRB);

public:
    void DrawRect(const RECT& _tRect);
    void DrawEllipse(const RECT& _tRect);
    void DrawTxt(const int& _x, const int& _y, wstring _wstring) { TextOut(m_hMemDC, _x, _y, _wstring.c_str(), _wstring.length()); }
    void DrawLine(const Line2F& _tLine);
    void DrawLine(const LINE& _tLine);
    /*void DrawBMP(const RECT& _tRect, HDC _bmpDC) {
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
    };*/
    void DrawBMP(HDC _hBmpDC, const RECT& _tDstRect, const RECT& _tSrcRect, UINT _transCol )
    {
        GdiTransparentBlt(m_hMemDC,
            _tDstRect.left - (m_tCurCameraPos.x - WINCX / 2), 
            _tDstRect.top - (m_tCurCameraPos.y - WINCY / 2),
            _tDstRect.right - _tDstRect.left,
            _tDstRect.bottom - _tDstRect.top,
            _hBmpDC,
            _tSrcRect.left,
            _tSrcRect.top,
            _tSrcRect.right-_tSrcRect.left,
            _tSrcRect.bottom-_tSrcRect.top,
            _transCol
        );
    }

    void DrawBackground(HDC _hBmpDC, const RECT& _tDstRect)
    {
        BitBlt(m_hMemDC,
            _tDstRect.left - (m_tCurCameraPos.x - WINCX / 2),
            _tDstRect.top - (m_tCurCameraPos.y - WINCY / 2),
            _tDstRect.right - (m_tCurCameraPos.x - WINCX / 2),
            _tDstRect.bottom - (m_tCurCameraPos.y - WINCY / 2),
            _hBmpDC, 0, 0, SRCCOPY);
    }

private:
    HDC         m_hDC{};
    HDC         m_hMemDC{};
    CObject*    m_pTarget{};
    Point2F     m_tPrevCameraPos{ WINCX / 2, WINCY / 2 };
    Point2F     m_tCurCameraPos{ WINCX / 2, WINCY / 2 };
    Point2F     m_tTargetPos{};
    Point2<int> m_tRegionLT{};
    Point2<int> m_tRegionRB{};

};
#define RENDER CRenderMgr::Get_Instance()