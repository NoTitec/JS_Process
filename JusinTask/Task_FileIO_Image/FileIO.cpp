
// 1. �ؽ�Ʈ rpg ����, �ҷ����� ���� ��

// - �����ϱ�� �ƹ� �������� �����ص� ��
// - �ҷ������ ������ �����ϴ� ������ ���� ��

#include "stdafx.h"
typedef struct tagPlayer
{
	char splayerName[20];
	int iHp;
	int iAtk;
}PLAYER, * LPPLAYER;
typedef struct tagMonster
{
	char smonsterName[20];
	int iHp;
	int iAtk;
}MONSTER, * LPMONSTER;

enum JOBINDEX
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	ENDJOBINDEX
};

enum MONSTERINDEX
{
	EASY = 1,
	NORMAL,
	HARD,
	ENDMONSTERINDEX
};

enum Scenes {
	SELECTJOBSCENE,
	FIELDSCENE,
	BATTLESCENE,
	END
};

//���� ������ ���������ؼ� �ش� �÷��̾� �޸� �ּ� ��ȯ
// ���μ� ����� ���� �ּ� ��ȯ ��� �Լ� ���� v1
LPPLAYER Select_Job();

//�÷��̾� ���� ���� ���� ���� �Լ�
void Save_Current_Player_Info(LPPLAYER lpplayer);
//���� �ڵ� ���п� ���� �����Լ�
void Main_Game();

//�� �Ŵ���
void SceneManager(int SceneNumber, LPPLAYER* lpplayer);
void SceneManager(int SceneNumber, LPPLAYER* lpplayer, LPMONSTER* lpmonster);

// ���� ���� ��
void Scene1(LPPLAYER* lpplayer);
// ����� ��
void Scene2(LPPLAYER* lpplayer);
// ���� ��
void Scene3(LPPLAYER* lpplayer, LPMONSTER* lpmonster);

//���� ���� �Լ�
//�ܺ� ��������ü ���ڷ� �޾Ƽ� �ȿ��� �Ҵ��ϴ� ����� �Լ� ���� v2
void Create_Monster(LPMONSTER* ppInfo, const char* pName, int iAttack, int iHp);
//���� �Լ�
int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster);
//�÷��̾� ���� ��� �Լ�
void Print_Player_Info(LPPLAYER);
//���� ���� ��� �Լ�
void Print_Monster_Info(LPMONSTER);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Main_Game();

	return 0;
}
//������ �߰�--------------------------------------------------------------
void Save_Current_Player_Info(LPPLAYER lpplayer)
{

	FILE* pFile = NULL;

	errno_t		err = fopen_s(&pFile, "./Data/Save.txt", "wb");

	if (0 == err)
	{
		fwrite(lpplayer, sizeof(PLAYER), 1, pFile);
		// fwrite(iArray, sizeof(int), 5, pFile);

		cout << "���� ����" << endl;

		fclose(pFile);	// 3�ܰ�
		system("pause");
		return;
	}
	else
	{
		cout << "���� ���� ����" << endl;
		system("pause");
	}
}

void Main_Game()
{
	//���� �÷��̾� ����Ű�� ������
	LPPLAYER lpplayer(nullptr);

	//���� ���� ��
	SceneManager(SELECTJOBSCENE, &lpplayer);
	//���������ߴµ� ������ lplayer�� nullptr�̸� �������̹Ƿ� ����
	if (lpplayer == nullptr)
	{
		cout << "�÷��̾� ���� ����" << endl;
		system("pause");
		return;
	}
	//����� ��
	SceneManager(FIELDSCENE, &lpplayer);

	//���������� �÷��̾� �޸� ��ȯ
	//if (pPlayer)
	if (nullptr != lpplayer)
	{
		delete lpplayer;
		lpplayer = nullptr;
	}
	return;
}
//�÷��̾� ���޸� �Ҵ��ϰ� ���� �ּ� ��ȯ�Լ�(���̺� ���� ����� �߰�)--------------------------------------------------------
LPPLAYER Select_Job()
{
	//���̺� ���� �ҷ����� �õ�

	FILE* pLoadFile = NULL;

	LPPLAYER pTemp = new PLAYER;

	errno_t		err = fopen_s(&pLoadFile, "./Data/Save.txt", "rb");

	if (0 == err)
	{
		fread(pTemp, sizeof(PLAYER), 1, pLoadFile);
		// fwrite(iTemp, sizeof(int), 5, pLoadFile);

		cout << "�ҷ����� ����" << endl;
		cout << "-------------" << endl;
		system("pause");
		
		fclose(pLoadFile);	// 3�ܰ�
		return pTemp;
	}
	//���̺� ������ ���� �÷��̾� ���� ���� �����ϰ� ��ȯ�ϰ� ����
	else
	{
		cout << "���̺� ���� ���� ����" << endl;

		LPPLAYER lpTemp = nullptr;
		int		iInput(0);
		bool	bContinue(false);

		while (!bContinue)
		{
			cout << "������ �����ϼ���(1. ���� 2. ������ 3. ���� 4. ����) : ";
			cin >> iInput;

			switch (iInput)
			{
			case WARRIOR:
				lpTemp = new PLAYER;
				strcpy_s(lpTemp->splayerName, sizeof(lpTemp->splayerName), "����");
				lpTemp->iAtk = 10;
				lpTemp->iHp = 100;
				bContinue = true;
				break;

			case WIZARD:
				lpTemp = new PLAYER;
				strcpy_s(lpTemp->splayerName, sizeof(lpTemp->splayerName), "������");
				lpTemp->iAtk = 10;
				lpTemp->iHp = 100;
				bContinue = true;
				break;

			case THIEF:
				lpTemp = new PLAYER;
				strcpy_s(lpTemp->splayerName, sizeof(lpTemp->splayerName), "����");
				lpTemp->iAtk = 10;
				lpTemp->iHp = 100;
				bContinue = true;
				break;

			case ENDJOBINDEX:
				cout << "������ �����մϴ�" << endl;
				bContinue = true;
				break;

			default:
				cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
				break;
			}
		}

		FILE* pFile = NULL;

		errno_t		err = fopen_s(&pFile, "./Data/Save.txt", "wb");

		if (0 == err)
		{
			fwrite(lpTemp, sizeof(PLAYER), 1, pFile);
			// fwrite(iArray, sizeof(int), 5, pFile);

			cout << "���� ����" << endl;

			fclose(pFile);	// 3�ܰ�
			return lpTemp;
		}
		else
		{
			cout << "���� ���� ����" << endl;
		}
	}

	
}

