#pragma once

#include "Scene.h"
class CObj;
class CMainGameScene : public CScene
{
public:
	CMainGameScene();
	virtual ~CMainGameScene();

public:
	// CScene��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Release() override;

private:
	HDC m_DC;
	list<CObj*> m_ObjList[OBJ_END];
	bool m_bStageClear;
	bool m_bPortalExisted;

	DWORD m_dwTime;
	int m_iFps;
	TCHAR m_szFPS[32];
};

