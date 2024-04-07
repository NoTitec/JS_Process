#pragma once
class Student
{
public:
	void Print_Name_Score();
public:
	void Set_Score(int score);
	int Get_Score();
	void Set_Name(const char* szname);
	const char* Get_Name();
private:
	char szName[20];
	int m_iscore;
};

