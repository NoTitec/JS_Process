// UnitTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Tool.h"
#include "UnitTool.h"
#include "afxdialogex.h"


// CUnitTool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUnitTool, CDialog)

CUnitTool::CUnitTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UNITTOOL, pParent)
	, m_strTest(_T(""))
	, m_strCopy(_T(""))
	, m_strName(_T(""))
	, m_iAttack(0)
	, m_iHp(0)
	, m_strFindName(_T(""))
{

}

CUnitTool::~CUnitTool()
{
}

void CUnitTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strTest);
	DDX_Text(pDX, IDC_EDIT2, m_strCopy);
	DDX_Text(pDX, IDC_EDIT3, m_strName);
	DDX_Text(pDX, IDC_EDIT4, m_iAttack);
	DDX_Text(pDX, IDC_EDIT5, m_iHp);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_RADIO1, m_Radio[0]);
	DDX_Control(pDX, IDC_RADIO2, m_Radio[1]);
	DDX_Control(pDX, IDC_RADIO3, m_Radio[2]);
	DDX_Control(pDX, IDC_CHECK1, m_Check[0]);
	DDX_Control(pDX, IDC_CHECK2, m_Check[1]);
	DDX_Control(pDX, IDC_CHECK3, m_Check[2]);
	DDX_Control(pDX, IDC_BUTTON3, m_Bitmap);
	DDX_Text(pDX, IDC_EDIT6, m_strFindName);
}


BEGIN_MESSAGE_MAP(CUnitTool, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUnitTool::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CUnitTool::OnListBox)
	ON_BN_CLICKED(IDC_BUTTON2, &CUnitTool::OnAdd)
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_EDIT6, &CUnitTool::OnSearchData)
	ON_BN_CLICKED(IDC_BUTTON6, &CUnitTool::OnDeleteData)
	ON_BN_CLICKED(IDC_BUTTON4, &CUnitTool::OnSaveData)
	ON_BN_CLICKED(IDC_BUTTON5, &CUnitTool::OnLoadData)
END_MESSAGE_MAP()


// CUnitTool 메시지 처리기입니다.


void CUnitTool::OnBnClickedButton1()
{
	// UpdateData : 정보 갱신함수

	UpdateData(TRUE);	// 다이얼로그 박스로부터 입력된 값들을 얻어옴

	m_strCopy = m_strTest;

	UpdateData(FALSE); // 다이얼로그 박스에 있는 값들을 반영
}


void CUnitTool::OnListBox()
{
	UpdateData(TRUE);

	CString		strFindName;

	// GetCurSel : 선택된 셀의 인덱스를 반환하는 함수
	int	iIndex = m_ListBox.GetCurSel();

	if (LB_ERR == iIndex)
		return;

	// GetText : 인덱스에 해당하는 문자열을 리스트 박스로부터 얻어오는 함수
	m_ListBox.GetText(iIndex, strFindName);

	auto	iter = m_mapUnitData.find(strFindName);

	if (iter == m_mapUnitData.end())
		return;

	m_strName = iter->second->strName;
	m_iHp = iter->second->iHp;
	m_iAttack = iter->second->iAttack;
	
	for (int i = 0; i < 3; ++i)
	{
		m_Radio[i].SetCheck(FALSE);
		m_Check[i].SetCheck(FALSE);
	}

	m_Radio[iter->second->byJobIndex].SetCheck(TRUE);

	if (iter->second->byItem & RUBY)
		m_Check[0].SetCheck(TRUE);

	if (iter->second->byItem & DIAMOND)
		m_Check[1].SetCheck(TRUE);

	if (iter->second->byItem & SAPPHIRE)
		m_Check[2].SetCheck(TRUE);

	
	UpdateData(FALSE);
}


void CUnitTool::OnAdd()
{
	UpdateData(TRUE);

	UNITDATA*	pUnit = new UNITDATA;

	pUnit->strName = m_strName;
	pUnit->iAttack = m_iAttack;
	pUnit->iHp = m_iHp;

	for (int i = 0; i < 3; ++i)
	{
		// 체크 되어 있는 버튼의 유무를 확인
		if (m_Radio[i].GetCheck())
		{
			pUnit->byJobIndex = i;
			break;
		}
	}

	pUnit->byItem = 0x00;

	if (m_Check[0].GetCheck())
		pUnit->byItem |= RUBY;

	if (m_Check[1].GetCheck())
		pUnit->byItem |= DIAMOND;

	if (m_Check[2].GetCheck())
		pUnit->byItem |= SAPPHIRE;


	// AddString : 리스트 박스에 매개 변수에 해당하는 문자열을 삽입
	m_ListBox.AddString(pUnit->strName);

	m_mapUnitData.insert({ pUnit->strName, pUnit });

	UpdateData(FALSE);
}


