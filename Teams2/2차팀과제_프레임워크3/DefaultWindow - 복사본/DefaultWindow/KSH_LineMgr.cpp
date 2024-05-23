#include "stdafx.h"
#include "KSH_LineMgr.h"
CKSH_LineMgr::CKSH_LineMgr()
{
}

CKSH_LineMgr::~CKSH_LineMgr()
{
	Release();
}

void CKSH_LineMgr::Initialize()
{
	Load_Line();
}

void CKSH_LineMgr::Render(HDC hDC)
{
	for (auto& Line : m_LineList)
		Line->Render(hDC);
}

void CKSH_LineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

bool CKSH_LineMgr::Collision_Line(float fX, float fY, float* pY)
{
	if (m_LineList.empty())
		return false;

	CLine* pTarget = nullptr;
	float f_closestY = FLT_MAX;
	for (auto& pLine : m_LineList)
	{
		//�÷��̾� x ��ǥ�� �� x��ǥ �����ΰ��
		if (fX >= pLine->Get_Info().tLeft.fX &&
			fX <= pLine->Get_Info().tRight.fX)
		{
			//�ڱ����� y ���� �� y�� �� �Ʒ��� �ִ¼��ΰ��
			float x1t = pLine->Get_Info().tLeft.fX;
			float y1t = pLine->Get_Info().tLeft.fY;
			float x2t = pLine->Get_Info().tRight.fX;
			float y2t = pLine->Get_Info().tRight.fY;
			float tmpfY = ((y2t - y1t) / (x2t - x1t)) * (fX - x1t) + y1t;
			//�÷��̾� x���� ���� y�� �÷��̾�y���� ũ�� �÷��̾� x���� ���� y�� �� �Ÿ����� �������
			//if (tmpfY >= fY&&tmpfY<=f_closestY)
			if (tmpfY >= fY - 10.f && tmpfY <= f_closestY)
			{
				pTarget = pLine;
				f_closestY = tmpfY;
			}

		}
	}
	if (!pTarget)
		return false;

	float x1 = pTarget->Get_Info().tLeft.fX;
	float y1 = pTarget->Get_Info().tLeft.fY;
	float x2 = pTarget->Get_Info().tRight.fX;
	float y2 = pTarget->Get_Info().tRight.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;
	return true;
}

void CKSH_LineMgr::Load_Line()
{
	HANDLE		hFile = CreateFile(L"../Data/KSH_Line.dat",		// ���� ��ο� �̸��� ���
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

		m_LineList.push_back(new CLine(tLine.tLeft, tLine.tRight));
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"ksh map data load �Ϸ�", L"Success", MB_OKCANCEL);
}