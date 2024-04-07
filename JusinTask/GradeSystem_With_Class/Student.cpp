#include "Student.h"
#include "stdafx.h"

void Student::Print_Name_Score()
{
	cout << "이름 : " << szName<<" ";
	cout << "점수 : " << m_iscore<<endl;
}

void Student::Set_Score(int score)
{
	m_iscore = score;
}

int Student::Get_Score()
{
	return m_iscore;
}

void Student::Set_Name(const char* szname)
{
	//cin >> szName;
	strcpy_s(szName, sizeof(szName), szname);
}

const char* Student::Get_Name()
{
	return szName;
}
