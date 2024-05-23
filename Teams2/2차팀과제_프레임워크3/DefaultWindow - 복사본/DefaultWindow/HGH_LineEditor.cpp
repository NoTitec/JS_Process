#include "stdafx.h"
#include "HGH_LineEditor.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "PushUpLineColliderComponent.h"
#include "RenderMgr.h"
#include <string>;
HGH_LineEditor::HGH_LineEditor()
{
}
HGH_LineEditor::~HGH_LineEditor()
{
	Release();
}
void HGH_LineEditor::Update()
{
	POINT pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (KEY.Key_Down('Q'))
	{
		m_eLineType = LineType::Push_Up_Line();
	}

	if (KEY.Key_Down(VK_LBUTTON))
	{
		cout << "VK_LBUTTON DOWN | idx: "<<idx << endl;
		cout << m_tPoint[0].x << "," << m_tPoint[0].y << " | " << m_tPoint[1].x << "," << m_tPoint[1].y << endl;
		m_tPoint[idx] = { (float)pt.x, (float)pt.y };

		if (idx == 1)
		{
			LineInfo info{ E2I(m_eLineType), m_tPoint[0].x,m_tPoint[0].y,m_tPoint[1].x,m_tPoint[1].y };
			m_tInfoList.push_back(info);
			Add_Line(info);
			m_tPoint[0] = m_tPoint[1];
		}
		
		idx = 1;
	}
	if (KEY.Key_Down(VK_RBUTTON))
	{
		cout << "VK_RBUTTON DOWN" << endl;
		idx = 0;
	}

	if (KEY.Key_Down('L'))
	{
		Load_Line();
	}
	if (KEY.Key_Down('S'))
	{
		Store_Line();
	}
}

void HGH_LineEditor::Render()
{
	RENDER.DrawTxt(0, 0, to_wstring(E2I(m_eLineType)));
}

void HGH_LineEditor::Store_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/HGH_Line.dat",		// ���� ��ο� �̸��� ���
		GENERIC_WRITE,			// ���� ���� ���(GENERIC_WRITE : ���� ����, GENERIC_READ : �б� ����)
		NULL,					// ���� ���, ������ �����ִ� ���¿��� �ٸ� ���μ����� ���� �� �� �㰡�ϴ� �Ϳ� ���ؼ� ����(null ���� �� �������� ����)
		NULL,					// ���� �Ӽ�, NULL�� �⺻ �� ���� ����
		CREATE_ALWAYS,			// ���� ���( CREATE_ALWAYS : ������ ���ٸ� ����, ������ ���� ����, OPEN_EXISTING : ������ ���� ��쿡�� �ҷ�����)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�( FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ��� ���� ����)
		NULL);					// ������ ������ �Ӽ��� ������ ���ø� ����(������� �ʱ� ������ NULL)

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Load Failed", _T("error"), MB_OK);
		return;
	}

	DWORD		dwByte{};

	for (auto info : m_tInfoList)
	{
		WriteFile(hFile, &info, sizeof(info), &dwByte, NULL);
		Add_Line(info);
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Store �Ϸ�", L"Success", MB_OKCANCEL);
}

void HGH_LineEditor::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/HGH_Line.dat",		// ���� ��ο� �̸��� ���
		GENERIC_READ,			// ���� ���� ���(GENERIC_WRITE : ���� ����, GENERIC_READ : �б� ����)
		NULL,					// ���� ���, ������ �����ִ� ���¿��� �ٸ� ���μ����� ���� �� �� �㰡�ϴ� �Ϳ� ���ؼ� ����(null ���� �� �������� ����)
		NULL,					// ���� �Ӽ�, NULL�� �⺻ �� ���� ����
		OPEN_EXISTING,			// ���� ���( CREATE_ALWAYS : ������ ���ٸ� ����, ������ ���� ����, OPEN_EXISTING : ������ ���� ��쿡�� �ҷ�����)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�( FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ��� ���� ����)
		NULL);					// ������ ������ �Ӽ��� ������ ���ø� ����(������� �ʱ� ������ NULL)

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Load Failed", _T("error"), MB_OK);
		return;
	}

	DWORD		dwByte(0);
	LineInfo	tLineInfo{};

	while (true)
	{
		ReadFile(hFile, &tLineInfo, sizeof(tLineInfo), &dwByte, NULL);

		if (0 == dwByte)
			break;

		Add_Line(tLineInfo);
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"load �Ϸ�", L"Success", MB_OKCANCEL);
}


void HGH_LineEditor::Release()
{
}

void HGH_LineEditor::Add_Line(LineInfo _tLineInfo)
{
	CObject* pLine{ new CObject(ObjectType::Line) };
	CLineColliderComponent* pLineCollider{};
	switch (_tLineInfo.lineType)
	{
	case E2I(LineType::Push_Up_Line):
		pLineCollider = new CPushUpLineColliderComponent(ComponentType::PushUpLineCollider);
		pLineCollider->Set_Line({ _tLineInfo.line });
		break;
	}
	pLineCollider->Set_Owner(pLine);
	pLineCollider->Init();
	pLine->Push_Back_Component(pLineCollider);
	OBJ.Add_Object(OBJ_LINE, pLine);
}