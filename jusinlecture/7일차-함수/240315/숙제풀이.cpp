#include <iostream>
#include <ctime>

using namespace std;


#pragma region ���� ���� ��

/*
int main()
{
	int	iComputer(0), iInput(0), iRound(5), iWin(0), iDraw(0), iLose(0);
	bool bChoice(true);

	srand(unsigned(time(NULL)));

	while ((0 < iRound) && (bChoice))
	{
		system("cls");

		iComputer = rand() % 3 + 1;

		cout << "1. ���� 2. ���� 3. �� 4. ���� : ";
		cin >> iInput;
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

	return 0;
}*/

#pragma endregion ���� ���� ��

#pragma region ������ �����

//int main()
//{
//	int	iDan(0), iGob(0);
//
//	cout << "���� �Է��ϼ��� : ";
//	cin >> iDan;
//
//	cout << "���� �Է��ϼ��� : ";
//	cin >> iGob;
//
//	for (int i = 2; i <= iDan; ++i)
//	{
//		for (int j = 1; j <= iGob; ++j)
//		{
//			cout << i << " * " << j << " = " << i * j << endl;
//		}
//
//		cout << "-----------------------------------" << endl;
//	}
//
//	return 0;
//}

#pragma endregion ������ �����

#pragma region �����

//int main()
//{
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if(i >= j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//
//	cout << "=====================================" << endl;
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if (i <= j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//
//	cout << "=====================================" << endl;
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if (4 <= i + j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//	
//	cout << "=====================================" << endl;
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
//			if (4 >= i + j)
//				cout << " * " << "\t";
//			else
//				cout << " " << "\t";
//		}
//
//		cout << endl;
//	}
//
//	return 0;
//}

#pragma endregion �����