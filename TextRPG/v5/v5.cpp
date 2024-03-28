#include "stdafx.h"
//�� ũ�� ���
const int mapSize = 15;
//�� �޴��� ������ int ��������
int iSceneNumber(0);
//�� �޸� ��ġ��Ͽ� ������
//�÷��̾� ��ǥ�� -1�� ǥ��
int** mapArray;
//���� ���� ��ǥ (�� ���ϴ�)
int iendx = mapSize - 1;
int iendy = mapSize - 1;

//���� ����ü
typedef struct tagWeapon
{
	char szWeaponName[20];
	int Atk;
} WEAPON, * LPWEAPON;

//�÷��̾� ����ü
typedef struct tagPlayer
{
	char szName[20];
	int iHp;
	int iCurrentLocation[2];//row,col
	WEAPON weapon;
} PLAYER, * LPPLAYER;
//�÷��̾� ������ ����������
LPPLAYER lpplayer=nullptr;

//���� ����ü
typedef struct tagZombie
{
	char szDifficulty[20];
	int iHp;
	int iAtk;
}ZOMBIE, * LPZOMBIE;
//�� ����ü
enum Scenes
{
	MAINSCENE,
	MOVESCENE,
	SELECTJOB,
	END
};
//���̵� ����ü
enum Diffeculty {
	EASY,
	NORMAL,
	HARD
};
//�Լ� ���� ��----------------------------------------------------
//���� ���� ���� �Լ�
void Main_Game();
//---------------------------
//�� �޴���
void SceneManager(int Scenenumber);
//----------------------------------------
//�� �Լ���
// 
//���� ��
void StartScene();
//�̵� ��
void Move_Scene(LPPLAYER lpplayer);
//�÷��̾� ���� ��
void Make_Player_Scene(LPPLAYER* lpplayer);
//�� �ʱ�ȭ �Լ�
void ResetMap(int** Array);

//�� ���� ���
void Print_map(int** Array, int size);
//�÷��̾� ���� ���
void Print_Player(LPPLAYER lpplayer);

//�÷��̾� �̵�+ ����
void Move_Player(int** Array, LPPLAYER* lpplayer, int direction);
//���� ��,�÷��̾����� ���̳ʸ� ���� ����,�ε��Լ�
bool Save_Data(int** Array, LPPLAYER lpplayer);
bool Load_Data(int** Array, LPPLAYER* lpplayer);
//���̳ʸ� ���Ͽ��� ��, �÷��̾� ���� �ҷ����� �Լ�
//----------------------------------------------
//����, ���Ǻ�-----------------------------------
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Main_Game();
	return 0;
}

void Print_Player(LPPLAYER lpplayer)
{
	cout << "-----------------------" << endl;
	cout << "���� : " << lpplayer->szName << endl;
	cout << "ü�� : " << lpplayer->iHp << endl;
	cout << "���� ��� : " << lpplayer->weapon.szWeaponName << endl;
	cout << "��� ���ݷ� : " << lpplayer->weapon.Atk << endl;
}
void Print_map(int** Array, int size)
{
	cout << "============================" << endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (Array[i][j] == -1)
			{
				cout << setw(3) << "*";
			}
			else
			{
				cout << setw(3) << Array[i][j];
			}
		}
		cout << endl;
	}
	cout << "============================" << endl;
}
void Move_Player(int** Array, LPPLAYER* lpplayer,int direction)
{
	//���� ���������� �б��Ͽ� �̵��������� �Ǻ��ϰ� �̵� ������ ��ġ�� �ش� ��ġ�� �̵���Ű��
	//���� �ش� ��ġ�� ���Ͱ��ִ� 1 ��ġ�� ������ �����ϰ� 0�̸� �׳� swap�� ����
	switch (direction)
	{
	case1:
		break;
	case 2:
		break;
	case 3:
		break;

	case 4:
		if (mapSize - 1 == (*lpplayer)->iCurrentLocation[1] % mapSize)
		{
			break;
		}
		if ((Array[(*lpplayer)->iCurrentLocation[0]][(*lpplayer)->iCurrentLocation[1] + 1]) == 1)
		{
			cout << "���������Լ� ȣ�� �ʿ�" << endl;
			//������� ����~~~~~~~~~~~~
			system("pause");
			break;
		}
		swap(Array[(*lpplayer)->iCurrentLocation[0]][(*lpplayer)->iCurrentLocation[1]], Array[(*lpplayer)->iCurrentLocation[0]][(*lpplayer)->iCurrentLocation[1] + 1]);
		(*lpplayer)->iCurrentLocation[1] += 1;
		break;
	}
	return;
}
bool Save_Data(int** Array, LPPLAYER lpplayer)
{
	FILE* pSaveFile = nullptr;

	errno_t		err = fopen_s(&pSaveFile, "./Data/Save.txt", "wb");

	if (0 == err)
	{
		fwrite(lpplayer, sizeof(PLAYER), 1, pSaveFile);
		// �� ������ ����
		for (int i = 0; i < mapSize; ++i)
		{
			fwrite(Array[i], sizeof(int), mapSize, pSaveFile);
		}

		fclose(pSaveFile);
		return true;
	}

	return false;
}
bool Load_Data(int** Array, LPPLAYER* lpplayer)
{
	(*lpplayer) = new PLAYER;

	FILE* pLoadFile = nullptr;

	errno_t err = fopen_s(&pLoadFile, "./Data/Save.txt", "rb");

	if (0 == err)
	{
		fread((*lpplayer), sizeof(PLAYER), 1, pLoadFile);
		// �� ������ �ε�
		for (int i = 0; i < mapSize; ++i)
		{
			fread(Array[i], sizeof(int), mapSize, pLoadFile);
		}

		fclose(pLoadFile);

		return true;
	}

	return false;
}
void Main_Game()
{
	//���� �õ� ����
	srand(unsigned(time(NULL)));
	//�ʿ� �޸� ���� �Ҵ� �� 0�ʱ�ȭ
	mapArray = new int* [mapSize];
	for (int i = 0; i < mapSize; ++i)
	{
		mapArray[i] = new int[mapSize];
		memset(mapArray[i], 0, sizeof(int) * mapSize);
	}

	//�� �������� ������ ���� �ݺ�
	while (iSceneNumber != END)
	{
		switch (iSceneNumber)
		{
		case MAINSCENE:
			SceneManager(MAINSCENE);
			break;
		case MOVESCENE:
			SceneManager(MOVESCENE);
			break;
		case SELECTJOB:
			SceneManager(SELECTJOB);
			break;
		}
	}

	//�� �޸� �Ҵ� ����
	for (int i = 0; i < mapSize; ++i)
	{
		delete[] mapArray[i];
	}
	delete[] mapArray;
	if (lpplayer != nullptr)
	{
		delete lpplayer;
	}
	return;
}

