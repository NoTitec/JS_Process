#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//��Ʈ����ũ Ƚ�� ���� ����
int iStrike(0);
//�� Ƚ�� ���� ����
int iBol(0);
//���� ���� 3�� ���� �迭
int iRandomArray[3] = {8,7,7};

//����� �Է� ���� 3�� ���� �迭
int iInputarray[3] = {};

//�õ尪 �ʱ�ȭ �Լ�
void Set_Random_Number_Seed();
//1~9 ������ �̾Ƴ��� �Լ�
int Get_1_9_Random_Number();
//�迭 ���� ����ϴ� �Լ�
void Print_Array(int iArray[], int iArraySize);
//������ �迭ũ�⸸ŭ �����ؼ� ��� �Լ�
void Fill_3_Random_Number_To_Array(int iArray[], int iArraySize);
//���� ���� �Է¹޾Ƽ� iInputArray�� ��� �Լ�
void Get_Input_For_iArray(int iArray[], int iArraySize);
//�� ���(�¸��� true ��ȯ)
bool Compare_Two_iArray_Is_Equal(int iRandomArray[], int iInputArray[], int* pBol, int* pStrike, int* i);
//�ִ� 9���� �¸����� : ��Ʈ����ũ �� �¸�, �й�����: 9���� �� �������� ��Ʈ����ũ 3ȸ ���� ���Ѱ��


int main()
{
	//�õ尪 ����
	Set_Random_Number_Seed();
	//������ ���� 3�� �̾� �������� �迭 ���
	//Fill_3_Random_Number_To_Array(iRandomArray, 3);
	//��Ʈ����ũ 3ȸ�� �Ǹ� ���� ����
	for (int i = 0; i < 9; i++)
	{
		cout << "���� : ";
		Print_Array(iRandomArray, 3);
		cout << endl;
		//���� 3�� �Է¹޾� �Է� �迭 ���
		Get_Input_For_iArray(iInputarray, 3);
		//�����迭, �Է� �迭 ���Ͽ� �Ǻ��ϰ� ��� ���
		//��Ʈ����ũ�� �¸�
		if (Compare_Two_iArray_Is_Equal(iRandomArray, iInputarray, &iBol, &iStrike, &i))
		{
			cout << "��Ʈ����ũ~";
			return 0;
		}
	}
	//9���� �ٵ������� �¸� ���Ѱ�� �й�
	cout << "Lose~" << endl;
	return 0;
}
void Set_Random_Number_Seed()
{
	srand(unsigned(time(NULL)));
}
//1~9 ������ �̾Ƴ��� �Լ�
int Get_1_9_Random_Number()
{
	int iRandomNumber = rand() % 9 + 1;
	return iRandomNumber;
}
//�迭 ���� ����ϴ� �Լ�
void Print_Array(int iArray[], int iArraySize)
{
	for (int i = 0; i < iArraySize; i++)
	{
		cout << setw(2) << iArray[i];
	}
}
//������ �迭ũ�⸸ŭ �����ؼ� ��� �Լ�
void Fill_3_Random_Number_To_Array(int iArray[], int iArraySize)
{
	for (int i = 0; i < iArraySize; i++)
	{
		iArray[i] = Get_1_9_Random_Number();
	}
}
//�迭ũ�⸸ŭ �Է¹޾Ƽ� �迭�� ��� �Լ�
void Get_Input_For_iArray(int iArray[], int iArraySize)
{
	cout << "���� �Է� : ";
	for (int i = 0; i < iArraySize; i++)
	{
		cin >> iArray[i];
	}
}
//����: ���� �迭, �Է� �迭, �� int ������ , ��Ʈ����ũ int ������, ���� ������
bool Compare_Two_iArray_Is_Equal(int iRandomArray[], int iInputArray[], int* pBol, int* pStrike, int* i)
{
	*pBol = 0;
	*pStrike = 0;

	//�̹� �Ǻ��� ���ڴ� ����
	bool bmatchedRandomArray[3] = { false };
	bool bmatchedInputArray[3] = { false };
	//��, ��ġ ��� ���� ��� ���
	for (int i = 0; i < 3; i++)
	{
		if (iRandomArray[i] == iInputArray[i])
		{
			*pStrike += 1;
			bmatchedRandomArray[i] = true;
			bmatchedInputArray[i] = true;
		}
	}
	//��Ʈ����ũ�� true��ȯ �� ����
	if (*pStrike == 3)
	{
		return true;
	}
	//��Ʈ����ũ�� �ƴϸ� ���� ȸ����, �� ��Ʈ����ũ �� ������ ����ϰ� �Լ� ����
	// ���� ������ ��ġ�� �ٸ� ����� ���� ���
	//�Է��� ���ڿ� ��µ� ���ڰ� ���� ������ ��
	for (int i = 0; i < 3; i++)
	{
		//��Ī�� �ȵ� �ε����϶��� Ž��
		if (!bmatchedRandomArray[i])
		{
			for (int j = 0; j < 3; j++)
			{
				if (!bmatchedRandomArray[i]&&!bmatchedInputArray[j])
				{
					//���� ���� �ε��� ��ġ�� �ٸ����
					if (iRandomArray[i] == iInputArray[j] && i != j)
					{
						*pBol += 1;
						bmatchedRandomArray[i] = true;
						bmatchedInputArray[j] = true;
						break;
					}
				}
			}
		}
	}
	cout << *i + 1 << "ȸ : ";
	Print_Array(iInputArray, 3);
	cout << " " << *pStrike << "��Ʈ����ũ" << *pBol << "��" << endl;
	return false;
}

// 3. �߱� ���� �����
/*
- 1~9������ ���� �� �������� 3���� ��󳻾� ȭ�鿡 ����Ѵ�(�������� ����)
- ���� �� ���� �Է¹޴´�.
- �Է��� ���ڿ� ��µ� ���ڰ� ���� �ڸ��� ������ ��Ʈ����ũ, ���� ������ ��
//a1[ 1, 2, 2] a2[2,2,1]
- �� ȸ �Է� ��, �� ��Ʈ����ũ �� ������ ���
- 3 ��Ʈ����ũ�� �¸� ��� �� ����
- 9ȸ���� 3 ��Ʈ����ũ�� ������ ���ϸ� �й�

���� : 8	 1	5
1ȸ :  1  2  3	 0 ��Ʈ����ũ 1��
2ȸ :  1  8  5	 1 ��Ʈ����ũ 2��
3ȸ :  8  1  5   3 ��Ʈ����ũ 0��
*/