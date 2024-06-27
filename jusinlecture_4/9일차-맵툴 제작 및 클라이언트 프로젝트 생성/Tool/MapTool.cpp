// MapTool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "MapTool.h"
#include "afxdialogex.h"
#include "FileInfo.h"


// CMapTool ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMapTool, CDialog)

CMapTool::CMapTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MAPTOOL, pParent), m_iDrawId(0)
{

}

CMapTool::~CMapTool()
{
}

void CMapTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CMapTool, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMapTool::OnListBox)
	ON_WM_DROPFILES()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMapTool �޽��� ó�����Դϴ�.


void CMapTool::OnListBox()
{
	UpdateData(TRUE);

	CString		strSelectName;

	int iIndex = m_ListBox.GetCurSel(); 
	
	if (LB_ERR == iIndex)
		return;

	m_ListBox.GetText(iIndex, strSelectName);
	
	auto iter = m_mapPngImg.find(strSelectName);

	if (iter == m_mapPngImg.end())
		return;

	m_Picture.SetBitmap(*(iter->second));

	int i(0);

	for (; i < strSelectName.GetLength(); ++i)
	{
			// isdigit : �Ű� ������ ���޹޾� ���ڰ� ���� Ÿ�� �������� ���� Ÿ�� �������� �Ǻ�
			// ���� Ÿ�� ���ڶ� �Ǹ�Ǹ� 0�� �ƴ� ���� ����

		if (0 != isdigit(strSelectName[i]))
			break;
	}
	// Delete(index, count) : �ε��� ��ġ�κ��� ī��Ʈ��ŭ ���ڸ� ����
	strSelectName.Delete(0, i);

	// _tstoi : ���ڿ��� ���������� ��ȯ�ϴ� �Լ�
	m_iDrawId = _tstoi(strSelectName);

	UpdateData(FALSE);
}


void CMapTool::OnDropFiles(HDROP hDropInfo)
{
	UpdateData(TRUE);

	CDialog::OnDropFiles(hDropInfo);

	TCHAR		szFilePath[MAX_PATH] = L"";
	TCHAR		szFileName[MAX_STR] = L"";

	// DragQueryFile : ��ӵ� ������ ������ ����
	// �� ��° �Ű� ������ 0xffffffff(-1)�� �����ϸ� ��ӵ� ������ ������ ��ȯ

	int	iFileCnt = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);

	for (int i = 0; i < iFileCnt; ++i)
	{
		DragQueryFile(hDropInfo, i, szFilePath, MAX_PATH);

		CString strRelative = CFileInfo::ConvertRelativePath(szFilePath);
		
		CString	strFileName = PathFindFileName(strRelative);

		lstrcpy(szFileName, strFileName.GetString());

		// Ȯ���� �� ����
		PathRemoveExtension(szFileName);

		strFileName = szFileName;

		auto iter = m_mapPngImg.find(strFileName);

		if(iter == m_mapPngImg.end())
		{
			CImage*		pPngImage = new CImage;
			pPngImage->Load(strRelative);

			m_mapPngImg.insert({ strFileName, pPngImage });
			m_ListBox.AddString(szFileName);
		}	
		
	}

	Horizontal_Scroll();
	
	UpdateData(FALSE);
}


void CMapTool::OnDestroy()
{
	for_each(m_mapPngImg.begin(), m_mapPngImg.end(), [](auto& MyPair)
	{
		MyPair.second->Destroy();
		Safe_Delete(MyPair.second);
	});

	m_mapPngImg.clear();


	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CMapTool::Horizontal_Scroll()
{
	CString		strName;
	CSize		Scrollsize;

	int			iWidth(0);

	CDC*	pDC = m_ListBox.GetDC();

	// GetCount : ����Ʈ �ڽ� ����� ���� ��ȯ
	for (int i = 0; i < m_ListBox.GetCount(); ++i)
	{
		m_ListBox.GetText(i, strName);

		// GetTextExtent : ���� ���ڿ��� ���̸� �ȼ� ������ ��ȯ
		Scrollsize = pDC->GetTextExtent(strName);

		if (Scrollsize.cx > iWidth)
			iWidth = Scrollsize.cx;
	}

	m_ListBox.ReleaseDC(pDC);

	// GetHorizontalExtent : ����Ʈ �ڽ��� ���η� ��ũ�� �� �� �ִ� �ִ� ������ ������ �Լ�
	if (iWidth > m_ListBox.GetHorizontalExtent())
		m_ListBox.SetHorizontalExtent(iWidth);

}
