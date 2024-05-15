#include "pch.h"
#include "SceneMgr.h"
#include "BossEntranceScene.h"

CBossEntranceScene::CBossEntranceScene()
{

}

CBossEntranceScene::~CBossEntranceScene()
{
	Release();
}

void CBossEntranceScene::Initialize()
{
	m_dwTime = GetTickCount();
	m_eEntranceSceneType = ENTRANCE_SCENE_TYPE::TALK_ONE_SCENE;
}

int CBossEntranceScene::Update()
{
	if (m_dwTime + 5000 < GetTickCount())
	{
		if (ENTRANCE_SCENE_TYPE::TALK_ONE_SCENE == m_eEntranceSceneType)
		{
			m_eEntranceSceneType = ENTRANCE_SCENE_TYPE::TALK_TWO_SCENE;
		}
		else if (ENTRANCE_SCENE_TYPE::TALK_TWO_SCENE == m_eEntranceSceneType)
		{
			CSceneMgr::Change_Active_Scene(SCENE_TYPE::BOSS_GAME_SCENE);
		}
		m_dwTime = GetTickCount();
	}
	return 0;
}

void CBossEntranceScene::Late_Update()
{

}

void CBossEntranceScene::Render(HDC _hdc)
{
	switch (m_eEntranceSceneType)
	{
	case ENTRANCE_SCENE_TYPE::TALK_ONE_SCENE:
	{
		HBRUSH blackBrush = (HBRUSH)::CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, blackBrush);
		::Rectangle(_hdc, 0, 0, WINCX, WINCY);
		::SelectObject(_hdc, oldBrush);
		::DeleteObject(blackBrush);

		HFONT scriptFont = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
		HFONT oldNameFont = (HFONT)::SelectObject(_hdc, scriptFont);
		::SetBkMode(_hdc, TRANSPARENT);
		::SetTextColor(_hdc, RGB(255, 255, 255));
		::TextOut(_hdc, WINCX / 2.0f - 275, WINCY / 2.0f - 75, L"유안: 남영이형 내가 도와줄게...", 19);
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::SetBkMode(_hdc, OPAQUE);
		::SelectObject(_hdc, oldNameFont);
		::DeleteObject(scriptFont);
		break;
	}
	case ENTRANCE_SCENE_TYPE::TALK_TWO_SCENE:
	{
		HBRUSH blackBrush = (HBRUSH)::CreateSolidBrush(RGB(136, 8, 8));
		HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, blackBrush);
		::Rectangle(_hdc, 0, 0, WINCX, WINCY);

		HFONT scriptFont = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("궁서"));
		HFONT oldNameFont = (HFONT)::SelectObject(_hdc, scriptFont);
		::SetBkMode(_hdc, TRANSPARENT);
		::SetTextColor(_hdc, RGB(255, 255, 255));
		::TextOut(_hdc, WINCX / 2.0f - 150, WINCY / 2.0f - 75, L"남영: 꾸에에엑", 8);
		::SetTextColor(_hdc, RGB(0, 0, 0));
		::SetBkMode(_hdc, OPAQUE);
		::SelectObject(_hdc, oldNameFont);
		::DeleteObject(scriptFont);

		::SelectObject(_hdc, oldBrush);
		::DeleteObject(blackBrush);
		break;
	}
	}
}

void CBossEntranceScene::Release()
{

}
