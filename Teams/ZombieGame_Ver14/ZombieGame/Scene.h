#pragma once
class CObj;
class CScene
{
public:
	CScene();
	virtual ~CScene();
public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Late_Update() PURE;
	virtual void Render(HDC _hdc) PURE;
	virtual void Release() PURE;
protected:
	HDC m_DC;
	list<CObj*> m_ObjList[OBJ_END];

	DWORD m_dwTime;
	int m_iFps;
	TCHAR m_szFPS[32];
};

