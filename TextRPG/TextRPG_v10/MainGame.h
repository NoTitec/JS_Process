#pragma once
#include "Define.h"
#include "CBase.h"
#include "CPlayer.h"

class CBase;
class CField;
class CStore;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Release();

private:
	CBase* m_pBase;
	CField* m_pFiled;
	CStore* m_pStore;
};
