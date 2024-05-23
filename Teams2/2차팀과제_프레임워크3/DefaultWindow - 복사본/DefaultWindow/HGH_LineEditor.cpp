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
	HANDLE		hFile = CreateFile(L"../Data/HGH_Line.dat",		// 파일 경로와 이름을 명시
		GENERIC_WRITE,			// 파일 접근 모드(GENERIC_WRITE : 쓰기 전용, GENERIC_READ : 읽기 전용)
		NULL,					// 공유 방식, 파일이 열려있는 상태에서 다른 프로세스가 오픈 할 때 허가하는 것에 대해서 설정(null 지정 시 공유하지 않음)
		NULL,					// 보안 속성, NULL인 기본 값 설정 유지
		CREATE_ALWAYS,			// 생성 방식( CREATE_ALWAYS : 파일이 없다면 생성, 있으면 덮어 쓰기, OPEN_EXISTING : 파일이 있을 경우에만 불러오기)
		FILE_ATTRIBUTE_NORMAL,	// 파일 속성( FILE_ATTRIBUTE_NORMAL : 아무런 속성이 없는 파일)
		NULL);					// 생성될 파일의 속성을 제공할 템플릿 파일(사용하지 않기 때문에 NULL)

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
	MessageBox(g_hWnd, L"Store 완료", L"Success", MB_OKCANCEL);
}

void HGH_LineEditor::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/HGH_Line.dat",		// 파일 경로와 이름을 명시
		GENERIC_READ,			// 파일 접근 모드(GENERIC_WRITE : 쓰기 전용, GENERIC_READ : 읽기 전용)
		NULL,					// 공유 방식, 파일이 열려있는 상태에서 다른 프로세스가 오픈 할 때 허가하는 것에 대해서 설정(null 지정 시 공유하지 않음)
		NULL,					// 보안 속성, NULL인 기본 값 설정 유지
		OPEN_EXISTING,			// 생성 방식( CREATE_ALWAYS : 파일이 없다면 생성, 있으면 덮어 쓰기, OPEN_EXISTING : 파일이 있을 경우에만 불러오기)
		FILE_ATTRIBUTE_NORMAL,	// 파일 속성( FILE_ATTRIBUTE_NORMAL : 아무런 속성이 없는 파일)
		NULL);					// 생성될 파일의 속성을 제공할 템플릿 파일(사용하지 않기 때문에 NULL)

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
	MessageBox(g_hWnd, L"load 완료", L"Success", MB_OKCANCEL);
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