void SceneManager(int Scenenumber)
{
	switch (Scenenumber) {
	case MAINSCENE:
		StartScene();
		break;
	case MOVESCENE:
		Move_Scene(lpplayer);
		break;
	case SELECTJOB:
		Make_Player_Scene(&lpplayer);
		break;
	}
	return;
}

//���� �� ���� �Լ�
void StartScene()
{
	cout << "-------------  Z City --------------" << endl;
	cout << "1. New Game 2. Load Game 3. Quit" << endl;

	bool bEndStartScene(true);
	int iInput(0);

	while (bEndStartScene)
	{
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			//�� ���� �ʱ�ȭ�ϰ� �� �ѹ� ���� ���� �ѹ��� ���� �� �Լ� ����
			ResetMap(mapArray);
			Print_map(mapArray, mapSize);
			iSceneNumber = SELECTJOB;
			return;
		case 2:
			//���Ͽ��� �� ���� �ҷ��ͼ� mapArray�� ä��� �÷��̾������� ä���
			if (Load_Data(mapArray, &lpplayer))
			{
				cout << "�ε� ����" << endl;
				iSceneNumber = MOVESCENE;
				system("pause");
				return;
			}
			//���� ������ �ٽ� �Է�
			break;
		case 3:
			iSceneNumber = END;
			bEndStartScene = false;
		}
	}

	return;
}

void ResetMap(int** Array)
{
	//�� �������� 1�Ǵ� 0���� ä���(1~10�߿� 8�̻��϶���)
	//1���� �ִ� ĭ, 0 �ƹ��͵� ���� ĭ

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			int iorigin = rand() % 10;
			if (8 <= iorigin)
				Array[i][j] = 1;
			else
			{
				Array[i][j] = 0;
			}
		}
	}
	Array[0][0] = -1;
}

void Make_Player_Scene(LPPLAYER* lpplayer)
{
	(*lpplayer) = new PLAYER;
	LPPLAYER temp = *lpplayer;
	int iInput(0);
	cout << "������ �����ϼ���(1. �л� 2. ���� 3. Į���� ) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s((*lpplayer)->szName,sizeof(temp->szName),"�л�");
		temp->iHp = 100;
		temp->iCurrentLocation[0] = 0; temp->iCurrentLocation[1] = 0;
		temp->weapon.Atk = 5;
		strcpy_s(temp->weapon.szWeaponName, sizeof(temp->weapon.szWeaponName), "�����");
		break;
	case 2:
		strcpy_s((*lpplayer)->szName, sizeof(temp->szName), "����");
		temp->iHp = 300;
		temp->iCurrentLocation[0] = 0; temp->iCurrentLocation[1] = 0;
		temp->weapon.Atk = 15;
		strcpy_s(temp->weapon.szWeaponName, sizeof(temp->weapon.szWeaponName), "����");
		break;
	case 3:
		strcpy_s((*lpplayer)->szName, sizeof(temp->szName), "Į����");
		temp->iHp = 99999;
		temp->iCurrentLocation[0] = 0; temp->iCurrentLocation[1] = 0;
		temp->weapon.Atk = 9999;
		strcpy_s(temp->weapon.szWeaponName, sizeof(temp->weapon.szWeaponName), "��Į");

		break;
	}
	iSceneNumber = MOVESCENE;
	return;
}

void Move_Scene(LPPLAYER lpplayer)
{
	//1.�� 2.�� 3.��. �� �����ʿ�~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//���� ���� ���� �׽�Ʈ���� �ϸ� �����ϰ� ������ ���߿�
	system("cls");
	Print_map(mapArray,mapSize);
	Print_Player(lpplayer);
	cout << "--------------------------" << endl;
	cout << "1.�� 2.�� 3.�� 4.�� 5.���� 6.���θ޴�" << endl;
	int iInput(0);
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		cout << "���̵�" << endl;
		break;
	case 2:
		cout << "���̵�" << endl;
		break;
	case 3:
		cout << "���̵�" << endl;
		break;
	case 4:
		Move_Player(mapArray,&lpplayer,iInput);
		break;
	case 5:
		cout << "����" << endl;
		if (Save_Data(mapArray, lpplayer))
		{
			cout << "���� ����" << endl;
			system("pause");
		}
		break;
	case 6:
		iSceneNumber = MAINSCENE;
		return;
	}
}
