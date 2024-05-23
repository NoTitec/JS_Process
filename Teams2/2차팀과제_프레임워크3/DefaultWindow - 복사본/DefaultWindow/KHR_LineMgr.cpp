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

	float fDistance = (numeric_limits<float>::max)();	// �÷��̾�� ���ǰ��� �Ÿ�

	for (auto& Line : m_LineList) {
		if (Line->Get_Info().tLeft.fX <= _fX && Line->Get_Info().tRight.fX >= _fX) {
			pTargetList.push_back(Line);
			float fPlatformY = Line->Get_Y(_fX);
			
			if ((_fY <= fPlatformY)) {						// �÷��̾ x�� ������ �� line�� �� player.y���� line.y(player.x ��ǥ ����)�� ���� line�� ����
				if (fDistance >= abs(_fY - fPlatformY)) {	// ���� �÷��̾���� �Ÿ��� ���� ª�� line�� ����
					fDistance = abs(_fY - fPlatformY);
					pTarget = Line;
				}
			}
		}
	}

	// ��� �� Ÿ�� �� ��( 45�� ���� ���ϸ� ����..)
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
	HANDLE		hFile = CreateFile(L"../Data/KHR_Line.dat",		// ���� ��ο� �̸��� ���
		GENERIC_WRITE,			// ���� ���� ���(GENERIC_WRITE : ���� ����, GENERIC_READ : �б� ����)
		NULL,					// ���� ���, ������ �����ִ� ���¿��� �ٸ� ���μ����� ���� �� �� �㰡�ϴ� �Ϳ� ���ؼ� ����(null ���� �� �������� ����)
		NULL,					// ���� �Ӽ�, NULL�� �⺻ �� ���� ����
		CREATE_ALWAYS,			// ���� ���( CREATE_ALWAYS : ������ ���ٸ� ����, ������ ���� ����, OPEN_EXISTING : ������ ���� ��쿡�� �ҷ�����)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�( FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ��� ���� ����)
		NULL);					// ������ ������ �Ӽ��� ������ ���ø� ����(������� �ʱ� ������ NULL)

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
	MessageBox(g_hWnd, L"save �Ϸ�", L"Success", MB_OKCANCEL);
}

void CKHR_LineMgr::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KHR_Line.dat",		// ���� ��ο� �̸��� ���
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
	MessageBox(g_hWnd, L"load �Ϸ�", L"Success", MB_OKCANCEL);

}