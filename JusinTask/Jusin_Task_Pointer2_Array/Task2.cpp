#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
// 2. �ζ� �����
// - �迭�� �̿��Ͽ� 1~45������ ���� �� �������� 6���� �̴´�.
// - �� 5ȸ �з��� ����Ѵ�.
// - ���� ȸ�� ������ �ߺ��� ���ڴ� ������ �� ����.
// - ���� ������ �̿��Ͽ� �������� ������ �϶�.(�����ڸ�)
/*
1	2	3	4	5	6
1	2	3	4	5	6
1	2	3	4	5	6
1	2	3	4	5	6
1	2	3	4	5	6
*/

void Set_Random_Number_Seed();
int Get_1_45_Random_Number();
void bubble_sort(int iArr[], int iArrSize);

int main()
{
	//���� �ѹ� �õ尪 ����
	Set_Random_Number_Seed();
	//6������ ���� ������ ũ�� 6�� �迭
	int iArray[6] = {};

	//5ȸ �ݺ��̹Ƿ� for�� 5�� ������
	for (int i = 0; i < 5; i++) 
	{
		//�迭�� �ߺ��ƴ� ���� ��
		int iCount(1);
		//�ݺ��� ���� ����
		bool bEnd(true);
		//ù��° ������ ������ �ߺ� �ƴϹǷ� iCount =1, �迭 ù��° ���Ҵ� ó������ ������ �ֱ�
		
		iArray[0] = Get_1_45_Random_Number();

		//���� 6���� ä���������� �ݺ�
		while (bEnd)
		{
			//������ ������ ���� �迭�� �ߺ��ִ��� �����ϴ� ����
			bool bduplication(false);
			//������ 1�� �̱�
			int Tmp = Get_1_45_Random_Number();
			//--���ݱ��� �迭�� ä�� �� ��ŭ�� �迭 ��ġ �˻��ϸ鼭 �ߺ� ���ִ��� �˻�
			for (int j = 0; j < iCount; j++)
			{
				//--�ߺ����� ����Ǹ� ����� �ߺ�Ȯ�� ���� true �����ϰ� �ش� �ݺ��� Ż��
				if (Tmp == iArray[j])
				{
					bduplication = true;
					break;
				}
			}
			//--�ߺ��� ������ �迭 �� ��ġ�� ���� �� �־��ְ� iCount++
			if (!bduplication)
			{
				iArray[iCount] = Tmp;
				++iCount;
			}
			//�迭 6���� ���ä������ �ݺ��� ����
			if (iCount == 6)
			{
				bEnd = false;
			}
		}
		//��������
		
		bubble_sort(iArray, iCount);
		//6�� ��� ä���� �迭 ��¹�
		for (int j = 0; j < 6; j++)
		{
			cout << setw(3) << iArray[j];
		}
		cout << endl;
	}
	//�ݺ��� �ȿ��� �� task
	// 
	// ���� 6���� ä���� ������ �ݺ��ؾ���(while)
	//--1~45 ������ �ѹ� �̱�
	//--ù��° ������ �ٷ� �迭 ����
	//--�׿� ��� ���ݱ��� ���� �� ��ŭ�� �迭 ��ġ �˻��ϸ鼭 �ߺ� ���ִ��� �˻�
	//--�ߺ��� ���°�� ���� ��ġ�� ���� �� �־��ְ�
	//--�ߺ����� ����Ǹ� �ٽ� �̰� �˻�, ���Խõ�
	//--�迭 6���� ��� ä������ �ݺ� ���� 
	//--�������� ���� �� ���
	return 0;
}

void Set_Random_Number_Seed()
{
	srand(unsigned(time(NULL)));
}

int Get_1_45_Random_Number()
{
	int iRandNumber = rand() % 45 + 1;
	return iRandNumber;
}

void bubble_sort(int iArr[], int iArrSize)
{
	int Tmp(0);
	//�ѹ��� 1���� ���ĵǹǷ� ���ĿϷ���� ���Ұ� n����� n-1�� ���İ��� �ʿ�
	for (int i = 0; i < iArrSize-1; i++)
	{
		//�� ���ĸ��� �񱳴� n-1,n-2,n-3 ��ŭ �񱳿����ʿ��ϹǷ� �ݺ��� 1���� �ѹ��� �񱳸� ���ϰԵ�
		//���帶�� ���ĵ� ���� �������� �� swap����
		for (int j = 0; j < iArrSize - i - 1; j++)
		{
			//ū���� �������̵�
			if (iArr[j] > iArr[j + 1])
			{
				Tmp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = Tmp;
			}
		}
	}
}