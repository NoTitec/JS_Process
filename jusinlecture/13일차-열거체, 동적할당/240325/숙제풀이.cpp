#include <iostream>

using namespace std;

#pragma region ����ǥ �����

////�л� ���� ����ü ����
//typedef struct tagInfo
//{
//	char szName[32];
//	int	 iKor;
//	int  iEng;
//	int  iMath;
//	int  iTotal;
//	float fAver;
//
//}INFO;
//
//// �迭 ������, �迭 ���� ��
//void	Input_Data(INFO _tStudent[], int _iCount);
//void	Output_Data(INFO _tStudent[], int _iCount);
//void	Search_Data(INFO _tStudent[], int _iCount);
//
//int main()
//{
//	//�л� 3�� ���� ������ �л� ����ü �迭
//	INFO	tStudent[3] = {};
//	int iInput(0);
//
//	while (true)
//	{
//		system("cls");
//
//		cout << "1. �Է� 2. ��� 3. �˻� 4. ���� : ";
//		cin >> iInput;
//
//#pragma region ����
//		/*switch (iInput)
//		{
//		case 1:
//			Input_Data(tStudent, sizeof(tStudent) / sizeof(INFO));
//			break;
//
//		case 2:
//			Output_Data(tStudent, sizeof(tStudent) / sizeof(INFO));
//			break;
//
//		case 3:
//			Search_Data(tStudent, sizeof(tStudent) / sizeof(INFO));
//			break;
//
//		case 4:
//			return 0;
//		}*/
//#pragma endregion ����
//
//		//�Լ� ������ �迭
//		void(*pFunc[3])(INFO*, int) = { Input_Data, Output_Data, Search_Data };
//
//		if (4 == iInput)
//			return 0 ;
//
//		pFunc[iInput - 1](tStudent, 3);		
//
//		system("pause");
//	}
//	
//	return 0;
//}
//
//void	Input_Data(INFO _tStudent[], int _iCount)
//{
//	for (int i = 0; i < _iCount; ++i)
//	{
//		cout << "�̸� �Է� : ";
//		cin >> _tStudent[i].szName;
//
//		cout << "���� �Է� : ";
//		cin >> _tStudent[i].iKor;
//		
//		cout << "���� �Է� : ";
//		cin >> _tStudent[i].iEng;
//
//		cout << "���� �Է� : ";
//		cin >> _tStudent[i].iMath;
//
//		_tStudent[i].iTotal = _tStudent[i].iKor + _tStudent[i].iEng + _tStudent[i].iMath;
//		_tStudent[i].fAver = _tStudent[i].iTotal / 3.f;
//	}
//}
//
//void Output_Data(INFO _tStudent[], int _iCount)
//{
//	for (int i = 0; i < _iCount; ++i)
//	{
//		cout << "--------------------------------" << endl;
//		cout << "�̸� : " << _tStudent[i].szName << endl;
//		cout << "���� : " << _tStudent[i].iKor << endl;
//		cout << "���� : " << _tStudent[i].iEng << endl;
//		cout << "���� : " << _tStudent[i].iMath << endl;
//		cout << "���� : " << _tStudent[i].iTotal << endl;
//		cout << "��� : " << _tStudent[i].fAver << endl;
//	}
//}
//
//void Search_Data(INFO _tStudent[], int _iCount)
//{
//	char	szFindName[32] = "";
//
//	cout << "�̸��� �Է��ϼ��� : ";
//	cin >> szFindName;
//
//	for (int i = 0; i < _iCount; ++i)
//	{
//		if (!strcmp(szFindName, _tStudent[i].szName))
//		{
//			cout << "--------------------------------" << endl;
//			cout << "�̸� : " << _tStudent[i].szName << endl;
//			cout << "���� : " << _tStudent[i].iKor << endl;
//			cout << "���� : " << _tStudent[i].iEng << endl;
//			cout << "���� : " << _tStudent[i].iMath << endl;
//			cout << "���� : " << _tStudent[i].iTotal << endl;
//			cout << "��� : " << _tStudent[i].fAver << endl;
//			system("pause");
//			return;
//		}
//	}
//
//	cout << "�˻��� �̸��� �����ϴ�. �̸��� ������ �����ϴ�" << endl;
//
//	for (int i = 0; i < _iCount; ++i)
//		cout << "�̸� : " << _tStudent[i].szName << endl;
//}

