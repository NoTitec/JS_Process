#include "Stage1.h"
#include "stdafx.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "UIMgr.h"
#include "PlayerHeadUI.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Player.h"
#include "PowerItem.h"
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
    CUI* pPlayerHeadUI = CAbstractFactory<CPlayerHeadUI>::Create_UI(ObjMgr->Get_Player_Pointer()->Get_Info().fX,ObjMgr->Get_Player_Pointer()->Get_Info().fY-32.f,ObjMgr->Get_Player_Pointer());
    pPlayerHeadUI->Set_FrameKey(L"PowerUp");
    UIMgr->Add_UI(UI_PLAYER_HEAD_MASSAGE, pPlayerHeadUI);
    ObjMgr->Add_Object(OBJ_BOSSMONSTER,CAbstractFactory<CGreenBoss>::Create());
    ObjMgr->Add_Object(OBJ_ITEM,CAbstractFactory<CPowerItem>::Create());
    BmpMgr->Insert_Bmp(L"../ResourceImage/Map/forest.bmp", L"forest");
}

int CStage1::Update()
{
    CObjMgr::Get_Instance()->Update();
    UIMgr->Update();
    return 0;
}

void CStage1::Late_Update()
{
    m_iScrollX -= m_iScrollXSpeed;
    if (WINCX - 3520 > m_iScrollX)
        m_iScrollX = 0;
    CObjMgr::Get_Instance()->Late_Update();
    UIMgr->Late_Update();
}

void CStage1::Render(HDC hDC)
{
    HDC hGroundDC = CBmpMgr::Get_Instance()->Find_Img(L"forest");

    //int	iScrollX = (int)ScrollMgr->Get_ScrollX();
    int	iScrollY = (int)ScrollMgr->Get_ScrollY();
    BitBlt(hDC, m_iScrollX, iScrollY, 3520, 720, hGroundDC, 0, 0, SRCCOPY);

    CObjMgr::Get_Instance()->Render(hDC);
    UIMgr->Render(hDC);
}

void CStage1::Release()
{
}
