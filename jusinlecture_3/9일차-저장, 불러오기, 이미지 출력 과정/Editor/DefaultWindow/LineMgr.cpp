#include "stdafx.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"

CLineMgr*	CLineMgr::m_pInstance = nullptr;
CLineMgr::CLineMgr()
{
	ZeroMemory(m_tLinePoint, sizeof(m_tLinePoint));
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	
}

int CLineMgr::Update()
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	//공중발판 선만들기 위해 우클릭시 m_tLinePoint 비우기
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RBUTTON))
	{
		ZeroMemory(m_tLinePoint, sizeof(tagLinePoint));
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		if ((!m_tLinePoint[LEFT].fX) && (!m_tLinePoint[LEFT].fY))
		{
			m_tLinePoint[LEFT].fX = (float)pt.x;
			m_tLinePoint[LEFT].fY = (float)pt.y;
		}

		else
		{
			m_tLinePoint[RIGHT].fX = (float)pt.x;
			m_tLinePoint[RIGHT].fY = (float)pt.y;

			m_LineList.push_back(new CLine(m_tLinePoint[LEFT], m_tLinePoint[RIGHT]));

			m_tLinePoint[LEFT].fX = m_tLinePoint[RIGHT].fX;
			m_tLinePoint[LEFT].fY = m_tLinePoint[RIGHT].fY;
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);

	if (CKeyMgr::Get_Instance()->Key_Down('S'))
	{
		Save_Line();
		return 0;
	}

	if (CKeyMgr::Get_Instance()->Key_Down('L'))
	{
		Load_Line();
		return 0;
	}

	
	return 0;
}

void CLineMgr::Late_Update()
{

}

void CLineMgr::Render(HDC hDC)
{
	for (auto& Line : m_LineList)
		Line->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

bool CLineMgr::Collision_Line(float fX, float* pY)
{
	if (m_LineList.empty())
		return false;

	CLine*		pTarget = nullptr;

	for (auto& pLine : m_LineList)
	{
		if (fX >= pLine->Get_Info().tLeft.fX &&
			fX <= pLine->Get_Info().tRight.fX)
		{
			pTarget = pLine;
		}
	}

	if (!pTarget)
		return false;

	float		x1 = pTarget->Get_Info().tLeft.fX;
	float		y1 = pTarget->Get_Info().tLeft.fY;
	float		x2 = pTarget->Get_Info().tRight.fX;
	float		y2 = pTarget->Get_Info().tRight.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;

	return true;
}

void CLineMgr::Save_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KSH_Line.dat",		// 파일 경로와 이름을 명시
									GENERIC_WRITE,			// 파일 접근 모드(GENERIC_WRITE : 쓰기 전용, GENERIC_READ : 읽기 전용)
									NULL,					// 공유 방식, 파일이 열려있는 상태에서 다른 프로세스가 오픈 할 때 허가하는 것에 대해서 설정(null 지정 시 공유하지 않음)
									NULL,					// 보안 속성, NULL인 기본 값 설정 유지
									CREATE_ALWAYS,			// 생성 방식( CREATE_ALWAYS : 파일이 없다면 생성, 있으면 덮어 쓰기, OPEN_EXISTING : 파일이 있을 경우에만 불러오기)
									FILE_ATTRIBUTE_NORMAL,	// 파일 속성( FILE_ATTRIBUTE_NORMAL : 아무런 속성이 없는 파일)
									NULL);					// 생성될 파일의 속성을 제공할 템플릿 파일(사용하지 않기 때문에 NULL)

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Save Failed", _T("error"), MB_OK);
		return;
	}

	DWORD	dwByte(0);

	for (auto& pLine : m_LineList)
	{
		WriteFile(hFile, &(pLine->Get_Info()), sizeof(LINE), &dwByte, nullptr);
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"save 완료", L"Success", MB_OKCANCEL);
}

void CLineMgr::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KSH_Line.dat",		// 파일 경로와 이름을 명시
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

	DWORD	dwByte(0);
	LINE	tLine{};

	while (true)
	{
		ReadFile(hFile, &tLine, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		m_LineList.push_back(new CLine(tLine.tLeft, tLine.tRight));
	}
	
	CloseHandle(hFile);
	MessageBox(g_hWnd, L"load 완료", L"Success", MB_OKCANCEL);

}
