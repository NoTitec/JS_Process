
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND g_hWnd;

// CToolView

IMPLEMENT_DYNCREATE(CToolView, CView)

BEGIN_MESSAGE_MAP(CToolView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CToolView 생성/소멸

CToolView::CToolView()
	: m_pSingle(nullptr)
{

}

CToolView::~CToolView()
{
}
void CToolView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	g_hWnd = m_hWnd;

	if (FAILED(CDevice::Get_Instance()->Init_Device()))
	{
		AfxMessageBox(L"Device Create Failed");
		return;
	}

	m_pSingle = new CSingleTexture;
	m_pSingle->Insert_Texture(L"../Texture/Cube.png");
}

void CToolView::OnDraw(CDC* /*pDC*/)
{
	CToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	D3DXMATRIX	matWorld, matScale, matRotZ, matTrans;

	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f);

	matWorld =  matScale * matTrans;

	float	fCenterX = m_pSingle->Get_Texture()->tImgInfo.Width / 2.f;
	float	fCenterY = m_pSingle->Get_Texture()->tImgInfo.Height / 2.f;

	CDevice::Get_Instance()->Render_Begin();

	CDevice::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);

	CDevice::Get_Instance()->Get_Sprite()->Draw(m_pSingle->Get_Texture()->pTexture,  // 텍스처 컴객체
		nullptr, // 출력할 이미지의 RECT 영역에 주소값(null인경우 0, 0부터 출력하겠다는 의미)
		&D3DXVECTOR3(fCenterX,fCenterY, 0.f), // 출력할 이미지의 중심 위치에 대한 vec3 주소값(null인경우 0,0이 텍스처의 중심 위치)
		nullptr, // 출력할 위치 vec3 주소값(null인 경우 스크린 상 0,0 좌표에 출력)
		D3DCOLOR_ARGB(255, 255, 255, 255));	// 출력할 원본 이미지와 섞을 색상 값, 0xffffffff를 넘겨주면 원본 색상 유지
	
	CDevice::Get_Instance()->Render_End();
}

void CToolView::OnDestroy()
{
	CView::OnDestroy();

	Safe_Delete(m_pSingle);

	CDevice::Get_Instance()->Destroy_Instance();
}


#pragma region 생략

BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
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
	CView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView 메시지 처리기

#pragma endregion 생략






