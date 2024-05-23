#include "stdafx.h"
#include "KJW_LineMgr.h"
#include "RenderMgr.h"


CKJW_LineMgr::CKJW_LineMgr()
{
}

CKJW_LineMgr::~CKJW_LineMgr()
{
	Release();
}

void CKJW_LineMgr::Initialize()
{

	KJW_LINE.Load_Line();
}

void CKJW_LineMgr::Render(HDC hDC)
{
	HPEN NewPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN OldPen = (HPEN)SelectObject(hDC, NewPen);
	for (auto& line : m_LineList)
	{
		line->Render(hDC);
	}
	DeleteObject(NewPen);
}

void CKJW_LineMgr::Release()
{
	for (auto& line : m_LineList)
	{
		Safe_Delete(line);
	}
}

CLine* CKJW_LineMgr::Get_Current_Line(Point2F _tPoint, float& _fYSol)
{
	CLine* result = nullptr;
	_fYSol = WINCY;
	//278
	for (auto& line : m_LineList)
	{
		if (_tPoint.x < line->Get_Info().tLeft.fX || line->Get_Info().tRight.fX < _tPoint.x)
			continue;
		float fy = Get_Line_Y_Solution(line, _tPoint.x);
		if (fy < _tPoint.y)
			continue;
		if ( fy < _fYSol)
		{
			_fYSol = fy;
			result = line;
		}
	}
	return result;
}

//Point보다 낮은 라인 중 가장 높은 지점
float CKJW_LineMgr::Get_Floor_Y(Point2F _tPoint)
{
	float result = WINCY;
	for (auto& line : m_LineList)
	{
		if (_tPoint.x < line->Get_Info().tLeft.fX || line->Get_Info().tRight.fX < _tPoint.x)
			continue;
		float fy = Get_Line_Y_Solution(line, _tPoint.x);
		if (fy < _tPoint.y)
			continue;
		result = min(result, fy);
	}
	return result;
}

float CKJW_LineMgr::Get_Line_Y_Solution(CLine* _pLine, float fX)
{
	float fH = _pLine->Get_Info().tRight.fY - _pLine->Get_Info().tLeft.fY;
	float fW = _pLine->Get_Info().tRight.fX - _pLine->Get_Info().tLeft.fX;

	float result = fH/fW*(fX - _pLine->Get_Info().tLeft.fX) +_pLine->Get_Info().tLeft.fY;
	return result;
}

float CKJW_LineMgr::Get_Wall_X(Point2F _tPoint, bool _bRight)
{
	float result = _bRight ? 99999 : 0;
	for (auto& line : m_LineList)
	{
		float fLY = line->Get_Info().tLeft.fY;
		float fRY = line->Get_Info().tRight.fY;
		float fTY = min(fLY,fRY);
		float fBY = max(fLY, fRY);
		if (fBY < _tPoint.y || fTY > _tPoint.y)
			continue;
		float fx = Get_Line_X_Solution(line, _tPoint.y);
		if (_bRight )
		{
			if (fx < _tPoint.x)
				continue;
			result = min(fx, result);
		}
		else
		{
			if (fx > _tPoint.x)
				continue;
			result = max(fx, result);
		}


	}
	return result;
}

float CKJW_LineMgr::Get_Line_X_Solution(CLine* _pLine, float fY)
{
	float fH = _pLine->Get_Info().tRight.fY - _pLine->Get_Info().tLeft.fY;
	float fW = _pLine->Get_Info().tRight.fX - _pLine->Get_Info().tLeft.fX;
	float fA = fH / fW;
	float fB = _pLine->Get_Info().tLeft.fY;
	return (fY- fB)/fA + _pLine->Get_Info().tLeft.fX;
}

void CKJW_LineMgr::Save_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KJW_Line.dat",		// 파일 경로와 이름을 명시
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



void CKJW_LineMgr::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KJW_Line.dat",		// 파일 경로와 이름을 명시
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