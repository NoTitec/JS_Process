#include "stdafx.h"
#include "MyString.h"

#pragma region 숙제 풀이 예

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
		cout << "일치" << endl;

	else
		cout << "불일치" << endl;*/

	cout << Temp.Get_String() << endl;
	//cout << Src.Get_String() << endl;

	return 0;
}
#pragma endregion 숙제 풀이 예