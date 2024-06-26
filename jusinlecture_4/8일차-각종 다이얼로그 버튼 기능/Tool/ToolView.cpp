
// ToolView.cpp : CToolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Tool.h"
#endif

#include "ToolDoc.h"
#include "ToolView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND g_hWnd;

// CToolView

IMPLEMENT_DYNCREATE(CToolView, CScrollView)

BEGIN_MESSAGE_MAP(CToolView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CToolView 생성/소멸

CToolView::CToolView() : m_pTerrain(nullptr)
{

}

CToolView::~CToolView()
{
}
void CToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// SetScrollSizes : 스크롤 바의 사이즈를 지정하는 CScrollView 멤버 함수
	// MM_TEXT : 픽셀 단위로 크기를 조정 옵션

	SetScrollSizes(MM_TEXT, CSize(TILEX * TILECX, TILEY * TILECY / 2));
	
	// AfxGetMainWnd : 현재의 메인 윈도우를 반환하는 전역 함수
	CMainFrame*	pMainFrm = (CMainFrame*)AfxGetMainWnd();

	RECT rcWnd{};

	// GetWindowRect : 현재 윈도우의 렉트 정보를 얻어오는 함수
	pMainFrm->GetWindowRect(&rcWnd);

	// SetRect : 지정한 매개 변수 대로 렉트 정보를 얻어오는 함수
	SetRect(&rcWnd, 0, 0, rcWnd.right - rcWnd.left, rcWnd.bottom - rcWnd.top);

	RECT rcMainView{};

	// GetClientRect : 현재 view 창의 렉트 정보를 얻어오는 함수
	GetClientRect(&rcMainView);

	float	fRowFrm = float(rcWnd.right - rcMainView.right);
	float	fColFrm = float(rcWnd.bottom - rcMainView.bottom);

	// SetWindowPos : 매개 변수대로 창의 위치와 크기를 조정하는 함수
	pMainFrm->SetWindowPos(nullptr,		// 배치할 윈도우의 Z순서에 대한 조건자 포인터(순서 변경 안함)
							0, 0,		// X, Y 좌표
							int(WINCX + fRowFrm),// 가로 크기
							int(WINCY + fColFrm),// 세로 크기
							SWP_NOZORDER);// 현재 순서를 유지하겠다는 플래그


	g_hWnd = m_hWnd;

	if (FAILED(CDevice::Get_Instance()->Init_Device()))
	{
		AfxMessageBox(L"Device Create Failed");
		return;
	}

	if (FAILED(CTextureMgr::Get_Instance()->Insert_Texture(L"../Texture/Cube.png", TEX_SINGLE, L"Cube")))
	{
		AfxMessageBox(L"Cube img insert Failed");
		return;
	}

	m_pTerrain = new CTerrain;
	m_pTerrain->Initialize();
	m_pTerrain->Set_MainView(this);	
}

void CToolView::OnDraw(CDC* /*pDC*/)
{
	CToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CDevice::Get_Instance()->Render_Begin();

	m_pTerrain->Render();
	
	CDevice::Get_Instance()->Render_End();
}

void CToolView::OnDestroy()
{
	CScrollView::OnDestroy();

	Safe_Delete(m_pTerrain);

	CTextureMgr::Get_Instance()->Destroy_Instance();
	CDevice::Get_Instance()->Destroy_Instance();
}

void CToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CScrollView::OnLButtonDown(nFlags, point);
		

	m_pTerrain->Tile_Change(D3DXVECTOR3((float)point.x + GetScrollPos(0), (float)point.y + GetScrollPos(1), 0.f), 1);
	// 화면 갱신 없음

	// TRUE : WM_ERASEBKGND, WM_PAINT가 동시에 호출
	// FALSE : WM_PAINT만 호출

	Invalidate(FALSE);

	CMainFrame*	pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());

	CMiniView*	pMiniView = dynamic_cast<CMiniView*>(pMainFrm->m_SecondSplitter.GetPane(0, 0));
	pMiniView->Invalidate(FALSE);

}

#pragma region 생략

BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}


BOOL CToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CToolView 진단

#ifdef _DEBUG
void CToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView 메시지 처리기

#pragma endregion 생략










void CToolView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CScrollView::OnMouseMove(nFlags, point);


	if (GetAsyncKeyState(VK_LBUTTON))
	{
		m_pTerrain->Tile_Change(D3DXVECTOR3((float)point.x + GetScrollPos(0), 
											(float)point.y + GetScrollPos(1), 0.f), 1);
		Invalidate(FALSE);

		CMainFrame*	pMainFrm = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
		CMiniView*	pMiniView = dynamic_cast<CMiniView*>(pMainFrm->m_SecondSplitter.GetPane(0, 0));
		pMiniView->Invalidate(FALSE);
	}

}
