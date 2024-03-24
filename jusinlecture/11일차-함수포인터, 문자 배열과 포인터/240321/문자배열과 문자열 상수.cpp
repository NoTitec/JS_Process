#include <iostream>

using namespace std;

int main()
{
	// 문자열 : 2byte 글자 집합, 다수의 글자를 사용할 때는 결국 배열을 사용해야만 한다.
	// NULL 문자 : 숫자 0을 의미('\0')하며 문자열에 끝을 의미

	//char szName[6] = {'j', 'u', 's', 'i', 'n'};

	char szName[6] = "jusin";

	
	for (int i = 0; i < sizeof(szName) / sizeof(char); ++i)
		cout << szName[i] << endl;

	cout << szName << endl;
	cin >> szName;
	cout << szName << endl;

	/*int		iData = 1 + 2;

	const char*	pStr = "aaaa";	
	const char*	pStr2 = "bbbb"; */

	//cin >> pStr; //포인터로 쓰기 불가

	//cout << pStr << endl;
	return 0;
}
// 1. 문자열을 입력 받고 null문자를 제외한 순수 문자의 길이를 계산하는 함수를 구현하라
// ex) jusin -> 5
// 
// 2. 입력 받은 문자열을 뒤집는 함수를 만들어라
// ex) jusin -> nisuj