void CUnitTool::OnDestroy()
{
	CDialog::OnDestroy();

	for_each(m_mapUnitData.begin(), m_mapUnitData.end(), [](auto& MyPair)
	{
		if (MyPair.second)
		{
			delete MyPair.second;
			MyPair.second = nullptr;
		}
	});

	m_mapUnitData.clear();
}


BOOL CUnitTool::OnInitDialog()
{
	CDialog::OnInitDialog();

	HBITMAP	hBitmap = (HBITMAP)LoadImage(nullptr, L"../Texture/JusinLogo1.bmp", IMAGE_BITMAP, 100, 50, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	m_Bitmap.SetBitmap(hBitmap);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUnitTool::OnSearchData()
{
	UpdateData(TRUE);

	auto& iter = m_mapUnitData.find(m_strFindName);

	if (iter == m_mapUnitData.end())
		return;

	// FindString : 문자열과 일치하는 목록을 찾고 그 목록의 인덱스 값을 반환(0번 목록부터 탐색)
	int		iIndex = m_ListBox.FindString(0, m_strFindName);

	if (LB_ERR == iIndex)
		return;

	m_ListBox.SetCurSel(iIndex);

	m_strName = iter->second->strName;
	m_iHp = iter->second->iHp;
	m_iAttack = iter->second->iAttack;

	for (int i = 0; i < 3; ++i)
	{
		m_Radio[i].SetCheck(FALSE);
		m_Check[i].SetCheck(FALSE);
	}

	m_Radio[iter->second->byJobIndex].SetCheck(TRUE);

	if (iter->second->byItem & RUBY)
		m_Check[0].SetCheck(TRUE);

	if (iter->second->byItem & DIAMOND)
		m_Check[1].SetCheck(TRUE);

	if (iter->second->byItem & SAPPHIRE)
		m_Check[2].SetCheck(TRUE);



	UpdateData(FALSE);
}


void CUnitTool::OnDeleteData()
{
	UpdateData(TRUE);

	CString		strFindName = L"";

	int	iIndex = m_ListBox.GetCurSel();

	if (LB_ERR == iIndex)
		return;

	m_ListBox.GetText(iIndex, strFindName);

	auto& iter = m_mapUnitData.find(strFindName);

	if (iter == m_mapUnitData.end())
		return;

	Safe_Delete(iter->second);
	m_mapUnitData.erase(iter);

	//DeleteString : 목록 중 인덱스에 해당하는 문자열을 삭제
	m_ListBox.DeleteString(iIndex);

	UpdateData(FALSE);
}


void CUnitTool::OnSaveData()
{
	// CFileDialog : 파일 불러오기 또는 다른 이름으로 저장에 필요한 대화상자를 생성하는 객체

	CFileDialog		Dlg(FALSE, // TRUE(불러오기, 열기), FALSE(다른 이름을 저장) 모드지정
						L"dat", // default 파일 확장자명
						L"*.dat",  // 대화 상자에 표시될 최초의 파일명
						OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, // OFN_HIDEREADONLY(읽기 전용 체크 박스 숨김) | OFN_OVERWRITEPROMPT(중복 파일 저장 시, 경고 메세지 띄움)
						L"Data Files(*.dat)|*.dat||", // 대화 상자에 표시될 파일 형식 "콤보 박스에 출력될 무자열 | 실제 사용할 필터링 문자열 ||"
						this);


	TCHAR	szPath[MAX_PATH] = L"";

	// 현재 프로젝트의 디렉토리 경로를 얻어옴
	GetCurrentDirectory(MAX_PATH, szPath);

	// 전체 경로 중 파일 이름만 잘라주는 함수
	// 경로 상에 파일 이름이 없다면 마지막 폴더 이름을 잘라냄
	PathRemoveFileSpec(szPath);

	lstrcat(szPath, L"\\Data");

	Dlg.m_ofn.lpstrInitialDir = szPath;

	
	// DoModal : 대화 상자를 실행, IDOK 혹은 IDCANCEL 반환
	if (IDOK == Dlg.DoModal())
	{
		// GetPathName : 선택된 경로를 반환하는 함수
		CString		str = Dlg.GetPathName().GetString();
		const TCHAR*		pGetPath = str.GetString();

		HANDLE		hFile = CreateFile(pGetPath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

		if (INVALID_HANDLE_VALUE == hFile)
			return;

		DWORD	dwByte(0);
		DWORD	dwStrByte(0);

		for (auto& MyPair : m_mapUnitData)
		{
			// key 값 저장
			dwStrByte = sizeof(TCHAR) * (MyPair.first.GetLength() + 1);

			WriteFile(hFile, &dwStrByte, sizeof(DWORD), &dwByte, nullptr);
			WriteFile(hFile, MyPair.first.GetString(), dwStrByte, &dwByte, nullptr);

			// value 값 저장

			WriteFile(hFile, &(MyPair.second->byItem), sizeof(BYTE), &dwByte, nullptr);
			WriteFile(hFile, &(MyPair.second->byJobIndex), sizeof(BYTE), &dwByte, nullptr);
			WriteFile(hFile, &(MyPair.second->iAttack), sizeof(int), &dwByte, nullptr);
			WriteFile(hFile, &(MyPair.second->iHp), sizeof(int), &dwByte, nullptr);

		}

		CloseHandle(hFile);
	}	
}


void CUnitTool::OnLoadData()
{
	UpdateData(TRUE);

	CFileDialog		Dlg(TRUE, // TRUE(불러오기, 열기), FALSE(다른 이름을 저장) 모드지정
						L"dat", // default 파일 확장자명
						L"*.dat",  // 대화 상자에 표시될 최초의 파일명
						OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, // OFN_HIDEREADONLY(읽기 전용 체크 박스 숨김) | OFN_OVERWRITEPROMPT(중복 파일 저장 시, 경고 메세지 띄움)
						L"Data Files(*.dat)|*.dat||", // 대화 상자에 표시될 파일 형식 "콤보 박스에 출력될 무자열 | 실제 사용할 필터링 문자열 ||"
						this);


	TCHAR	szPath[MAX_PATH] = L"";

	GetCurrentDirectory(MAX_PATH, szPath);

	PathRemoveFileSpec(szPath);

	lstrcat(szPath, L"\\Data");

	Dlg.m_ofn.lpstrInitialDir = szPath;
	
	if (IDOK == Dlg.DoModal())
	{
		for (auto& MyPair : m_mapUnitData)
			delete MyPair.second;

		m_mapUnitData.clear();

		// 리스트 목록 초기화
		m_ListBox.ResetContent();

		CString		str = Dlg.GetPathName().GetString();
		const TCHAR*		pGetPath = str.GetString();

		HANDLE		hFile = CreateFile(pGetPath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

		if (INVALID_HANDLE_VALUE == hFile)
			return;

		DWORD	dwByte(0);
		DWORD	dwStrByte(0);
		UNITDATA		tData{};

		while (true)
		{
			// key 값
			ReadFile(hFile, &dwStrByte, sizeof(DWORD), &dwByte, nullptr);

			TCHAR*	pName = new TCHAR[dwStrByte];

			ReadFile(hFile, pName, dwStrByte, &dwByte, nullptr);

			// value 값

			ReadFile(hFile, &(tData.byItem), sizeof(BYTE), &dwByte, nullptr);
			ReadFile(hFile, &(tData.byJobIndex), sizeof(BYTE), &dwByte, nullptr);
			ReadFile(hFile, &(tData.iAttack), sizeof(int), &dwByte, nullptr);
			ReadFile(hFile, &(tData.iHp), sizeof(int), &dwByte, nullptr);

			if (0 == dwByte)
			{
				delete[]pName;
				break;
			}

			UNITDATA*		pUnit = new UNITDATA;
			pUnit->strName = pName;

			delete[]pName;
			pName = nullptr;

			pUnit->byItem = tData.byItem;
			pUnit->byJobIndex = tData.byJobIndex;
			pUnit->iAttack = tData.iAttack;
			pUnit->iHp = tData.iHp;

			m_mapUnitData.insert({ pUnit->strName, pUnit });
			m_ListBox.AddString(pUnit->strName);
		}

		CloseHandle(hFile);
	}

	UpdateData(FALSE);
}
