#include "stdafx.h"
#include "PHJ_LineMgr.h"
#include "RenderMgr.h"
#include "ScrollMgr.h"

CPHJLineMgr* CPHJLineMgr::m_pInstance = nullptr;

inline static bool mycompare(CLine* A, CLine* B) // 라인 정렬용 함수 포인터
{
	float Ay = (A->Get_Info().tLeft.fY + A->Get_Info().tRight.fY) * 0.5f;
	float By = (B->Get_Info().tLeft.fY + B->Get_Info().tRight.fY) * 0.5f;
	return Ay < By;
}

CPHJLineMgr::CPHJLineMgr()
{
}

CPHJLineMgr::~CPHJLineMgr()
{
	Release();
}

void CPHJLineMgr::Initialize()
{
	Load_Line();
	m_LineList.sort(mycompare);
}

void CPHJLineMgr::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/PHJLine.dat",		// 파일 경로와 이름을 명시
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
		ReadFile(hFile, &tLine, sizeof(LINE), &dwByte, nullptr); // LINE 단위로 끊어서 읽어오기

		if (0 == dwByte) // 다 읽었으면 종료
			break;

		m_LineList.push_back(new CLine(tLine.tLeft, tLine.tRight)); // 읽어론 LINE 추가
	}

	CloseHandle(hFile);
}

void CPHJLineMgr::Render(HDC hDC)
{
	for (auto& Line : m_LineList)
	{
		LINE Tmp = Line->Get_Info();
		int iScrollX = (int)SCROLL.Get_ScrollX();
		Tmp.tLeft.fX += iScrollX;
		Tmp.tRight.fX += iScrollX;
		RENDER.DrawLine(Tmp);
	}
}

void CPHJLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}


bool CPHJLineMgr::Collision_Line(float fX, float fY, float* pY)
{
	if (m_LineList.empty())
		return false;

	CLine*		pTarget = nullptr;

	float		x1, y1, x2, y2, LineY;
	for (auto& pLine : m_LineList)
	{
		if (fX >= pLine->Get_Info().tLeft.fX &&
			fX <= pLine->Get_Info().tRight.fX)
		{
			x1 = pLine->Get_Info().tLeft.fX;
			y1 = pLine->Get_Info().tLeft.fY;
			x2 = pLine->Get_Info().tRight.fX;
			y2 = pLine->Get_Info().tRight.fY;
			LineY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;
			if(LineY >= fY - 10.f) // 경사 이동용 보정치
			{
				pTarget = pLine;
				break;
			}
		}
	}

	if (!pTarget)
		return false;

	x1 = pTarget->Get_Info().tLeft.fX;
	y1 = pTarget->Get_Info().tLeft.fY;
	x2 = pTarget->Get_Info().tRight.fX;
	y2 = pTarget->Get_Info().tRight.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;

	return true;
}
