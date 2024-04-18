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
		cout << "불일치라 false리턴됨";
	if (a == c)
		cout << "일치";*/
	
	return 0;
}