//�÷��̾ �����ִ� �� �޴���
void SceneManager(int SceneNumber, LPPLAYER* lpplayer)
{
	switch (SceneNumber)
	{
	case SELECTJOBSCENE:
		Scene1(lpplayer);
		break;
	case FIELDSCENE:
		Scene2(lpplayer);
		break;
	}
}
//�÷��̾�� ���� �����ִ� �� �޴���
void SceneManager(int SceneNumber, LPPLAYER* lpplayer, LPMONSTER* lpmonster)
{
	switch (SceneNumber)
	{
	case BATTLESCENE:
		Scene3(lpplayer, lpmonster);
	}
}
//���� ���� �� ó�� �Լ�
//���ڴ� �÷��̾� �����ּ� Ÿ��
void Scene1(LPPLAYER* lpplayer)
{//�÷��̾� Ÿ�� �����Ͱ� �Ҵ��� ���޸� ����Ű����
	*lpplayer = Select_Job();
}

//����� �� ó�� �Լ�
//���ڴ� �÷��̾� �����ּ� Ÿ��
void Scene2(LPPLAYER* lpplayer)
{
	int		iInput(0);
	LPMONSTER pMonster = nullptr;

	while (true)
	{
		system("cls");
		//�̹� lpplayer�� �ּҰ��̹Ƿ� *�ٿ��� �ٽ� �����͸� �Ѱܾ���()
		Print_Player_Info(*lpplayer);

		cout << "1. �ʱ� 2. �߱� 3. ��� 4. ���� �÷��̾� ���� ���� 5. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Monster(&pMonster, "�ʱ�", 3, 30);
			break;

		case 2:
			//Create_Monster(&pMonster, "�߱�", 6, 60);
			break;

		case 3:
			Create_Monster(&pMonster, "���", 9, 90);
			break;
		case 4:
			Save_Current_Player_Info(*lpplayer);
			break;
		case 5:
			return;
		}
		//���ͻ��� ����ξȵ����� �ٽ� ���û����޴� ����
		if (pMonster == nullptr)
		{
			continue;
		}
		SceneManager(BATTLESCENE, lpplayer, &pMonster);

	}

}

void Scene3(LPPLAYER* lpplayer, LPMONSTER* lpmonster)
{
	int iResult = Battle(*lpplayer, *lpmonster);

	if (1 == iResult)
	{
		(*lpplayer)->iHp = 100;
	}

	if (nullptr != *lpmonster)
	{
		delete* lpmonster;
		*lpmonster = nullptr;
	}
}

void Create_Monster(LPMONSTER* ppMonster, const char* pName, int iAttack, int iHp)
{
	(*ppMonster) = new MONSTER;
	strcpy_s((*ppMonster)->smonsterName, sizeof((*ppMonster)->smonsterName), pName);
	(*ppMonster)->iHp = iHp;
	(*ppMonster)->iAtk = iAttack;
}

int Battle(LPPLAYER lpplayer, LPMONSTER lpmonster)
{
	int iInput(0);

	while (true)
	{
		system("cls");

		Print_Player_Info(lpplayer);
		Print_Monster_Info(lpmonster);

		cout << "1. ���� 2. ���� : ";
		cin >> iInput;

		if (1 == iInput)
		{
			lpmonster->iHp -= lpplayer->iAtk;
			lpplayer->iHp -= lpmonster->iAtk;

			if (0 >= lpplayer->iHp)
			{
				cout << "�÷��̾� ���" << endl;
				system("pause");
				return 1;
			}

			if (0 >= lpmonster->iHp)
			{
				cout << "�¸�" << endl;
				system("pause");
				return 0;
			}
		}

		else if (2 == iInput)
			return 0;
	}
}

void Print_Player_Info(LPPLAYER lpplayer)
{
	cout << "----------------------------------------" << endl;
	cout << "�̸� : " << lpplayer->splayerName << endl;
	cout << "ü�� : " << lpplayer->iHp << "\t���ݷ� : " << lpplayer->iAtk << endl;
}
void Print_Monster_Info(LPMONSTER lpmonster)
{
	cout << "----------------------------------------" << endl;
	cout << "�̸� : " << lpmonster->smonsterName << endl;
	cout << "ü�� : " << lpmonster->iHp << "\t���ݷ� : " << lpmonster->iAtk << endl;
}