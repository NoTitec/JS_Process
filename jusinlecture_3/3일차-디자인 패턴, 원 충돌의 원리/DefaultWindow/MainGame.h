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


// 1. �¿�� �����̴� ���͸� �����϶�
// 2. ��Ʈ �浹�� �̿��Ͽ� ���Ϳ� �Ѿ��� �����϶�

// bool IntersectRect(����� ����� ��Ʈ�� �ּ�, �浹�� ��Ʈ�� �ּ�1, �浹�� ��Ʈ�� �ּ�2)

// �ָ� �� ����
// 1. �ﰢ �Լ� ����
// 2. �÷��̾ ������ �������� ���� �ϳ� �׸�, ���� ȸ�� ��Ŵ(����)
// 3. ������ �ٶ󺸴� �������� �÷��̾� �̵��ؾ� �Ѵ