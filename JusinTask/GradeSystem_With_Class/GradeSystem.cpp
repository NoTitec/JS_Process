#include "stdafx.h"
#include "Student.h"
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif
// ����ǥ ���α׷��� Ŭ������ ����� ���� �迭�� �����϶�

//- �Է��� ������ �� ���� �Է��� �� ���� �Է��� ����
//- ����� ������ ���
//- �Է��� �ٽ� ������ �߰� �Է��� �ǵ��� ���� ��
void ExtendArr(Student**arrAdress,int CurArraySize,int AdditinalSpace) {
	Student* temp = new Student[CurArraySize+AdditinalSpace];
	memcpy(temp, *arrAdress, sizeof(Student)*CurArraySize);
	delete[](*arrAdress);
	*arrAdress = temp;
	temp = NULL;
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int ilength(0);
	int inewlength(0);

	Student* Students = nullptr;

	bool bEnd(false);
	while (!bEnd)
	{
		int iInput(0);
		cout << "1. �Է� 2. ��� 3. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			cout << "�� �� �߰�?" << endl;
			cin >> inewlength;
			if (nullptr == Students) {
				Students = new Student[inewlength];
				for (int i = 0; i < inewlength; i++)
				{
					cout << "�̸� �Է� : ";
					char szTemp[20];
					cin >> szTemp;
					Students[i].Set_Name(szTemp);
					cout << "���� �Է� : ";
					int iTemp;
					cin >> iTemp;
					Students[i].Set_Score(iTemp);
				}
				ilength = inewlength;
			}
			else
			{
				ExtendArr(&Students, ilength,inewlength);
				for (int i = ilength; i < ilength + inewlength; i++)
				{
					cout << "�̸� �Է� : ";
					char szTemp[20];
					cin >> szTemp;
					Students[i].Set_Name(szTemp);
					cout << "���� �Է� : ";
					int iTemp;
					cin >> iTemp;
					Students[i].Set_Score(iTemp);
				}
				ilength += inewlength;
			}
			break;

		case 2:
			for (int i = 0; i < ilength; i++)
			{
				cout << i + 1 << "��° �л�" << endl;
				cout << Students[i].Get_Name()<<" ";
				cout << Students[i].Get_Score() << endl;
			}
			break;

		case 3:
			bEnd = true;
			break;
		default:

			break;
		}
	}

	delete[](Students);
	Students = nullptr;
	return 0;
}