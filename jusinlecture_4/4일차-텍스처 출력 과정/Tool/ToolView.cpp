
// ToolView.cpp : CToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CToolView ����/�Ҹ�

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

	CDevice::Get_Instance()->Get_Sprite()->Draw(m_pSingle->Get_Texture()->pTexture,  // �ؽ�ó �İ�ü
		nullptr, // ����� �̹����� RECT ������ �ּҰ�(null�ΰ�� 0, 0���� ����ϰڴٴ� �ǹ�)
		&D3DXVECTOR3(fCenterX,fCenterY, 0.f), // ����� �̹����� �߽� ��ġ�� ���� vec3 �ּҰ�(null�ΰ�� 0,0�� �ؽ�ó�� �߽� ��ġ)
		nullptr, // ����� ��ġ vec3 �ּҰ�(null�� ��� ��ũ�� �� 0,0 ��ǥ�� ���)
		D3DCOLOR_ARGB(255, 255, 255, 255));	// ����� ���� �̹����� ���� ���� ��, 0xffffffff�� �Ѱ��ָ� ���� ���� ����
	
	CDevice::Get_Instance()->Render_End();
}

void CToolView::OnDestroy()
{
	CView::OnDestroy();

	Safe_Delete(m_pSingle);

	CDevice::Get_Instance()->Destroy_Instance();
}


#pragma region ����

BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}


BOOL CToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CToolView ����

#ifdef _DEBUG
void CToolView::AssertValid() const
{
	CView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView �޽��� ó����

#pragma endregion ����






