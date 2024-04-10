#include "Field.h"
#include "stdafx.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCombat.h"
CField::CField()
{
	m_pPlayer = nullptr;
	m_Monster = nullptr;
}

CField::~CField()
{
	Release();
}

void CField::Set_Player(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

//int CField::Battle()
//{
//	int iInput(0);
//
//	while (true)
//	{
//		system("cls");
//		m_pPlayer->Render();
//		m_Monster->Render();
//
//		cout << "1.���� 2.����:";
//		cin >> iInput;
//
//		switch (iInput)
//		{
//		case 1:
//			m_pPlayer->Take_Damage(m_Monster->Get_Attack());
//			m_Monster->Take_Damage(m_pPlayer->Get_Attak());
//
//			if (0 >= m_pPlayer->Get_Hp())
//			{
//				cout << "�÷��̾� ���" << endl;
//				system("pause");
//				return 1;
//			}
//			if (0 >= m_Monster->Get_Hp())
//			{
//				cout << "�¸�" << endl;
//				system("pause");
//				return 0;
//			}
//			break;
//		case 2:
//			return 0;
//		}
//		//system("pause");
//	}
//}

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
		m_Monster = new CMonster("�ʱ�", 3, 30);
		break;
	case CMonster::NORMAL:
		m_Monster = new CMonster("�߱�", 6, 60);

		break;
	case CMonster::HARD:
		m_Monster = new CMonster("���", 9, 90);

		break;

	case 4:
		return;
	}

	int iResult = CCombat::Battle(m_pPlayer, m_Monster);

	if (1 == iResult)
	{
		m_pPlayer->Set_Hp(100);
	}
	else
	{
		SAFE_DELETE(m_Monster);
	}
}

void CField::Release()
{
	SAFE_DELETE(m_Monster);

}
