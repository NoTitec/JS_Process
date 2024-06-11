#include "Select.h"
#include "stdafx.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "AbstractFactory.h"
#include "UIMgr.h"
#include "StartButton.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
CSelect::CSelect() : m_iselectindex(0)
{
}

CSelect::~CSelect()
{
    Release();
}

void CSelect::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../ResourceImage/Select/Select_Character.bmp", L"SelectCharacter");
	//CUI* pStartButton = CAbstractFactory<CStartButton>::Create_UI(650.f, 50.f);
	//pStartButton->Set_FrameKey(L"StartButton");
	//UIMgr->Add_UI(UI_MENU, pStartButton);
	SoundMgr->PlayBGM(L"02_Invitation.ogg", 0.3f);
}

int CSelect::Update()
{
	if(m_dwPlayerselectTime+3000<GetTickCount())
		CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE_1);

    return 0;
}

void CSelect::Late_Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		m_dwPlayerselectTime = GetTickCount();
		switch (m_iselectindex)
		{
		case 0:
			SoundMgr->PlaySoundW(L"select koyori.wav",SOUND_SELECT,1.f);
			break;
		case 1:
			SoundMgr->PlaySoundW(L"select tengai.wav", SOUND_SELECT, 1.f);

			break;
		case 2:
			SoundMgr->PlaySoundW(L"select katana.wav", SOUND_SELECT, 1.f);

			break;
		case 3:
			SoundMgr->PlaySoundW(L"select sho.wav", SOUND_SELECT, 1.f);

			break;
		case 4:
			SoundMgr->PlaySoundW(L"select_junis.wav", SOUND_SELECT, 1.f);

			break;

		}
		//CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::SC_STAGE_1);
		return;
	}
	if (KeyMgr->Key_Down(VK_RIGHT))
	{
		if (m_iselectindex < 5)
			++m_iselectindex;
	}
	if (KeyMgr->Key_Down(VK_LEFT))
	{
		if (m_iselectindex > 0)
		{
			--m_iselectindex;
		}
	}
}

void CSelect::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"SelectCharacter");
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, WINCX *m_iselectindex, 0, SRCCOPY);
	UIMgr->Render(hDC);
}

void CSelect::Release()
{
	SoundMgr->StopSound(SOUND_BGM);
}
