#include <iostream>
#include <ctime>

using namespace std;

//2. ���� ���� �� ���� �����
//
//- ������ �̾Ƽ� 0~2�� ���ڸ� �����.(��ǻ���� ���� ���� �� ���� �ش�)
//- 1. ���� 2. ���� 3. �� 4. ����
//- ����ڰ� �Է��� ���� ������ ���� �߻��� ���� ���� ���� ���Ͽ� ��, ��, �и� ���
//- �� 5���� ���� ��, ������ ���� ���� �� �� �� �� �� �� �и� ���
#pragma region ���� ���� ��

//���� �õ� ���� �Լ�
void Set_Random_Number_Seed();
//1~3 ���� �̴� �Լ�
int Get_Random_Number();
//�޴���� �Լ�
void Print_Menu();
//����� �Է¹޴� �Լ�
int Get_User_Input();
//��ǻ�� ���� ����� �� ���Ͽ� ��,��,�� �����ϴ� �Լ�
void Do_Task();

int main()
{
	Set_Random_Number_Seed();

	Do_Task();

	return 0;
}

#pragma endregion ���� ���� ��

void Set_Random_Number_Seed()
{
	srand(unsigned(time(NULL)));
}

int Get_Random_Number()
{
	return rand() % 3 + 1;
}

void Print_Menu()
{
	cout << "1. ���� 2. ���� 3. �� 4. ���� : ";
}

int Get_User_Input()
{
	int iInput(0);
	cin >> iInput;
	return iInput;
}

void Do_Task()
{
	int	iComputer(0), iInput(0), iRound(5), iWin(0), iDraw(0), iLose(0);
	bool bChoice(true);

	while ((0 < iRound) && (bChoice))
	{
		system("cls");

		iComputer = Get_Random_Number();
		Print_Menu();

		iInput = Get_User_Input();
		--iRound;

		switch (iInput)
		{
		case 1:
			if (1 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "����� : ����" << endl;
				cout << "���º�" << endl;
				++iDraw;
			}
			else if (2 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "����� : ����" << endl;
				cout << "�й�" << endl;
				++iLose;
			}
			else
			{
				cout << "��ǻ�� : ��" << endl;
				cout << "����� : ����" << endl;
				cout << "�¸�" << endl;
				++iWin;
			}

			break;

		case 2:
			if (1 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "����� : ����" << endl;
				cout << "�¸�" << endl;
				++iWin;
			}
			else if (2 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "����� : ����" << endl;
				cout << "���º�" << endl;
				++iDraw;
			}
			else
			{
				cout << "��ǻ�� : ��" << endl;
				cout << "����� : ����" << endl;
				cout << "�й�" << endl;
				++iLose;
			}
			break;

		case 3:
			if (1 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "����� : ��" << endl;
				cout << "�й�" << endl;
				++iLose;
			}
			else if (2 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "����� : ��" << endl;
				cout << "�¸�" << endl;
				++iWin;
			}
			else
			{
				cout << "��ǻ�� : ��" << endl;
				cout << "����� : ��" << endl;
				cout << "���º�" << endl;
				++iDraw;
			}
			break;

		case 4:
			bChoice = false;
			cout << "������ �����մϴ�" << endl;
			break;

		default:
			cout << "�߸� �����̽��ϴ�" << endl;
			++iRound;
			break;
		}

		system("pause");
	}

	system("cls");
	cout << "�� : " << iWin << "\t�� : " << iDraw << "\t�� : " << iLose << endl;
	system("pause");
}
