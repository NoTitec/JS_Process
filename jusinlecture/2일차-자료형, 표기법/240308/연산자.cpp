#include <iostream>

using namespace std;

int main()
{
	// 산술 연산자 : +, -, *, /, %(나머지 연산자)

	// cout << (11 / 3) << endl;
	// cout << (11 % 3) << endl;	// 나머지 연산자는 몫이 아닌 나머지 값을 구해줌

	/////////////////////////////////////////
	// 프로그래밍 문법상 0 나누기는 불가능 하다.
	// nan(not a number) : 숫자가 아닌 결과가 발생했을 때, 알려주는 debug 에러 문구

	// int		iDst(11), iSrc(0), iTmp(0);
	// cout << (iDst / iSrc) << endl;
	// cout << (iDst % iSrc) << endl;


	// sizeof 연산자 : 자료형의 크기 또는 데이터의 크기를 계산해주는 연산자

	// cout << sizeof(bool) << endl;
	// cout << sizeof(char) << endl;
	// cout << sizeof(short) << endl;
	// cout << sizeof(int) << endl;
	// cout << sizeof(float) << endl;
	// cout << sizeof(long long) << endl;
	// cout << sizeof(long double) << endl;

	// 대입 연산자(할당 연산자) : 값을 대입해주는 연산자
	// 1. 오른쪽에서 왼쪽으로 대입이 발생
	// 2. 대입 연산자 기준으로 왼쪽 자료형과 오른쪽 자료형은 같아야 한다.

	//int		iA(10), iB(20), iC(30);

	//float	fD(40.123f);

	// iA = iB;
	// iB = iC;
	// iA = iB = iC = 200;

	//iA = fD;

	// '\t' : tab 키를 누를 것만큼 옆으로 띄어쓰기 
	// cout << iA << "\t" << iB << "\t" << iC << endl;

	// 관계 연산자 : 두 항목의 대소 관계를 판단하여 참 또는 거짓을 반환하는 연산자

	// <, >, <=, >= , ==(같다), !=(같지 않다)

	//int	iDst(10), iSrc(20);

	//cout << (iDst < iSrc) << endl;		// 1
	//cout << (iDst > iSrc) << endl;		// 0
	//cout << (iDst <= iSrc) << endl;		// 1
	//cout << (iDst >= iSrc) << endl;		// 0
	//cout << (iDst == iSrc) << endl;		// 0
	//cout << (iDst != iSrc) << endl;		// 1

	// 논리 연산자 : 두 조건을 토대로 참 또는 거짓을 만들어내는 연산자
	// &&(and 연산자), ||(or 연산자), !(not 연산자)

	// && : 비교하는 두 논리 모두 참인 경우 참을 반환

	/*cout << (true  && true) << endl;
	cout << (false && true) << endl;
	cout << (true  && false) << endl;
	cout << (false && false) << endl;*/

	// || : 비교하는 두 논리 중 하나라도 참인 경우 참을 반환

	// cout << (true  || true) << endl;
	// cout << (false || true) << endl;
	// cout << (true  || false) << endl;
	// cout << (false || false) << endl;

	// ! : 참을 거짓으로 거짓을 참으로 만들어 주는 연산자

	/*bool		bChoice(true);

	cout << bChoice << endl;
	cout << (!bChoice) << endl;*/

	////////////////////////////////////

	/*int		iData(0);

	cout << "숫자를 입력하세요 : ";
	cin >> iData;

	cout << "입력 받은 값 : " << iData << endl;*/
		
	return 0;
}

// 단순한 성적표 프로그램 만들기

// 국어, 영어, 수학 점수를 입력 받음
// 총점과 평균을 구함

// 국어 영어 수학 총점 평균
// ?   ?    ?    ?    ?