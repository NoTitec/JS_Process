#include "stdafx.h"
#include "TileMgr.h"
#include "AbstractFactory.h"
#include "ScrollMgr.h"

CTileMgr* CTileMgr::m_pInstance = nullptr;

CTileMgr::CTileMgr()
{
	m_vecTile.reserve(TILEX * TILEY);
}

CTileMgr::~CTileMgr()
{
	Release();
}

void CTileMgr::Initialize()
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			float	fX = float((TILECX >> 1) + (TILECX * j));
			float	fY = float((TILECY >> 1) + (TILECY * i));

			CObj*	pTile = CAbstractFactory<CTile>::Create(fX, fY);
			m_vecTile.push_back(pTile);
		}
	}

}

void CTileMgr::Update()
{
	for (auto& pTile : m_vecTile)
		pTile->Update();
}

void CTileMgr::Late_Update()
{
	for (auto& pTile : m_vecTile)
		pTile->Late_Update();
}

void CTileMgr::Render(HDC hDC)
{
	// for (auto& pTile : m_vecTile)
	// 	pTile->Render(hDC);

	int iCullX = abs(int(CScrollMgr::Get_Instance()->Get_ScrollX() / TILECX));
	int iCullY = abs(int(CScrollMgr::Get_Instance()->Get_ScrollY() / TILECY));

	int	iMaxX = iCullX + (WINCX / TILECX) + 2;
	int	iMaxY = iCullY + (WINCY / TILECY) + 2;

	for (int i = iCullY; i < iMaxY; ++i)
	{
		for (int j = iCullX; j < iMaxX; ++j)
		{
			int	iIndex = i * TILEX + j;

			if(0 > iIndex || (size_t)iIndex >= m_vecTile.size())
				continue;

			m_vecTile[iIndex]->Render(hDC);
		}
	}
}

void CTileMgr::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), DeleteObj());
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

void CTileMgr::Picking_Tile(POINT pt, int _iDrawID, int _iOption)
{
	int	x = pt.x / TILECX;
	int	y = pt.y / TILECY;

	int		iIndex = y * TILEX + x;

	if (0 > iIndex || (size_t)iIndex >= m_vecTile.size())
		return;

	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(_iDrawID);
	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_Option(_iOption);
}

void CTileMgr::Save_Tile()
{
	HANDLE		hFile = CreateFile(L"../Data/Tile.dat",		// ���� ��ο� �̸��� ���
		GENERIC_WRITE,			// ���� ���� ���(GENERIC_WRITE : ���� ����, GENERIC_READ : �б� ����)
		NULL,					// ���� ���, ������ �����ִ� ���¿��� �ٸ� ���μ����� ���� �� �� �㰡�ϴ� �Ϳ� ���ؼ� ����(null ���� �� �������� ����)
		NULL,					// ���� �Ӽ�, NULL�� �⺻ �� ���� ����
		CREATE_ALWAYS,			// ���� ���( CREATE_ALWAYS : ������ ���ٸ� ����, ������ ���� ����, OPEN_EXISTING : ������ ���� ��쿡�� �ҷ�����)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�( FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ��� ���� ����)
		NULL);					// ������ ������ �Ӽ��� ������ ���ø� ����(������� �ʱ� ������ NULL)

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"save Failed", _T("error"), MB_OK);
		return;
	}

	DWORD	dwByte(0);
	int	iDrawID(0), iOption(0);

	for (auto& pTile : m_vecTile)
	{
		iDrawID = dynamic_cast<CTile*>(pTile)->Get_DrawID();
		iOption = dynamic_cast<CTile*>(pTile)->Get_Option();

		WriteFile(hFile, &(pTile->Get_Info()), sizeof(INFO), &dwByte, nullptr);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, nullptr);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, nullptr);
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Tile Save �Ϸ�", L"Success", MB_OKCANCEL);
}

void CTileMgr::Load_Tile()
{
	HANDLE		hFile = CreateFile(L"../Data/Tile.dat",		// ���� ��ο� �̸��� ���
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
	int	iDrawID(0), iOption(0);
	INFO tInfo{};

	Release();

	while(true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);
		ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, nullptr);
		ReadFile(hFile, &iOption, sizeof(int), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		CObj*	pTile = CAbstractFactory<CTile>::Create(tInfo.fX, tInfo.fY);

		dynamic_cast<CTile*>(pTile)->Set_DrawID(iDrawID);
		dynamic_cast<CTile*>(pTile)->Set_Option(iOption);

		m_vecTile.push_back(pTile);
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Tile Load �Ϸ�", L"Success", MB_OK);
}
