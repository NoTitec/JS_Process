#pragma once

// #include "Player.h"

// ���� ���� : ��ȣ ���� �Ǵ� ������ �����ϴ� ���, �ڷ����� ������ �˷���

// 1. ���� ���� ��, ��ü �����͸� ��� ������ �����ؾ� �Ѵ�.
// 2. cpp ���Ͽ� ����� ���Խ������ �Ѵ�.

class CPlayer;

class CMonster
{
public:
	CMonster();
	~CMonster();

public:
	void	Draw();
	
	void	Output()
	{
		cout << "academy" << endl;
	}

private:
	CPlayer*			m_pPlayer;
};

