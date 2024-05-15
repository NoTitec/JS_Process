#pragma once

#include "Scene.h"
class CBossEntranceScene : public CScene
{
public:
	enum ENTRANCE_SCENE_TYPE
	{
		TALK_ONE_SCENE,
		TALK_TWO_SCENE,
		ENTRANCE_SCENE_END
	};
public:
	CBossEntranceScene();
	virtual ~CBossEntranceScene();
public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;
private:
	DWORD m_dwTime;
	ENTRANCE_SCENE_TYPE m_eEntranceSceneType;
};

