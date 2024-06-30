// MapTool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Tool.h"
#include "MapTool.h"
#include "afxdialogex.h"
#include "FileInfo.h"
#include "MainFrm.h"
#include "ToolView.h"


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
	ON_BN_CLICKED(IDC_BUTTON1, &CMapTool::OnSaveData)
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

void CMapTool::OnSaveData()
{
	CFileDialog		Dlg(FALSE, // TRUE(�ҷ�����, ����), FALSE(�ٸ� �̸��� ����) �������
		L"dat", // default ���� Ȯ���ڸ�
		L"*.dat",  // ��ȭ ���ڿ� ǥ�õ� ������ ���ϸ�
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, // OFN_HIDEREADONLY(�б� ���� üũ �ڽ� ����) | OFN_OVERWRITEPROMPT(�ߺ� ���� ���� ��, ��� �޼��� ���)
		L"Data Files(*.dat)|*.dat||", // ��ȭ ���ڿ� ǥ�õ� ���� ���� "�޺� �ڽ��� ��µ� ���ڿ� | ���� ����� ���͸� ���ڿ� ||"
		this);


	TCHAR	szPath[MAX_PATH] = L"";

	// ���� ������Ʈ�� ���丮 ��θ� ����
	GetCurrentDirectory(MAX_PATH, szPath);

	// ��ü ��� �� ���� �̸��� �߶��ִ� �Լ�
	// ��� �� ���� �̸��� ���ٸ� ������ ���� �̸��� �߶�
	PathRemoveFileSpec(szPath);

	lstrcat(szPath, L"\\Data");

	Dlg.m_ofn.lpstrInitialDir = szPath;


	// DoModal : ��ȭ ���ڸ� ����, IDOK Ȥ�� IDCANCEL ��ȯ
	if (IDOK == Dlg.DoModal())
	{
		// GetPathName : ���õ� ��θ� ��ȯ�ϴ� �Լ�
		CString		str = Dlg.GetPathName().GetString();
		const TCHAR*		pGetPath = str.GetString();

		HANDLE		hFile = CreateFile(pGetPath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

		if (INVALID_HANDLE_VALUE == hFile)
			return;

		CMainFrame*		pMainFrm  = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
		CToolView*		pMainView = dynamic_cast<CToolView*>(pMainFrm->m_MainSplitter.GetPane(0, 1));
		CTerrain*		pTerrain = pMainView->m_pTerrain;
		vector<TILE*>&	vecTile = pTerrain->Get_VecTile();

		if (vecTile.empty())
			return;

		DWORD	dwByte(0);

		for (auto& pTile : vecTile)
			WriteFile(hFile, pTile, sizeof(TILE), &dwByte, nullptr);	

		CloseHandle(hFile);
	}
}
