#include "stdafx.h"
#include "PHJ_LineMgr.h"
#include "RenderMgr.h"
#include "ScrollMgr.h"

CPHJLineMgr* CPHJLineMgr::m_pInstance = nullptr;

inline static bool mycompare(CLine* A, CLine* B) // ���� ���Ŀ� �Լ� ������
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
	HANDLE		hFile = CreateFile(L"../Data/PHJLine.dat",		// ���� ��ο� �̸��� ���
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
		ReadFile(hFile, &tLine, sizeof(LINE), &dwByte, nullptr); // LINE ������ ��� �о����

		if (0 == dwByte) // �� �о����� ����
			break;

		m_LineList.push_back(new CLine(tLine.tLeft, tLine.tRight)); // �о�� LINE �߰�
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
			if(LineY >= fY - 10.f) // ��� �̵��� ����ġ
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
