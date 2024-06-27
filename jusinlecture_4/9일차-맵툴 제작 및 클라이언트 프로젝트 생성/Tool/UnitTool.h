#pragma once

#include "afxwin.h"
#include "Include.h"

class CUnitTool : public CDialog
{
	DECLARE_DYNAMIC(CUnitTool)

public:
	CUnitTool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CUnitTool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UNITTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnListBox();
	afx_msg void OnAdd();
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnSearchData();
	afx_msg void OnDeleteData();
	afx_msg void OnSaveData();
	afx_msg void OnLoadData();
public:
	CString m_strTest;
	CString m_strCopy;
	//-------- value ----------//
	CString m_strName;
	int m_iAttack;
	int m_iHp;

	// control
	CListBox m_ListBox;
	CButton m_Radio[3];
	CButton m_Check[3];
	CButton m_Bitmap;

	// general
	map<CString, UNITDATA*>		m_mapUnitData;
	CString m_strFindName;

};

// 탐색(검색) 에디트 컨트롤을 이용하여 만들기
// - 내가 입력한 문자열과 일치하는 리스트 박스의 목록 셀이 선택되어짐

// 삭제 버튼을 이용하여 만들기
// - 내가 마우스로 클릭한 리스트 박스 셀을 삭제

// 저장하기 기능, 불러오기 기능 버튼을 이용하여 만들기