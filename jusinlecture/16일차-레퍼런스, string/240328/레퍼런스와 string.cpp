#include "stdafx.h"

void	Swap(int& a, int& b)
{
	int c = 0;

	c = a; 
	a = b;
	b = c;
}

#pragma region ���۷���
//int main()
//{
//	// ���۷��� �ڷ��� : L-Value�� ������ ����
//
//	// ������   : ���� ����
//	// ���۷���  : ���� ����
//
//
//	// int		iData = 10;
//	// 
//	// int		iSrc = iData;
//	// 
//	// int&	r  = iData;
//	// 
//	// const int&	r2 = 10;	// �б� �������� ����
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
//	// int&	r = iData;		// ����� ���ÿ� �ʱ�ȭ ���·� ������ ���� ������ ������ ���۷���
//	// 
//	// r = 30;
//	// 
//	// cout << iData << endl;
//	// 
//	// int	iSrc(400);
//	// 
//	// r = iSrc;		// ���۷����� ����ó�� ������ ����� �ٲ� �� ����.
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

#pragma endregion ���۷���

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

