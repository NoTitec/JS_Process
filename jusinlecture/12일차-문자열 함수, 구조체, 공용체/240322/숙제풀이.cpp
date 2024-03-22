#include <iostream>

using namespace std;

int	My_Strlen(char _szName[]);
void	Reverse_String(char _szName[]);

int main()
{
	char	szName[64] = "";
	int		iLength(0);

	cout << "문자열 입력 : ";
	cin >> szName;

	iLength = My_Strlen(szName);
	cout << "문자열 길이 : " << iLength << endl;

	Reverse_String(szName);
	cout << "뒤집은 결과 : " << szName << endl;


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