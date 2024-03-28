#include "stdafx.h"

void	Swap(int& a, int& b)
{
	int c = 0;

	c = a; 
	a = b;
	b = c;
}

#pragma region 레퍼런스
//int main()
//{
//	// 레퍼런스 자료형 : L-Value만 참조가 가능
//
//	// 포인터   : 간접 참조
//	// 레퍼런스  : 직접 참조
//
//
//	// int		iData = 10;
//	// 
//	// int		iSrc = iData;
//	// 
//	// int&	r  = iData;
//	// 
//	// const int&	r2 = 10;	// 읽기 전용으로 참조
//	// 
//	// // r2 = 20;
//	// 
//	// cout << r2 << endl;
//
//	// int&	r3 = *(new int);
//	// r3 = 100;
//	// cout << r3 << endl;
//
//
//	//int*	p = &iData;
//
//	// *(&iData) = 20;
//	//*p = 20;
//
//	// int&	r = iData;		// 선언과 동시에 초기화 형태로 참조한 값만 참조가 가능한 레퍼런스
//	// 
//	// r = 30;
//	// 
//	// cout << iData << endl;
//	// 
//	// int	iSrc(400);
//	// 
//	// r = iSrc;		// 레퍼런스는 변수처럼 참조의 대상을 바꿀 수 없다.
//	// 
//	// cout << iData << endl;
//	// 
//	// r = 500;
//	// 
//	// //cout << iSrc << endl;
//	// cout << iData << endl;
//
//	//cout << &iData << endl;
//	//cout << &r << endl;
//	//
//	//cout << sizeof(short&) << endl;
//
//	int	iDst(10), iSrc(20);
//
//	cout << iDst << "\t" << iSrc << endl;
//
//	Swap(iDst, iSrc);
//
//	cout << iDst << "\t" << iSrc << endl;
//
//	return 0;
//}

#pragma endregion 레퍼런스

#pragma region string

int main()
{
	// char	szName[32] = "hello";
	// char	szDst[32] = "";
	// 
	// //szDst = szName;
	// strcpy_s(szDst, sizeof(szDst), szName);
	// //char*	pName = new char[];
	// 
	// //char* pName = "hello world";
	// //cin >> pName;
	// //cout << pName << endl;
	// 
	// string	strName = "hello world";
	// string	strDst = strName;
	// string	strSrc = "_hello everyone";
	// 
	// //cin >> strName;
	// 
	// //strName += strSrc;
	// 
	// if("hello world" == strName)
	// 	cout << strName << endl;
	// 
	// cout << strName.length() << endl;
	// cout << strName.size() << endl;
	// 
	// cout << strDst << endl;


	// char	szName[32] = "jusin";
	// string strName = "hello";
	// 
	// // strName = szName;
	// 
	// //szName = strName;
	// 
	// strcpy_s(szName, sizeof(szName), strName.c_str());
	// 
	// cout << strName << endl;
	// cout << szName << endl;
	
	return 0;
}

#pragma endregion string

