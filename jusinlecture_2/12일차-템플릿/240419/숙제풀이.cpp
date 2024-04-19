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

#pragma region cout의 생성 예

//#include <stdio.h>
//
//namespace MyStd
//{
//	class Ostream
//	{
//	public:
//		Ostream&	operator <<(int _iData)
//		{
//			printf("%d", _iData);
//
//			return *this;
//		}
//
//		Ostream&	operator <<(char* pData)
//		{
//			printf("%s", pData);
//			return *this;
//		}
//	};
//
//	Ostream		COUT;
//	char*		ENDL = "\n";
//}
//
//using namespace MyStd;
//
//
//int main()
//{
//	COUT << 100 << ENDL;
//
//	return 0;
//}

#pragma endregion cout의 생성 예


