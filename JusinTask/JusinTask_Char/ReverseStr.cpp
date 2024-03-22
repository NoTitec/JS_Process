// 2. 입력 받은 문자열을 뒤집는 함수를 만들어라
// ex) jusin -> nisuj

#include <iostream>

using namespace std;
int Get_Str_Length(const char* str);
void Reverse_Str(char str[],int strlength);

int main()
{
	char Str[100];
	int iStrLength(0);
	
	cin >> Str;
	iStrLength = Get_Str_Length(Str);
	Reverse_Str(Str,iStrLength);
	cout << Str;
	return 0;
}

int Get_Str_Length(const char* str)
{
	int iStrindex(0);
	int iStrLength(0);
	const char* pstr = str;
	while (*pstr++ != '\0')
	{
		iStrLength++;
	}
	return iStrLength;
}

void Reverse_Str(char str[],int strlength)
{
	//0 1 2 3 4 5
	//ex) jusin
	//{j,u,s,i,n,'\0'}
	for (int i = 0; i < (strlength / 2); i++)
	{
		swap(str[i], str[strlength - i-1]);
	}

}
