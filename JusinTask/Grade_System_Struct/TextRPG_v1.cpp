#include <iostream>

using namespace std;

//�÷��̾� ���� ����ü ����
typedef struct tagPlayer {
	char s_Name[20];
	int iHp;
	int iAtk;
}PLAYER,*LPPLAYER;

//���� ���� ����ü ����
typedef struct tagMonster {
	char s_Name[20];
	int iHp;
	int iAtk;
}MONSTER,*LPMONSTER;

//�÷��̾� �������� ������ ����ü
//PLAYER tPlayerArray[3] = {};
//�÷��̾� �ν��Ͻ�
PLAYER tPlayer = {};
//�÷��̾� �ν��Ͻ� ����Ű�� ������
LPPLAYER ptPlayer = &tPlayer;

//���� ���� ������ ����ü
//MONSTER tMonsterArray[3] = {};
//���� �ν��Ͻ�
MONSTER tMonster = {};
//���� �ν��Ͻ� ����Ű�� ������
LPMONSTER ptMonster= &tMonster;

//���� ���� ���� bool ����(Stage 1)
bool bEndGame(true);
//stage2 ���� bool ����
bool bEndStage2(true);
//���� ���� �ʱ�ȭ�ϰ� ���� �����ϴ� �Լ�
void InitGame();
//�÷��̾� ���� ��� �Լ�
void Print_Player_Status(LPPLAYER lpplayer);
//���� �Լ�
void Start_Battle(int idiffecult);

int main()
{
	InitGame();
	//����ص� ��������â���� ���ư����� �����Ƿ� ���������� �ʱ����� �����ϰ��־�� �ҷ��ü�����
	//����ܰ� �� ������
	PLAYER tbackupPlayer;
	strcpy_s(tbackupPlayer.s_Name, sizeof(tbackupPlayer.s_Name), ptPlayer->s_Name);
	tbackupPlayer.iHp = ptPlayer->iHp;
	tbackupPlayer.iAtk = ptPlayer->iAtk;

	while (bEndGame)
	{
		//stage 1
		int iStage1Input(0);
		if (ptPlayer->iHp == 0)
		{
			strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), tbackupPlayer.s_Name);
			ptPlayer->iHp = tbackupPlayer.iHp;
			ptPlayer->iAtk = tbackupPlayer.iAtk;
		}
		Print_Player_Status(ptPlayer);
		cout << "1. ����� 2. ���� :";
		cin >> iStage1Input;
		if (iStage1Input == 2)
		{
			system("cls");
			return 0;
		}
		else
		{
			bEndStage2 = true;
			//stage 2
			while (bEndStage2)
			{
				int iStage2Input(0);
				Print_Player_Status(ptPlayer);
				cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� :";
				cin >> iStage2Input;
				if (iStage2Input == 4)
				{
					//= �� ==�� �Ǿ��ֳ� �������� Ű���� ����
					bEndStage2 = false;
				}
				else if(iStage2Input==1)
				{
					Start_Battle(iStage2Input);
				}
				else if (iStage2Input == 2)
				{
					Start_Battle(iStage2Input);
				}
				else if (iStage2Input == 3)
				{
					Start_Battle(iStage2Input);
				}
				else
				{
					cout << "�߸��� �Է�" << endl;
				}
			}
		}
	}
	return 0;
}

void InitGame()
{
	int iInput(0);
	cout << "==============================================" << endl;
	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) :" << endl;

	char cJobArray[3][20] = {"����","������","����"};
	cin >> iInput;
	switch (iInput)
	{
	case 1:
		strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), cJobArray[iInput - 1]);
		ptPlayer->iHp = 100;
		ptPlayer->iAtk = 10;
		break;
	case 2:
		strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), cJobArray[iInput - 1]);
		ptPlayer->iHp = 100;
		ptPlayer->iAtk = 10;
		break;
	case 3:
		strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), cJobArray[iInput - 1]);
		ptPlayer->iHp = 100;
		ptPlayer->iAtk = 10;
		break;
	default:
		cout << "�߸��� �Է�";
		break;
	}
}

