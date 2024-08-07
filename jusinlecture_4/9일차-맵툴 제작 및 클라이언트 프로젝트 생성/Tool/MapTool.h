#pragma once
#include "afxwin.h"

#include "Include.h"


class CMapTool : public CDialog
{
	DECLARE_DYNAMIC(CMapTool)

public:
	CMapTool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMapTool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnListBox();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnDestroy();

public:
	void		Horizontal_Scroll();

public:
	CListBox m_ListBox;
	CStatic m_Picture;
	int		m_iDrawId;

	map<CString, CImage*>		m_mapPngImg;

};
