#pragma once
#include "Define.h"
#include "Obj.h"
#include "stdafx.h"
class CMainGame
{
public:
	//�ɹ��ʱ�ȭ
	CMainGame();
	//�޸� ����
	~CMainGame();

public:
	//�ڵ�޾ƿ���, �÷��̾� ����
	void Initialize();
	//�÷��̾� ������Ʈ
	void Update();
	//�÷��̾� ����
	void Render();
	//�ɹ� ����
	void Release();
private:
	CObj* m_pPlayer;
	list<CObj*>	m_BulletList;
	HDC m_DC;
	
};