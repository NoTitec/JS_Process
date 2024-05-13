#pragma once

class CObj;
class CUI;
class CUIMgr
{
public:
	CUIMgr();
	virtual ~CUIMgr();

public:
	static void Initialize();
	static void Update();
	static void Late_Update();
	static void Render();
	static void Release();
public:
	static void Set_Target(CObj* _pTarget) { pTarget = _pTarget; }
private:
	static CObj* pTarget;
	static vector<CUI*> uis;
};

