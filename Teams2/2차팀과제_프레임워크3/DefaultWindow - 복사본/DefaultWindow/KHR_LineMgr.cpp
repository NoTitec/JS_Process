#include "stdafx.h"
#include "KHR_LineMgr.h"

CKHR_LineMgr* CKHR_LineMgr::m_pInstance = nullptr;

CKHR_LineMgr::CKHR_LineMgr()
{
}

CKHR_LineMgr::~CKHR_LineMgr()
{
    Release();
}

void CKHR_LineMgr::Initialize()
{
	Load_Line();
}

void CKHR_LineMgr::Render(HDC hDC)
{
	for (auto& Line : m_LineList)
	{
		Line->Render(hDC);
	}
}

void CKHR_LineMgr::Release()
{
    for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CKHR_Line*>);
    m_LineList.clear();
}

bool CKHR_LineMgr::Collision_Line(float _fX, float _fY, float* _pY)
{
	if (m_LineList.empty())
		return false;

	CKHR_Line*		 pTarget = nullptr;
	list<CKHR_Line*> pTargetList;

	float fDistance = (numeric_limits<float>::max)();	// 플레이어와 발판과의 거리

	for (auto& Line : m_LineList) {
		if (Line->Get_Info().tLeft.fX <= _fX && Line->Get_Info().tRight.fX >= _fX) {
			pTargetList.push_back(Line);
			float fPlatformY = Line->Get_Y(_fX);
			
			if ((_fY <= fPlatformY)) {						// 플레이어가 x값 범위에 든 line들 중 player.y보다 line.y(player.x 좌표 기준)가 작은 line들 선별
				if (fDistance >= abs(_fY - fPlatformY)) {	// 그중 플레이어와의 거리가 가장 짧은 line을 선별
					fDistance = abs(_fY - fPlatformY);
					pTarget = Line;
				}
			}
		}
	}

	// 경사 선 타야 할 때( 45도 각도 이하만 가능..)
	for (auto& Line : pTargetList) {
		if (_fY - 10.f <= Line->Get_Y(_fX)) {
			pTarget = Line;
		}
	}

	if(!pTarget)
		return false;

	*_pY = pTarget->Get_Y(_fX);

	return true;
}

void CKHR_LineMgr::Save_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KHR_Line.dat",		// 파일 경로와 이름을 명시
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

void CKHR_LineMgr::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KHR_Line.dat",		// 파일 경로와 이름을 명시
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

		m_LineList.push_back(new CKHR_Line(tLine.tLeft, tLine.tRight));
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"load 완료", L"Success", MB_OKCANCEL);

}