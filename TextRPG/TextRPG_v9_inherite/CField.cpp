#include "CField.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCombat.h"
#include "stdafx.h"
CField::CField()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

CField::~CField()
{
	Release();
}

void CField::Set_Player(Character* pPlayer)
{
	m_pPlayer = pPlayer;
}

void CField::Initialize()
{
}

void CField::Update()
{
	int iInput(0);
	//system("pause");
	system("cls");
	m_pPlayer->Render();
	cout << "1.�ʱ� 2.�߱� 3.��� 4.�� �ܰ�:";
	cin >> iInput;
	switch (iInput)
	{
	case CMonster::EASY:
		m_pMonster = new CMonster("�ʱ�", 3, 30);
		break;
	case CMonster::NORMAL:
		m_pMonster = new CMonster("�߱�", 6, 60);

		break;
	case CMonster::HARD:
		m_pMonster = new CMonster("���", 9, 90);

		break;

	case 4:
		return;
	}

	int iResult = CCombat::Battle(m_pPlayer, m_pMonster);

	if (1 == iResult)
	{
		m_pPlayer->Set_Hp(100);
	}
	else
	{
		SAFE_DELETE(m_pMonster);
	}
}

void CField::Release()
{
	SAFE_DELETE(m_pMonster);
}
