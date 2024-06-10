#include "GameOverScene.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "AbstractFactory.h"
#include "UIMgr.h"
#include "StartButton.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
CGameOverScene::CGameOverScene()
{
}

CGameOverScene::~CGameOverScene()
{
    Release();

}

void CGameOverScene::Initialize()
{
    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../ResourceImage/Loby/FreeBirdMain.bmp", L"Logo");
    SoundMgr->PlayBGM(L"17_And_.ogg", 0.3f);
}

int CGameOverScene::Update()
{
    return 0;
}

void CGameOverScene::Late_Update()
{
    if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
    {
        CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_LOGO);
        return;
    }
}

void CGameOverScene::Render(HDC hDC)
{
    HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"GameOver");
    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CGameOverScene::Release()
{
    SoundMgr->StopSound(SOUND_BGM);
}
