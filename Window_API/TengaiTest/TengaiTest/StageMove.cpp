#include "StageMove.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "AbstractFactory.h"
#include "UIMgr.h"
#include "StartButton.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
CStageMove::CStageMove()
{
}

CStageMove::~CStageMove()
{
    Release();
}

void CStageMove::Initialize()
{
    m_dwNextSceneDelayTime = GetTickCount();
}

int CStageMove::Update()
{
    if (m_dwNextSceneDelayTime + 3000 < GetTickCount())
    {
        int i = SceneMgr->Get_LoadCallerID();
        switch (i)
        {
        case CSceneMgr::SC_STAGE_1:
            CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE_2);

            break;

        }
    }
    return 0;
}

void CStageMove::Late_Update()
{
    /*if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
    {
        CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE_2);
    }*/
}

void CStageMove::Render(HDC hDC)
{
    HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Load");
    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0 , 0, SRCCOPY);
}

void CStageMove::Release()
{
}