void Print_Player_Status(LPPLAYER lpplayer)
{
	system("cls");
	cout << "==============================================" << endl;
	cout << "�̸� : " << lpplayer->s_Name << endl;
	cout << "ü�� : " << lpplayer->iHp << "\t���ݷ� : " << lpplayer->iAtk << endl;
}
void Print_Monster_Status(LPMONSTER lpmonster)
{
	//system("cls");
	cout << "==============================================" << endl;
	cout << "�̸� : " << lpmonster->s_Name << endl;
	cout << "ü�� : " << lpmonster->iHp << "\t���ݷ� : " << lpmonster->iAtk << endl;
}
void Start_Battle(int idiffecult)
{
	bool bBattleEnd(true);
	//���� ���̵� ���� ���� ����
	char cMonsterNameArray[3][20] = { "�ʱ�","�߱�","���" };
	switch (idiffecult)
	{
	case 1:
		strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), cMonsterNameArray[idiffecult - 1]);
		ptMonster->iHp = 30;
		ptMonster->iAtk = 3;
		break;
	case 2:
		strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), cMonsterNameArray[idiffecult - 1]);
		ptMonster->iHp = 60;
		ptMonster->iAtk = 6;
		break;
	case 3:
		strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), cMonsterNameArray[idiffecult - 1]);
		ptMonster->iHp = 90;
		ptMonster->iAtk = 9;
		break;

	default:
		cout << "���� �߸� ����" << endl;
		return;
		break;
	}
	//�÷��̾ �װų� �¸��ϰų� ������������ �ݺ�
	while (bBattleEnd)
	{
		int iStage3Input(0);
	//�÷��̾� ���� ���
		Print_Player_Status(ptPlayer);
	//���� ���� ���
		Print_Monster_Status(ptMonster);
	//���� ���� ����
		cout << "1. ���� 2. ���� :";
		cin >> iStage3Input;
	//���������ϸ� ���� �ν��Ͻ� �ʱ�ȭ�ϰ� return
		if (iStage3Input == 2)
		{
			strcpy_s(ptMonster->s_Name, sizeof(ptMonster->s_Name), "");
			ptMonster->iHp = 0;
			ptMonster->iAtk = 0;
			return;
		}
	//���ݽ�
		else if(iStage3Input==1)
		{
			int iTmpPlayerHP = (ptPlayer->iHp) - (ptMonster->iAtk);
			//--1. �÷��̾� ��� �Ǻ� ���� �׾����� �÷��̾� ���� �ʱ� ���·� �ٲ��ְ� bEndstage2 false�� �ٲ��ְ� �÷��̾� ��� ��� �� return
			if (iTmpPlayerHP <= 0)
			{
				strcpy_s(ptPlayer->s_Name, sizeof(ptPlayer->s_Name), "");
				ptPlayer->iHp = 0;
				ptPlayer->iAtk = 0;
				bEndStage2 = false;
				cout << "�÷��̾� ���" << endl;
				system("pause");
				return;
			}
			//���׾����� �÷��̾�� ���� ������ ���ݷ� ������ ������ ������
			else
			{
				//���� �� 0���� �۰ų� ������ �¸� ����ϰ� return
				int iTmpMonsterHP = (ptMonster->iHp) - (ptPlayer->iAtk);
				if (iTmpMonsterHP <= 0)
				{
					cout << "�¸�" << endl;
					system("pause");
					return;
				}
				//�÷��̾ ���͵� ���������
				else
				{
					ptPlayer->iHp -= ptMonster->iAtk;
					ptMonster->iHp -= ptPlayer->iAtk;
				}
			}
		}
	//���ݵ� �������ƴ� �̻��� �Է��� ���
		else{
			cout << "�߸��� �Է�" << endl;
		}
	}
}
