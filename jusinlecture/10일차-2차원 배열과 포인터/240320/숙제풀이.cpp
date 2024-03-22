#include <iostream>
#include <ctime>

using namespace std;

#pragma region ���� ���

//int main()
//{
//	const int iSize(5);
//
//	int	iArray[iSize * iSize] = {};
//
//	for (int i = 0; i < 25; ++i)
//	{
//		iArray[i] = i + 1;
//	}
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
// //�ʿ��� Ÿ�� ���ο� �ش�
//			int	iIndex = i * 5 + j;
//
//			cout << iArray[iIndex] << "\t";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

#pragma endregion ���� ���

#pragma region �ζ� �����

// int pArray[] : �Լ��� �Ű� ������ �迭�� �̸��� ���� �� ����(int�� �����Ϳ� �����ϰ� ����)
//void		Bubble_Sort(int pArray[], int _iSize);
//
//int main()
//{
//	srand(unsigned(time(NULL)));
//
//	int		iArray[45] = {};
//	int		iLotto[6] = {};
//
//	for (int i = 0; i < 45; ++i)
//		iArray[i] = i + 1;
//
//	int	iDst(0), iSrc(0);
//
//	for (int k = 0; k < 6; ++k)
//	{
//		for (int j = 0; j < 500; ++j)
//		{
//			iDst = rand() % 45;
//			iSrc = rand() % 45;
//
//			swap(iArray[iDst], iArray[iSrc]);
//		}
//		
//		for (int i = 0; i < 6; ++i)
//			iLotto[i] = iArray[i];
//		
//		// sizeof(�迭�� �̸�) : �Ҵ��� ��ü �迭�� ũ�⸦ ���
//
//		//Bubble_Sort(iLotto, sizeof(iLotto) / sizeof(int));
//		Bubble_Sort(iLotto, size(iLotto));
//
//		for (int i = 0; i < 6; ++i)
//			cout << iLotto[i] << "\t";
//
//		cout << endl;
//		cout << "-----------------------------------------------------" << endl;
//	}
//	
//	return 0;
//}
//void		Bubble_Sort(int pArray[], int _iSize)
//{
//	for (int i = 0; i < _iSize; ++i)
//	{
//		for (int j = 0; j < _iSize - 1; ++j)
//		{
//			if (pArray[j] > pArray[j + 1])
//				swap(pArray[j], pArray[j + 1]);
//		}
//	}
//}

#pragma endregion �ζ� �����

#pragma region �߱� ����

//void		Init_BaseBall(int _iArray[], int _iSize);
//int			Strike(int _iAnswer[], int _iInput[], int _iSize);
//int			Ball(int _iAnswer[], int _iInput[], int _iSize);
//
//int main()
//{
//	srand(unsigned(time(NULL)));
//
//	int		iArray[9] = {};
//	int		iAnswer[3] = {};
//	int		iInput[3] = {};
//	int		iCount(0), iStrike(0), iBall(0);
//
//	Init_BaseBall(iArray, sizeof(iArray) / sizeof(int));
//
//	for (int i = 0; i < 3; ++i)
//		iAnswer[i] = iArray[i];
//
//	while (true)
//	{
//		system("cls");
//
//		cout << "------------------------------------------------------" << endl;
//		cout << "���� : " << iAnswer[0] << "\t" << iAnswer[1] << "\t" << iAnswer[2] << endl;
//		cout << "------------------------------------------------------" << endl;
//
//		if (9 <= iCount)
//		{
//			cout << "�й�" << endl;
//			break;
//		}
//
//		cout << iCount + 1 << " ȸ�� �Է� : ";
//		cin >> iInput[0] >> iInput[1] >> iInput[2];
//		iCount++;
//
//		iStrike = Strike(iAnswer, iInput, sizeof(iAnswer) / sizeof(int));
//		iBall = Ball(iAnswer, iInput, sizeof(iAnswer) / sizeof(int)) ;
//
//		cout << iStrike << " ��Ʈ����ũ\t" << iBall << " ��" << endl;
//
//		if (3 == iStrike)
//		{
//			cout << iCount << "ȸ�� �¸�" << endl;
//			break;
//		}
//
//		system("pause");
//	}
//
//
//	return 0;
//}
//void		Init_BaseBall(int _iArray[], int _iSize)
//{
//	for (int i = 0; i < _iSize; ++i)
//		_iArray[i] = i + 1;
//
//	for (int i = 0; i < 100; ++i)
//		swap(_iArray[rand() % 9], _iArray[rand() % 9]);
//
//}
//int			Strike(int _iAnswer[], int _iInput[], int _iSize)
//{
//	int	iStrike(0);
//
//	for (int i = 0; i < _iSize; ++i)
//	{
//		if (_iAnswer[i] == _iInput[i])
//			++iStrike;
//	}
//
//	return iStrike;
//}
//int			Ball(int _iAnswer[], int _iInput[], int _iSize)
//{
//	int	iBall(0);
//
//	for (int i = 0; i < _iSize; ++i)
//	{
//		for (int j = 0; j < _iSize; ++j)
//		{
//			if(i == j)
//				continue;
//
//			if (_iAnswer[i] == _iInput[j])
//				++iBall;
//		}		
//	}
//
//	return iBall;
//}

#pragma endregion �߱� ����

// 1. 5 * 5 �迭�� �̿��Ͽ� ���� ������
// - 1~25���� 5*5 �迭�� �����
// - ���ڸ� �Է� �ް� �Է� ���� ���� ��ġ�� ��ġ�� ���ڸ� *�� ����Ѵ�.
// - * �� �ټ��������� �߻��� ��� ���� ������Ų��.
// - 5 ���� �̻��̸� ����

// 2. ����(0) �̵� ��Ű��

/*
- 0~24���� 5 * 5�迭 ���·� ���
- 2. �Ʒ� 4. ���� 6. ������ 8. ��
- ��ȣ�� ������ ��� ���� 0�� ��ġ�� �̵�

0	1	2		1	0	2		1	4	2
3	4	5	-6>	3	4	5 -2>	3	0	5
6	7	8		6	7	8		6	7	8
*/

// 3. 2���� �迭�� �̿��Ͽ� 90�� ȸ���ϴ� ���� ����ϱ�
/*

1	2	3			7	4	1			9	8	7			3	6	9			1	2	3
4	5	6	-1ȸ��>	8	5	2	-2ȸ��>	6	5	4	-3ȸ��>	2	5	8 -4ȸ��>	4	5	6
7	8	9			9	6	3			3	2	1			1	4	7			7	8	9

*/
