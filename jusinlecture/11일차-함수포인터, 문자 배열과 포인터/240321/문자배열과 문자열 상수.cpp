#include <iostream>

using namespace std;

int main()
{
	// ���ڿ� : 2byte ���� ����, �ټ��� ���ڸ� ����� ���� �ᱹ �迭�� ����ؾ߸� �Ѵ�.
	// NULL ���� : ���� 0�� �ǹ�('\0')�ϸ� ���ڿ��� ���� �ǹ�

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

	//cin >> pStr; //�����ͷ� ���� �Ұ�

	//cout << pStr << endl;
	return 0;
}
// 1. ���ڿ��� �Է� �ް� null���ڸ� ������ ���� ������ ���̸� ����ϴ� �Լ��� �����϶�
// ex) jusin -> 5
// 
// 2. �Է� ���� ���ڿ��� ������ �Լ��� ������
// ex) jusin -> nisuj