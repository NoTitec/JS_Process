#include "stdafx.h"
#include "Monster.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

CMonster::CMonster()
{
	ZeroMemory(m_tPoint, sizeof(m_tPoint));
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 300.f;
	m_tInfo.fCY = 300.f;

	m_fSpeed = 3.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Plg.bmp", L"Plg");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Reset.bmp", L"Reset");

	m_pFrameKey = L"Monster";
	m_eRender = RENDER_GAMEOBJECT;
}

int CMonster::Update()
{

	float	fDiagonal = sqrt((m_tInfo.fCX / 2.f)* (m_tInfo.fCX / 2.f) + (m_tInfo.fCY / 2.f)* (m_tInfo.fCY / 2.f));

	// �»��
	m_tPoint[0].x = long((m_tInfo.fCX / 2.f) + cos((m_fAngle + 135.f) * PI / 180.f) * fDiagonal);
	m_tPoint[0].y = long((m_tInfo.fCY / 2.f) - sin((m_fAngle + 135.f) * PI / 180.f) * fDiagonal);

	// ����
	m_tPoint[1].x = long((m_tInfo.fCX / 2.f) + cos((m_fAngle + 45.f) * PI / 180.f) * fDiagonal);
	m_tPoint[1].y = long((m_tInfo.fCY / 2.f) - sin((m_fAngle + 45.f) * PI / 180.f) * fDiagonal);

	// ���ϴ�
	m_tPoint[2].x = long((m_tInfo.fCX / 2.f) + cos((m_fAngle + 225.f) * PI / 180.f) * fDiagonal);
	m_tPoint[2].y = long((m_tInfo.fCY / 2.f) - sin((m_fAngle + 225.f) * PI / 180.f) * fDiagonal);

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing('R'))
		m_fAngle += 3.f;
}

void CMonster::Render(HDC hDC)
{
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);
	HDC hPlgDC = CBmpMgr::Get_Instance()->Find_Img(L"Plg");
	HDC hResetDC = CBmpMgr::Get_Instance()->Find_Img(L"Reset");
	
	PlgBlt(hPlgDC, // ȸ���� �̹����� ������� DC
		m_tPoint,	// ȸ����ų ������ ù ��° �ּ�
		hMemDC,		// ȸ�� ��ų �̹��� DC
		0, 0,		// ������ �̹����� LEFT, TOP ��ǥ
		(int)m_tInfo.fCX, (int)m_tInfo.fCY, // ������ �̹����� ����, ���� ������
		NULL, NULL, NULL);
	
	GdiTransparentBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hPlgDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));

	BitBlt(hPlgDC,
		0, 0,
		m_tInfo.fCX, m_tInfo.fCY,
		hResetDC, 0, 0, SRCCOPY);
}

void CMonster::Release()
{
}
