#include "stdafx.h"
#include "Mystring.h"
int main()
{
	Mystring a("aaa");
	Mystring b("bbb");
	a = a + b;
	a.PrintN();
	//Mystring c("aaa");
	/*if (!(a == b))
		cout << "����ġ�� false���ϵ�";
	if (a == c)
		cout << "��ġ";*/
	
	return 0;
}