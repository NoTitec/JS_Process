#pragma once

#include "afxwin.h"
#include "Include.h"

class CUnitTool : public CDialog
{
	DECLARE_DYNAMIC(CUnitTool)

public:
	CUnitTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUnitTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UNITTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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

// Ž��(�˻�) ����Ʈ ��Ʈ���� �̿��Ͽ� �����
// - ���� �Է��� ���ڿ��� ��ġ�ϴ� ����Ʈ �ڽ��� ��� ���� ���õǾ���

// ���� ��ư�� �̿��Ͽ� �����
// - ���� ���콺�� Ŭ���� ����Ʈ �ڽ� ���� ����

// �����ϱ� ���, �ҷ����� ��� ��ư�� �̿��Ͽ� �����