#include <iostream>

using namespace std;

int main()
{
	// ��� ������ : +, -, *, /, %(������ ������)

	// cout << (11 / 3) << endl;
	// cout << (11 % 3) << endl;	// ������ �����ڴ� ���� �ƴ� ������ ���� ������

	/////////////////////////////////////////
	// ���α׷��� ������ 0 ������� �Ұ��� �ϴ�.
	// nan(not a number) : ���ڰ� �ƴ� ����� �߻����� ��, �˷��ִ� debug ���� ����

	// int		iDst(11), iSrc(0), iTmp(0);
	// cout << (iDst / iSrc) << endl;
	// cout << (iDst % iSrc) << endl;


	// sizeof ������ : �ڷ����� ũ�� �Ǵ� �������� ũ�⸦ ������ִ� ������

	// cout << sizeof(bool) << endl;
	// cout << sizeof(char) << endl;
	// cout << sizeof(short) << endl;
	// cout << sizeof(int) << endl;
	// cout << sizeof(float) << endl;
	// cout << sizeof(long long) << endl;
	// cout << sizeof(long double) << endl;

	// ���� ������(�Ҵ� ������) : ���� �������ִ� ������
	// 1. �����ʿ��� �������� ������ �߻�
	// 2. ���� ������ �������� ���� �ڷ����� ������ �ڷ����� ���ƾ� �Ѵ�.

	//int		iA(10), iB(20), iC(30);

	//float	fD(40.123f);

	// iA = iB;
	// iB = iC;
	// iA = iB = iC = 200;

	//iA = fD;

	// '\t' : tab Ű�� ���� �͸�ŭ ������ ���� 
	// cout << iA << "\t" << iB << "\t" << iC << endl;

	// ���� ������ : �� �׸��� ��� ���踦 �Ǵ��Ͽ� �� �Ǵ� ������ ��ȯ�ϴ� ������

	// <, >, <=, >= , ==(����), !=(���� �ʴ�)

	//int	iDst(10), iSrc(20);

	//cout << (iDst < iSrc) << endl;		// 1
	//cout << (iDst > iSrc) << endl;		// 0
	//cout << (iDst <= iSrc) << endl;		// 1
	//cout << (iDst >= iSrc) << endl;		// 0
	//cout << (iDst == iSrc) << endl;		// 0
	//cout << (iDst != iSrc) << endl;		// 1

	// �� ������ : �� ������ ���� �� �Ǵ� ������ ������ ������
	// &&(and ������), ||(or ������), !(not ������)

	// && : ���ϴ� �� �� ��� ���� ��� ���� ��ȯ

	/*cout << (true  && true) << endl;
	cout << (false && true) << endl;
	cout << (true  && false) << endl;
	cout << (false && false) << endl;*/

	// || : ���ϴ� �� �� �� �ϳ��� ���� ��� ���� ��ȯ

	// cout << (true  || true) << endl;
	// cout << (false || true) << endl;
	// cout << (true  || false) << endl;
	// cout << (false || false) << endl;

	// ! : ���� �������� ������ ������ ����� �ִ� ������

	/*bool		bChoice(true);

	cout << bChoice << endl;
	cout << (!bChoice) << endl;*/

	////////////////////////////////////

	/*int		iData(0);

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iData;

	cout << "�Է� ���� �� : " << iData << endl;*/
		
	return 0;
}

// �ܼ��� ����ǥ ���α׷� �����

// ����, ����, ���� ������ �Է� ����
// ������ ����� ����

// ���� ���� ���� ���� ���
// ?   ?    ?    ?    ?