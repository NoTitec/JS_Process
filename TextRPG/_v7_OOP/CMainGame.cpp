#include "CMainGame.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "stdafx.h"

enum DIFFICULTY
{
	EASY = 1,
	NORMAL,
	HARD
};
CMainGame::CMainGame()
{
	m_Player = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

//���� ���� �� �÷��̾� ��ü �����ϰ� ������ true, ���н� false ��ȯ
bool CMainGame::Initialize()
{
	m_Player = new CPlayer;
	int iInput(0);
	bool bContinue(false);

	while (!bContinue)
	{
		cout << "������ �����ϼ���(1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ����) : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			m_Player->Initialize("����", 10, 100);
			bContinue = true;

			break;

		case WIZARD:
			m_Player->Initialize("������", 10, 100);
			bContinue = true;

			break;

		case THIEF:
			m_Player->Initialize("����", 10, 100);
			bContinue = true;

			break;

		case LOAD:
			bContinue = m_Player->Load_Player_Data();


			break;

		default:
			cout << "Wrong Input Man~~~" << endl;
			break;
		}
	}

	if (m_Player)
	{
		return true;
	}
	cout << "�÷��̾� ��ü ���� ����" << endl;
	system("pause");
	return false;
}

void CMainGame::Update()
{
	int iInput(0);
	bool bCheckSaveOk = false;

	while (true)
	{
		system("cls");
		CMonster* pMonster = new CMonster;
		m_Player->Print_Player_Info();
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �����ϱ� 5. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			pMonster->Initialize("�ʱ�", 3, 30);
			break;

		case NORMAL:
			pMonster->Initialize("�߱�", 6, 60);

			break;
		case HARD:
			pMonster->Initialize("���", 12, 90);

			break;
		case 4:
			bCheckSaveOk = m_Player->Save_Player_Data();
			system("pause");
			break;
			//5�������� ���� ����
		case 5:
			SAFE_DELETE(pMonster)
				return;

		default:
			cout << "you Input wrong Number Boy~~~~" << endl;

		}
		//�޴��� ���崭������ ������ �ҷ����� �ٽ� ���̵� ���ø޴��� ���ư���
		if (bCheckSaveOk)
		{
			bCheckSaveOk = false;
			continue;
		}
		//���� ���������� ���� ����
		int BattleResult = Battle(m_Player, pMonster);
		if (1 == BattleResult)
		{
			m_Player->Set_Hp(100);
		}
		//�׾��� �̰�� �����Ƶ� ���� �������Ƿ� �����ߴ� ���� ���޸� �����ϰ� nullptr �ʱ�ȭ
		SAFE_DELETE(pMonster)
	}
}

int CMainGame::Battle(CPlayer* player, CMonster* monster)
{
	int iInput(0);

	//�÷��̾�, ���Ͱ� �װų� ����ĥ������ ���� �ݺ�
	//�÷��̾� �¸�-> 0
	//�÷��̾� ���-> 1
	//�÷��̾� ����-> 2
	while (true)
	{
		system("cls");
		player->Print_Player_Info();
		monster->Print_Monster_Info();
		cout << "1. ���� 2. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			player->Take_Damage(monster->Get_Atk());
			monster->Take_Damage(player->Get_Atk());
			if (0 >= player->Get_Hp())
			{
				cout << "�÷��̾� ���" << endl;
				system("pause");
				return 1;
			}
			if (0 >= monster->Get_Hp())
			{
				cout << "���� ��ġ" << endl;
				cout << "�¸�" << endl;
				system("pause");
				return 0;
			}
			break;
		case 2:
			return 2;
		default:
			cout << "you input wrong bro~~~~" << endl;
		}
	}
	return 0;
}

void CMainGame::Release()
{
	SAFE_DELETE(m_Player);
}
