#include <iostream>
#include <bitset>

using namespace std;

int main()
{
#pragma region L-Value �� R-Value
	// L-Value �� R-Value

	// R - Value : ������ ���� �����ʿ� ��ġ�ϸ� ���Ⱑ �Ұ����� �б� Ÿ���� ������
	// L - Value : ����, ���� ��� ��ġ�� �� ������, �б�, ���Ⱑ ��� ������ Ÿ���� ������

	//const int		iData = 10;
	//int				iSrc  = iData;

	//&10;
	//&iData;

	//cout << iData << endl;
	//cout << iSrc << endl;
#pragma endregion L-Value �� R-Value

#pragma region ��Ʈ ���� ������

	// &(and), |(or), ~(not), ^(xor)

	// int		iDst(10), iSrc(13);

	// bitset<����� ��Ʈ ��>(2������ ����� ������)

	//cout << bitset<8>(iDst) << endl;
	//cout << bitset<8>(iSrc) << endl;

	/*cout << "----------------&-----------------" << endl;
	cout << bitset<8>(iDst & iSrc) << endl;
	cout << (iDst & iSrc) << endl;*/

	/*cout << "----------------|-----------------" << endl;
	cout << bitset<8>(iDst | iSrc) << endl;
	cout << (iDst | iSrc) << endl;*/

	/*cout << "----------------^-----------------" << endl;
	cout << bitset<8>(iDst ^ iSrc) << endl;
	cout << (iDst ^ iSrc) << endl;*/

	/*cout << "----------------~-----------------" << endl;
	cout << bitset<8>(~iDst) << endl;
	cout << (~iDst) << endl;*/

/*
	00001010
	11110101	1�� ����
 +		   1    2�� ����
-------------
   100000000	

*/

#pragma endregion ��Ʈ ���� ������

#pragma region ����Ʈ ������

	// <<, >>	: ��Ʈ�� ���� �Ǵ� ���������� �̵���Ű�� ������

	int iData(-10);

	//cout << bitset<8>(iData) << endl;
	//cout << "-----------------------------" << endl;
	//cout << bitset<8>(iData << 2) << endl;
	//cout << (iData << 2) << endl;		//10 * 2^2

	//cout << "-----------------------------" << endl;
	//cout << bitset<8>(iData >> 3) << endl;	// 10 / (2^3)
	//cout << (iData >> 3) << endl;

	cout << bitset<16>(iData<<7 ) << endl;
	cout << (iData <<7) << endl;

	/*float		fDst(100.f);

	fDst / 2.f;
	fDst * 0.5f;*/	

	/*int		iDst(100);

	iDst / 2;
	iDst * 0.5f;
	iDst >> 1;	*/


#pragma endregion ����Ʈ ������

#pragma region ������ �����

	// +=, -=, *=, /=, %=, <<=, >>=
	// �ڱ� �ڽ��� ���� ��ȭ��Ű���� �ϴ� ���� Ÿ�Կ� ���� ������ ������ ����

	//int		iTmp(10);
	//iTmp = iTmp + 20;
	//iTmp += 20;

	//cout << iTmp << endl;

#pragma endregion ������ �����

#pragma region ���� ������

	// ++, --
	// �ڱ� �ڽ��� ���� �ϳ� ���� ��Ű�ų� �Ǵ� �ϳ� ���� ��Ű�� ������
	// int		iSrc(1);

	// ++iSrc;		// ���� ���� : �� ���� �� ����
	// iSrc++;		// ���� ���� : �� ���� �� ����

	// cout << (iSrc++) << endl;

	// cout << (++(++iSrc)) << endl;
	// cout << ((iSrc++)++) << endl;	

#pragma endregion ���� ������
	
	return 0;
}