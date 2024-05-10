#pragma once

class CObj;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();
private:
	HDC m_DC;
	list<CObj*> m_ObjList[OBJ_END];

	DWORD m_dwTime;
	int m_iFps;
	TCHAR m_szFPS[32];
};

