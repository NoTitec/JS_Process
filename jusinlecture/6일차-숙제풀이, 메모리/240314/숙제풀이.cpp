#include <iostream>
#include <ctime>

using namespace std;

#pragma region ������ �����

//int main()
//{	
//	int	i(2), j(1);
//
//	while (10 > i)
//	{
//		cout << i << " * " << j << " = " << i * j << endl;
//		++j;	
//
//		if (9 < j)
//		{
//			++i;
//			j = 1;
//			cout << "--------------------------------" << endl;
//		}
//	}
//
//	return 0;
//}

#pragma endregion ������ �����

#pragma region ���Ǳ� ���� �����

//int main()
//{
//	int		iMoney(0), iInput(0), iCoke(100), iCider(200), iFanta(300);
//	bool	bChoice(true);
//
//	cout << "���� �־��ּ��� : ";
//	cin >> iMoney;
//
//	while (bChoice)
//	{
//		system("cls");
//
//		cout << "�ܾ� : " << iMoney << endl;
//		cout << "1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ : ";
//		cin >> iInput;
//
//#pragma region if�� �ۼ� ��
//		/*if (1 == iInput)
//		{
//			if (iMoney >= iCoke)
//			{
//				cout << "�ݶ� ���� �Ϸ�" << endl;
//				iMoney -= iCoke;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//		}
//
//		else if (2 == iInput)
//		{
//			if (iMoney >= iCider)
//			{
//				cout << "���̴� ���� �Ϸ�" << endl;
//				iMoney -= iCider;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//		}
//
//		else if (3 == iInput)
//		{
//			if (iMoney >= iFanta)
//			{
//				cout << "ȯŸ ���� �Ϸ�" << endl;
//				iMoney -= iFanta;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//		}
//
//		else if (4 == iInput)
//		{
//			cout << "�ܾ��� " << iMoney << " �� �Դϴ�" << endl;
//			bChoice = false;
//		}
//
//		else
//		{
//			cout << "�߸� �����̽��ϴ�" << endl;
//		}*/
//#pragma endregion if�� �ۼ� ��
//
//		switch (iInput)
//		{
//		case 1:
//			if (iMoney >= iCoke)
//			{
//				cout << "�ݶ� ���� �Ϸ�" << endl;
//				iMoney -= iCoke;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//			break;
//
//		case 2:
//			if (iMoney >= iCider)
//			{
//				cout << "���̴� ���� �Ϸ�" << endl;
//				iMoney -= iCider;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//			break;
//
//		case 3:
//			if (iMoney >= iFanta)
//			{
//				cout << "ȯŸ ���� �Ϸ�" << endl;
//				iMoney -= iFanta;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//			break;
//
//		case 4:
//			cout << "�ܾ��� " << iMoney << " �� �Դϴ�" << endl;
//			bChoice = false;
//			break;
//
//		default:
//			cout << "�߸� �����̽��ϴ�" << endl;
//			break;
//		}	
//
//		system("pause");
//	}
//
//	return 0;
//}

#pragma endregion ���Ǳ� ���� �����

#pragma region Ȧ¦ ���� �����

//int main()
//{
//	int		iAnswer(0), iInput(0), iRound(5), iWin(0), iLose(0);
//	bool	bChoice(true);
//
//	srand(unsigned(time(NULL)));
//
//	while ((0 < iRound) && bChoice)
//	{
//		system("cls");
//
//		iAnswer = (rand() % 10) + 1;
//
//		cout << "���� : " << iAnswer << endl;
//
//		cout << iRound << " ȸ ���ҽ��ϴ�" << endl;
//		cout << "1. Ȧ�� 2. ¦�� 3. ���� : ";
//		cin >> iInput;
//		--iRound;
//
//		if (1 == iInput)
//		{
//			if (0 != iAnswer % 2)
//			{
//				cout << "��ǻ�� : Ȧ" << endl;
//				cout << "����� : Ȧ" << endl;
//				cout << "����" << endl;
//				++iWin;
//			}
//			else
//			{
//				cout << "��ǻ�� : ¦" << endl;
//				cout << "����� : Ȧ" << endl;
//				cout << "����" << endl;
//				++iLose;
//			}
//		}
//
//		else if (2 == iInput)
//		{
//			if (0 != iAnswer % 2)
//			{
//				cout << "��ǻ�� : Ȧ" << endl;
//				cout << "����� : ¦" << endl;
//				cout << "����" << endl;
//				++iLose;
//			}
//			else
//			{
//				cout << "��ǻ�� : ¦" << endl;
//				cout << "����� : ¦" << endl;
//				cout << "����" << endl;
//				++iWin;
//			}
//		}
//
//		else if (3 == iInput)
//		{
//			cout << "������ �����մϴ�" << endl;
//			bChoice = false;
//		}
//		else
//		{
//			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
//			++iRound;
//		}
//
//		system("pause");
//	}
//
//	system("cls");
//	cout << "�� : " << iWin << "\t�� : " << iLose << endl;
//	system("pause");
//
//	return 0;
//}

#pragma endregion Ȧ¦ ���� �����



//1. 2�� for���� �̿��Ͽ� ������ 2~9�ܱ��� ����ϱ�
//
//- �ܰ� ���� �Է� �޾ƶ�.
//
//ex) 5��, 4��
//
//2 * 1 = 2
//2 * 2 = 4
//2 * 3 = 6
//2 * 4 = 8
//
//3 * 1 = 2
//3 * 2 = 4
//3 * 3 = 6
//3 * 4 = 8
//
//4 * 1 = 2
//4 * 2 = 4
//4 * 3 = 6
//4 * 4 = 8
//
//5 * 1 = 2
//5 * 2 = 4
//5 * 3 = 6
//5 * 4 = 8
//
//2. ���� ���� �� ���� �����
//
//- ������ �̾Ƽ� 0~2�� ���ڸ� �����.(��ǻ���� ���� ���� �� ���� �ش�)
//- 1. ���� 2. ���� 3. �� 4. ����
//- ����ڰ� �Է��� ���� ������ ���� �߻��� ���� ���� ���� ���Ͽ� ��, ��, �и� ���
//- �� 5���� ���� ��, ������ ���� ���� �� �� �� �� �� �� �и� ���

/*
3. 2�� for���� �̿��� �����

*
**
***
****
*****

*****
 ****
  ***
   **
    *

	* 
   ** 
  ***
 ****
*****

*****
****
***
**
*

*/