#pragma once
#include "afxwin.h"

#include "Include.h"


class CMapTool : public CDialog
{
	DECLARE_DYNAMIC(CMapTool)

public:
	CMapTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMapTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
