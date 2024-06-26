
// ToolView.h : CToolView 클래스의 인터페이스
//

#pragma once

#include "Include.h"
#include "Device.h"

#include "TextureMgr.h"
#include "Terrain.h"

class CToolDoc;

class CToolView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CToolView();
	DECLARE_DYNCREATE(CToolView)

// 특성입니다.
public:
	CToolDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();

public:
	CTerrain*		m_pTerrain;

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ToolView.cpp의 디버그 버전
inline CToolDoc* CToolView::GetDocument() const
   { return reinterpret_cast<CToolDoc*>(m_pDocument); }
#endif



// 1. 직선의 방정식을 이용하여 마우스와 충돌한 타일 이미지를 교체해라

// y = ax + b
// 
// a : 기울기 (y 증가량 / x 증가량)
// b : y 절편 (x가 0일 때, y 값)

// 2. 미니맵에 타일 600장 모두 출력되게 만들고 픽킹에 따라 텍스처 변화까지 만들어라