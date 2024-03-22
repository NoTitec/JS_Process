#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
// 2. 로또 만들기
// - 배열을 이용하여 1~45사이의 숫자 중 무작위로 6개를 뽑는다.
// - 총 5회 분량을 출력한다.
// - 같은 회차 내에서 중복된 숫자는 존재할 수 없다.
// - 버블 정렬을 이용하여 오름차순 정렬을 하라.(전공자만)
/*
1	2	3	4	5	6
1	2	3	4	5	6
1	2	3	4	5	6
1	2	3	4	5	6
1	2	3	4	5	6
*/

void Set_Random_Number_Seed();
int Get_1_45_Random_Number();
void bubble_sort(int iArr[], int iArrSize);

int main()
{
	//랜덤 넘버 시드값 변경
	Set_Random_Number_Seed();
	//6개뽑은 수들 저장할 크기 6의 배열
	int iArray[6] = {};

	//5회 반복이므로 for문 5번 돌도록
	for (int i = 0; i < 5; i++) 
	{
		//배열에 중복아닌 원소 수
		int iCount(1);
		//반복문 제어 변수
		bool bEnd(true);
		//첫번째 뽑은건 무조건 중복 아니므로 iCount =1, 배열 첫번째 원소는 처음뽑은 랜덤수 넣기
		
		iArray[0] = Get_1_45_Random_Number();

		//숫자 6개가 채워질때까지 반복
		while (bEnd)
		{
			//랜덤수 뽑은게 현재 배열에 중복있는지 저장하는 변수
			bool bduplication(false);
			//랜덤수 1개 뽑기
			int Tmp = Get_1_45_Random_Number();
			//--지금까지 배열에 채운 수 만큼의 배열 위치 검사하면서 중복 값있는지 검사
			for (int j = 0; j < iCount; j++)
			{
				//--중복값이 검출되면 그즉시 중복확인 변수 true 변경하고 해당 반복문 탈출
				if (Tmp == iArray[j])
				{
					bduplication = true;
					break;
				}
			}
			//--중복이 없으면 배열 빈 위치에 뽑은 수 넣어주고 iCount++
			if (!bduplication)
			{
				iArray[iCount] = Tmp;
				++iCount;
			}
			//배열 6개가 모두채워지면 반복문 종료
			if (iCount == 6)
			{
				bEnd = false;
			}
		}
		//버블정렬
		
		bubble_sort(iArray, iCount);
		//6개 모두 채워진 배열 출력문
		for (int j = 0; j < 6; j++)
		{
			cout << setw(3) << iArray[j];
		}
		cout << endl;
	}
	//반복문 안에서 할 task
	// 
	// 숫자 6개가 채워질 때까지 반복해야함(while)
	//--1~45 랜덤수 한번 뽑기
	//--첫번째 뽑은건 바로 배열 삽입
	//--그외 경우 지금까지 뽑은 수 만큼의 배열 위치 검사하면서 중복 값있는지 검사
	//--중복값 없는경우 지금 위치에 뽑은 수 넣어주고
	//--중복값이 검출되면 다시 뽑고 검사, 삽입시도
	//--배열 6개가 모두 채워지면 반복 종료 
	//--버블정렬 수행 후 출력
	return 0;
}

void Set_Random_Number_Seed()
{
	srand(unsigned(time(NULL)));
}

int Get_1_45_Random_Number()
{
	int iRandNumber = rand() % 45 + 1;
	return iRandNumber;
}

void bubble_sort(int iArr[], int iArrSize)
{
	int Tmp(0);
	//한번에 1개식 정렬되므로 정렬완료까지 원소가 n개라면 n-1번 정렬과정 필요
	for (int i = 0; i < iArrSize-1; i++)
	{
		//매 정렬마다 비교는 n-1,n-2,n-3 만큼 비교연산필요하므로 반복문 1번당 한번씩 비교를 덜하게됨
		//라운드마다 정렬된 원소 직전까지 비교 swap실행
		for (int j = 0; j < iArrSize - i - 1; j++)
		{
			//큰수가 오른쪽이동
			if (iArr[j] > iArr[j + 1])
			{
				Tmp = iArr[j];
				iArr[j] = iArr[j + 1];
				iArr[j + 1] = Tmp;
			}
		}
	}
}