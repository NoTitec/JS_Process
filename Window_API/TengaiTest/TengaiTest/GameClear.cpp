#include "GameClear.h"

CGameClear::CGameClear()
{
}

CGameClear::~CGameClear()
{
    Release();
}

void CGameClear::Initialize()
{
    SoundMgr->PlayBGM(L"cugbae-gasa-lyrics.mp3", 0.5f);
}

int CGameClear::Update()
{
    return 0;
}

void CGameClear::Late_Update()
{
    if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
    {
        CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_LOGO);
        return;
    }
}

void CGameClear::Render(HDC hDC)
{
    HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Clear");
    BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CGameClear::Release()
{
    SoundMgr->StopSound(SOUND_BGM);
}
