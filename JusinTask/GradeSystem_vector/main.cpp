#include "stdafx.h"
#include "CStudent.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

//�䱸����
//���� 3�� �Է¹ޱ�
//�޴�
//1. �߰��Է� 2. ��� 3. �˻� 4.���� 5.����
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	vector<CStudent> vecStudent;
	vector<CStudent>::iterator Studentiter;
	int iInput(0);
	bool bEnd(false);

	//���� 3�� �Է�
	for (int i = 0; i < 3; ++i)
	{
		CStudent Student;
		cout << "�̸� �Է�:";
		char szTemp[20];
		cin >> szTemp;
		Student.Set_Name(szTemp);
		cout << "���� ���� �Է�:";
		int i_tempmath;
		cin >> i_tempmath;
		Student.Set_MathScore(i_tempmath);
		cout << "���� ���� �Է�:";
		int i_tempenglish;
		cin >> i_tempenglish;
		Student.Set_EnglishScore(i_tempenglish);
		vecStudent.push_back(Student);
	}

	while (!bEnd)
	{
		cout << "1. �߰��Է� 2. ��� 3. �˻� 4.���� 5.����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			int iaddcount;
			cout << "�� �� �߰�?" << endl;
			cin >> iaddcount;
			for (int i = 0; i < iaddcount; ++i)
			{
				CStudent Student;
				cout << "�̸� �Է�:";
				char szTemp[20];
				cin >> szTemp;
				Student.Set_Name(szTemp);
				cout << "���� ���� �Է�:";
				int i_tempmath;
				cin >> i_tempmath;
				Student.Set_MathScore(i_tempmath);
				cout << "���� ���� �Է�:";
				int i_tempenglish;
				cin >> i_tempenglish;
				Student.Set_EnglishScore(i_tempenglish);
				vecStudent.push_back(Student);
			}
			break;
		case 2:
			if (!vecStudent.empty())
			{
				for (size_t i = 0; i < vecStudent.size(); ++i)
				{
					vecStudent[i].Render();
				}
			}
			break;
		case 3:
			cout << "ã������ �л� �̸� �Է� : " << endl;
			char szTemp[20];
			cin >> szTemp;
			if (!vecStudent.empty())
			{
				for (Studentiter = vecStudent.begin(); Studentiter != vecStudent.end(); ++Studentiter)
				{
					if (0==strcmp(szTemp, (*Studentiter).Get_Name()))
					{
						(*Studentiter).Render();
						Studentiter = vecStudent.begin();
						break;
					}
				}
			}
			break;
		case 4:
			cout << "Regist Name at Death Note " << endl;
			char szTemp2[20];
			cin >> szTemp2;

			if (!vecStudent.empty())
			{
				for (Studentiter = vecStudent.begin(); Studentiter != vecStudent.end(); ++Studentiter)
				{
					if (0 == strcmp(szTemp2, (*Studentiter).Get_Name()))
					{
						Studentiter = vecStudent.erase(Studentiter);
						Studentiter = vecStudent.begin();
						break;
					}
				}
			}
			break;
		case 5:
			bEnd = true;
			break;
		}
	}
	return 0;
}