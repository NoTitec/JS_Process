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
// 성적표 프로그램을 클래스로 만들고 동적 배열을 구현하라

//- 입력을 누르면 몇 명을 입력할 지 묻고 입력을 받음
//- 출력을 누르면 출력
//- 입력을 다시 누르면 추가 입력이 되도록 만들 것
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
		cout << "1. 입력 2. 출력 3. 종료" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			cout << "몇 명 추가?" << endl;
			cin >> inewlength;
			if (nullptr == Students) {
				Students = new Student[inewlength];
				for (int i = 0; i < inewlength; i++)
				{
					cout << "이름 입력 : ";
					char szTemp[20];
					cin >> szTemp;
					Students[i].Set_Name(szTemp);
					cout << "점수 입력 : ";
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
					cout << "이름 입력 : ";
					char szTemp[20];
					cin >> szTemp;
					Students[i].Set_Name(szTemp);
					cout << "점수 입력 : ";
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
				cout << i + 1 << "번째 학생" << endl;
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