#include <iostream>
#include <bitset>

using namespace std;

int main()
{
#pragma region L-Value 와 R-Value
	// L-Value 와 R-Value

	// R - Value : 연산자 기준 오른쪽에 위치하며 쓰기가 불가능한 읽기 타입의 데이터
	// L - Value : 좌항, 우항 모두 위치할 수 있으며, 읽기, 쓰기가 모두 가능한 타입의 데이터

	//const int		iData = 10;
	//int				iSrc  = iData;

	//&10;
	//&iData;

	//cout << iData << endl;
	//cout << iSrc << endl;
#pragma endregion L-Value 와 R-Value

#pragma region 비트 단위 연산자

	// &(and), |(or), ~(not), ^(xor)

	// int		iDst(10), iSrc(13);

	// bitset<출력할 비트 수>(2진수로 출력할 데이터)

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
	11110101	1의 보수
 +		   1    2의 보수
-------------
   100000000	

*/

#pragma endregion 비트 단위 연산자

#pragma region 시프트 연산자

	// <<, >>	: 비트를 왼쪽 또는 오른쪽으로 이동시키는 연산자

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


#pragma endregion 시프트 연산자

#pragma region 연산자 축약형

	// +=, -=, *=, /=, %=, <<=, >>=
	// 자기 자신의 값을 변화시키고자 하는 변수 타입에 적용 가능한 연산자 문법

	//int		iTmp(10);
	//iTmp = iTmp + 20;
	//iTmp += 20;

	//cout << iTmp << endl;

#pragma endregion 연산자 축약형

#pragma region 증감 연산자

	// ++, --
	// 자기 자신의 값을 하나 증가 시키거나 또는 하나 감소 시키는 연산자
	// int		iSrc(1);

	// ++iSrc;		// 전위 연산 : 선 연산 후 대입
	// iSrc++;		// 후위 연산 : 선 대입 후 연산

	// cout << (iSrc++) << endl;

	// cout << (++(++iSrc)) << endl;
	// cout << ((iSrc++)++) << endl;	

#pragma endregion 증감 연산자
	
	return 0;
}