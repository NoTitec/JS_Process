#include <iostream>
// #include <time.h>
#include <ctime>

using namespace std;

// ��� c++ ���Ŀ� ������ typedef ��ü ����
using BOOL = int;

int main()
{

#pragma region while

	//int		iNumber(3);

	//while (--iNumber)
	//{
	//	cout << 1 << endl;
	//}



	/*while (true)
	{
		cout << 1 << endl;
		iNumber--;

		if (0 == iNumber)
		{
			break;
		}
	}*/
	
	/*int i(1);

	while (10 > i)
	{
		cout <<	2 << " * " << i << " = " << i * 2 << endl;
		++i;
	}*/

#pragma endregion while

#pragma region do while

	/*do 
	{
		�ڵ� ��

	} while (���ǽ�);*/

	/*int		iNumber(3);

	do 
	{
		cout << 1 << endl;

	} while (--iNumber);*/

	//int		iInput(0), iSum(0);

	//do 
	//{
	//	//iInput �Է�
	//	cin >> iInput;

	//	//2�� ���� �������� 0�� �ƴϸ�
	//	if (0 != iInput % 2)
	//	{
	//		//continue
	//		continue;			// �ݺ��� �ȿ����� ��� ����, �ڵ��� �帧�� �ݺ����� �� ������ �̵�
	//	}
	//	//�������� 0�̸� isum�� �Է°��� iInput�� ������
	//	iSum += iInput;
	//	
	//} //iInput�� -1�� �ƴ��̻� ���ѹݺ�
	//while (-1 != iInput);

	//cout << "�հ� : " << iSum << endl;

#pragma endregion do while

#pragma region for

	//for ( �ʱ�ȭ�� ; ���ǽ� ; ������ )
	//{
	//	�ڵ� ��
	//}

	// c��� ������ for��
	/*int	i = 999;

	for (i = 0; i < 3; i++)
	{
	cout << i << endl;
	}

	cout << i << endl;*/

	// c++������ for��

	/*int	i = 999;

	for (int i = 0; i < 3; ++i)
	{
	cout << i << endl;
	}

	cout << i << endl;*/


	/*for (int i = 0, j = 0; i < 3 && j < 3; ++i, j += 2)
	{
	cout << i << endl;
	}*/

#pragma endregion for

#pragma region ���� for��

//for (int i = 0; i < 2; ++i)
//{
//	cout << 1 << endl;
//
//	for (int j = 0; j < 3; ++j)
//	{
//		cout << 2 << endl;
//	}
//
//	cout << 3 << endl;
//}

#pragma endregion ���� for��

#pragma region ����

	// ���� : ������ ��Ģ�� ���� ������ ��

	// rand �Լ� : 0 ~ 32767 ���� ���̿� �ִ� �������� ���� ����
	// srand�Լ� : ����ǥ�� �������ִ� �Լ�
	// time�Լ� : ���� �ð��� �� ������ ��ȯ�Ͽ� �ҷ����� �Լ�

	//time_t	Time_Dst = 0;
	//// typedef : ������ �����ϴ� �ڷ����� ����ڰ� ���ϴ� �̸��� �ڷ������� ��ü �Ǵ� �߰��Ͽ� ����� ����
	//
	//time(&Time_Dst);

	//cout << Time_Dst << endl;
	
	//�õ尪 ����
	//srand(time(&Time_Dst));

	// //NULL = ���� 0

	//srand(unsigned(time(NULL)));

	//cout << rand() << endl;
	//cout << rand() << endl;
	//cout << rand() << endl;

	// well512 ���� �߻� �˰���

	//int		iInput(0);

	//while (true)
	//{
	//	//���� �ܼ�â ���� �����
	//	system("cls");
	//	
	//	cout << "���ڸ� �Է��ϼ��� : ";
	//	cin >> iInput;

	//	cout << iInput << endl;
	//	//Ű�� ��������� ���α׷��� �Ͻ�����
	//	system("pause");
	//}
#pragma endregion ����

return 0;
}

// 1. while���� �̿��Ͽ� ������ 2~9�ܱ��� ��� ����ϱ�

// 2. ���Ǳ� ����
/*
- �������� �Է¹ް� �׻� �ܾ��� ����Ѵ�
- �޴��� 1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ 
- �ش� ����� �����Ͽ� ���� ��, "xx ���� �Ϸ�"�� ���
- ��, �������� ������ ��� �ܾ��� �����մϴ� ���
- 4���� ������ "�Ž��� ���� <�ܾ�>�Դϴ�" ��� ��, ���α׷� ����
*/

// 3. Ȧ¦ ����

//- �� ���帶�� ������ �̿��Ͽ� ������ ���� ����, ȭ�鿡 ����϶�
//- ������ ������ 1~10 ���� �� �ϳ��� �ݺ��� ������ �߻�
//- 1. Ȧ�� 2. ¦�� 3. ����
//- �� 5���带 �ǽ��ϰ� ������ ����� ������ '�� �� �� ��' ���