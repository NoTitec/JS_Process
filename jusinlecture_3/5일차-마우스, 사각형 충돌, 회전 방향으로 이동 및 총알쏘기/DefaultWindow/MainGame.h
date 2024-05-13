#pragma once

#include "Player.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
#pragma region ����
	//CObj*		m_pPlayer;
	//list<CObj*>	m_BulletList;
#pragma endregion ����
	
	list<CObj*>		m_ObjList[OBJ_END];


	HDC			m_DC;
	DWORD		m_dwTime;
	int			m_iFps;
	TCHAR		m_szFPS[32];

};

// ������ ����
// : �ڵ��� �������� ������ ���·� ����� �����ϱ� ���ϰ� ���� ������ ����

// https://refactoring.guru/ko/design-patterns

// �߻� ���丮 ���� : ���� ������ �� ������� �ν��Ͻ��� ����� ������ �߻�ȭ ��Ŵ, ��ü ���� �� ���ݵǴ� �������� �۾��� �߻�ȭ ��
// �ݺ��� ���� : ���� ǥ�� ����� �������� �ʰ� �������� ���� ����� �����ϴ� ����

// �÷��̾ ���� �ٴϴ� ���� (�� �Լ�)
