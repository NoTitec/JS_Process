#include <iostream>
#include <ctime>

using namespace std;

#pragma region 숫자 출력

//int main()
//{
//	const int iSize(5);
//
//	int	iArray[iSize * iSize] = {};
//
//	for (int i = 0; i < 25; ++i)
//	{
//		iArray[i] = i + 1;
//	}
//
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 5; ++j)
//		{
// //맵에서 타일 가로에 해당
//			int	iIndex = i * 5 + j;
//
//			cout << iArray[iIndex] << "\t";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

#pragma endregion 숫자 출력

#pragma region 로또 만들기

// int pArray[] : 함수의 매개 변수로 배열의 이름을 받을 수 있음(int형 포인터와 동일하게 동작)
//void		Bubble_Sort(int pArray[], int _iSize);
//
//int main()
//{
//	srand(unsigned(time(NULL)));
//
//	int		iArray[45] = {};
//	int		iLotto[6] = {};
//
//	for (int i = 0; i < 45; ++i)
//		iArray[i] = i + 1;
//
//	int	iDst(0), iSrc(0);
//
//	for (int k = 0; k < 6; ++k)
//	{
//		for (int j = 0; j < 500; ++j)
//		{
//			iDst = rand() % 45;
//			iSrc = rand() % 45;
//
//			swap(iArray[iDst], iArray[iSrc]);
//		}
//		
//		for (int i = 0; i < 6; ++i)
//			iLotto[i] = iArray[i];
//		
//		// sizeof(배열의 이름) : 할당한 전체 배열의 크기를 계산
//
//		//Bubble_Sort(iLotto, sizeof(iLotto) / sizeof(int));
//		Bubble_Sort(iLotto, size(iLotto));
//
//		for (int i = 0; i < 6; ++i)
//			cout << iLotto[i] << "\t";
//
//		cout << endl;
//		cout << "-----------------------------------------------------" << endl;
//	}
//	
//	return 0;
//}
//void		Bubble_Sort(int pArray[], int _iSize)
//{
//	for (int i = 0; i < _iSize; ++i)
//	{
//		for (int j = 0; j < _iSize - 1; ++j)
//		{
//			if (pArray[j] > pArray[j + 1])
//				swap(pArray[j], pArray[j + 1]);
//		}
//	}
//}

#pragma endregion 로또 만들기

#pragma region 야구 게임

//void		Init_BaseBall(int _iArray[], int _iSize);
//int			Strike(int _iAnswer[], int _iInput[], int _iSize);
//int			Ball(int _iAnswer[], int _iInput[], int _iSize);
//
//int main()
//{
//	srand(unsigned(time(NULL)));
//
//	int		iArray[9] = {};
//	int		iAnswer[3] = {};
//	int		iInput[3] = {};
//	int		iCount(0), iStrike(0), iBall(0);
//
//	Init_BaseBall(iArray, sizeof(iArray) / sizeof(int));
//
//	for (int i = 0; i < 3; ++i)
//		iAnswer[i] = iArray[i];
//
//	while (true)
//	{
//		system("cls");
//
//		cout << "------------------------------------------------------" << endl;
//		cout << "정답 : " << iAnswer[0] << "\t" << iAnswer[1] << "\t" << iAnswer[2] << endl;
//		cout << "------------------------------------------------------" << endl;
//
//		if (9 <= iCount)
//		{
//			cout << "패배" << endl;
//			break;
//		}
//
//		cout << iCount + 1 << " 회차 입력 : ";
//		cin >> iInput[0] >> iInput[1] >> iInput[2];
//		iCount++;
//
//		iStrike = Strike(iAnswer, iInput, sizeof(iAnswer) / sizeof(int));
//		iBall = Ball(iAnswer, iInput, sizeof(iAnswer) / sizeof(int)) ;
//
//		cout << iStrike << " 스트라이크\t" << iBall << " 볼" << endl;
//
//		if (3 == iStrike)
//		{
//			cout << iCount << "회차 승리" << endl;
//			break;
//		}
//
//		system("pause");
//	}
//
//
//	return 0;
//}
//void		Init_BaseBall(int _iArray[], int _iSize)
//{
//	for (int i = 0; i < _iSize; ++i)
//		_iArray[i] = i + 1;
//
//	for (int i = 0; i < 100; ++i)
//		swap(_iArray[rand() % 9], _iArray[rand() % 9]);
//
//}
//int			Strike(int _iAnswer[], int _iInput[], int _iSize)
//{
//	int	iStrike(0);
//
//	for (int i = 0; i < _iSize; ++i)
//	{
//		if (_iAnswer[i] == _iInput[i])
//			++iStrike;
//	}
//
//	return iStrike;
//}
//int			Ball(int _iAnswer[], int _iInput[], int _iSize)
//{
//	int	iBall(0);
//
//	for (int i = 0; i < _iSize; ++i)
//	{
//		for (int j = 0; j < _iSize; ++j)
//		{
//			if(i == j)
//				continue;
//
//			if (_iAnswer[i] == _iInput[j])
//				++iBall;
//		}		
//	}
//
//	return iBall;
//}

#pragma endregion 야구 게임

// 1. 5 * 5 배열을 이용하여 빙고를 만들어라
// - 1~25까지 5*5 배열을 만든다
// - 숫자를 입력 받고 입력 받은 값과 일치한 위치의 숫자를 *로 출력한다.
// - * 이 다섯개인줄이 발생할 경우 빙고를 증가시킨다.
// - 5 빙고 이상이면 종료

// 2. 숫자(0) 이동 시키기

/*
- 0~24까지 5 * 5배열 상태로 출력
- 2. 아래 4. 왼쪽 6. 오른쪽 8. 위
- 번호를 눌렀을 경우 숫자 0의 위치를 이동

0	1	2		1	0	2		1	4	2
3	4	5	-6>	3	4	5 -2>	3	0	5
6	7	8		6	7	8		6	7	8
*/

// 3. 2차원 배열을 이용하여 90도 회전하는 상태 출력하기
/*

1	2	3			7	4	1			9	8	7			3	6	9			1	2	3
4	5	6	-1회전>	8	5	2	-2회전>	6	5	4	-3회전>	2	5	8 -4회전>	4	5	6
7	8	9			9	6	3			3	2	1			1	4	7			7	8	9

*/
