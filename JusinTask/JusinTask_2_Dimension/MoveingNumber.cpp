#include<iostream>
#include<iomanip>
using namespace std;
// 2. ����(0) �̵� ��Ű��

/*
- 0~24���� 5 * 5�迭 ���·� ���
- 2. �Ʒ� 4. ���� 6. ������ 8. ��
- ��ȣ�� ������ ��� ���� 0�� ��ġ�� �̵�

0	1	2		1	0	2		1	4	2
3	4	5	-6>	3	4	5 -2>	3	0	5
6	7	8		6	7	8		6	7	8
*/

//����-----------------------------
// 
//1. 5*5 ũ�� �� ����
// 1-1 �ʿ� 2���� �迭 �ʿ�
// 
//2. ������ġ 0,0
// 2-1 ��ġ����� �迭 �ʿ�
// 
//3. �����¿� �̵� �迭����
// 3-1 �����¿� �̵����� �迭 �ʿ�
// 3-2. ��ư������ �̵����� ���� �迭 �ʿ�
// 
//4. ��ư ������ �ϴ� �� ���� �ȹ������ üũ
// 
//5. �� ������ ����� ������ �̵��Ϸ��� ��ǥ���� ����ġ���� swap
// 
//6. -1�� �Է��ϸ� ������ ����ǵ���

//�Լ�
// ���� �� ����ϴ� �Լ�
void Print_Current_Map(int(*Array)[5]);

// �̵��Ϸ��� ��ġ�� �� ������� üũ�ϴ� �Լ�
bool Is_Move_Location_Valid(int*x,int*y);



// ��!!
int iMap[5][5] = {};
// ���� ��ǥ ������ �迭
int iLocationArray[2] = {};
//�� ���� �迭
int dx[4] = { 0, 0, -1, 1 }; // ��, ��, ��, ��
int dy[4] = { -1, 1, 0, 0 }; // ��, ��, ��, ��

//���� �迭
int directions[4] = { 0,1,2,3 }; //��, ��, ��, ��

//���� �������� bool ����
bool bEnd(true);

int main()
{
	//�� �ʱ�ȭ�� for��
	for (int i = 0; i < 5; i++)
	{
		for(int j=0;j<5;j++)
		{ 
			iMap[i][j] = i * 5 + j;
		}
	}
	//�ʱ� ���� ���
	Print_Current_Map(iMap);

	//����� �Է� ���� ����
	int iInput(0);

	//-1�� �Է����� �ʴ� �� ������ �̵� �����ϴ� while��
	while (bEnd)
	{
		//�̵��Ϸ��� ��ǥ ������ ����
		int nx(0);
		int ny(0);
		int dd(0);
		//������� ���� �Է�
		cout << "�����ϰ����ϴ� ������ ���� (����� -1)" << endl;
		cout << "2. �Ʒ� 4. ���� 6. ������ 8. ��" << endl;
		cin >> iInput;

		//�̵��Ϸ��� ��ǥ ���
		switch (iInput)
		{
			//��
		case 8:
			dd = directions[0];
			//�̵��Ϸ��� ��ǥ
			nx=iLocationArray[0] + dx[dd];
			ny=iLocationArray[1] + dy[dd];
			//�̵��Ϸ��� ��ǥ�� ��ȿ�� ��ġ�� �̵�
			if (Is_Move_Location_Valid(&nx,&ny))
			{
				swap(iMap[ny][nx],iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] = nx;
				iLocationArray[1] = ny;
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "�� ���� ���" << endl;
			}
			break;
			//��
		case 2:
			dd = directions[1];
			//�̵��Ϸ��� ��ǥ
			nx = iLocationArray[0] + dx[dd];
			ny = iLocationArray[1] + dy[dd];
			//�̵��Ϸ��� ��ǥ�� ��ȿ�� ��ġ�� �̵�
			if (Is_Move_Location_Valid(&nx, &ny))
			{
				swap(iMap[ny][nx], iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] = nx;
				iLocationArray[1] = ny;
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "�� ���� ���" << endl;
			}
			break;
			//��
		case 4:
			dd = directions[2];
			//�̵��Ϸ��� ��ǥ
			nx = iLocationArray[0] + dx[dd];
			ny = iLocationArray[1] + dy[dd];
			//�̵��Ϸ��� ��ǥ�� ��ȿ�� ��ġ�� �̵�
			if (Is_Move_Location_Valid(&nx, &ny))
			{
				swap(iMap[ny][nx], iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] = nx;
				iLocationArray[1] = ny;
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "�� ���� ���" << endl;
			}
			break;
			//��
		case 6:
			dd = directions[3];
			//�̵��Ϸ��� ��ǥ
			nx = iLocationArray[0] + dx[dd];
			ny = iLocationArray[1] + dy[dd];
			//�̵��Ϸ��� ��ǥ�� ��ȿ�� ��ġ�� �̵�
			if (Is_Move_Location_Valid(&nx, &ny))
			{
				swap(iMap[ny][nx], iMap[iLocationArray[1]][iLocationArray[0]]);
				iLocationArray[0] += dx[dd];
				iLocationArray[1] += dy[dd];
				Print_Current_Map(iMap);
			}
			else
			{
				cout << "�� ���� ���" << endl;
			}
			break;
			//����
		case -1:
			bEnd = false;
			break;
			//��Ÿ�Է�
		default:
			cout << "�߸��� �Է��Դϴ�";
			break;
		}
	}
	return 0;
}

//���ڷ� ���� 5*5�迭�� ���� ���ڰ� ������ִ� �Լ�
void Print_Current_Map(int(*Array)[5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout <<setw(3)<< Array[i][j];
		}
		cout << endl;
	}
	cout << "-------------------" << endl;
}

bool Is_Move_Location_Valid(int* x, int* y)
{
	//x��ǥ�� �� ������ ����� ���
	if (*x < 0 || *x >= 5)
	{
		return false;
	}
	//y��ǥ�� �� ������ ����� ���
	if (*y < 0 || *y >= 5)
	{
		return false;
	}
	return true;
}
