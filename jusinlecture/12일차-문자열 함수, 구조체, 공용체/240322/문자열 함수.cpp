#include <iostream>

using namespace std;

int main()
{

	// ���ڿ� ���� �Լ�

	// strcpy(���� ���� ���ڿ�, ���� �� ���ڿ�)
	// char* strcpy(char* _Dest, char const* _Source)
	
	// strcpy_s(���� ���� ���ڿ�, ���� ���� ���ڿ� �޸� ũ��, ���� �� ���ڿ�)
	//errno_t strcpy_s(char* _Destination, rsize_t _SizeInBytes, char const* _Source)
	
	/*char	szName[32] = "hellohellohello";
	char	szTemp[32] = "world";

	cout << strcpy_s(szName, sizeof(szName), szTemp) << endl;
	cout << szName << endl;*/

	// ���ڿ� ���� �Լ� : �� ���ڿ��� ���ս�Ű�� �Լ�

	// (������ ���� ��� ���ڿ�, ������ ���ڿ�)
	//char* strcat( char, _Destination,char const*, _Source)

	// (��� ���� ������ ���ڿ�, ��� ���� ������ ���ڿ��� ũ��, ������ ���ڿ�)
	// errno_t __cdecl strcat_s(char* _Destination, rsize_t _SizeInBytes,char const* _Source)
		
	//char	szName[32] = "hello";
	//char	szTemp[32] = "_world";

	//strcat_s(szName, sizeof(szName), szTemp);

	//cout << szName << endl;
	//cout << szTemp << endl;

	// ���ڿ� ���̸� ������ִ� �Լ�(null���ڸ� ������ ������ ���� ���̸� ���)
	// size_t strlen(char* pStr)

	// int iLength = strlen("hello");
	// cout << iLength << endl;

	// �� ���ڿ��� ��ġ ���θ� �Ǵ��ϴ� �Լ�
	// (���� ���ڿ� �ּ�1, ���� ���ڿ� �ּ�2)
	// int strcmp(char const* _Str1, char const* _Str2);

	/*char	szName[32] = "hello";

	if (!strcmp("hello", szName))
		cout << "��ġ" << endl;

	else
		cout << "����ġ" << endl;*/

	return 0;
}