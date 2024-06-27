// MapTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "MapTool.h"
#include "afxdialogex.h"
#include "FileInfo.h"


// CMapTool 대화 상자입니다.

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


// CMapTool 메시지 처리기입니다.


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
			// isdigit : 매개 변수로 전달받안 글자가 문자 타입 글자인지 숫자 타입 글자인지 판별
			// 숫자 타입 글자라 판명되면 0이 아닌 값을 리턴

		if (0 != isdigit(strSelectName[i]))
			break;
	}
	// Delete(index, count) : 인덱스 위치로부터 카운트만큼 문자를 삭제
	strSelectName.Delete(0, i);

	// _tstoi : 문자열을 정수형으로 변환하는 함수
	m_iDrawId = _tstoi(strSelectName);

	UpdateData(FALSE);
}


void CMapTool::OnDropFiles(HDROP hDropInfo)
{
	UpdateData(TRUE);

	CDialog::OnDropFiles(hDropInfo);

	TCHAR		szFilePath[MAX_PATH] = L"";
	TCHAR		szFileName[MAX_STR] = L"";

	// DragQueryFile : 드롭된 파일의 정보를 얻어옴
	// 두 번째 매개 변수가 0xffffffff(-1)로 지정하면 드롭된 파일의 개수를 반환

	int	iFileCnt = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);

	for (int i = 0; i < iFileCnt; ++i)
	{
		DragQueryFile(hDropInfo, i, szFilePath, MAX_PATH);

		CString strRelative = CFileInfo::ConvertRelativePath(szFilePath);
		
		CString	strFileName = PathFindFileName(strRelative);

		lstrcpy(szFileName, strFileName.GetString());

		// 확장자 명 제거
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

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CMapTool::Horizontal_Scroll()
{
	CString		strName;
	CSize		Scrollsize;

	int			iWidth(0);

	CDC*	pDC = m_ListBox.GetDC();

	// GetCount : 리스트 박스 목록의 개수 반환
	for (int i = 0; i < m_ListBox.GetCount(); ++i)
	{
		m_ListBox.GetText(i, strName);

		// GetTextExtent : 현재 문자열의 길이를 픽셀 단위로 변환
		Scrollsize = pDC->GetTextExtent(strName);

		if (Scrollsize.cx > iWidth)
			iWidth = Scrollsize.cx;
	}

	m_ListBox.ReleaseDC(pDC);

	// GetHorizontalExtent : 리스트 박스가 가로로 스크롤 할 수 있는 최대 범위를 얻어오는 함수
	if (iWidth > m_ListBox.GetHorizontalExtent())
		m_ListBox.SetHorizontalExtent(iWidth);

}
