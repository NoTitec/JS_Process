#include "stdafx.h"
#include "MyString.h"

#pragma region ���� Ǯ�� ��

int main()
{
	CMyString		Temp("jusin");
	CMyString		Src("_academy");

	CMyString		Dest("jusin");

	// Src = Temp;
	// Src = "hello";

	Temp = Temp + Src;
	// Temp = Temp + "_hello";

	/*if (Temp == "jusin")
		cout << "��ġ" << endl;

	else
		cout << "����ġ" << endl;*/

	cout << Temp.Get_String() << endl;
	//cout << Src.Get_String() << endl;

	return 0;
}
#pragma endregion ���� Ǯ�� ��