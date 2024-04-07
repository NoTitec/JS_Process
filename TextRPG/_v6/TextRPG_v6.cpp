#include "stdafx.h"
#include <fstream>
#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

enum JOBINDEX
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	LOAD,
	END
};
enum DIFFICULTY
{
	EASY=1,
	NORMAL,
	HARD
};
//�ʿ� �Լ� ���

#pragma region �÷��̾� �Լ�
//���� �����ϰ� �ش� �÷��̾� �ν��Ͻ��� ���� ���� �� �ּ� ��ȯ�ϴ� �Լ�
LPPLAYER Make_Player();
//�ʿ��� �÷��̾� ���� ���ڷ� �޾� ���� �Ҵ��� �÷��̾� �޸𸮿� ���� ä��� �Լ�
void Create_Player(LPPLAYER* lpplayer, const char* pName, int iAtk, int iHp);
void Print_Player_Info(LPPLAYER lpplayer);
#pragma endregion �÷��̾� �Լ�

#pragma region ���� �Լ�
void Create_Monster(LPMONSTER* lpmonster, const char* pName, int iAtk, int iHp);
void Print_Monster_Info(LPMONSTER lpmonster);
#pragma endregion ���� �Լ�

#pragma region ����������Լ�
bool Save_Player_Data(LPPLAYER lplayer);
bool Load_Player_Data(LPPLAYER* lpplayer);
#pragma endregion ����������Լ�
//���� ���� �Լ�
void Game_Start(LPPLAYER lpplayer);

//�÷��̾�� ������ ���� �� ��� ��ȯ
int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster);


///////////////////////////////////////////////////////
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	LPPLAYER player = Make_Player();

	if (player == nullptr)
	{
		return -1;
	}

	Game_Start(player);

	SAFE_DELETE(player)
	return 0;
}

LPPLAYER Make_Player()
{

	LPPLAYER lpplayer = nullptr;
	int iInput(0);
	bool bContinue(false);

	while (!bContinue)
	{
		cout << "������ �����ϼ���(1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ����) : ";
		cin >> iInput;

		switch (iInput)
		{
		case WARRIOR:
			Create_Player(&lpplayer,"����",10,100);
			bContinue = true;

			break;

		case WIZARD:
			Create_Player(&lpplayer, "������", 10, 100);
			bContinue = true;

			break;

		case THIEF:
			Create_Player(&lpplayer, "����", 10, 100);
			bContinue = true;

			break;

		case LOAD:
			bContinue=Load_Player_Data(&lpplayer);
			

			break;

		default:
			cout << "Wrong Input Man~~~"<<endl;
			break;
		}

	}
	return lpplayer;
}

void Create_Player(LPPLAYER* lpplayer, const char* pName, int iAtk, int iHp)
{
	(*lpplayer) = new PLAYER;

	strcpy_s((*lpplayer)->szName, sizeof((*lpplayer)->szName), pName);
	(*lpplayer)->iAtk = iAtk;
	(*lpplayer)->iHp = iHp;
}

void Print_Player_Info(LPPLAYER lpplayer)
{
	cout<<"�̸� : " << lpplayer->szName << endl;
	cout<<"ü�� : " << lpplayer->iHp << endl;
	cout<<"���ݷ� : " << lpplayer->iAtk << endl;
}

void Create_Monster(LPMONSTER* lpmonster, const char* pName, int iAtk, int iHp)
{
	(*lpmonster) = new MONSTER;
	strcpy_s((*lpmonster)->szName, sizeof((*lpmonster)->szName), pName);
	(*lpmonster)->iAtk = iAtk;
	(*lpmonster)->iHp = iHp;
}

void Print_Monster_Info(LPMONSTER lpmonster)
{
	cout << "�̸� : " << lpmonster->szName << endl;
	cout << "ü�� : " << lpmonster->iHp << endl;
	cout << "���ݷ� : " << lpmonster->iAtk << endl;
}

bool Save_Player_Data(LPPLAYER lplayer)
{
	FILE* pFile = nullptr;
	if (0 == fopen_s(&pFile, "./Data/Save.txt", "wb"))
	{
		fwrite(lplayer, sizeof(PLAYER), 1, pFile);
		cout << "���� �Ϸ�" << endl;

		fclose(pFile);
		return true;
	}
	else
	{
		cout << "���� ����" << endl;
		return false;
	}
}

bool Load_Player_Data(LPPLAYER* lpplayer)
{
	(*lpplayer) = new PLAYER;
	ifstream readFile;
	readFile.open("./Data/Save.txt");
	if (readFile.is_open())
	{
		readFile.read((char*)(*lpplayer),sizeof(PLAYER));
		cout << "�ҷ����� ����" << endl;
		readFile.close();
		return true;
	}
	else
	{
		cout << "�ҷ����� ����" << endl;
		return false;
	}
	/*(*lpplayer) = new PLAYER;
	FILE* pFile = nullptr;
	if (0 == fopen_s(&pFile, "./Data/Save.txt", "rb"))
	{
		fread((*lpplayer), sizeof(PLAYER), 1, pFile);
		cout << "�ҷ����� ����" << endl;
		fclose(pFile);
		return true;
	}
	else
	{
		cout << "�ҷ����� ����" << endl;
		return false;
	}*/
}

void Game_Start(LPPLAYER lpplayer)
{
	int iInput(0);
	LPMONSTER lpmonster = nullptr;
	bool bCheckSaveOk = false;

	while (true)
	{
		system("cls");
		Print_Player_Info(lpplayer);
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �����ϱ� 5. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case EASY:
			Create_Monster(&lpmonster, "�ʱ�", 3, 30);
			break;

		case NORMAL:
			Create_Monster(&lpmonster, "�߱�", 6, 60);

			break;
		case HARD:
			Create_Monster(&lpmonster, "���", 9, 90);

			break;
		case 4:
			bCheckSaveOk=Save_Player_Data(lpplayer);
			system("pause");
			break;
			//5�������� ���� ����
		case 5:
			SAFE_DELETE(lpmonster)
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
		int BattleResult = Battle(lpplayer, lpmonster);
		if (1 == BattleResult)
		{
			lpplayer->iHp = 100;
		}
		//�׾��� �̰�� �����Ƶ� ���� �������Ƿ� �����ߴ� ���� ���޸� �����ϰ� nullptr �ʱ�ȭ
		SAFE_DELETE(lpmonster)
	}
}

int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster)
{
	int iInput(0);

	//�÷��̾�, ���Ͱ� �װų� ����ĥ������ ���� �ݺ�
	//�÷��̾� �¸�-> 0
	//�÷��̾� ���-> 1
	//�÷��̾� ����-> 2
	while (true)
	{
		system("cls");
		Print_Player_Info(lpplayer);
		Print_Monster_Info(lpmonster);

		cout << "1. ���� 2. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			lpplayer->iHp -= lpmonster->iAtk;
			lpmonster->iHp -= lpplayer->iAtk;
			if (0 >= lpplayer->iHp)
			{
				cout << "�÷��̾� ���" << endl;
				system("pause");
				return 1;
			}
			if (0 >= lpmonster->iHp)
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
			cout << "you input wrong bro~~~~"<<endl;
		}
	}
	return 0;
}
