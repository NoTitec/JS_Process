#include "Stage1.h"
#include "stdafx.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Player.h"
#include "GreenBoss.h"
CStage1::CStage1(): m_iScrollXSpeed(3),m_iScrollX(0)
{
}

CStage1::~CStage1()
{
    Release();

}

void CStage1::Initialize()
{
    ObjMgr->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
    ObjMgr->Add_Object(OBJ_BOSSMONSTER,CAbstractFactory<CGreenBoss>::Create());
    BmpMgr->Insert_Bmp(L"../ResourceImage/Map/forest.bmp", L"forest");
}

int CStage1::Update()
{
    CObjMgr::Get_Instance()->Update();

    return 0;
}

void CStage1::Late_Update()
{
    m_iScrollX -= m_iScrollXSpeed;
    if (WINCX - 3520 > m_iScrollX)
        m_iScrollX = 0;
    CObjMgr::Get_Instance()->Late_Update();

}

void CStage1::Render(HDC hDC)
{
    HDC hGroundDC = CBmpMgr::Get_Instance()->Find_Img(L"forest");

    //int	iScrollX = (int)ScrollMgr->Get_ScrollX();
    int	iScrollY = (int)ScrollMgr->Get_ScrollY();
    BitBlt(hDC, m_iScrollX, iScrollY, 3520, 720, hGroundDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);

}

void CStage1::Release()
{
}