#pragma endregion ����ǥ �����

#pragma region TextRPG

//����ü ����
typedef struct tagInfo
{
	char	szName[32];
	int		iAttack;
	int		iHp;

}INFO;

//������ ������ �÷��̾� �ν��Ͻ� �����Լ�
INFO		Select_Job();
//����ü ���� ��� �Լ�
void		Render(INFO* pInfo);
//����� �ʱ�ȭ
void		Field(INFO* pPlayer);
//���� ����
void		Create_Monster(INFO tMonster[], int iCount);
//����
void		Fight(INFO* pPlayer, INFO* pMonster);

int main()
{
	INFO	tPlayer = {};

	tPlayer = Select_Job();

	int		iInput(0);

	while (true)
	{
		system("cls");
		Render(&tPlayer);

		cout << "1. ����� 2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Field(&tPlayer);
			break;

		case 2:
			return 0;
		}
	}

	return 0;
}

INFO		Select_Job()
{
	INFO	tTemp = {};
	int		iInput(0);

	cout << "������ �����ϼ���(1. ���� 2. ������ 3 ����) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "����");
		tTemp.iAttack = 10;
		tTemp.iHp = 100;
		break;

	case 2:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "������");
		tTemp.iAttack = 10;
		tTemp.iHp = 100;
		break;

	case 3:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "����");
		tTemp.iAttack = 10;
		tTemp.iHp = 100;
		break;
	}

	return tTemp;
}

void		Render(INFO* pInfo)
{
	cout << "----------------------------------------" << endl;
	cout << "�̸� : " << pInfo->szName << endl;
	cout << "ü�� : " << pInfo->iHp << "\t���ݷ� : " << pInfo->iAttack << endl;
}

void		Field(INFO* pPlayer)
{
	int			iInput(0);
	//����ͼ� ���� ������ ���� �迭
	INFO		tMonster[3];

	while (true)
	{
		system("cls");
		Render(pPlayer);

		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		cin >> iInput;

		if (4 == iInput)
			return;

		//int		iArray[3];
		//sizeof(iArray)	-> 12byte		/ 4byte ->	3
		// iArray == &iArray[0]

		else if (3 >= iInput)
		{
			Create_Monster(tMonster, sizeof(tMonster) / sizeof(INFO));
			Fight(pPlayer, &tMonster[iInput- 1]);
		}
	}
}

void		Create_Monster(INFO tMonster[], int iCount)
{
	strcpy_s(tMonster[0].szName, sizeof(tMonster[0].szName), "�ʱ�");
	strcpy_s(tMonster[1].szName, sizeof(tMonster[1].szName), "�߱�");
	strcpy_s(tMonster[2].szName, sizeof(tMonster[2].szName), "���");

	for (int i = 0; i < iCount; ++i)
	{
		tMonster[i].iHp = (i + 1) * 30;
		tMonster[i].iAttack = (i + 1) * 3;
	}
}
void		Fight(INFO* pPlayer, INFO* pMonster)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		Render(pPlayer);
		Render(pMonster);

		cout << "1. ���� 2. ���� : ";
		cin >> iInput;

		if (1 == iInput)
		{
			pMonster->iHp -= pPlayer->iAttack;
			pPlayer->iHp -= pMonster->iAttack;

			if (0 >= pPlayer->iHp)
			{
				cout << "�÷��̾� ���" << endl;
				pPlayer->iHp = 100;
				system("pause");
				return;
			}

			if (0 >= pMonster->iHp)
			{
				cout << "�¸�" << endl;
				system("pause");
				return;
			}
		}

		else if (2 == iInput)
			return;
	}

}

#pragma endregion TextRPG

