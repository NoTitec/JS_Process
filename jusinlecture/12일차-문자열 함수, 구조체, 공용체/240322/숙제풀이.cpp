#include <iostream>

using namespace std;

int	My_Strlen(char _szName[]);
void	Reverse_String(char _szName[]);

int main()
{
	char	szName[64] = "";
	int		iLength(0);

	cout << "���ڿ� �Է� : ";
	cin >> szName;

	iLength = My_Strlen(szName);
	cout << "���ڿ� ���� : " << iLength << endl;

	Reverse_String(szName);
	cout << "������ ��� : " << szName << endl;


	return 0;
}
int	My_Strlen(char _szName[])
{
	int	iLength(0);

	/*for (int i = 0; '\0' != _szName[i]; ++i)
		++iLength;*/

	while ('\0' != _szName[iLength])
		iLength++;

	return iLength;
}
void	Reverse_String(char _szName[])
{
	int iLength = My_Strlen(_szName);

	int iRevIdx = iLength - 1;

	for (int i = 0; i < iLength / 2; ++i, --iRevIdx)
	{
	/*	char	cTemp = _szName[i];
		_szName[i] = _szName[iRevIdx];
		_szName[iRevIdx] = cTemp;

		--iRevIdx;*/

		/*char	cTemp = _szName[i];
		_szName[i] = _szName[iRevIdx];
		_szName[iRevIdx--] = cTemp;	*/

		swap(_szName[i], _szName[iRevIdx]);
	}

}